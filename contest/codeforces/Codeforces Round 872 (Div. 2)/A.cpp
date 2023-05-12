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

// typedef long long LL;
// typedef pair<int, int> PII;
// struct edge{
//   int a, b, c;
//   bool operator < (const edge &t) const{
//     return c < t.c;
//   }
// };

// int lowbit(int x) { return x & -x; }

const int N = 1e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n;

void solve(){
  int T;
  cin >> T;
  while(T--){
    string s;
    cin >> s;
    n = s.size();
    bool flag = true;
    for(int i = 1; i < n; i++)
      if(s[i] != s[i - 1])
        flag = false;

    if(flag){
      puts("-1");
      continue;
    }

    flag = true;
    for(int i = 0; i < n / 2 - 1; i++)
      if(s[i] != s[n - i - 1])
        flag = false;
    if(flag) cout << n - 1 << endl;
    else cout << n << endl;
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