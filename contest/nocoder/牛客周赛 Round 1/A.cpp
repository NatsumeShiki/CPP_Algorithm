#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
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
  for(int i = 0; i < 3 * n; i++){
    for(int j = 0; j < n; j++) cout << '*';
    for(int j = 0; j < n * 2; j++) cout << '.';
    for(int j = 0; j < n; j++) cout << '*';
    cout << endl;
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++) cout << '.';
    for(int j = 1; j <= n; j++) cout << '*';
    for(int j = 1; j <= 2 * n - i * 2; j++) cout << '.';
    for(int j = 1; j <= n; j++) cout << '*';
    for(int j = 1; j <= i; j++) cout << '.';
    cout << endl;
  }
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}