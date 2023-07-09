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

const int N = 110, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int cnt[N];

void solve(){
  int T;
  cin >> T;
  while(T--){
    int n, k, x;
    cin >> n >> k >> x;

    if(x != 1){
      puts("YES");
      cout << n << endl;
      for(int i = 0; i < n; i++) cout << 1 << " ";
      cout << endl;
    }else{
      if(k >= 2 && n % 2 == 0){
        puts("YES");
        cout << n / 2 << endl;
        for(int i = 0; i < n / 2; i++) cout << 2 << " ";
        cout << endl;
      }else if(k >= 3){
        puts("YES");
        cout << n / 2 << endl;
        cout << 3 << " ";
        for(int i = 0; i < n / 2 - 1; i++) cout << 2 << " ";
        cout << endl;
      }else{
        puts("NO");
      }
    }
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