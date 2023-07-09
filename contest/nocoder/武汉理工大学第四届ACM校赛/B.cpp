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

const int N = 510, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
LL a[N];

void solve(){
  cin >> n >> k;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 2; i <= n; i++) a[i - 1] = a[i] - a[i - 1];
  n--;

  LL res = 0;
  while(k--){
    int maxv = 1e9, index = 0, sum = 0;
    for(int i = 1; i < n; i++){
      int x = a[i] + a[i + 1];
      if(x > sum && a[i] != 0 && a[i + 1] != 0){
        sum = x;
        index = i;
        maxv = max(a[i], a[i + 1]);
      }else if(x == sum){
        if(maxv > max(a[i], a[i + 1])){
          maxv = max(a[i], a[i + 1]);
          index = i;
        }
      }
    }

    // printf("%d %lld\n", index, sum);

    a[index] += a[index + 1];
    index ++;
    for(; index < n; index++) a[index] = a[index + 1];
    n--;
    for(int j = 1; j <= n; j++) printf("%d ", a[j]);
    puts("");
  }
  for(int i = 1; i <= n; i++) res += a[i] * a[i];
  // cout << res << endl;

  printf("%lld\n", res);
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}