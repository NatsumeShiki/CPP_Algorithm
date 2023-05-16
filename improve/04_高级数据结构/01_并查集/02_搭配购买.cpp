// Joe觉得云朵很美，决定去山上的商店买一些云朵。

// 商店里有 n
//  朵云，云朵被编号为 1,2,…,n
// ，并且每朵云都有一个价值。

// 但是商店老板跟他说，一些云朵要搭配来买才好，所以买一朵云则与这朵云有搭配的云都要买。

// 但是Joe的钱有限，所以他希望买的价值越多越好。

// 输入格式
// 第 1
//  行包含三个整数 n，m，w
// ，表示有 n
//  朵云，m
//  个搭配，Joe有 w
//  的钱。

// 第 2?n+1
// 行，每行两个整数 ci，di
//  表示 i
//  朵云的价钱和价值。

// 第 n+2?n+1+m
//  行，每行两个整数 ui，vi
// ，表示买 ui
//  就必须买 vi
// ，同理，如果买 vi
//  就必须买 ui
// 。

// 输出格式
// 一行，表示可以获得的最大价值。

// 数据范围
// 1≤n≤10000
// ,
// 0≤m≤5000
// ,
// 1≤w≤10000
// ,
// 1≤ci≤5000
// ,
// 1≤di≤100
// ,
// 1≤ui,vi≤n
// 输入样例：
// 5 3 10
// 3 10
// 3 10
// 3 10
// 5 100
// 10 1
// 1 3
// 3 2
// 4 2
// 输出样例：
// 1

// 将一个连通块中的所有物品当成一个物品，然后做一遍01背包问题
#include<iostream>
#include<cstring>
using namespace std;

const int N = 10010;
int p[N], v[N], w[N];
int n, m, W;
int f[N];

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int main(){
    scanf("%d%d%d", &n, &m, &W);
    for(int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);
    for(int i = 1; i <= n; i++) p[i] = i;
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        a = find(a), b = find(b);
        if(a == b) continue;
        v[b] += v[a];
        w[b] += w[a];
        p[a] = b;
    }
    
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int pi = find(i);
        if(i == p[i]){
            v[cnt] = v[pi];
            w[cnt] = w[pi];
            cnt++;
        }
    }

    for(int i = 0; i < cnt; i++)
        for(int j = W; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[W] << endl;
    
    return 0;
}


#include<iostream>
#include<cstring>
using namespace std;

const int N = 10010;
int v[N], w[N], p[N];
int f[N];
int n, m, vol;

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m >> vol;
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    
    while(m--){
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if(pa != pb){
            v[pb] += v[pa];
            w[pb] += w[pa];
            p[pa] = pb;
        }
    }
    
    for(int i = 1; i <= n; i++)
        if(p[i] == i)
            for(int j = vol; j >= v[i]; j--)
                f[j] = max(f[j], f[j - v[i]] + w[i]);
                
                
    cout << f[vol] << endl;
    
    
    return 0;
}