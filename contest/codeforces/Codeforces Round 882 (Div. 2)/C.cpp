#include<bits/stdc++.h>
using namespace std;

#define int long long
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
const int N = 31 * 1e5 + 10;
int n, m;
int s[N];
int idx;

void insert(int tr[N][2], int cnt[], int x, int v){
    int p = 0;
    for(int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(!tr[p][u]) tr[p][u] = ++idx;
        p = tr[p][u];
        cnt[p] += v;
    }
}

int query(int tr[N][2], int cnt[], int x){
    int p = 0, res = 0;
    for(int i = 30; i >= 0; i--){
        int u = x >> i & 1;
        if(cnt[tr[p][!u]]) p = tr[p][!u], res = res * 2 + !u;
        else p = tr[p][u], res = res * 2 + u;
    }
    return res;
}

void solve(){
    cin >> n;
   int tr[N][2] = {0}, cnt[N] = {0};
    idx = 0;
    m = n + 1;
    int res = 0;
    insert(tr, cnt, s[0], 1);
    for(int i = 1; i <= n; i++){
        cin >> s[i];
        s[i] ^= s[i - 1];
        if(i - m - 1 >= 0) insert(tr, cnt, s[i - m - 1], -1);
        res = max(res, query(tr, cnt, s[i]) ^ s[i]);
        insert(tr, cnt, s[i], 1);
    }
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

// #include<bits/stdc++.h>
// using namespace std;

// #define int long long
// #define x first
// #define y second
// int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

// typedef long long LL;
// typedef pair<int, int> PII;
// typedef pair<int, PII> PIII;
// typedef pair<int, PIII> PIIII;
// struct edge{
//   int a, b, c;
//   bool operator < (const edge &t) const{
//     return c < t.c;
//   }
// };

// int lowbit(int x) { return x & -x; }

// const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
// int n, m, k, t;
// map<int, int> mp;
// int a[N];

// void solve(){
//     mp.clear();
//     cin >> n;
//     for(int i = 1; i <= n; i++) cin >> a[i];

//     int maxv = -1;
//     int res = 0;
//     mp[0] = 1;
//     for(int i = 1; i <= n; i++){
//         res ^= a[i];
//         for(auto item : mp){
//             maxv = max(maxv, item.first ^ res);
//         }
//         mp[res] = 1;
//     }
//     cout << maxv << endl;
// }

// signed main(){
//   #ifndef ONLINE_JUDGE
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//   // ios::sync_with_stdio(false);
//   // cin.tie(0);
//   #endif

//   int T = 1;
//   cin >> T;
//   while(T--){
//     solve();
//   }

//   return 0;
// }