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
set<int> S;

int lowbit(int x) { return x & -x; }

const int N = 1e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
string str;

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n >> str;
    S.clear();
    // cout << str << endl;
    for(int i = 0; i < n - 1; i++){
      char a = str[i], b = str[i + 1];
      int x = (a - 'a') * 26 + b - 'a';
      S.insert(x);
    }
    cout << S.size() << endl;
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