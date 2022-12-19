// “饱了么”外卖系统中维护着 N 家外卖店，编号 1∼N。

// 每家外卖店都有一个优先级，初始时 (0 时刻) 优先级都为 0。

// 每经过 1 个时间单位，如果外卖店没有订单，则优先级会减少 1，最低减到 0；而如果外卖店有订单，则优先级不减反加，每有一单优先级加 2。

// 如果某家外卖店某时刻优先级大于 5，则会被系统加入优先缓存中；如果优先级小于等于 3，则会被清除出优先缓存。

// 给定 T 时刻以内的 M 条订单信息，请你计算 T 时刻时有多少外卖店在优先缓存中。

// 输入格式
// 第一行包含 3 个整数 N,M,T。

// 以下 M 行每行包含两个整数 ts 和 id，表示 ts 时刻编号 id 的外卖店收到一个订单。

// 输出格式
// 输出一个整数代表答案。

// 数据范围
// 1≤N,M,T≤105,
// 1≤ts≤T,
// 1≤id≤N
// 输入样例：
// 2 6 6
// 1 1
// 5 2
// 3 1
// 6 2
// 2 1
// 6 2
// 输出样例：
// 1
// 样例解释
// 6 时刻时，1 号店优先级降到 3，被移除出优先缓存；2 号店优先级升到 6，加入优先缓存。

// 所以是有 1 家店 (2 号) 在优先缓存中。

#include<iostream>
#include<algorithm>
using namespace std;

#define x first
#define y second

typedef pair<int, int> PII;
const int N = 1e5 + 10;
int n, m, T;
int score[N], last[N]; // score数组记录id店铺的score，last数组记录id店铺上一次出现订单的时刻
bool st[N]; // st数据记录id店铺是否在队列中
PII order[N]; // order数组保存订单

int main(){
    scanf("%d%d%d", &n, &m, &T);
    for(int i = 0; i < m; i++) scanf("%d%d", &order[i].x, &order[i].y);
    sort(order, order + m); // 将订单排序
    
    for(int i = 0; i < m;){
        int j = i;
        while(j < m && order[j] == order[i]) j++; // 查看有多少个订单是相同的
        int t = order[i].x, id = order[i].y, cnt = j - i; // t记录这一批相同订单的时刻，cnt记录订单的数量
        i = j; 
        
        score[id] -= t - last[id] - 1; // 让id店铺减去相应的score
        if(score[id] < 0) score[id] = 0; // 如果score变成负数了，就把他重置为0
        if(score[id] <= 3) st[id] = false; // 如果score小等于3了，就移除队列
        
        score[id] += cnt * 2; // 将订单的score加上去
        if(score[id] > 5) st[id] = true; // 如果score大于5，就进队列
        
        last[id] = t; // 保存id店铺上一次订单的时刻
    }
    
    for(int i = 1; i <= n; i++) // 一个循环是把最后没有订单的店铺减去相应的score，相应的移出队列
        if(last[i] < T){
            score[i] -= T - last[i];
            if(score[i] <= 3) st[i] = false;
        }
        
    int res = 0;
    for(int i = 1; i <= n; i++) res += st[i]; // 记录那些店铺的st为true，如果为ture就表示在最后时刻它还是在队列中
    
    cout << res << endl;
    
    return 0;
}