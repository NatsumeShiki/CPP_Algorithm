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

const int N = 1e8 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
int a[N], maxv[N];

void solve(){
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = n; i >= 1; i--) maxv[i] = max(maxv[i + 1], a[i]);

  stack<int> st;
  for(int i = 1; i <= n; ){
    if(st.empty()) st.push(a[i]), i++;
    else if(st.top() < maxv[i]) st.push(a[i]), i++;
    else if(st.top() > maxv[i]) {
      cout << st.top() << " ";
      st.pop();
    }
  }

  while(st.size()){
     cout << st.top() << " ";
     st.pop();
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
  // cin >> T;
  while(T--){
    solve();
  }

  return 0;
}