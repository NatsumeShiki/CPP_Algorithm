#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PIII, int> PIIII;
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
  cin >> n >> m >> k;

  // if(n >= m * k) {
  //   cout << m * k << endl;
  //   return;
  // }
  int sum = m * k;
  int res = 0;
  int x;
  if(k % 2 == 0) x = k / 2 - 1;
  else x = k / 2;
  // cout << x << " x" << endl;
  res += (n - 1) * x;
  sum -= res;
  // cout << sum << "  sum" << endl;
  // cout << res << "  res" << endl;
  if(sum % k > x) res -= k - sum % k;
  else res += sum % k;

  if(res > m * k) res = m * k;
  cout << res << endl;
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