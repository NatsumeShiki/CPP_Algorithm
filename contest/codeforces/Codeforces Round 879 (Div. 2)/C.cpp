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
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    
    int res1 = 0, res2 = 0;
    for(int i = 0; i < n; i++)
      if(s1[i] != s2[i])
        res1++;

    reverse(s1.begin(), s1.end());
    for(int i = 0; i < n; i++)
      if(s1[i] != s2[i])
        res2++;

    if(res1 == 0){
      puts("0");
    }else if(res1 == 1){
      puts("1");
    }else if(res2 == 0){
      puts("2");
    }else if(res2 == 1){
      puts("2");
    } else{
      if(res1 % 2 == 0) res1 *= 2;
      else res1 = res1 + res1 - 1;
      if(res2 % 2 == 1) res2 = res2 + res2;
      else res2 = res2 + res2 - 1;
      cout << min(res1, res2) << endl;
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