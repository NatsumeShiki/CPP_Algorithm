#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define FOR(n) for(int i = 0; i < n; i++) 
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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m, k, t;
int arr[N];
vector<int> alls;
int ola[N];

void init(){
  for(int i = 1; i <= 10; i++){
    int res = i;
    int x = i;
    for(int j = 2; j <= x / j; j++){
      if(x % j == 0){
        while(x % j == 0) x /= j;
        res = res * (j - 1) / j;
      }
    }
    if(x > 1) res = res * (x - 1) / x;
    ola[i] = res;
  }
}

int qmi(int a, int b){
  int res = 1;
  while(b){
    if(b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

void solve(){
  cin >> n;
  // for(int i = 1; i <= n; i++){
  //   int ans = 0;
  //   for(int j = 1; j <= n; j++){
  //     ans += ola[j] * (i / j);
  //   }
  //   cout << ans << " ";
  //   res += ans;
  // }
  // cout << res << endl;

  int res = ((n % mod) * ((n + 1) % mod)) % mod;
  res = (res * ((n + 2) % mod)) % mod;
  cout << res * (qmi(6, mod - 2) % mod) % mod << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();
  // for(int i = 1; i <= 10; i++) cout << ola[i] << " ";
  // cout << endl;
  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}