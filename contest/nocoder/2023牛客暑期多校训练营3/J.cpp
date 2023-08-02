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

const int N = 1e6 + 10, M = 2e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, m, k, t;
int arr[N];
vector<int> alls;
int d[M];
int h[N], e[M], ne[M], idx;
int res[M], cnt;

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}


bool topsort(){
  queue<int> q;
  for(int i = 1; i <= n; i++)
    if(d[i] == 0){
      q.push(i);
    }

  while(q.size()){
    int t = q.front();
    q.pop();
    res[cnt++] = t;
    for(int i = h[t]; ~i; i = ne[i]){
      int j = e[i];
      if(--d[j] == 0){
        q.push(j);
      }
    }
  }

  return cnt == n;
}

void solve(){
  cin >> n >> m;
  memset(h, -1, sizeof h);
  while(m--){
    int a, b;
    cin >> a >> b;
    d[b]++;
    add(a, b);
  }
  if(topsort()){
    cout << 1 << endl;
    for(int i = 0; i < cnt; i++) cout << res[i] << " \n"[i == n - 1];
  }else{
    cout << 2 << endl;
    for(int i = 1; i <= n; i++) cout << i << " \n"[i == n - 1];
    cout << endl;
    for(int i = n; i >= 1; i--) cout << i << " "[i == 0];
  }
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