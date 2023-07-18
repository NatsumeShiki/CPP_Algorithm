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

const int N = 3e7 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
int primes[N];
bool st[N];
int res[N];
int cnt;

void solve(){
  cin >> n;
  for(int i = 2; i <= n; i++){
    if(!st[i]) primes[cnt++] = i, res[i] = i;
    for(int j = 0; primes[j] <= n / i; j++){
      st[primes[j] * i] = true;
      res[primes[j] * i] = primes[j];
      if(i % primes[j] == 0) break;
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; i++) {
    // cout << i << " " << res[i] << endl;
    ans += res[i];
  }
  cout << ans << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}