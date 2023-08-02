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
int p[N];
bool st[N];
int pos[N];
int h[N], e[M], ne[M], idx, w[M];

int find(int x){
  if(x != p[x]) p[x] = find(p[x]);
  return p[x];
}

void add(int a, int b, int c){
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void solve(){
  cin >> n >> m;
  vector<vector<PII>> v(n + 10);  
  vector<int> dist(n + 10);
  vector<bool> st(n + 10);
  while(m--){
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, -c});
  }

  for(int i = 1; i <= n; i++){
    if(!st[i]){
      st[i] = true;
      queue<int> q;
      q.push(i);
      while(q.size()){
        int t = q.front();
        q.pop();

        for(auto [b, c] : v[t]){
          if(!st[b]){
            st[b] = true;
            q.push(b);
            dist[b] = dist[t] + c;
          }else if(dist[b] != dist[t] + c){
            puts("NO");
            return;
          }
        }
      }
    }
  }
  // for(int i = 1; i <= n; i++) cout << dist[i] << " ";
  // cout << endl;
  puts("YES");
  // vector<vector<PII>> v(n + 1);
  // for(int i = 1; i <= n; i++) {
  //   pos[i] = 1e18;
  // }
  // for(int i = 0; i < m; i++) {
  //   int a, b, c;
  //   cin >> a >> b >> c;
  //   if(c < 0){
  //     c = -c;
  //     swap(a, b);
  //   }
  //   v[a].push_back({b, c});
  //   v[b].push_back({a, -c});
  //   // p[find(a)] = find(b);
  //   // e[i] = {a, b, c};
  //   // cout << a << " " << b << " " << c << endl;
  // }

  // for(int i = 1; i <= n; i++){
  //   if(!v[i].size()) continue;
  //   if(pos[i] == 1e18) pos[i] = 0;
  //   for(auto item : v[i]){
  //     if(pos[item.x] != 1e18){
  //       pos[i] = pos[item.x] - item.y;
  //     }
  //   }
  //   // for(int i = 1; i <= n; i++) cout << pos[i] << " ";
  //   // cout << endl;
  //   for(auto item : v[i]){
  //     if(pos[item.x] != 1e18 && pos[i] + item.y != pos[item.x]){
  //     // cout << i << " " << pos[i] << " " << item.y << " " << pos[item.x] << endl;
  //       puts("NO");
  //       return;
  //     }
  //     pos[item.x] = pos[i] + item.y; 
  //   }
  // }
  // puts("YES");

  // for(int i = 0; i < m; i++){
  //   int a = e[i].a, b = e[i].b, c = e[i].c;
  //   int pa = find(a);
  //   cout << pa << " ";
  //   if(!st[pa]){
  //     pos[a] = 0;
  //     pos[b] = pos[a] + c;
  //     st[pa] = true;
  //   }else{
  //     if(pos[b] != 1e18 && pos[a] + c != pos[b]){
  //       puts("NO");
  //       return;
  //     }
  //     if(pos[a] != 1e18 && pos[a] + c != pos[b]){
  //       puts("NO");
  //       return;
  //     }

  //     if(pos[a] == 1e18) pos[a] = pos[b] - c;
  //     else if(pos[b] == 1e18) pos[b] = pos[a] + c;
  //   }
  // }
  // // for(int i = 1; i <= n; i++) cout << pos[i] << " ";
  // cout << endl;
  // puts("YES");
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}