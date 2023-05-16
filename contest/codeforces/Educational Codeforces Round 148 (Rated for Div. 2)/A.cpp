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
int n, m, k, t;

void solve(){
  int T;
  cin >> T;
  while(T--){
    string s;
    cin >> s;
    n = s.size();

    bool flag = false;
    for(int i = 1; i < n; i++)
      if(s[i] != s[i - 1]){
        flag = true;
        break;
      }
    if(!flag){
      puts("NO");
      continue;
    }

    flag = false;
    for(int i = 1; i < n / 2; i++)
      if(s[i] != s[i - 1]){
        flag = true;
        break;
      }
    for(int i = n / 2 + 2; i < n; i++)
      if(s[i] != s[i - 1]){
        flag = true;
        break;
      }
    if(!flag) puts("NO");
    else puts("YES");
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