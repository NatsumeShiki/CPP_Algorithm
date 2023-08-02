  #include<bits/stdc++.h>
  using namespace std;

  #define int long long
  #define x first
  #define y second
  #define endl "\n"
  #define FOR(n) for(int i = 0; i < n; i++) 
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

  const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f, mod = 998244353;
  int n, m, k, t;
  int arr[M];
  vector<int> alls;
  int last[M];
  int s[M];
  int dp[M][3];

  void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) cin >> s[i];

    for(int i = 1; i <= n; i++){
      last[i] = last[i - 1];
      if(s[i - 1] == 1) last[i] = i - 1;
    }

    int res = 0;
    for(int i = 1; i <= n; i++){
      if(s[i] == 1){
        int k = last[i];
        if(i - k >= 3) {
          // dp[i][0] = max(dp[k][0], max(dp[k][1], dp[k][2])) + arr[i - 1];
          dp[i][0] = max({dp[k][0], dp[k][1], dp[k][2]}) + arr[i - 1];
          dp[i][1] = max(dp[k][0], max(dp[k][1], dp[k][2])) + arr[i];
          dp[i][2] = max(dp[k][0], max(dp[k][1], dp[k][2])) + arr[i + 1];
        }else if(i - k == 2){
          dp[i][0] = max(dp[k][0], dp[k][1]) + arr[i - 1];
          dp[i][1] = max(dp[k][0], max(dp[k][1], dp[k][2])) + arr[i];
          dp[i][2] = max(dp[k][0], max(dp[k][1], dp[k][2])) + arr[i + 1];
        }else{
          dp[i][0] = dp[k][0] + arr[i - 1];
          dp[i][1] = max(dp[k][0], dp[k][1]) + arr[i];
          dp[i][2] = max(dp[k][0], max(dp[k][1], dp[k][2])) + arr[i + 1];
        }
        res = max(res, dp[i][0]);
        res = max(res, dp[i][1]);
        res = max(res, dp[i][2]);
      }
    }
    cout << res << endl;
  }

  signed main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while(T--){
      solve();
    }

    return 0;
  }