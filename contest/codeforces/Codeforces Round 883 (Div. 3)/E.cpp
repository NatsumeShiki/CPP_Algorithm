#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PIII, int> PIIII;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int arr[N];
bool st[M];

void solve(){
  for(int i = 2; i <= 1e6; i++){
    int j = i;
    int cnt = 1 + 1 * j;
    int k = j * j;
      // cout << cnt << " " << k << endl;

    while(cnt <= 1e6){
      cnt += k;
      // cout << cnt << " " << k << endl;
      // cout << (cnt < 100000) << endl;
      k *= j;
      if(cnt <= 1e6) st[cnt] = true;
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

    solve();
  int T = 1;
  cin >> T;
  while(T--){
    cin >> n;
    if(st[n]) puts("yes");
    else puts("no");
  }

  return 0;
}