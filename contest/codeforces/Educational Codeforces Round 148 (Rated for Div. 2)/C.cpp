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

const int N = 3e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int a[M];

void solve(){
  int T;
  cin >> T;
  while(T--){
    scanf("%d", &m);
    memset(a, 0, sizeof a);
    n = 1;
    for(int i = 1; i <= m; i++) {
      int x;
      scanf("%d", &x);
      if(x != a[n - 1]) a[n++] = x;
    }
    n--;
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;

    if(n == 1){
      puts("1");
      continue;
    }else if(n == 2){
      puts("2");
      continue;
    }

    bool flag = true;
    for(int i = 2; i <= n; i++)
      if(a[i] < a[i - 1]){
        flag = false;
        break;
      }
    if(flag) {
      puts("2");
      continue;
    }

    flag = true;
    for(int i = 2; i <= n; i++)
      if(a[i] > a[i - 1]){
        flag = false;
        break;
      }
    if(flag) {
      puts("2");
      continue;
    }

    int res = 0;
    for(int i = 1; i <= n;){
      int j = i + 1;
      if(j <= n && a[j] > a[j - 1]){
        for(; j <= n; j++)
          if(a[j] < a[j - 1]) break;
      }
      else{
        for(; j <= n; j++)
          if(a[j] > a[j - 1]) break;
      }
      i = j;
      res++;
    }
    // if(a[1] < a[2]) a[0] = -1e9;
    // else a[0] = 1e9;
    // int i = 1;
    // while(i < n){
    //   if(i + 1 <= n && a[i] < a[i + 1])
    //     while(i + 1 <= n && a[i] < a[i + 1]) i++;
    //   else if(i + 1 <= n && a[i] > a[i + 1])
    //     while(i + 1 <= n && a[i] > a[i + 1]) i++;
    //   res++;
    // }
    res++;
    cout << res << endl;
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