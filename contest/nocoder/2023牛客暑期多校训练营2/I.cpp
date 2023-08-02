#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
int n, t;
int a[N];
map<int, int> mp;
int get_num(int x){
    int cnt = 0;
    while(x){
        x /= 10;
        cnt ++;
    }
    return cnt;
}

void get(int k){
  int t = k * k;
  int cnt = 0;
  while(t){
    if(!mp[t]) mp[t] = k;
    t /= 10;
    if(cnt++ > 9) return;
  }
}
 
void init(){
  for(int i = 1; i <= 1e6; i++){
    get(i);
  }
}
 

bool check(int y){
    y = y * y;
    int cnt = get_num(y);
    int x = 1;
    while(cnt - t > 0){
        cnt --;
        x *= 10;
    }
    y /= x;
    if(y == n) return true;
    return false;
}
void solve(){
	// cin >> n;
  n = rand();
  cout << n << " ";
    t = get_num(n);
    for(int i = 0, x = 1; i <= 9; i ++ , x *= 10){
        int y = sqrt(n * x);
        if(check(y)){
            cout << y << endl;
            return ;
        }else if(check(y + 1)){
            cout << y + 1 << endl;
            return;
        }
    }
    cout << mp[n] << " ";
    cout << "-1" << endl;
}
signed main() {
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  init();
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}