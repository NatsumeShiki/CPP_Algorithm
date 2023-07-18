#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
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
bool st[N];
int x[N], y[N];

int getDist(int i, int j){
  int dx = x[i] - x[j], dy = y[i] - y[j];
  return dx * dx + dy * dy;
}

void solve(){
  cin >> n >> m;
  st[0] = true;
  for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
  queue<int> q;
  q.push(0);
  while(q.size()){
    int t = q.front();
    q.pop();
    // cout << t << endl;
    for(int i = 0; i < n; i++)
      if(getDist(t, i) <= m * m){
        if(!st[i]) q.push(i); 
        st[i] = true;
      }
  }

  for(int i = 0; i < n; i++)
    if(st[i]) puts("Yes");
    else puts("No");
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}