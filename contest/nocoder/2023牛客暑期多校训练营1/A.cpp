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

int qmi(int a, int b){
  int res = 1;
  while(b){
    if(b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}

int exgcd(int a, int b, int& x, int& y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve(){
  cin >> n >> m;
  // cout << n << " " << m << " ";
  // if(n == 1 && m == 1){
  //   cout << 499122177 << endl;
  //   return;
  // }

  int st = 1, ed = 2;
  while(st * 2 + 1 < n){
    st = st * 2 + 1;
    ed *= 2;
  }

  int k = st + ed - n;
  if(k > m) k = m;
  int res1 = 1, res2 = 1;
  res1 = qmi(st, k);
  res2 = qmi(ed, k);
  // cout << st << " " << ed << endl;
  st = st * 2 + 1;
  ed *= 2;
  m -= k;
  while(m > 0){
    int k = ed;
    if(k > m) k = m;
    // cout << k << endl;
    res1 = res1 * qmi(st, k) % mod;
    res2 = res2 * qmi(ed, k) % mod;
    st = st * 2 + 1;
    ed *= 2;
    m -= k;
  // cout << res1 << " " << res2 << endl;

  }

  // if(n == 1 && m == 1) res1 = 1, res2 = 2;
  int x, y;
  int d = exgcd(res2, mod, x, y);
  cout << ((x * res1 / d % mod) + mod) % mod << endl;
  // cout << res1 << " " << res2 << endl;

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
  // while(T--){
  // for(int i = 1; i <= 10; i++)
  //   for(int j = 1; j <= 10; j++)
      solve();

  // }
  // }

  return 0;
}