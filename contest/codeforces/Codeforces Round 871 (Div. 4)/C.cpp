#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
 
const int N = 2e5 + 10;
int n;
int w[N];
string s[N];

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> w[i] >> s[i];
    int res = 0x3f3f3f3f;
    for(int i = 0; i < n; i++)
      if(s[i] == "11")
        res = min(res, w[i]);

    int a = 0x3f3f3f3f, b = 0x3f3f3f3f;
    for(int i = 0; i < n; i++){
      if(s[i] == "10") a = min(a, w[i]);
      if(s[i] == "01") b = min(b, w[i]);
    }
    res = min(res, a + b);
    if(res == 0x3f3f3f3f) res = -1;
    cout << res << endl;
  }
}

int main(){
  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif

  solve();

  return 0;
}