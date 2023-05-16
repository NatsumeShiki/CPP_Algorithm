// 在实现程序自动分析的过程中，常常需要判定一些约束条件是否能被同时满足。

// 考虑一个约束满足问题的简化版本：假设 x1,x2,x3,…
//  代表程序中出现的变量，给定 n
//  个形如 xi=xj
//  或 xi≠xj
//  的变量相等/不等的约束条件，请判定是否可以分别为每一个变量赋予恰当的值，使得上述所有约束条件同时被满足。

// 例如，一个问题中的约束条件为：x1=x2，x2=x3，x3=x4，x1≠x4
// ，这些约束条件显然是不可能同时被满足的，因此这个问题应判定为不可被满足。

// 现在给出一些约束满足问题，请分别对它们进行判定。

// 输入格式
// 输入文件的第 1
//  行包含 1
//  个正整数 t
// ，表示需要判定的问题个数，注意这些问题之间是相互独立的。

// 对于每个问题，包含若干行：

// 第 1
//  行包含 1
//  个正整数 n
// ，表示该问题中需要被满足的约束条件个数。

// 接下来 n
//  行，每行包括 3
//  个整数 i,j,e
// ，描述 1
//  个相等/不等的约束条件，相邻整数之间用单个空格隔开。若 e=1
// ，则该约束条件为 xi=xj
// ；若 e=0
// ，则该约束条件为 xi≠xj
// 。

// 输出格式
// 输出文件包括 t
//  行。

// 输出文件的第 k
//  行输出一个字符串 YES 或者 NO，YES 表示输入中的第 k
//  个问题判定为可以被满足，NO 表示不可被满足。

// 数据范围
// 1≤n≤105

// 1≤i,j≤109
// 输入样例：
// 2
// 2
// 1 2 1
// 1 2 0
// 2
// 1 2 1
// 2 1 1
// 输出样例：
// NO
// YES

// 题目给出两个点的值在1-1e9，所以先做离散化，将所有查询先保存起来，将相等的先合并到一个连通块，最后查询那些不相等的，看看是否有冲突
#include<iostream>
#include<cstring>
#include<unordered_map>
using namespace std;

const int N = 2e5 + 10;
int n, m;
int p[N]; // 保存祖宗节点
unordered_map<int, int> S; // 用于离散化，因为不需要排序，直接映射就可以

struct Query{ // 保存查询
    int x, y, e;
}query[N];

int get(int x){ // 离散化，如果当前还没有保存x，则将它存进S中，映射为++n
    if(S.count(x) == 0) S[x] = ++n;
    return S[x];
}

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        n = 0;
        S.clear();
        scanf("%d", &m);
        for(int i = 0; i < m; i++){ // 将查询先保存起来
            int x, y, e;
            scanf("%d%d%d", &x, &y, &e);
            query[i] = {get(x), get(y), e};
        }
        
        for(int i = 1; i <= n; i++) p[i] = i; // 设置祖宗节点是他自己
        
        for(int i = 0; i < m; i++)
            if(query[i].e == 1){ // 将所有相等的先合并到一个连通块中
                int pa = find(query[i].x), pb = find(query[i].y);
                p[pa] = pb;
            }
            
        bool has_conflict = false; // 是否有冲突的bool
        for(int i = 0; i < m; i++)
            if(query[i].e == 0){ // 查询所有不相等的项
                int pa = find(query[i].x), pb = find(query[i].y);
                if(pa == pb){ // 如果他们在一个连通块中，说明有冲突
                    has_conflict = true;
                    break;
                }
            }
        
        if(has_conflict) puts("NO");
        else puts("YES");
    }
    
    return 0;
}