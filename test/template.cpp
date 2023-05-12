#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 1e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n;
struct dre{
  int b, w, h;
  bool operator < (const dre &t) const{
    if(b != t.b) return b < t.b;
    if(w != t.w) return w < t.w;
    return h < t.h;
  }  
}dress[N];
int res = 0;

void dfs(int u, dre last, int cnt){
  res = max(res, cnt);
  if(cnt + n - u - 1 <= res) return;
  for(int i = u; i < n; i++){
    int b = dress[i].b, w = dress[i].w, h = dress[i].h;
    if(b > last.b && w > last.w && h > last.h)
      dfs(u + 1, {b, w, h}, cnt + 1);
  }
}

void solve(){
  // int T;
  // cin >> T;
  // while(T--){

  // }
  cin >> n;
  for(int i = 0; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    dress[i] = {a, b, c};
  }
  sort(dress, dress + n);
  
  dre st = {0, 0, 0};
  dfs(0, st, 0);
  cout << res << endl;
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