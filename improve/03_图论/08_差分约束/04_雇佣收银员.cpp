// 一家超市要每天 24
//  小时营业，为了满足营业需求，需要雇佣一大批收银员。

// 已知不同时间段需要的收银员数量不同，为了能够雇佣尽可能少的人员，从而减少成本，这家超市的经理请你来帮忙出谋划策。

// 经理为你提供了一个各个时间段收银员最小需求数量的清单 R(0),R(1),R(2),…,R(23)
// 。

// R(0)
//  表示午夜 00:00
//  到凌晨 01:00
//  的最小需求数量，R(1)
//  表示凌晨 01:00
//  到凌晨 02:00
//  的最小需求数量，以此类推。

// 一共有 N
//  个合格的申请人申请岗位，第 i
//  个申请人可以从 ti
//  时刻开始连续工作 8
//  小时。

// 收银员之间不存在替换，一定会完整地工作 8
//  小时，收银台的数量一定足够。

// 现在给定你收银员的需求清单，请你计算最少需要雇佣多少名收银员。

// 输入格式
// 第一行包含一个不超过 20
//  的整数，表示测试数据的组数。

// 对于每组测试数据，第一行包含 24
//  个整数，分别表示 R(0),R(1),R(2),…,R(23)
// 。

// 第二行包含整数 N
// 。

// 接下来 N
//  行，每行包含一个整数 ti
// 。

// 输出格式
// 每组数据输出一个结果，每个结果占一行。

// 如果没有满足需求的安排，输出 No Solution。

// 数据范围
// 0≤R(0)≤1000
// ,
// 0≤N≤1000
// ,
// 0≤ti≤23
// 输入样例：
// 1
// 1 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
// 5
// 0
// 23
// 22
// 1
// 10
// 输出样例：
// 1

/*
将0-23映射到1-24
1. 0 <= x[i] <= num[i] i点需要的人数大于等于0并且小于等于有的人数
2. x[i-7] + x[i-6] + ... + x[i] >= r[i]
                      ||
1. 0 <= s[i] - s[i - 1] <= num[i]  s是x的前缀和
2. i >= 8 s[i] - s[i - 8] >= r[i]
   1 <= i <= 7 s[i] + s[24] - s[i + 16] >= ri 这里的s[24]是常数
根据上面这些条件可以得到下面不等式
1. s[i] >= s[i - 1] + 0
2. s[i - 1] >= s[i] - num[i];
3. i >= 8 s[i] >= s[i - 8] + r[i]
4. 1 <= i <= 7, s[i] >= s[i + 16] - s[24] + r[i]
采用枚举的方式 s[24]可以描述成 s[24] <= c, s[24] >= c，可以转换成 s[24] <= s[0] + c  s[0] <= s[24] + c
*/
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 30, M = 100;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int cnt[N];
int n;
int num[N], r[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void build(int c){
    memset(h, -1, sizeof h);
    idx = 0;
    
    for(int i = 1; i <= 24; i++){
        add(i - 1, i, 0); // s[i] >= s[i - 1] + 0
        add(i, i - 1, -num[i]); // s[i - 1] >= s[i] - num[i]
    }
    for(int i = 8; i <= 24; i++) add(i - 8, i, r[i]); // i >= 8 s[i] >= s[i - 8] + r[i]
    for(int i = 1; i <= 7; i++) add(i + 16, i, -c + r[i]); // s[i] >= s[i + 16] - s[24] + r[i]
    add(0, 24, c), add(24, 0, -c); // s[24] <= s[0] + c  s[0] <= s[24] + c
}

bool spfa(int c){
    build(c); // 建图
    
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    memset(dist, -0x3f, sizeof dist);
    dist[0] = 0;
    
    queue<int> q;
    q.push(0);
    st[0] = true;
    
    while(q.size()){
        int t = q.front();
        q.pop();
        
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= 25) return false; 
                if(!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return true;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        for(int i = 1; i <= 24; i++) cin >> r[i]; // 如果每个时间段需要的人数
        cin >> n;
        memset(num, 0, sizeof num); // 重置num
        for(int i = 0; i < n; i++) { // 读入从t+1时间段的人
            int t;
            cin >> t;
            num[t + 1]++;
        }
        bool success = false;
        for(int i = 0; i <= 1000; i++) // 枚举s[24]
            if(spfa(i)){ // 如果返回true，表示此时的i即为正确答案，结果就是s[24]
                cout << i << endl;
                success = true;
                break;
            }
        if(!success) puts("No Solution");
    }
    
    return 0;
}