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

const int N = 3500, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
char p1[2][3] = {{".."}, {".*"}}, p2[2][3] = {{"**"}, {"*."}};
char a1[N][N] = {{"******"}, {"******"}, {"******"}, {"***..."}, {"***..."}, {"***..."}};
char b1[N][N] = {{"......"}, {"......"}, {"......"}, {"...***"}, {"...***"}, {"...***"}};
char a2[N][N], b2[N][N];

void solve(){
  cin >> m;
  n = 2;
  k = 6;

  while(--m){
    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
        for(int x = 0; x <= k; x++)
          for(int y = 0; y <= k; y++){
            char c;
            if(p1[i][j] == '.') c = b1[x][y];
            else c = a1[x][y];
            // cout << c << endl;
            // exit(0);
            a2[i * k + x][j * k + y] = c;
          }

    for(int i = 0; i < 2; i++)
      for(int j = 0; j < 2; j++)
        for(int x = 0; x <= k; x++)
          for(int y = 0; y <= k; y++){
            char c;
            if(p2[i][j] == '.') c = b1[x][y];
            else c = a1[x][y];
            b2[i * k + x][j * k + y] = c;
          }

    memcpy(a1, a2, sizeof a2);
    memcpy(b1, b2, sizeof b2);
    k *= n;
  }

  for(int i = 0; i < k; i++) puts(a1[i]);

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