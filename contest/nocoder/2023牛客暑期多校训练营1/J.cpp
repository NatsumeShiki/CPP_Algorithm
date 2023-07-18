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
int res1 = 0, res2 = 0;

int exgcd(int a, int b, int& x, int& y){
    if(!b){
        x = 1, y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void add(int a, int b){
  if(res1 == 0){
    res1 = a, res2 = b;
    return;
  }
  res1 = res1 * b + a * res2;
  res2 *= b;
}

int gcd(int a, int b){
  return b ? gcd(b, a % b) : a;
}

void dfs(int now, int sum, int x, int up, int down){
  if(now >= sum){
    // cout << now << " " << sum << " " << x << " " << up << " " << down << endl;
    add(up, down);
    return;
  }
  if(now <= 0 || now < x) return;
  // cout << now << " " << sum << " " << x << " " << up << " " << down << endl;
  // int a = up, b = down,
  // mul(up, down, 1, 2);
  down *= 2;
  dfs(now + x, sum, 1, up, down);

  dfs(now - x, sum, x * 2, up, down);
}

void solve(int n, int m){
  // // int ans1 = 0, ans2 = 0;
  res1 = 0, res2 = 0;
  dfs(n, n + m, 1, 1, 1);
  int k = gcd(res1, res2);
  cout << n << " " << m << " " << res1 / k << " " << res2 / k << endl;

  // int a = 1, b = 1;
  // for(int i = 1; i <= 2; i++) a = a * 3 % mod, b = b * 4 % mod;
  // for(int i = 1; i <= 8; i++) a = a * 7 % mod, b = b * 8 % mod;
  // for(int i = 1; i <= 16; i++) a = a * 15 % mod, b = b * 16 % mod;
  // for(int i = 1; i <= 4; i++) a = a * 31 % mod, b = b * 32 % mod;
  // cout << a << endl << b << endl;
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
  // for(int i = 1; i <= 4; i++){
  //   for(int j = 1; j <= 4; j++)
      solve(15, 1);

  // }
  // }

  return 0;
}