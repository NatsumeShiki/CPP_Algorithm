#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<string, int> PSI;
typedef pair<int, string> PIS;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
string s[3];
int cnt[3][10];
int shunxu[6][3] = {
  {0, 1, 2},
  {0, 2, 1},
  {1, 0, 2},
  {1, 2, 0}, 
  {2, 0, 1},
  {2, 1, 0}
};

int get(int x){
  // cout << x << endl;
  int res = INF;
  for(int i = 0; i < 6; i++){
    int index = 0;
    for(int j = 0; j < 3; j++){
      // cout << shunxu[i][j] << endl;
      int t = shunxu[i][j];
      while(true){
        if(s[t][index % n] - '0' == x){
          if(j != 2) index++;
          break;
        }
        index++;
      }
    }
    res = min(res, index);
  }
  // cout << x << "  " << res << endl;
  return res;
}

void solve(){
  cin >> n;
  for(int i = 0; i < 3; i++){
    cin >> s[i];
    for(int j = 0; j < n; j++){
      cnt[i][s[i][j] - '0']++;
    }
  }

  int res = INF;
  for(int i = 0; i < 10; i++){
    if(!cnt[1][i] || !cnt[2][i] || !cnt[0][i]) continue;
    res = min(res, get(i));
  }
  if(res == INF) res = -1;
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
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}