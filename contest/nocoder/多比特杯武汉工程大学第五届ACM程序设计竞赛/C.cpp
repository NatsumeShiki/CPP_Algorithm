#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
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
int s[N], cnt[N];
int fact[N], infact[N];

int qmi(int a, int b){
  int res = 1;
  while(b){
    if(b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

int C(int a, int b){
  return fact[a] * infact[a - b] % mod * infact[b] % mod;
}

void solve(){
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    cnt[x]++;
  }
  for(int i = 1; i <= 2e5; i++) s[i] = s[i - 1] + cnt[i];
  fact[0] = infact[0] = 1;
  for(int i = 1; i <= 2e5; i++){
    fact[i] = fact[i - 1] * i % mod;
    infact[i] = infact[i - 1] * qmi(i, mod - 2) % mod;
  }
  int res = 0;
  for(int i = 1; i + k <= 2e5; i++){
    int a = s[i + k] - s[i - 1], b = cnt[i], c = cnt[i + k];
    if(a < m || !b || !c) continue;
    res = (res + C(a, m) - C(a - b, m) - C(a - c, m) + C(a - b - c, m)) % mod;
  }
  cout << (res + mod) % mod << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}