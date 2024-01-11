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
  cin >> s;
  n = s.size();
  if(s[0] >= '5'){
    cout << "10";
    for(int i = 1; i < n; i++) cout << 0;
    cout << endl;
    return;
  }

  int t = 0;
  int index = -1;
  for(int i = n - 1; i >= 0; i--){
    if(s[i] + t >= '5'){
      t = 1;
      index = i;
    }else{
      if(t == 1) index = i;
      t = 0;
    }
  }

  if(index == -1) {
    cout << s << endl;
    return;
  }
  for(int i = 0; i < index; i++) cout << s[i];
  if(s[index] + t >= '5') cout << "10";
  else cout << (char)(s[index] + 1);
  for(int i = index + 1; i < n; i++) cout << 0;
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
    solve();
  }

  return 0;
}