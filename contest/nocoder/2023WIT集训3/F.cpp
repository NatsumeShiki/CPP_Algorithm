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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
bool st[N];
int primes[N], sz[N];
int cnt;

void solve(){
  cin >> n;
  for(int i = 2; i <= n; i++){
    if(!st[i]){
      primes[cnt] = i;
      while(n % i == 0) {
        n /= i;
        sz[cnt]++;
      }
      cnt++;
    }
  }
  // for(int i = 0; i < cnt; i++) cout << primes[i] << " " << sz[i] << endl;
  // cout << cnt << endl;
  if(n > 1) {
    primes[cnt] = n;
    sz[cnt] = 1;
    cnt++;
  }

  int res = 0;
  for(int i = 0; i < cnt; i++) res += sz[i];
  // cout << res << endl;
  if(res % 2 == 0) puts("Johnson");
  else puts("Nancy");
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