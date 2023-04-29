// 幼儿园里有 N
//  个小朋友，老师现在想要给这些小朋友们分配糖果，要求每个小朋友都要分到糖果。

// 但是小朋友们也有嫉妒心，总是会提出一些要求，比如小明不希望小红分到的糖果比他的多，于是在分配糖果的时候， 老师需要满足小朋友们的 K
//  个要求。

// 幼儿园的糖果总是有限的，老师想知道他至少需要准备多少个糖果，才能使得每个小朋友都能够分到糖果，并且满足小朋友们所有的要求。

// 输入格式
// 输入的第一行是两个整数 N,K
// 。

// 接下来 K
//  行，表示分配糖果时需要满足的关系，每行 3
//  个数字 X,A,B
// 。

// 如果 X=1
// ．表示第 A
//  个小朋友分到的糖果必须和第 B
//  个小朋友分到的糖果一样多。
// 如果 X=2
// ，表示第 A
//  个小朋友分到的糖果必须少于第 B
//  个小朋友分到的糖果。
// 如果 X=3
// ，表示第 A
//  个小朋友分到的糖果必须不少于第 B
//  个小朋友分到的糖果。
// 如果 X=4
// ，表示第 A
//  个小朋友分到的糖果必须多于第 B
//  个小朋友分到的糖果。
// 如果 X=5
// ，表示第 A
//  个小朋友分到的糖果必须不多于第 B
//  个小朋友分到的糖果。
// 小朋友编号从 1
//  到 N
// 。

// 输出格式
// 输出一行，表示老师至少需要准备的糖果数，如果不能满足小朋友们的所有要求，就输出 −1
// 。

// 数据范围
// 1≤N≤105
// ,
// 1≤K≤105
// ,
// 1≤X≤5
// ,
// 1≤A,B≤N
// ,
// 输入数据完全随机。

// 输入样例：
// 5 7
// 1 1 2
// 2 3 2
// 4 4 1
// 3 4 5
// 5 4 5
// 2 3 5
// 4 5 1
// 输出样例：
// 11

/*
1 A = B    A >= B, B <= A
2 A < B    B >= A + 1
3 A >= B   A >= B
4 A > B    A >= B + 1
5 A <= B   B >= A
每个点 x >= 1，可以看成是 xi >= x0 + 1，连一条从0到i的边，长度为1
求的是最小值，求最长路
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10, M = 3e5 + 10; // 最坏的情况所有都是第一种情况，所以边数一共为 2m + n
int h[N], e[M], w[M], ne[M], idx;
LL dist[N];
bool st[N];
int n, m;
int cnt[N]; // 判断是否存在环

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(){
    memset(dist, -0x3f, sizeof dist); // 因为求的是最小值，所以设置成无穷小
    dist[0] = 0;
    st[0] = true;
    // queue<int> q;
    // q.push(0);
    stack<int> s; // 使用队列会TLE，可以换成栈试一试
    s.push(0);
    
    while(s.size()){
        // int t = q.front();
        // q.pop();
        int t = s.top();
        s.pop();
        
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + w[i]){ // 从t到j的边的意思是 dist[j] >= dist[t] + w[i]，所以当dist[j] < dist[t]时需要更新，求的是最小值
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n + 1) return true;
                if(!st[j]){
                    st[j] = true;
                    // q.push(j);
                    s.push(j);
                }
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    while(m--){
        int a, b, c;
        scanf("%d%d%d", &c, &a, &b);
        if(c == 1) add(b, a, 0), add(a, b, 0);
        else if(c == 2) add(a, b, 1);
        else if(c == 3) add(b, a, 0);
        else if(c == 4) add(b, a, 1);
        else if(c == 5) add(a, b, 0);
    }
    for(int i = 1; i <= n; i++) add(0, i, 1); // 添加从0到i的长度为1的边
    
    if(spfa()) puts("-1"); // 如果存在环，无解
    else{
        LL res = 0;
        for(int i = 1; i <= n; i++) res += dist[i]; // 累计所有糖过数量
        printf("%lld\n", res);
    }
    
    
    return 0;
}