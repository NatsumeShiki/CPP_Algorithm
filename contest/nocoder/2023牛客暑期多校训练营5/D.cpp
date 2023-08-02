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
int n, m, k, t, c;
int arr[N];
vector<int> alls;


// void init(){

// }

int gcd(int a, int b){
  return b ? gcd(b, a % b) : a;
}

void solve(){
  int res = 0;
  cin >> k >> c >> n;
  int a, b;
  for(int i = 1; i * i <= c; i++){
    // cout << i << " ";
    if(c % i == 0){
      b = c / i;
      if((c - b) % k == 0) {
        // cout << i << " ";
        a = (c - b) / k;
        if(gcd(a, b) >= n && a && b) res++;
      }
      
      // cout << a << " " << b << endl;
      if(i * i == c) continue;
      b = i;
      if((c - b) % k != 0) continue;
      // cout << i << " ";
      a = (c - b) / k;
      if(gcd(a, b) >= n && a && b) res++;
      // cout << a << " " << b << endl;
    }
    b = i;
    
  }
  cout << res << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  // init(1e5);
  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}