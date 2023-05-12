// 煤矿工地可以看成是由隧道连接挖煤点组成的无向图。

// 为安全起见，希望在工地发生事故时所有挖煤点的工人都能有一条出路逃到救援出口处。

// 于是矿主决定在某些挖煤点设立救援出口，使得无论哪一个挖煤点坍塌之后，其他挖煤点的工人都有一条道路通向救援出口。

// 请写一个程序，用来计算至少需要设置几个救援出口，以及不同最少救援出口的设置方案总数。

// 输入格式
// 输入文件有若干组数据，每组数据的第一行是一个正整数 N
// ，表示工地的隧道数。

// 接下来的 N
//  行每行是用空格隔开的两个整数 S
//  和 T
// （S≠T
// ），表示挖煤点 S
//  与挖煤点 T
//  由隧道直接连接。

// 注意，每组数据的挖煤点的编号为 1∼Max
// ，其中 Max
//  表示由隧道连接的挖煤点中，编号最大的挖煤点的编号，可能存在没有被隧道连接的挖煤点。

// 输入数据以 0
//  结尾。

// 输出格式
// 每组数据输出结果占一行。

// 其中第 i
//  行以 Case i: 开始（注意大小写，Case 与 i 之间有空格，i 与 : 之间无空格，: 之后有空格）。

// 其后是用空格隔开的两个正整数，第一个正整数表示对于第 i
//  组输入数据至少需要设置几个救援出口，第二个正整数表示对于第 i
//  组输入数据不同最少救援出口的设置方案总数。

// 输入数据保证答案小于 264
// ，输出格式参照以下输入输出样例。

// 数据范围
// 1≤N≤500
// ，
// 1≤Max≤1000
// 输入样例：
// 9
// 1  3
// 4  1
// 3  5
// 1  2
// 2  6
// 1  5
// 6  3
// 1  6
// 3  2
// 6
// 1  2
// 1  3
// 2  4
// 2  5
// 3  6
// 3  7
// 0
// 输出样例：
// Case 1: 2 4
// Case 2: 4 1

/*
如果有0个割点，需要开两个出口，方案数是C(2, cnt)
如果有1个割点，开设1个出口，方案数乘以(cnt - 1)
如果割点数大于1，不用开设出口，方案数乘等1
*/
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

typedef unsigned long long ULL;
const int N = 1010, M = 1010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int dcc_cnt;
vector<int> dcc[N];
bool cut[N];
int root;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u){
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;
    
    if(u == root && h[u] == -1){
        dcc_cnt++;
        dcc[dcc_cnt].push_back(u);
        return;
    }
    
    int cnt = 0;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(!dfn[j]){
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if(dfn[u] <= low[j]){
                cnt++;
                if(u != root || cnt > 1) cut[u] = true;
                dcc_cnt++;
                int y;
                do{
                    y = stk[top--];
                    dcc[dcc_cnt].push_back(y);
                }while(y != j);
                dcc[dcc_cnt].push_back(u);
            }
        }else low[u] = min(low[u], dfn[j]);
    }
}

int main(){
    int T = 1;
    while(cin >> m, m){
        for(int i = 1; i <= dcc_cnt; i++) dcc[i].clear();
        idx = n = timestamp = top = dcc_cnt = 0;
        memset(h, -1, sizeof h);
        memset(dfn, 0, sizeof dfn);
        memset(cut, 0, sizeof cut);
        
        while(m--){
            int a ,b;
            cin >> a >> b;
            n = max(n, a), n = max(n, b);
            add(a, b), add(b, a);
        }
        
        for(root = 1; root <= n; root++)
            if(!dfn[root])
                tarjan(root);
                
        int res = 0;
        ULL num = 1;
        for(int i = 1; i <= dcc_cnt; i++){
            int cnt = 0;
            for(int j = 0; j < dcc[i].size(); j++)
                if(cut[dcc[i][j]])
                    cnt++;
                    
            if(cnt == 0) {
                if(dcc[i].size() > 1) res += 2, num *= dcc[i].size() * (dcc[i].size() - 1) / 2;
                else res++;
            }
            else if(cnt == 1) res ++, num *= dcc[i].size() - 1;
        }
        
        printf("Case %d: %d %llu\n", T++, res, num);
    }
    
    return 0;
}