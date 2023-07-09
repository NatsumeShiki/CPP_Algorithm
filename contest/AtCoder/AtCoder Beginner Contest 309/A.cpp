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
  int n, m, k, t;
  int arr[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

  void solve(){
    int a, b;
    cin >> a >> b;
    
    if(a % 3 == 0){
      if(b == a - 1) {
        puts("Yes");
        return;
      }
    }else if(b == a + 1){
      puts("Yes");
      return;
    }
    puts("No");
  
  }

  signed main(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    #endif
    // for(int i = 1; i < 9; i++)
    //   for(int j = i + 1; j < 9; j++)
    //     cout << i << " " << j << endl;
    int T = 1;
    // cin >> T;
    while(T--){
      solve();
    }

    return 0;
  }