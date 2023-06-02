#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
#include<unordered_map>
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

const int N = 10, M = 20;
bool col[N], row[N], deg[M], rdeg[M];
int g[N][N];
int n;
int res;

void dfs(int x, int y, int cnt){
  if(y == n) x++, y = 0;
  if(x == n){
    if(cnt == n) res++;
    return;
  }

  dfs(x, y + 1, cnt);
  if(g[x][y] == 1 && !row[x] && !col[y] && !deg[x + y] && !rdeg[x - y + n]){
    row[x] = col[y] = deg[x + y] = rdeg[x - y + n] = true;
    dfs(x, y + 1, cnt + 1);
    row[x] = col[y] = deg[x + y] = rdeg[x - y + n] = false;
  }
}

int s[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void solve(){
  int n = 100;
  int arr[100];
  for(int i = 0; i < n; i++) cin >> arr[i];
  set<int> S;
  int cnt = 0;
  for(int a = 0; a < n; a++)
    for(int b = a + 1; b < n; b++)
      for(int c = b + 1; c < n; c++)
        for(int d = c + 1; d < n; d++){
          int year = arr[a] * 1000 + arr[b] * 100 + arr[c] * 10 + arr[d];
          if(year != 2023) continue;
          for(int e = d + 1; e < n; e++)
            for(int f = e + 1; f < n; f++){
              int month = arr[e] * 10 + arr[f];
              if(month < 1 || month > 12) continue;
              for(int g = f + 1; g < n; g++)
                for(int h = g + 1; h < n; h++){
                  int day = arr[g] * 10 + arr[h];
                  if(day >= 1 && day <= s[month]){
                    S.insert(year * 1000 + month * 100 + day);
                    cnt++;
                  }
                } 
            }
        }

  cout << S.size() << endl;
  cout << cnt << endl;
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