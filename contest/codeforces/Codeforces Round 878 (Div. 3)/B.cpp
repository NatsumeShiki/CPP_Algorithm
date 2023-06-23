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
LL n, m, k, t;

LL qmi(LL a, LL b){
  LL res = 1;
  while(b){
    if(b & 1) res = res * a;
    // cout << (b & 1) << " " << res << endl;
    b >>= 1;
    a = a * a;
    if(res >= n) return res;
  }
  return res;
}


void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n >> k;
    n++;
    LL res;
    if(k > 30) res = n;
    else res = qmi(2, k);
    cout << min(n, res) << endl;
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