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

LL find(int x){
    return (LL)x * (x + 1) * (x + 2) / 6;
}

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int cnt[M];

void solve(){
    LL n;
    cin >> n;
    LL l = 1, r = 1000000;
    while(l < r){
        LL mid = l + r >> 1;
        if(find(mid) >= n) r = mid;
        else l = mid + 1;
    }
    cout << r << endl;
    for(int i = r; i; i -- ){
        if(n > (r - i + 1) * i){
            n -= (r - i + 1) * i;
            cout << r - i + 1 << endl;
        }
        else{
            int cnt = n / i;
            cout << cnt << endl;
            n -= cnt * i;
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

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}