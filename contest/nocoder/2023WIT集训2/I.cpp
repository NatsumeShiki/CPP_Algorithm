#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int p[N], d[N], cnt[N];

int find(int x){
  if(x != p[x]) {
    int t = find(p[x]);
    d[x] += d[p[x]];
    p[x] = t;
  }
  return p[x];
}

void solve(){
  n = 30000;
  for(int i = 1; i <= n; i++) p[i] = i, cnt[i] =  1;
  cin >> m;
  while(m--){
    char op[2];
    int a, b;
    cin >> op >> a;
    if(op[0] == 'M'){
      cin >> b;
      a = find(a), b = find(b);
      d[b] = cnt[a];
      cnt[a] += cnt[b];
      p[b] = a;
    }else{
      int pa = find(a);
      cout << cnt[pa] - d[a] - 1 << endl;
    }
  }
  
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}