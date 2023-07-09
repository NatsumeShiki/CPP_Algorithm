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
int n, m, k, p, x, q, y;
int arr[N];
int sum;
int res;
bool st[N];

void bfs(){
  priority_queue<PII, vector<PII>, greater<PII>> heap;
  heap.push({0, sum});
  st[sum] = true;
  while(heap.size()){
    auto t = heap.top();
    heap.pop();

    int a = t.x, b = t.y;
    // cout << a << " " << b << endl;
    if(b == 0) {
      cout << a << endl;
      return;
    }
    if(!st[(b + x) % n]){
      st[(b + x) % n] = true;
      heap.push({a + p, (b + x) % n});
    }
    if(!st[(b - y + n) % n]){
      st[(b - y + n) % n] = true;
      heap.push({a + q, (b - y + n) % n});
    }
  }
}

void solve(){
  cin >> n >> p >> x >> q >> y;
  for(int i = 0; i < n; i++){
    int t;
    cin >> t;
    sum += t;
  }
  sum %= n;
  // cout << sum << endl;
  bfs();
  
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