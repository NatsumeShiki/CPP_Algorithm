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
int n, m;
int a[N], s[N];


void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n >> m;
    memset(a, 0, sizeof a);
    int cnt = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++){
      int x;
      cin >> x;
      if(x == -1) cnt1++;
      else if(x == -2) cnt2++;
      else {
        if(!a[x]) cnt++;
        a[x] = 1;
      }
    }
    for(int i = 1; i <= m; i++) s[i] = s[i - 1] + a[i];
    int res = 0;
    for(int i = 1; i <= m; i++){
      if(!a[i]) continue;
      int x = min(i - s[i], cnt1);
      int y = min((m - i) - (s[m] - s[i]), cnt2);
      res = max(res, x + y + cnt);
    }
    res = max(res, cnt1 + cnt);
    res = max(res, cnt2 + cnt);
    res = min(res, m);
    cout << res << endl;
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