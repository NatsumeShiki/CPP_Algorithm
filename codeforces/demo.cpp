#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;

typedef pair<int, int> PII;
const int N = 2010, M = N * N;
int n, m, k;
int h[N], e[M], ne[M], idx;
int color[N];
bool st[N];
PII query[N];
int dist[N][N];

void add(int a, int b){
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int s, int dist[]){
  queue<int> q;
  q.push(s);
  st[s] = true;
  while(q.size()){
    int t = q.front();
    q.pop();
    for(int i = h[t]; ~i; i = ne[i]){
      int j = e[i];
      if(!st[j]){
        dist[j] = dist[t] + 1;
        q.push(j);
        st[j] = true;
      }
    }
  }
}

void solve(){
  scanf("%d%d", &n, &m);
  memset(h, -1, sizeof h);
  while(m--){
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  for(int i = 1; i <= n; i++){
    memset(st, 0, sizeof st);
    bfs(i, dist[i]);
  }
  // for(int i = 1; i <= n; i++){
  //   for(int j = 1; j <= n; j++)
  //     printf("%d ", dist[i][j]);
  //     puts("");
  // }
  scanf("%d", &k);
  for(int i = 0; i < k; i++) {
    int p, d;
    scanf("%d%d", &p, &d);
    query[i] = {p, d};
    for(int i = 1; i <= n; i++)
      if(dist[p][i] < d){
        color[i] = 1;
      }
  }

  for(int i = 1; i <= n; i++)
    if(!color[i])
      color[i] = 2;

  for(int i = 0; i < k; i++){
    int p = query[i].first, d = query[i].second;
    bool flag = false;
    for(int i = 1; i <= n; i++)
      if(dist[p][i] == d && color[i] == 2){
        flag = true;
        break;
      }
    if(!flag) {
      puts("No");
      return;
    }
  }

  puts("Yes");
  for(int i = 1; i <= n; i++)
    printf("%d", color[i] - 1);
}

int main(){

  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif
  solve();

  return 0;
}


 