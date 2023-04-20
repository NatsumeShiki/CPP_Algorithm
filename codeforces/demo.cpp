#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;

// string s;
int n;

void solve(){
  int t;
  cin >> t;
  while(t--){
    cin >> n;
    string str, res;
    cin >> str;
    // res = str;
    // for(int i = 1; i < n; i++){
    //   string s = str[i] + str.substr(0, i) + str.substr(i + 1);
    //   if(res.compare(s) > 0) res = s;
    // }
    // cout << res <<endl;
    int index = n + 1, i = 1;
    char c = 'z';
    for(; i < n; i++)
      if(str[i] != str[i - 1])
        break;
    for(; i < n; i++) 
      if(c >= str[i]){
        c = str[i];
        index = i;
      }

    if(index < n && str[index] <= str[0]) str = str[index] + str.substr(0, index) + str.substr(index + 1);
    cout << str << endl;
  }
}

int main(){

  // string s = "abc", str = "aba";
  // cout << s.compare(str) << endl;

  #ifndef ONLINE_JUDGE
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  // ios::sync_with_stdio(false);
  // cin.tie(0);
  #endif
  solve();

  return 0;
}


 