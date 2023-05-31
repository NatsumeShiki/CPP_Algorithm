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
// int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 110, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
char g[N][N];
string str = "snuke";
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool dfs(int x, int y, int type, string s, int cnt){
  if(x < 0 || x >= n || y < 0 || y >= m) return false; 
  s += g[x][y];
  if(cnt == 5){
    // cout << s << endl;
    if(s == str) return true;
    return false;
  }
  return dfs(x + dx[type], y + dy[type], type, s, cnt + 1);
}

void print(int x, int y, int type, int cnt){
  cout << x + 1 << " " << y + 1 << endl;
  if(cnt == 5) return;
  print(x + dx[type], y + dy[type], type, cnt + 1);
}

void solve(){

  cin >> n >> m;
  for(int i = 0; i < n; i++) cin >> g[i];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      for(int k = 0; k < 8; k++){
        string s = "";
        if(dfs(i, j, k, s, 1)){
          print(i, j, k, 1);
          return;
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

  solve();

  return 0;
}