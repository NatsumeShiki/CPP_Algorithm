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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
vector<int> alls;
int a[N];
int f[N];

void solve(){
  cin >> n;
  for(int i = 1; i <= n; i++){
    int x, y;
    cin >> x >> y;
    x = !x;
    // y = !y;
    arr[i] = x + y;
    // cout << x + y << " " << i << endl;
  }

  int len = 0;
  f[0] = -INF;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    x = arr[x];
    int l = 0, r = len;
    while(l < r){
      int mid = l + r + 1 >> 1;
      if(f[mid] <= x) l = mid;
      else r = mid - 1;
    }
    f[l + 1] = x;
    len = max(len, l + 1);
    // cout << x << " ";
  }
  cout << n - len << endl;
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