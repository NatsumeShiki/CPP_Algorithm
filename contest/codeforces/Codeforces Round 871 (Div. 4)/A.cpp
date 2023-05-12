#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<vector>
using namespace std;
 
int n;


void solve(){
  int T;
  cin >> T;
  string str = "codeforces";
  while(T--){
    string s;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++)
      if(s[i] != str[i])
        cnt++;

    cout << cnt << endl;
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