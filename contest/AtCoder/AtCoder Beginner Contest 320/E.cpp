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
int res[N];

void solve(){
  cin >> n >> m;
  priority_queue<int, vector<int>, greater<int>> heap;
  for(int i = 1; i <= n; i++) heap.push(i);
  priority_queue<PII, vector<PII>, greater<PII>> q;
  while(m--){
    int a, b, c;
    cin >> a >> b >> c;
    // cout << a <<  b << c << endl;
    while(q.size()){
      auto [x, y] = q.top();
      if(x <= a) {
        q.pop();
        heap.push(y);
      }else break;
    }

    if(heap.size()){
      int t = heap.top();
      heap.pop();
      res[t] += b;
      q.push({a + c, t});
    }
  }

  for(int i = 1; i <= n; i++) cout << res[i] << endl;
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