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

void solve(){
  cin >> n;
  if(n == 1) {
    puts("0");
    return;
  }
  
  int ans = 0;
  for(int i = 1; i < n; i++){
    int x = i;
    int res = i;
    for(int j = 2; j <= x / j; j++){
      if(x % j == 0){
        while(x % j == 0) x /= j;
        res = res / j * (j - 1);
      }
    }
    if(x > 1) res = res / x * (x - 1);
    // if(i == 2) cout << i << " " << res << endl;
    ans += res;
  }
  cout << ans * 2 + 1 << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}