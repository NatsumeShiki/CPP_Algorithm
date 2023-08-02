// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define x first
// #define y second
// #define endl "\n"
// #define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
// #define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
// #define pep(i,a,b) for(int i = int(a);i < int(b);++i)
// #define per(i,a,b) for(int i = int(b);i > int(b);--i);
// int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

// typedef long long LL;
// typedef pair<int, int> PII;
// typedef pair<PII, int> PIII;
// typedef pair<PII, PII> PIIII;
// typedef pair<int, char> PIC;
// typedef pair<char, int> PCI;
// struct edge{
//   int a, b, c;
//   bool operator < (const edge &t) const{
//     return c < t.c;
//   }
// };

// int lowbit(int x) { return x & -x; }

// const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
// int n, m, k, t;
// int arr[N];
// vector<int> alls;
// struct node{
//   int l, r;
//   int sum, price, add; 
// }tr[N << 2];

// void pushup(int u){
//   tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
//   tr[u].price = (tr[u << 1].price + tr[u << 1 | 1].price) % mod;
// }

// void pushdown(int u){
//   node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
//   if(root.add){
//     left.add += root.add, left.price = (left.price + (left.r - left.l + 1) * root.add % mod) % mod;
//     right.add += right.add, right.price = (right.price + (right.r - right.l + 1) * right.add % mod) % mod;
//     root.add = 0;
//   }
// }

// void build(int u, int l, int r){
//   tr[u] = {l, r};
//   if(l == r) return;
//   int mid = l + r >> 1;
//   build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//   pushup(u);
// }

// void change(int u, int l, int r){
//   // cout << l << " " << r << " " << tr[u].sum << " " << tr[u].price << endl;
//   if(l == r) {
//     tr[u].sum = (tr[u].sum * 2 + tr[u].price) % mod;
//     return;
//   }
//   int mid = l + r >> 1;
//   pushdown(u);
//   change(u << 1, l, mid), change(u << 1 | 1, mid + 1, r);
//   pushup(u);
// }

// void modify(int u, int l, int r, int d){
//   // cout << l << " " << r << " " << tr[u].l << " " << tr[u].r <<  endl;
//   if(tr[u].l >= l && tr[u].r <= r){
//     tr[u].add = (tr[u].add + d) % mod;
//     tr[u].price = (tr[u].price + (tr[u].r - tr[u].l + 1) * d % mod) % mod;
//     // cout << u << " "<< tr[u].price << endl;
//   }else{
//     pushdown(u);
//     int mid = tr[u].l + tr[u].r >> 1;
//     if(l <= mid) modify(u << 1, l, r, d);
//     if(r > mid) modify(u << 1 | 1, l, r, d);
//     pushup(u);
//   }
// }

// int query(int u, int l, int r){
//   // cout << l << " " << r << " " << tr[u].l << " " << tr[u].r <<  endl;
//   // cout << tr[u].price << endl;
//   if(tr[u].l >= l && tr[u].r <= r) return tr[u].price;
//   else{
//     pushdown(u);
//     int mid = tr[u].l + tr[u].r >> 1;
//     int res = 0;
//     if(l <= mid) res = (res + query(u << 1, l, r)) % mod;
//     if(r > mid) res = (res + query(u << 1 | 1, l, r)) % mod;
//     return res;
//   }
// }

// void solve(){
//   cin >> n >> m;
//   build(1, 1, n);
//   for(int i = 1; i <= m; i++){
//     int op, l, r, x;
//     cin >> op >> l >> r;
//     if(op == 0){
//       cin >> x;
//       change(1, 1, n);
//       modify(1, l, r, x);
//     }else{
//       cout << tr[1].sum << endl;
//       cout << (tr[1].sum + query(1, l, r)) % mod << endl;
//       change(1, 1, n);
//     }
//     // cout << op << " " << l << " " << r << " "  << endl;

//     for(int i = 1; i <= 4; i++)
//       cout << i << " " << tr[i].l << " " << tr[i].r << " " << tr[i].sum << " " << tr[i].price << endl;  
//   }
// }

// signed main(){
//   #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//   #endif
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);

//   int T = 1;
//   while(T--){
//     solve();
//   }

//   return 0;
// }

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
int arr[N];
vector<int> alls;
struct node{
  int l, r;
  int sum, price, add; 
}tr[N << 2];

void pushup(int u){
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    tr[u].price = tr[u << 1].price + tr[u << 1 | 1].price;
}

void pushdown(int u){
    node &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if(root.add){
        left.add += root.add, left.sum += (LL)(left.r - left.l + 1) * root.add;
        right.add += root.add, right.sum += (LL)(right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}

void change(int u, int l, int r){
  // cout << l << " " << r << " " << tr[u].sum << " " << tr[u].price << endl;
  if(l == r) {
    tr[u].sum = (tr[u].sum * 2 + tr[u].price) % mod;
    return;
  }
  int mid = l + r >> 1;
  pushdown(u);
  change(u << 1, l, mid), change(u << 1 | 1, mid + 1, r);
  pushup(u);
}

void build(int u, int l, int r){
    if(l == r) tr[u] = {l, r};
    else{
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int d){
    if(tr[u].l >= l && tr[u].r <= r) {
        tr[u].add += d;
        tr[u].sum += (LL)(tr[u].r - tr[u].l + 1) * d;
    }else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r, d);
        if(r > mid) modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

LL query(int u, int l, int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].price;
    else{
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        LL res = 0;
        if(l <= mid) res = query(u << 1, l, r);
        if(r > mid) res += query(u << 1 | 1, l, r);
        return res;
    }
}

void solve(){
  cin >> n >> m;
  build(1, 1, n);
  for(int i = 1; i <= m; i++){
    int op, l, r, x;
    cin >> op >> l >> r;
    if(op == 0){
      cin >> x;
      // change(1, 1, n);
      modify(1, l, r, x);
    }else{
      // change(1, 1, n);
      cout << tr[1].sum << endl;
      cout << (tr[1].sum + query(1, l, r)) % mod << endl;
    }
    // cout << op << " " << l << " " << r << " "  << endl;

    // for(int i = 1; i <= 4; i++)
    //   cout << i << " " << tr[i].l << " " << tr[i].r << " " << tr[i].sum << " " << tr[i].price << endl;  
  }
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