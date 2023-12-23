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

const int N = 1010, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
vector<int> alls;
int a[N][N];
 
int change(int target){
  int res = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
      if(a[i][j] == target && a[n - i + 1][n - j + 1] != target) res++;
 
  return res;
}
 
void solve(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++) 
      cin >> a[i][j];
 
  int cnt = 0;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++){
      if(a[i][j] != a[n - i + 1][n - j + 1]){
        a[n - i + 1][n - j + 1] = a[i][j];
        cnt++;
      }
    }
 
  if(cnt > k) puts("NO");
  else if(n % 2 == 0 && (k - cnt) % 2 == 1) puts("NO");
  else puts("YES");
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