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

const int N = 31 * 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
int tr[N][2];
int cnt[N];
int idx;

void insert(int u, int x, int p, int y){
  if(u == -1) return;
  int t = x >> u & 1;
  if(!tr[p][t]) tr[p][t] = ++idx;
  cnt[tr[p][t]] += y;
  insert(u - 1, x, tr[p][t], y);
}

int query(int u, int x, int p, int hp){
  if(u == -1) return 0;
  int t = hp >> u & 1;
  int tt = x >> u & 1;
  int res = 0;
  if(t == 0){
    if(tr[p][!tt]) res += cnt[tr[p][!tt]];
    if(tr[p][tt]) res += query(u - 1, x, tr[p][tt], hp);
  }else{
    if(tr[p][!tt]) res += query(u - 1, x, tr[p][!tt], hp);
  }
  return res;
}

void solve(){
  cin >> n >> m;
  while(n--){
    int op, x, hp;
    cin >> op >> x;
    if(op == 0){
      insert(31, x, 0, 1);
    }else if(op == 1){
      insert(31, x, 0, -1);
    }else{
      cin >> hp;
      int res = query(31, x, 0, hp);
      if(!res) m--;
      cout << res << endl;
    }
  }
  cout << m << endl;
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}