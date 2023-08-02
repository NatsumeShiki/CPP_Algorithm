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
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
int d[N];
bool st[N];

void solve(){
  cin >> n;
  int maxv = n * (1 + n) / 2;
  int res = 0;
  for(int i = 1; i <= n; i++) st[i] = false;
  for(int i = 1; i <= n - 1; i++){
    cin >> arr[i];
    d[i] = arr[i] - arr[i - 1];
    if(d[i] > n) res = d[i];
    // st[i] = false;
    // cout << d[i] << " ";
  }

  for(int i = 1; i <= n - 1; i++){
    if(d[i] > maxv){
      cout << "No" << endl;
      return;
    }
    if(d[i] <= n && st[d[i]]) res = d[i];
    if(d[i] <= n) st[d[i]] = true;
  }

  int a = 0, b = 0;
  for(int i = 1; i <= n; i++){
    if(!st[i]){
      if(a == 0) a = i;
      else if(a != 0 && b == 0) b = i;
      else{
        cout << "No" << endl;
        return;
      }
    }
  }
  // cout << endl << a << " " << b << endl;
  if((a == 0 && b == 0) || (a + b == res) || res == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
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
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}