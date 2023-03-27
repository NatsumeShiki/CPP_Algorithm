// 农夫知道一头牛的位置，想要抓住它。

// 农夫和牛都位于数轴上，农夫起始位于点 N
// ，牛位于点 K
// 。

// 农夫有两种移动方式：

// 从 X
//  移动到 X−1
//  或 X+1
// ，每次移动花费一分钟
// 从 X
//  移动到 2∗X
// ，每次移动花费一分钟
// 假设牛没有意识到农夫的行动，站在原地不动。

// 农夫最少要花多少时间才能抓住牛？

// 输入格式
// 共一行，包含两个整数N和K。

// 输出格式
// 输出一个整数，表示抓到牛所花费的最少时间。

// 数据范围
// 0≤N,K≤105
// 输入样例：
// 5 17
// 输出样例：
// 4

#include<iostream>
#include<queue>
using namespace std;

const int N = 2e5 + 10;
int start, fin;
int step ;
bool st[N];

int bfs(){
    queue<int> q;
    q.push(start);
    while(q.size()){
        step++;
        int cnt = q.size();
        while(cnt--){
            int t = q.front();
            q.pop();
            if(t + 1 <= 2e5 && !st[t + 1]){
                st[t + 1] = true;
                q.push({t + 1});
                if(t + 1 == fin) return step;
            }
            if(t - 1 >= 0 && !st[t - 1]){
                st[t - 1] = true;
                q.push({t - 1});
                if(t - 1 == fin) return step;
            }
            if(t * 2 <= 2e5 && !st[t * 2]){
                st[t * 2] = true;
                q.push({t * 2});
                if(t * 2 == fin) return step;
            }
        }
    }
    return -1;
}

int main(){
    cin >> start >> fin;
    
    if(start == fin) puts("0");
    else cout << bfs() << endl;
    
    return 0;
}

// 大佬的代码
#include<iostream>
#include<cstring>
using namespace std;

const int N = 2e5 + 10;
int n, k;
int dist[N];
int q[N];

int bfs(){
    memset(dist, -1, sizeof dist);
    dist[n] = 0;
    int hh = 0, tt = 0;
    q[0] = n;
    while(hh <= tt){
        int t = q[hh++];
        if(t == k) return dist[k];
        if(t + 1 <= k && dist[t + 1] == -1){
            dist[t + 1] = dist[t] + 1;
            q[++tt] = t + 1;
        }
        if(t - 1 >= 0 && dist[t - 1] == -1){
            dist[t - 1] = dist[t] + 1;
            q[++tt] = t - 1;
        }
        if(t * 2 < N && dist[t * 2] == -1){
            dist[t * 2] = dist[t] + 1;
            q[++tt] = t * 2;
        }
    }
    return -1;
}

int main(){
    cin >> n >> k;
    
    cout << bfs() << endl;
    
    return 0;
}