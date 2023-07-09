#include<bits/stdc++.h>
using namespace std;

// #define int long long
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
struct node{
  LL x, y;
  int index;
  bool operator<(const node &t)const{
    if(y == t.y && x != t.x) return x < t.x;
    if(x * t.y != t.x * y) return x * t.y < t.x * y;

    return index > t.index;
  }
}a[N];

void solve(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    LL x, y;
    scanf("%lld%lld", &x, &y);
    a[i] = {x, x + y, i + 1};
  }
  sort(a, a + n);
  reverse(a, a + n);
  for(int i = 0; i < n; i++) {
    // cout << a[i].x << " " << a[i].y << " " << a[i].index << endl;
    cout << a[i].index << endl;
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