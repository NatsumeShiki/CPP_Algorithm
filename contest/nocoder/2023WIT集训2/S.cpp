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
bool st[M];
int dist[M];

int get(int x){
  int cnt = 0;
  while(x){
    cnt++;
    x -= lowbit(x);
  }
  return cnt;
}

void bfs(){
  queue<int> q;
  q.push(n);
  // cout << get(1) << endl;
  while(q.size()){
    int t = q.front();
    q.pop();

    int k = get(t);
    int s[4] = {t + 1, t - 1, t + k, t - k};
    for(int i = 0; i < 4; i++){
      int a = s[i];
      if(a < 0 || a > 1e6 || st[a]) continue;
      st[a] = true;
      dist[a] = dist[t] + 1;
      q.push(a);  
      if(a == m){
        cout << dist[a] << endl;
        exit(0);
      }
    }
  } 
}

void solve(){
  cin >> n >> m;
  bfs();
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}