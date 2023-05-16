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
  // int T;
  // cin >> T;
  // while(T--){

  // }
  string s;
  cin >> n >> s;
  int a = 0, b = 0;
  bool flag = true;
  for(int i = 0; i < n; i++){
    if(s[i] == 'T') a++;
    else b++;

    if(a == b){
      if(s[i] == 'T') flag = false;
      else flag = true;
    }
  }

  if(a > b) puts("T");
  else if(b > a) puts("A");
  else{
    if(flag) puts("T");
    else puts("A");
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