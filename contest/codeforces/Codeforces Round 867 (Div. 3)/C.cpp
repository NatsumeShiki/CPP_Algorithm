#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
 
typedef long long LL;
int n;

void solve(){
  int T;
  cin >> T;
  while(T--){
    cin >> n;
    // LL l, c;
    // c = 13 + (n - 4) * 6;
    // if(n % 2) l = 13 + (n - 4) * 5;
    // else l = 13 + (n - 4) * 6;;

    // cout << l + c << endl;

    LL len = n - 4;
    LL last = 11 + 2 * (len - 1);
    LL sum = (11 + last) * len / 2;
    cout << 26 + sum << endl;
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