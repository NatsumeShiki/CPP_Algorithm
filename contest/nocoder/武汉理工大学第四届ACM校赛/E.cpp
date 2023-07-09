#include<bits/stdc++.h>
using namespace std;

#define int long long
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

const int N = 1010, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
// string a[N], b[N];
// int res[N];
vector<string> all;


void solve(){
  cin >> n;
  for(int i = 0; i < n; i++){
    string s;
    cin >> s;
    all.push_back(s);
  }

  cin >> m;
  cout << m << endl;
  while(m--){
    string s;
    cin >> s;
    cout << find(all.begin(), all.end(), s) - all.begin() + 1 << endl;
    all.erase(find(all.begin(), all.end(), s));
    all.insert(all.begin(), s);
  }
  // cin >> n;
  // for(int i = 1; i <= n; i++) cin >> a[i];
  // cin >> m;
  // for(int i = 1; i <= m; i++) cin >> b[i];

  // int cnt = 0;
  // for(int i = 1; i <= m; i++){
  //   string str = b[i];
  //   int j = 1;
  //   while(j <= n && a[j] != str) j++;
  //   res[cnt++] = j;
  //   while(j > 1) a[j] = a[j - 1], j--;
  //   a[1] = str;
  // }

  // cout << cnt << endl;
  // for(int i = 0; i < cnt;i ++) cout << res[i] << endl;
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