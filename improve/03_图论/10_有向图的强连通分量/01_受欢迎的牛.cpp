// 每一头牛的愿望就是变成一头最受欢迎的牛。

// 现在有 N
//  头牛，编号从 1
//  到 N
// ，给你 M
//  对整数 (A,B)
// ，表示牛 A
//  认为牛 B
//  受欢迎。

// 这种关系是具有传递性的，如果 A
//  认为 B
//  受欢迎，B
//  认为 C
//  受欢迎，那么牛 A
//  也认为牛 C
//  受欢迎。

// 你的任务是求出有多少头牛被除自己之外的所有牛认为是受欢迎的。

// 输入格式
// 第一行两个数 N,M
// ；

// 接下来 M
//  行，每行两个数 A,B
// ，意思是 A
//  认为 B
//  是受欢迎的（给出的信息有可能重复，即有可能出现多个 A,B
// ）。

// 输出格式
// 输出被除自己之外的所有牛认为是受欢迎的牛的数量。

// 数据范围
// 1≤N≤104
// ,
// 1≤M≤5×104
// 输入样例：
// 3 3
// 1 2
// 2 1
// 2 3
// 输出样例：
// 1
// 样例解释
// 只有第三头牛被除自己之外的所有牛认为是受欢迎的。

#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

const int N = 10010, M = 50010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
bool in_stk[N]; // 保存i号点是否在栈中
int id[N], scc_cnt, sz[N]; // id保存i号点是哪个连通块，scc_cnt是连通块的数量，sz保存连通块中点的数量
int dout[N]; // 保存连通块的出度为多少
int stk[N], top; // 模拟栈

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u){
    dfn[u] = low[u] = ++timestamp; // 先将u点的两个时间戳都定义成一样的
    stk[++top] = u, in_stk[u] = true; // 将u存入栈中，设置u在栈中
    for(int i = h[u]; ~i; i = ne[i]){ // 遍历u的所有邻点
        int j = e[i];
        if(!dfn[j]){ // 如果j还没有设置时间戳
            tarjan(j); // 则对j做tarjan算法
            low[u] = min(low[u], low[j]); // 在low[u]和low[j]中取最小值赋值给low[u]，表示u所能到的最小时间戳
        }else if(in_stk[j]) low[u] = min(low[u], dfn[j]); // 如果j已经有时间戳了，并且j此时在栈中，说明这是一条横叉边，则在low[u]和dfn[j]中取最小值赋值给low[u]，表示u所能到的最小时间戳
    }
    
    if(dfn[u] == low[u]){ // 如果u的时间戳和u所能到的最小时间戳相同，说明u是这个连通分量的最高点
        ++scc_cnt;
        int y; // 连通分量数量增加
        do{
            y = stk[top--]; // 获取栈顶元素
            in_stk[y] = false;  // 设置它不在栈中
            id[y] = scc_cnt; // 将这个点的id设置为它是第几个连通分量
            sz[scc_cnt]++; // 连通块中点的数量增加
        }while(y != u);  // 直到栈顶元素为u
    }
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    
    for(int i = 1; i <= n; i++) // 对每个点做tarjan算法，获取它是在哪个连通块中
        if(!dfn[i])
            tarjan(i);
    
    for(int i = 1; i <= n; i++) // 缩点操作，枚举每个点
        for(int j = h[i]; ~j; j = ne[j]){ // 枚举它的邻边
            int k = e[j];
            int a = id[i], b = id[k]; // 获取这两个点所在的连通块编号
            if(a != b) dout[a]++; // 如果这两个点所在的连通块编号不同，那么存在一条a到b的边，将a的出度加1，不需要真的建立这条边
        }

    // 统计每个点的出度是否为0，如果出度为0的连通块大于1，说明不存在受欢迎的牛，如果 出度为0的连通块数量等于1，则结果就是这个连通块中点的数量

        
    printf("%d\n", sum);
    
    return 0;
}    int zeros = 0, sum = 0; // zeros统计出度为0的连通块数量，sum保存受欢迎的牛的数量
    for(int i = 1; i <= scc_cnt; i++) 
        if(!dout[i]){ // 如果编号为i的连通块的出度为0
            zeros++; // 出度为0数量增加
            sum += sz[i]; // 受欢迎的牛的数量增加i号连通块中点的数量
            if(zeros > 1){ // 如果出度为0的连通块数量大于1
                sum = 0; // 不存在受欢迎的牛
                break;
            }
        }