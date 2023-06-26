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

const int N = 15, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int n1, m1, n2, m2, n3, m3;
char a[N][N], b[N][N], c[35][35], d[35][35];

bool check(int x1, int y1, int x2, int y2){
  for(int i = 0; i < 35; i++)
    for(int j = 0; j < 35; j++)
      d[i][j] = '.';

  for(int i = x1, i1 = 0; i < x1 + n1; i++, i1++)
    for(int j = y1, j1 = 0; j < y1 + m1; j++, j1++)
      if(a[i1][j1] == '#')
        d[i][j] = '#';

  for(int i = x2, i1 = 0; i < x2 + n2; i++, i1++)
    for(int j = y2, j1 = 0; j < y2 + m2; j++, j1++)
      if(b[i1][j1] == '#')
        d[i][j] = '#';

  for(int i = 0; i < 30; i++){
    for(int j = 0; j < 30; j++){
      if(c[i][j] != d[i][j]) 
        return false;
    }
  }
  return true;
}

void solve(){
  cin >> n1 >> m1;
  for(int i = 0; i < n1; i++) cin >> a[i];
  cin >> n2 >> m2;
  for(int i = 0; i < n2; i++) cin >> b[i];
  cin >> n3 >> m3;
  for(int i = 0; i < 35; i++)
    for(int j = 0; j < 35; j++)
      c[i][j] = '.';
  for(int i = 10; i < 10 + n3; i++) 
    for(int j = 10; j < 10 + m3; j++)
      cin >> c[i][j];

  for(int i = 0; i < 30 - n1; i++){
    for(int j = 0; j < 30 - m1; j++){
      for(int k = 0; k < 30 - n2; k++){
        for(int u = 0; u < 30 - m2; u++){
          if(check(i, j, k, u)){
            puts("Yes");
            exit(0);
          }
        }
      }
    }
  }
  puts("No");
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