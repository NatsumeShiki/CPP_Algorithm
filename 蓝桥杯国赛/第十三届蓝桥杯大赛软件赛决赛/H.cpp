//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<set>
//#include<vector> 
//using namespace std;
//
//typedef long long LL;
//const int N = 1e5 + 10, M = N * 2; 
//typedef pair<int, int> PII;
//int h[N], e[M], w[M], ne[M], idx;
//int dist[N], p[N], res[M], st[N];
//vector<PII> query[N];
//int n, m;
//int cnt[N];
//
//void add(int a, int b){
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
// 
//void dfs(int u, int fa){
////	dist[u] += cnt[u];
//	for(int i = h[u]; ~i; i = ne[i]){
//		int j = e[i];
//		if(j == fa) continue;
//		dist[j] = dist[u] + cnt[j];
////		cout << dist[j] << " " << j << endl;
//		dfs(j, u);
//	}
//}
//
//int find(int x){
//	if(x != p[x]) p[x] = find(p[x]);
//	return p[x];
//}
//
//void tarjan(int u){
//	st[u] = 1;
//	for(int i = h[u]; ~i; i = ne[i]){
//		int j = e[i];
//		if(!st[j]){
//			tarjan(j);
//			p[j] = u;
//		}
//	}
//	
////	for(PII item : query[u])
//	for(int i = 0; i < query[u].size(); i++){
//		PII item = query[u][i];
//		int y = item.first, id = item.second;
//		if(st[y] == 2){
//			int anc = find(y);
//			res[id] = dist[u] + dist[y] - dist[anc];
//		}
//	}
//	
//	st[u] = 2;
//}
// 
//void solve(){
//	scanf("%d%d", &n, &m);
//	memset(h, -1, sizeof h);
//	for(int i = 0; i < n - 1; i++){
//		int a, b;
//		scanf("%d%d", &a, &b);
//		add(a, b), add(b, a);
//		cnt[a]++, cnt[b]++;
//	}
//	
//	for(int i = 0; i < m; i++){
//		int a, b;
//		scanf("%d%d", &a, &b);
//		if(a != b) {
//			query[a].push_back({b, i});
//			query[b].push_back({a, i});
//		}
//	}
//	
//	for(int i = 1; i <= n; i++) p[i] = i;
//	dist[1] = cnt[1];
////	cout << dist[1] << endl; 
//	dfs(1, -1);
//	tarjan(1);
////	for(int i = 1; i <= n; i++) cout << dist[i] << " ";
////	cout << endl;
//
//	for(int i = 0; i < m; i++){
//		if(!res[i]) puts("1");
//		else printf("%d\n", res[i]);
//	}
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

//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<set>
//#include<queue>
//using namespace std;
//
//typedef long long LL;
//const int N = 1e5 + 10, M = N * 2;
//int h[N], e[M], ne[M], idx;
//int depth[N], dist[N], fa[N][20];
//int cnt[N];
//int n, m;
//
//void add(int a, int b){
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//
//void bfs(int root){
//	memset(depth, 0x3f, sizeof depth);
//	dist[1] = cnt[1];
//	depth[1] = 1;
//	depth[0] = 0;
//	queue<int> q;
//	q.push(root);
//	while(q.size()){
//		int t = q.front();
//		q.pop();
//		for(int i = h[t]; ~i; i = ne[i]){
//			int j = e[i];
//			if(depth[j] > depth[t] + 1){
//				depth[j] = depth[t] + 1;
//				dist[j] = dist[t] + cnt[j];
//				q.push(j);
//				fa[j][0] = t;
//				for(int k = 1; k <= 19; k++)
//					fa[j][k] = fa[fa[j][k - 1]][k - 1];
//			}
//		}
//	}
//}
//
//
//int lca(int a, int b){
//	if(depth[a] < depth[b]) swap(a, b);
//	for(int k = 19; k >= 0; k--)
//		if(depth[fa[a][k]] >= depth[b])
//			a = fa[a][k];
//	if(a == b) return a;
//	for(int k = 19; k >= 0; k--)
//		if(fa[a][k] != fa[b][k]){
//			a = fa[a][k];
//			b = fa[b][k];
//		}
//	return fa[a][0];
//}
// 
//
//void solve(){
//	scanf("%d%d", &n, &m);
//	int root = 1;
//	memset(h, -1, sizeof h);
//	
//	for(int i = 0; i < n - 1; i++){
//		int a, b;
//		scanf("%d%d", &a, &b);
//		cnt[a]++, cnt[b]++;
//		add(a, b), add(b, a);
//	} 
//	
//	bfs(root);
////	for(int i = 1; i <= n; i++) cout << dist[i] << " ";
////	cout << endl; 
//	
//	while(m--){
//		int a, b;
//		scanf("%d%d", &a, &b);
//		if(a == b) puts("1");
//		else{
//			int p = lca(a, b);
////			cout << "p = " << p << endl;
//			int res;
//			if(p == a) res = dist[b] - dist[a] + cnt[a];
//			else if(p == b) res = dist[a] - dist[b] + cnt[b];
//			else res = dist[a] + dist[b] - dist[p];
//			cout << res << endl;
//		} 
//	}
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
