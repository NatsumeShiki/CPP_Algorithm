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

const int N = 5e4 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int tr1[N], tr2[N];


void add(int tr[], int x, int v){
  for(int i = x; i <= n; i += lowbit(i)) tr[i] += v;
}

int query(int tr[], int x){
  int res = 0;
  for(int i = x; i; i -= lowbit(i)) res += tr[i];
  return res;
}

void solve(){
  cin >> n >> m;
  while(m--){
    int k, l, r;
    cin >> k >> l >> r;
    if(k == 1){
      add(tr1, l, 1);
      add(tr2, r, 1);
    }else{
      cout << query(tr1, r) - query(tr2, l - 1) << endl;
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