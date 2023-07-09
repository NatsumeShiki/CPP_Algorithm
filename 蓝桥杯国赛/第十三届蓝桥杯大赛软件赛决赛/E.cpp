//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//
//typedef long long LL;
//const  int  N = 1010;
//int g[N][N], dist[N];
//bool st[N]; 
//int cnt[N];
//int n, m;
//
//void dijkstra(){
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	for(int i = 0;  i < n; i++){
//		int t = -1;
//		for(int j = 1; j <= n; j++){
//			if(!st[j] && (t == -1 || dist[j] < dist[t]))
//				t = j;
//		}
//		
//		st[t] = true;
//		for(int j = 1; j <= n; j++)
//			if(!st[j])
//				dist[j] = min(dist[j], dist[t] + g[t][j] + cnt[j]);
//	}
//}
// 
//void solve(){
//	cin >> n >> m;
//	for(int i = 1; i <= n; i++) cin >> cnt[i];
//	memset(g, 0x3f, sizeof g);
//	while(m--){
//		int a, b, c;
//		cin >> a >> b >> c;
//		g[a][b] = g[b][a] = min(g[a][b], c);
//	}
//	
//	dijkstra();
//	
//	cout << dist[n] - cnt[n] << endl;
//}
//
//int main(){
//  #ifndef ONLINE_JUDGE
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
//  // ios::sync_with_stdio(false);
//  // cin.tie(0);
//  #endif
//
//  solve();
//
//  return 0;
//}

#include<iostream>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
const int N = 10010, M = N * 2;
int h[N], e[M], w[M], ne[M], idx;
int n, m;
int cnt[N];
int dist[N];
bool st[N];

void add(int a, int b, int c){
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
} 
 
void dijkstra(){
	priority_queue< PII, vector<PII>, greater<PII> > heap;
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	heap.push({dist[1], 1});
	while(heap.size()){
		PII t = heap.top();
		heap.pop();
		
		int ver = t.second, dis = t.first;
		if(st[ver]) continue;
		st[ver] = true;
		
		for(int i = h[ver]; ~i; i = ne[i]){
			int j = e[i];
			if(dist[j] > dis + w[i] + cnt[j]){
				dist[j] = dis + w[i] + cnt[j];
				heap.push({dist[j], j});
			}
		} 
	}
}
 
void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &cnt[i]);
	memset(h, -1, sizeof h);
	while(m--){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c), add(b, a, c);
	}
	
	dijkstra();
	printf("%d\n", dist[n] - cnt[n]);
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
