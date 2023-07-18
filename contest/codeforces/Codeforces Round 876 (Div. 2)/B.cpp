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
  int a, b;
  bool operator < (const edge &t) const{
    if(a != t.a) return a < t.a;
    return b > t.b;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
edge e[N];
bool st[N];

void solve(){
  cin >> n;
  // for(int i = 0; i < n; i++) st[i] = false;
  for(int i = 0; i < n; i++) cin >> e[i].a >> e[i].b;
  sort(e, e + n);

  int res = 0;
  int cnt = 0;
  int last = 0;
  for(int i = 0; i < n; i++){
    auto t = e[i];
    int a = t.a, b = t.b;
    if(!st[a]) {
      st[last] = false;
      cnt = a;
      st[a] = true;
      last = a;
    }
    if(cnt) {
      res += b;
      cnt--;
    }
    // cout << res << " " << cnt << endl;
  }
  st[last] = false;
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