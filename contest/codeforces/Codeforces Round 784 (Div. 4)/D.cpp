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
char a[N];

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    scanf("%s", a);

    bool success = true;
    for(int i = 0;  i< n; i++){
      if(a[i] != 'W'){
        success = false;
        break;
      }
    }
    if(success){
      puts("YES");
      continue;
    }

    if(n == 1 && a[0] != 'W'){
      puts("NO");
      continue;
    }else if(n == 2 && ((a[0] == 'W' && a[1] != 'W') || a[0] != 'W' && a[1] == 'W')){
      puts("NO");
      continue;
    }
    
    bool flag = false;
    int l = 0, r = n - 1;
    int red = 0, blue = 0;
    while(l < n && a[l] != 'W'){
      if(a[l] == 'R') red++;
      else blue++;
      l++;
    }
    if((blue && !red) || (!blue && red)){
      puts("NO");
      continue;
    }
    red = 0, blue = 0;
    while(r >= 0 && a[r] != 'W'){
      if(a[r] == 'R') red++;
      else blue++;
      r--;
    }
    if((blue && !red) || (!blue && red)){
      puts("NO");
      continue;
    }

    for(int i = l; i < r; ){
      int j = i + 1;
      if(a[i] == 'W'){
        int red = 0, blue = 0;
        while(j < n && a[j] != 'W'){
          if(a[j] == 'B') blue++;
          else red++;
          j++;
        }
        // cout << red << " " << blue << endl;
        if(j - i - 1 == 1){
          flag = true;
          break;
        }else {
          if((blue && !red) || (!blue && red)){
            flag = true;
            break;
          }
        }
      }
      i = j;
    }
    if(flag) puts("NO");
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