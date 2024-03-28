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
// int ne0[N], ne1[N];

void solve(){
  cin >> n >> s;
  reverse(s.begin(), s.end());
  int cnt = 0;
  for(int i = 0; i < n; i++){
    if(s[i] == '1')
      cnt++;
  }
  if(cnt == 0){
    for(int i = 1; i <= n; i++) cout << "0 ";
    cout << endl;
    return;
  }

  for(int i = 1; i < n; i++){
    if(i + cnt > n){
      cout << "-1 ";
      continue;
    }
    int j = 0, k = i;
    int res = 0;

    while(j < i){
      if(s[j] == '0') {
        j++;
        continue;
      }
      while(s[k] == '1') k++;
      res += k - j;
      s[j] = '0', s[k] = '1';
      k++;
      j++;
    }
    cout << res << " ";
  }
  cout << -1 << endl;
}

void solve1(){
  cin >> n >> s;
  int res = 0;
  int l = n, r = n;
  for(int i = 1; i <= n; i++){
    if(res == -1){
      cout << "-1 ";
      continue;
    }

    if(l > n - i && s[n - i] == '0') l -= 1;
    else{
      while(l > 0 && s[l - 1] == '1') l--;
      if(l == 0) res = -1;
      else res += r - l;
      l--;
    }
    r--;
    cout << res << " ";
  }
  cout << endl;
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
    solve1();
  }

  return 0;
}