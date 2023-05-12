#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
// #include<bits/stdc++.h>
using namespace std;
// #define x first
// #define y second
// #define int long long
// int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
// typedef pair<int, int> PII;
// struct edge{
//   int a, b, c;
//   bool operator < (const edge &t) const{
//     return c < t.c;
//   }
// };

int lowbit(int x) { return x & -x; }

const int N = 110, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m;

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n >> m;
    LL maxd1 = -INF, maxd2 = -INF, mind1 = INF, mind2 = INF;
    for(int i = 0; i < n * m; i++){
      int x;
      cin >> x;
      if(x > maxd1) maxd2 = maxd1, maxd1 = x;
      else if(x > maxd2) maxd2 = x;
      if(x < mind1) mind2 = mind1, mind1 = x;
      else if(x < mind2) mind2 = x;
    }
    if(n < m) swap(n, m);

    LL res1 = 0, res2 = 0;
    res1 += (maxd1 - mind2) * (m - 1);
    res1 += (maxd1 - mind1) * (n - 1) * m;
    res2 += (maxd2 - mind1) * (m - 1);
    res2 += (maxd1 - mind1) * (n - 1) * m;
    cout << max(res1, res2) << endl;
  }
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