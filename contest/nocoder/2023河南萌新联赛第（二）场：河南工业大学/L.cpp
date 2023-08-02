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
char s[N];
struct node{
  int l, r;
  int llen, lch, rlen, rch;
  int mlen, mch, mpos;
}tr[N * 4];

void pushup(node &u, node &l, node &r){
  u.l = l.l;
  u.r = r.r;;
  u.llen = l.llen, u.lch = l.lch;
  if(l.llen == l.r - l.l + 1 && l.rch == r.lch){
    u.llen = l.llen + r.llen;
  }
  u.rlen = r.rlen, u.rch = r.rch;
  if(r.r - r.l + 1 == r.rlen && r.lch == l.rch){
    u.rlen = r.rlen + l.rlen;
  }
  u.mlen = l.mlen, u.mch = l.mch, u.mpos = l.mpos; 
  if(l.rlen + r.llen > u.mlen && l.rch == r.lch){
    u.mlen = l.rlen + r.llen, u.mch = l.rch, u.mpos = l.r - l.rlen + 1;
  }
  if(r.mlen > u.mlen){
    u.mlen = r.mlen, u.mch = r.mch, u.mpos = r.mpos;
  }
}

void pushup(int u){
  pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r){
  if(l == r) tr[u] = {l, r, 1, s[l] - 'a', 1, s[l] - 'a', 1, s[l] - 'a', l};
  else{
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
  }
}

void modify(int u, int pos, int v){
  if(tr[u].l == pos && tr[u].r == pos) tr[u] = {pos, pos, 1, v, 1, v, 1, v, pos};
  else{
    int mid = tr[u].l + tr[u].r >> 1;
    if(pos <= mid) modify(u << 1, pos, v);
    else modify(u << 1 | 1, pos, v);
    pushup(u);
  }
}

node query(int u, int l, int r){
  if(tr[u].l >= l && tr[u].r <= r) return tr[u];
  else{
    int mid = tr[u].l + tr[u].r >> 1;
    if(r <= mid) return query(u << 1, l, r);
    else if(l > mid) return query(u << 1 | 1, l, r);
    else{
      auto left = query(u << 1, l, r);
      auto right = query(u << 1 | 1, l, r);
      node res;
      pushup(res, left, right);
      return res;
    }
  }
}

void solve(){
  cin >> n >> m;
  cin >> s + 1;
  build(1, 1, n);
  while(m--){
    int k;
    char c;
    cin >> k;
    if(k == 1){
      int l, r;
      cin >> l >> r;
      node res = query(1, l, r);
      cout << res.mpos << " " << res.mpos + res.mlen - 1 << endl;
      // cout << query(1, l, r).tmax
    }else{
      int pos;
      cin >> pos >> c;
      modify(1, pos, c - 'a');
    }
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