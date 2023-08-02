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
int n, m, k, t;
int arr[N], idx;
bool st[N];
// vector<int> alls;
int p[N];
edge e[N];
vector<int> alls[N];

int find(int x){
  if(x != p[x]) p[x] = find(p[x]);
  return p[x];
}

bool check(int mid){
  for(int i = 1; i <= n; i++) p[i] = i;
  for(int i = 0; i < m; i++){
    if(e[i].c > mid) break;
    auto [a, b, c] = e[i];
    int pa = find(a), pb = find(b);
    if(pa != pb) p[pa] = pb;
  }

  int pa = find(arr[0]);
  for(int i = 1; i < idx; i++)
    if(find(arr[i]) != pa) return false;
  return true;
}

void solve(){
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    e[i] = {a, b, c};
  }
  cin >> k;
  for(int i = 0; i < k; i++){
    int cnt;
    cin >> cnt;
    while(cnt--){
      int x;
      cin >> x;
      if(!st[x]) st[x] = true, arr[idx++] = x;
    }
  }
  sort(e, e + m);
  int l = 0, r = 1e9;
  while(l < r){
    int mid = l + r >> 1;
    if(check(mid)) r = mid;
    else l = mid + 1;
  }
  cout << l << endl;

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