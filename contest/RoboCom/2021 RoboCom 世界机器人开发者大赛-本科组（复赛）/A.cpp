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

void solve(){
  int a[3], b[3], c[3], d[3];
  n = 3;
  bool flag = true;
  int sum1 = 0, sum2 = 0;
  for(int i = 0; i < n; i++) cin >> a[i], sum1 += a[i];
  for(int i = 0; i < n; i++) {
    cin >> b[i];
    c[i] = b[i] - a[i];
    sum2 += b[i];
    if(c[i] % 20 != 0) flag = false;
    c[i] /= 20;
    // cout << c[i] << endl;
  }
  if(sum1 != sum2) flag = false;  
  for(int i = 0; i < n; i++){
    d[i] = (c[i] % 3 + 3) % 3;
    // cout << d[i] << endl;
  }
  // cout << flag << endl;
  if(d[0] != d[1] || d[0] != d[2] || d[1] != d[2]) flag = false;

  if(!flag) {
    cout << -1 << endl;
    return;
  }

  int maxv = max({abs(c[0]), abs(c[1]), abs(c[2])});
  // cout << maxv << endl;
  int res = maxv / 2;
  maxv -= res * 2;
  cout << res + maxv << endl;
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