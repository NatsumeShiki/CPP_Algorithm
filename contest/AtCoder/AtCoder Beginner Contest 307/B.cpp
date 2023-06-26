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
string s[N];

bool check(string str){
  int x = str.size();
  // cout << x << endl;
  for(int i = 0; i < x / 2; i++)
    if(str[i] != str[x - i - 1]) return false;
  return true;
}

void solve(){
  cin >> n;
  for(int i = 0; i < n; i++) cin >> s[i];

  bool flag = false;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      string str = s[i] + s[j];
      // cout << str << endl;
      if(check(str)){
        flag = true;
        break;
      }
      // cout << flag << endl;
    }
    if(flag) break;
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