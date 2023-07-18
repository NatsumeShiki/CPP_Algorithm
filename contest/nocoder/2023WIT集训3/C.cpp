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
  int h[N], e[M], w[M], ne[M], idx;
  int dist[N];

  void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
  }

  void bfs(){
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    while(q.size()){
      int t = q.front();
      q.pop();

      for(int i = h[t]; ~i; i = ne[i]){
        int j = e[i];
        if(dist[j] > dist[t] + w[i]){
          dist[j] = dist[t] + w[i];
          q.push(j);
        }
      }
    }
  }

  void solve(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
      int a, b, c;
      cin >> a >> b >> c;
      add(a, b, c), add(b, a, c);
    }

    bfs();
    // cout << dist[n] << endl;
    if(dist[n] == 0x3f3f3f3f3f3f3f3f) puts("qwb baka");
    else cout << dist[n] << endl;
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