// 给定一张图，请你找出欧拉回路，即在图中找一个环使得每条边都在环上出现恰好一次。

// 输入格式
// 第一行包含一个整数 t
// ，t∈{1,2}
// ，如果 t=1
// ，表示所给图为无向图，如果 t=2
// ，表示所给图为有向图。

// 第二行包含两个整数 n,m
// ，表示图的结点数和边数。

// 接下来 m
//  行中，第 i
//  行两个整数 vi,ui
// ，表示第 i
//  条边（从 1
//  开始编号）。

// 如果 t=1
//  则表示 vi
//  到 ui
//  有一条无向边。
// 如果 t=2
//  则表示 vi
//  到 ui
//  有一条有向边。
// 图中可能有重边也可能有自环。

// 点的编号从 1
//  到 n
// 。

// 输出格式
// 如果无法一笔画出欧拉回路，则输出一行：NO。

// 否则，输出一行：YES，接下来一行输出 任意一组 合法方案即可。

// 如果 t=1
// ，输出 m
//  个整数 p1,p2,…,pm
// 。令 e=|pi|
// ，那么 e
//  表示经过的第 i
//  条边的编号。如果 pi
//  为正数表示从 ve
//  走到 ue
// ，否则表示从 ue
//  走到 ve
// 。
// 如果 t=2
// ，输出 m
//  个整数 p1,p2,…,pm
// 。其中 pi
//  表示经过的第 i
//  条边的编号。
// 数据范围
// 1≤n≤105
// ,
// 0≤m≤2×105
// 输入样例1：
// 1
// 3 3
// 1 2
// 2 3
// 1 3
// 输出样例1：
// YES
// 1 2 -3
// 输入样例2：
// 2
// 5 6
// 2 3
// 2 5
// 3 4
// 1 2
// 4 2
// 5 1
// 输出样例2：
// YES
// 4 1 3 5 2 6

#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10, M = 4e5 + 10;
int type;
int n, m;
int h[N], e[M], ne[M], idx;
bool used[M]; // 标记边是否已经遍历过了
int ans[M], cnt; // 保存结果遍历边的顺序
int din[N], dout[N]; // 保存每个点的入度和出度

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u){
    for(int &i = h[u]; ~i; ){ // 使用引用，i = ne[i]的时候相当于删除了这条边
        if(used[i]){ // 如果这条边被使用过了，删除这条边
            i = ne[i];
            continue;
        }
        
        used[i] = true; // 将这条边标记为已经使用了
        if(type == 1) used[i ^ 1] = true; // 如果是无向图，把它的反向边也设置为使用过了
        
        int t; // 用来保存这是第几条边
        if(type == 1){ // 如果是无向图
            t = i / 2 + 1; // (0,1)(2,3)(4,5)，计算是第几条边
            if(i & 1) t = -t; // 如果i & 1等于1，说明使用的是反向边
        }else t = i + 1; // 有向图的话，边的下标从0开始，所以编号就是下标加1
        
        int j = e[i]; // 获得边的终点
        i = ne[i]; // 边使用过了直接删除
        dfs(j); // 继续从j开始搜索
        
        ans[++cnt] = t; // 从下往上保存结果，因为从上往下过程中，可能存在环美哦与遍历到
    }
}

int main(){
    scanf("%d", &type);
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        if(type == 1) add(b, a); // 无向边
        din[b]++, dout[a]++;
    }
    
    if(type == 1){
        for(int i = 1; i <= n; i++)
            if(din[i] + dout[i] & 1){ // 无向图存在欧拉回路的充要条件是度数为奇数的点的个数为0
                puts("NO");
                return 0;
            }
    }else{
        for(int i = 1; i <= n; i++)
            if(din[i] != dout[i]){ // 有向图存在欧拉回路的充要条件是所有点的入度等于出度
                puts("NO");
                return 0;
            }
    }
    
    for(int i = 1; i <= n; i++) // 找到第一个存在路径的点
        if(h[i] != -1){
            dfs(i);
            break;
        }
        
    if(cnt < m){ // 如果cnt小于m，说明有点被隔离的，无欧拉回路
        puts("NO");
        return 0;
    }
    
    puts("YES"); // 从后往前输出结果
    for(int i = cnt; i; i--) printf("%d ", ans[i]);
    puts("");
    
    return 0;
} 