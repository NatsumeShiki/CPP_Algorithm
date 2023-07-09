#include<bits/stdc++.h>
using namespace std;

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

const int N = 2e5 + 10, M = 1e6 + 10, INF = 0x3f3f3f3f;
int n, m, k, t;
char s[55];

void solve(){
  cin >> s;
  // cout << s << endl;
  n = strlen(s);
  while(n > 1){
    int index = 0;
    for(int i = 0; i < n - 1; i++){
      if(s[i] == 'a' && s[i + 1] == 'b'){
        index = i;
        break;
      }
    }
    if(s[index] != 'a' || s[index + 1] != 'b') break;
    while(index < n - 2) {
      s[index] = s[index + 2];
      index++;
    }
    s[index] = '\0';
    n = strlen(s);
    // cout << s << endl;
  }

  if(n > 0) cout << "Bad" << endl;
  else cout << "Good" << endl;
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