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
int arr[100][100];
string s, str;
int cnt[100];
int a[N];
int res = 0;


void solve(){
  cin >> n;
  memset(cnt, 0, sizeof cnt);
  set<int> S;
  for(int i = 0; i < n; i++){
    cin >> a[i];
    for(int j = 0; j < a[i]; j++) {
      cin >> arr[i][j];
      cnt[arr[i][j]]++;
      S.insert(arr[i][j]);
    }
  } 
  int t = S.size();

  int res = 0;
  for(int i = 1; i <= 50; i++){
    
    for(int j = 0; j < n; j++){
      bool flag = false;
      for(int k = 0; k < a[j]; k++){
        if(arr[j][k] == i) {
          flag = true;
          break;
        }
      }
      if(flag){
        for(int k = 0; k < a[j]; k++){
          cnt[arr[j][k]]--;
        }
      }
    }

    int ans = 0;
    for(int j = 1; j <= 50; j++) 
      if(cnt[j]) ans++;
    
    if(ans != t) res = max(res, ans);
    
    for(int j = 0; j < n; j++){
      bool flag = false;
      for(int k = 0; k < a[j]; k++){
        if(arr[j][k] == i) {
          flag = true;
          break;
        }
      }
      if(flag){
        for(int k = 0; k < a[j]; k++){
          cnt[arr[j][k]]++;
        }
      }
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
  cout.tie(nullptr);

  int T = 1;
  cin >> T;
  while(T--){
    solve();
  }

  return 0;
}