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
// vector<int> alls;
set<int> S1;
set<int> S2;
set<int> S;

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= n / i; i++){
    if(n % i != 0) continue;
    S1.insert(i);
    S1.insert(n / i);
  }

  for(int i = 1; i <= m / i; i++){
    if(m % i != 0) continue;
    S2.insert(i);
    S2.insert(m / i);
  }

  for(auto a : S1)
    for(auto b : S2)
      S.insert(a * b);

  cout << S.size() << endl;
  for(auto a : S) cout << a << " ";
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
  while(T--){
    solve();
  }

  return 0;
}