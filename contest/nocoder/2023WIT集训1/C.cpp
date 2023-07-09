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
map<int, int> mp;
int big[N], small[N];

void solve(){
  cin >> n >> m;
  int index;
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    if(x > m) big[i]++;
    else if(x < m) small[i]++;
    else index = i;
  }

  for(int i = 1; i <= n; i++){
    big[i] += big[i - 1];
    small[i] += small[i - 1];
  }

  LL res = 0;
  for(int i = index; i <= n; i++) mp[big[i] - small[i]]++;
  for(int i = 0; i < index; i++) res += mp[big[i] - small[i]];
  cout << res << endl;
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