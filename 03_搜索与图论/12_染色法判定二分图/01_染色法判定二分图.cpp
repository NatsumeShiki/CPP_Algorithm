// 给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环。

// 请你判断这个图是否是二分图。

// 输入格式
// 第一行包含两个整数 n 和 m。

// 接下来 m 行，每行包含两个整数 u 和 v，表示点 u 和点 v 之间存在一条边。

// 输出格式
// 如果给定图是二分图，则输出 Yes，否则输出 No。

// 数据范围
// 1≤n,m≤105
// 输入样例：
// 4 4
// 1 3
// 1 4
// 2 3
// 2 4
// 输出样例：
// Yes

#include<cstring>
#include<iostream>
using namespace std;
const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N]; // 记录每个点染色成哪个

void add(int a, int b){
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

bool dfs(int u, int c){
    color[u] = c; // 将t这个点染成c
    
    for(int i = h[u]; i != -1; i = ne[i]){ // 将这个点在邻接表中的子节点多染成3-c
        int j = e[i];
        if(!color[j]){ // 如果这个点还没被染色，就染成3-c
            if(!dfs(j, 3 - c)) return false;
        }else if(color[j] == c) return false; // 如果已经染色了，就判断和父节点是不是相同的，如果相同就出现了矛盾，返回false
    }
    return true; // 没有矛盾返回true
}

int main(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a); // 无向图，所以要两个都添加
    }
    
    bool flag = true; // 用来保存这个图是不是二分图，默认先设置为true，如果有矛盾，就设置为false，表示不是二分图
    for(int i = 1; i <= n; i++){
        if(!color[i]){  // 如果这个点还没有染色，就默认染成1
            if(!dfs(i, 1)){ // 如果递归过程中出现矛盾，返回false，表示不是二分图，跳出循环
                flag = false;
                break;
            }
        }
    }
    if(flag) cout << "Yes";
    else cout << "No";
    
    return 0;
}