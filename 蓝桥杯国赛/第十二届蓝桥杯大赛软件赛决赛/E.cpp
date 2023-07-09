#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
 
void solve(){
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		char c = s[i];
		if(c > 95) c -= 32;
		cout << c;
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
