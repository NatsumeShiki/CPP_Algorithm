// 农夫约翰上周刚刚建好了新的牛棚，并引进了最新的挤奶技术。

// 不幸的是，由于工程问题，牛棚中的每个单间都不太一样。

// 第一周，约翰将奶牛们随机分配在了各个单间中。

// 但是很快他就发现，每头奶牛都只愿意在一部分自己喜欢的单间中产奶。

// 在过去的一周中，农夫约翰一直在收集有关哪些奶牛愿意在哪些单间产奶的数据。

// 一个单间只能分配给一头奶牛，当然，一头奶牛也可能只愿意在一个单间中产奶。

// 给定奶牛的住宿喜好，请你计算，通过合理分配奶牛的住所，最多能够让多少奶牛可以住在自己愿意产奶的单间中。

// 输入格式
// 第一行包含两个整数 N
//  和 M
// ，分别表示奶牛的数量以及单间的数量。

// 接下来 N
//  行，每行记录一个奶牛愿意产奶的单间信息。首先包含一个整数 Si
// ，表示这头奶牛愿意在 Si
//  个单间中产奶。接下来包含 Si
//  个不同的整数，表示这些单间的编号。

// 所有单间的编号为 1∼M
// 。

// 输出格式
// 输出一个整数，表示可以被分配在自己愿意产奶的单间中的奶牛的最大数量。

// 数据范围
// 0≤N,M≤200

// 0≤Si≤M
// 输入样例：
// 5 5
// 2 2 5
// 3 2 3 4
// 2 1 5
// 3 1 2 5
// 1 2
// 输出样例：
// 4

// 邻接矩阵
#include<iostream>
#include<cstring>
using namespace std;

const int N = 210, M = 40010;
int match[N];
bool st[N], g[N][N];
int n, m;

int find(int x){
    for(int i = 1; i <= m; i++){
        if(!st[i] && g[x][i]){
            st[i] = true;
            if(!match[i] || find(match[i])) {
                match[i] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        int cnt;
        scanf("%d", &cnt);
        while(cnt--){
            int x;
            scanf("%d", &x);
            g[i][x] = true;
        }
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++){
        memset(st, false, sizeof st);
        if(find(i)) res++;
    }
    printf("%d\n", res);
    
    return 0;
}

// 邻接表
#include<iostream>
#include<cstring>
using namespace std;

const int N = 210, M = 40010;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];
int n, m;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x){
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(!st[j]){
            st[j] = true;
            if(match[j] == 0 || find(match[j])){
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i++){
        int cnt;
        scanf("%d", &cnt);
        while(cnt--){
            int x;
            scanf("%d", &x);
            add(i, x);
        }
    }
    
    int res = 0;
    for(int i = 1; i <= n; i++){
        memset(st, false, sizeof st);
        if(find(i)) res++;
    }
    printf("%d\n", res);
    
    return 0;
}