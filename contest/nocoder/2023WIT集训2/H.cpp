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
int p[N];
map<string, int> mp;

int find(int x){
  if(x != p[x]) p[x] = find(p[x]);
  return p[x];
}

void solve(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    string s;
    cin >> s;
    if(!mp[s]) mp[s] = i;
    p[i] = i;
  }

  while(m--){
    int k;
    string s1, s2;
    cin >> k >> s1 >> s2;
    int a = mp[s1], b = mp[s2];
    if(k == 1){
      p[find(a)] = find(b);
    }else{
      if(find(a) == find(b)) puts("1");
      else puts("0");
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