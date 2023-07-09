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
int prime[M];
int cnt;
bool st[M];

void getPrimes(){
  int n = 1e6;
  for(int i = 2; i <= n; i++){
    if(!st[i]) prime[cnt++] = i;
    for(int j = 2; i * j <= n; j++) st[j * i] = true;
  }
}

void solve(){
  int T;
  cin >> T;
  getPrimes();
  while(T--){
    int x;
    cin >> x;
    bool flag = true;
    while(x){
      int l = 0, r = cnt - 1;
      while(l < r){
        int mid = l + r + 1 >> 1;
        if(prime[mid] <= x) l = mid;
        else r = mid - 1;
      }
      if(prime[l] != x){
        flag = false;
        break;
      }
      x /= 10;
    }
    if(flag) puts("YES");
    else puts("NO");
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