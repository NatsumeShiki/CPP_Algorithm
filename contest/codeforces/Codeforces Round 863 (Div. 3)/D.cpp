#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define all(a) a.begin(), a.end()
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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
string s, str;
int fib[50];

void solve(){
  int x, y;
  cin >> n >> x >> y;
  while(n > 0){
    if(y > fib[n - 1] && y <= fib[n]) {
      cout << "No\n";
      return;
    }
    if(y > fib[n]) y -= fib[n];
    swap(x, y);
    n--;
  }
  cout << "Yes\n";
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  fib[0] = fib[1] = 1;
  for(int i = 2; i <= 44; i++){
    fib[i] = fib[i - 1] + fib[i - 2];
    // cout << i << " " << fib[i] << endl;
  }
  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}