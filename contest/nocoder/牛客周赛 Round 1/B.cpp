#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef pair<int, PIII> PIIII;
typedef pair<int, char> PIC;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
PIC a[N];

void solve(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &a[i].x);
  scanf("%c", &a[0].y);
  for(int i = 0; i < n; i++) scanf("%c", &a[i].y);

  sort(a, a + n);
  LL res = 0;
  for(int i = 0; i < n; ){
    int j = i;
    LL x = 0, y = 0;
    int temp = a[j].x;
    for(; j < n && a[j].x == temp; j++){
      // cout << a[j].x << " " << a[j].y << endl;
      if(a[j].y == 'B') x++;
      else y++;
    }
    // cout << x << " " << y << endl;
    res += x * y;
    i = j;
  }

  cout << res << endl;
  // for(int i = 0; i< n; i++) printf("%c", a[i].y);


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