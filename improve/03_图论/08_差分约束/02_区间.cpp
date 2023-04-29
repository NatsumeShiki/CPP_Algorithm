// 给定 n
//  个区间 [ai,bi]
//  和 n
//  个整数 ci
// 。

// 你需要构造一个整数集合 Z
// ，使得 ∀i∈[1,n]
// ，Z
//  中满足 ai≤x≤bi
//  的整数 x
//  不少于 ci
//  个。

// 求这样的整数集合 Z
//  最少包含多少个数。

// 输入格式
// 第一行包含整数 n
// 。

// 接下来 n
//  行，每行包含三个整数 ai,bi,ci
// 。

// 输出格式
// 输出一个整数表示结果。

// 数据范围
// 1≤n≤50000
// ,
// 0≤ai,bi≤50000
// ,
// 0≤ci≤bi−ai+1
// 输入样例：
// 5
// 3 7 3
// 8 10 3
// 6 8 1
// 1 3 1
// 10 11 1
// 输出样例：
// 6

/*
本题目是一定有解的，最坏的情况是把0-50000所有数都选上
把原范围变成1-500001
s[i]表示从1-i中选择的数的个数，最终要求的是S50001的最小值，因此使用最长路径
对于每个s，要满足的条件有下面三个
1. s[i] >= s[i-1] 1 <= i <= 50001  [i-1]->[i] 0
2. s[i] - s[i - 1] <= 1 => s[i - 1] >= s[i] - 1   [i]->[i-1] -1
3. [a, b] 选择c个 s[b] - s[a - 1] >= c s[b] >= s[a - 1] + c  [a - 1]->[b] c
*/
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const int N = 50010, M = 2e5 + 10;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int n;

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(){
    memset(dist, -0x3f, sizeof dist);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    
    while(q.size()){
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
}

int main(){
    cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= 50001; i++) add(i - 1, i, 0), add(i, i - 1, -1);
    for(int i = 0; i < n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a++, b++;
        add(a - 1, b, c);
    }
    
    spfa();
    cout << dist[50001] << endl;
    
    return 0;
}