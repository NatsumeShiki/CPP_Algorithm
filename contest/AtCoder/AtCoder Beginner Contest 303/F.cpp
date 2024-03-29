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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;

void solve(){
  cin >> n;
  string a, b;
  cin >> a >> b;
  bool flag = true;
  for(int i = 0; i < n; i++){
    if(a[i] == '1' && b[i] == 'l') continue;
    else if(a[i] == 'l' && b[i] == '1') continue;
    else if(a[i] == '0' && b[i] == 'o') continue;
    else if(a[i] == 'o' && b[i] == '0') continue;
    else if(a[i] != b[i]) flag = false;
  }
  if(flag) puts("Yes");
  else puts("No");
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