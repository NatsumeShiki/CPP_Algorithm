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

const int N = 55, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
char str[N][N];

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> str[i];

    for(int i = 0; i < m; i++){
      for(int j = n - 1; j >= 0; j--){
        if(str[j][i] == '*'){
          int k = j;
          while(k + 1 < n && str[k + 1][i] == '.') k++;
          char c = str[j][i];
          str[j][i] = '.';
          str[k][i] = c;
        }
      }
    }

    for(int i = 0; i < n; i++) cout << str[i] << endl;
    cout << endl;
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