  #include<bits/stdc++.h>
  using namespace std;

  #define int long long
  #define x first
  #define y second
  #define endl "\n"
  #define rep(i,a,b) for(int i = int(a);i <= int(b);++i)
  #define rer(i,a,b) for(int i = int(b);i >= int(a);--i)
  #define pep(i,a,b) for(int i = int(a);i < int(b);++i)
  #define per(i,a,b) for(int i = int(b);i > int(b);--i);
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
  int arr[N];
  vector<int> alls;

  void solve(){
    string s;
    cin >> n >> m >> s;
    s = " " + s;

    vector<int> lf(n + 1), rg(n + 1);
    lf[1] = 0;
    for(int i = 1; i <= n; i++){
      if(i > 1) lf[i] = lf[i - 1];
      if(s[i] == '0') lf[i] = i;
      // cout << lf[i] << " \n"[i == n];
    }
    rg[n] = n + 1;
    for(int i = n; i >= 1; i--){
      if(i < n) rg[i] = rg[i + 1];
      if(s[i] == '1') rg[i] = i;
      // cout << rg[i] << " \n"[i == 1];
    }

    set<PII> S;
    while(m--){
      int l, r;
      cin >> l >> r;
      // cout << l << " " << r << " ";
      l = rg[l], r = lf[r];
      if(l > r) S.insert({-1, -1});
      else S.insert({l, r});
      // cout << l << " " << r << endl;
    }

    cout << S.size() << endl;
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
    cin >> T;
    while(T--){
      solve();
    }

    return 0;
  }