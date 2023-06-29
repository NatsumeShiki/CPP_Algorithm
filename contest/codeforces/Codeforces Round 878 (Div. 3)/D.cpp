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
int a[N];

bool check(int mid){
  int x = 0, y = 0;
  while(x + 1 < n && a[0] + mid * 2 >= a[x + 1]) x++;
  // cout << x << endl;
  y = x + 1;
  while(y + 1 < n && a[x + 1] + mid * 2 >= a[y + 1]) y++;
  // cout << x << " " << y << " " << mid << endl;
  // cout << a[n - 1] - a[y + 1] << endl;
  if(x + 1 == n || y + 1 == n) return true;
  if(a[y + 1] + mid * 2 < a[n - 1]) return false;

  return true;
}

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int l = 0, r = 1e9;
    while(l < r){
      int mid = l + r >> 1;
      if(check(mid)) r = mid;
      else l = mid + 1;
      // cout << mid << endl;
    }
    cout << l << endl;
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