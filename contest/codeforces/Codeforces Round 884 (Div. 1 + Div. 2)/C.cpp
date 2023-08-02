#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define FOR(n) for(int i = 0; i < n; i++) 
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
vector<int> alls;

void solve(){
  cin >> n;
  int res1 = 0, res2 = 0;
  int min1 = -1e9, min2 = -1e9;
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    if(i % 2 == 1) {
      if(x > 0) res1 += x;
      min1 = max(min1, x);
    }
    if(i % 2 == 0) {
      if(x > 0) res2 += x;
      min2 = max(min2, x);
    }
  }
  
  if(res1 > 0 || res2 > 0) cout << max(res1, res2) << endl;
  else cout << max(min1, min2) << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}