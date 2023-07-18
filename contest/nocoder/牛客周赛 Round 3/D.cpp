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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m, k, t;
int arr[N];

void solve(){
  cin >> n;
  int cnt1 = 4;
  int cnt2 = (n * 2 + (n - 2) * 2 - 4) % mod;
  int cnt3 = (n * n - cnt1 - cnt2) % mod;
  int a = cnt1 * (1 + cnt1) % mod;
  int b = cnt2 * (1 + cnt1 + cnt1 + cnt2) / 2 % mod * 3 % mod;
  int c = cnt3 * ((1 + cnt1 + cnt2 + n * n % mod) % mod) % mod * 2 % mod;
  // cout << cnt1 << " " << cnt2 << " " << cnt3 << endl;
  // cout << a << " " << b << " " << c << endl;
  cout << (a + b + c) % mod << endl; 
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