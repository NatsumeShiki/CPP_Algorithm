// 有个人的家族很大，辈分关系很混乱，请你帮整理一下这种关系。

// 给出每个人的孩子的信息。

// 输出一个序列，使得每个人的孩子都比那个人后列出。

// 输入格式
// 第 1
//  行一个整数 n
// ，表示家族的人数；

// 接下来 n
//  行，第 i
//  行描述第 i
//  个人的孩子；

// 每行最后是 0
//  表示描述完毕。

// 每个人的编号从 1
//  到 n
// 。

// 输出格式
// 输出一个序列，使得每个人的孩子都比那个人后列出；

// 数据保证一定有解，如果有多解输出任意一解。

// 数据范围
// 1≤n≤100
// 输入样例：
// 5
// 0
// 4 5 1 0
// 1 0
// 5 3 0
// 3 0
// 输出样例：
// 2 4 5 3 1

#include<iostream>
#include<cstring>
using namespace std;

const int N = 110, M = N * N;
int h[N], e[M], ne[M], idx;
int d[N], q[N];
int n;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    int hh = 0, tt = -1;
    for(int i = 1; i <= n; i++)
        if(!d[i])
            q[++tt] = i;
            
    while(hh <= tt){
        int t = q[hh++];
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(--d[j] == 0)
                q[++tt] = j;
        }
    }
}

int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++){
        int x;
        while(cin >> x, x)
            add(i, x), d[x]++;
    }
    
    topsort();
    for(int i = 0; i < n; i++) printf("%d ", q[i]);
    
    return 0;
}