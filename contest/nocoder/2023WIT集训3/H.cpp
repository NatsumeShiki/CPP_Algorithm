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

  int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
  }

  void solve(){
    cin >> n;
    int res = 0;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for(int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if(x == 1) cnt3++;
      if(x == 0) cnt4++;
      if(x % 2 == 1) cnt1++;
      else cnt2++;
      res = gcd(res, x);
    }
    // cout << cnt3 << endl << cnt4 << endl;
    // if(cnt1 == 0 && cnt2 == 0) puts("0");
    if(cnt4 == n) puts("0");
    else if(res != 1) puts("1");
    else if(cnt1 == 0) puts("1");
    else if(cnt3 + cnt4 == n) puts("1");
    else puts("2");
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