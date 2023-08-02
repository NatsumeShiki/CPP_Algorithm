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
  cin >> n >> s;
  int m = s.size();
  if(m == 1){
    if(s == "0") {
      cout << string(n, '1');
      cout << endl;
    }
    else{
      cout << string(n, '0');
      cout << endl;
    }
  }else if(m == 2){
    if(s == "00") {
      cout << string(n, '1');
      cout << endl;
    }
    else {
      cout << string(n, '0');
      cout << endl;
    }
  }else{
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= m - 2; i++){
      if(s[i] == '0') cnt1++;
      else cnt2++;
    }

    if(!cnt1){
      cout << string(n, '0');
      cout << endl;
      return;
    }else if(!cnt2){
      cout << string(n, '1');
      cout << endl;
      return;
    }

    bool flag = true;
    string t(n, '1');
    string str = s + t + s;
    // cout << str << endl;
    for(int i = 1; i < n + m; i++){
      string substr = str.substr(i, m);
      // cout << substr << endl;
      if(s == substr){
        flag = false;
        break;
      }
    }
    if(flag){
      cout << string(n, '1');
      cout << endl;
    }else{
      cout << string(n, '0');
      cout << endl;
    }
  }
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