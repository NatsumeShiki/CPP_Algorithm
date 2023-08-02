#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  string a;
  int b;
  string c;
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
bool stRow[M], stCol[M];
edge e[M];

void solve(){
  cin >> n >> m >> k;
  int res = 0;
  for(int i = 1; i <= k; i++){
    string a;
    int b;
    string c;
    cin >> a >> b >> c;
    e[i] = {a, b, c};
  }

  int row = n, col = m;
  for(int i = k; i; i--){
    auto [a, b, c] = e[i];
    if(a == "row"){
      if(stRow[b]) continue;
      if(c == "on"){
        res += col;
        row--;
      }else{
        // res -= (m - col);
        row--;
      }
      stRow[b] = true;
    }else{
      if(stCol[b]) continue;
      if(c == "on"){
        res += row;
        col--;
      }else{
        // res -= (n - row);
        col--;
      }
      stCol[b] = true;
    }
    // cout << res << endl;
  }
  cout << res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}