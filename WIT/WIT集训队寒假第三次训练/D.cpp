#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x first
#define y second
#define endl "\n"
#define all(a) a.begin(), a.end()
#define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
#define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
#define pep(i,a,b) for(int i = int(a);i < int(b);++i)
#define per(i,a,b) for(int i = int(b);i > int(b);--i);
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<PII, PII> PIIII;
typedef pair<string, int> PSI;
typedef pair<int, string> PIS;
typedef pair<int, char> PIC;
typedef pair<char, int> PCI;
struct edge{
  int a, b, c;
  bool operator < (const edge &t) const{
    return c < t.c;
  }
};

int lowbit(int x) { return x & -x; }

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f3f3f3f3f, mod = 998244353;
int n, m, k, t, q;
int arr[M];
string s, str;
int h[M], e[M], ne[M], idx;
int d[M];
int f[M], cnt;

bool topsort(){
  priority_queue<int, vector<int>, greater<int>> q;
  for(int i = 1; i <= n; i++)
    if(!d[i])
      q.push(i);

  while(q.size()){
    int t = q.top();
    q.pop();
    f[cnt++] = t;
    for(int i = h[t]; ~i; i = ne[i]){
      int j = e[i];
      d[j]--;
      if(!d[j]){
        q.push(j);
      }
    }
  }
  return cnt == n;
}


void add(int a, int b){
  e[idx] = b, ne[idx]= h[a], h[a] = idx++;
}

void solve(){
  cin >> n >> m;
  memset(h, -1, sizeof h);
  while(m--){
    int a, b;
    cin >> a >> b;
    add(a, b);
    d[b]++;
  }

  if(!topsort()) cout << -1;
  else for(int i = 0; i < cnt; i++) cout << f[i] << " ";
}

signed main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T = 1;
  while(T--){
    solve();
  }

  return 0;
}