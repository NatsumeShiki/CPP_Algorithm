#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;
typedef long long LL;
const int N = 1010, M = 5010;
int month[N], day[N], v[N];
int n, m, k;
int s[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int f[N][M];
int last[N];
PII tickets[N];  

//bool find(int a, int b){
//	int x = s[month[a] - 1] + day[a];
//	int y = s[month[b] - 1] + day[b];
//	if(abs(x - y) >= k) return true;
//	return false; 
//}

void solve(){
	cin >> n >> m >> k;
	
	for(int i = 1; i <= 12; i++) s[i] = s[i - 1] + s[i];
	for(int i = 1; i <= n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tickets[i] = {s[a - 1] + b, c};
	}
	sort(tickets + 1, tickets + n + 1);
	
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++){
			if(tickets[i].x - tickets[j].x >= k) 
				last[i] = j;
		}

	int res = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++){
			f[i][j] = f[i - 1][j];
			PII t = tickets[i];
			if(j >= t.y) 
				f[i][j] = max(f[i][j], f[last[i]][j - t.y] + t.y);
				
			res = max(res, f[i][j]);	
		}			
	
	cout << res << endl;

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
