#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long LL;
const  int  N = 1010;
int g[N][N], dist[N];
bool st[N]; 
int cnt[N];
int n, m;

void dijkstra(){
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for(int i = 0;  i < n; i++){
		int t = -1;
		for(int j = 1; j <= n; j++){
			if(!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		}
		
		st[t] = true;
		for(int j = 1; j <= n; j++)
			if(!st[j])
				dist[j] = min(dist[j], dist[t] + g[t][j] + cnt[j]);
	}
}
 
void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> cnt[i];
	memset(g, 0x3f, sizeof g);
	while(m--){
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	
	dijkstra();
	
	cout << dist[n] - cnt[n] << endl;
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
