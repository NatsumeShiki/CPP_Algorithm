// n 个小朋友站成一排。

// 现在要把他们按身高从低到高的顺序排列，但是每次只能交换位置相邻的两个小朋友。

// 每个小朋友都有一个不高兴的程度。

// 开始的时候，所有小朋友的不高兴程度都是 0。

// 如果某个小朋友第一次被要求交换，则他的不高兴程度增加 1，如果第二次要求他交换，则他的不高兴程度增加 2（即不高兴程度为 3），依次类推。当要求某个小朋友第 k 次交换时，他的不高兴程度增加 k。

// 请问，要让所有小朋友按从低到高排队，他们的不高兴程度之和最小是多少。

// 如果有两个小朋友身高一样，则他们谁站在谁前面是没有关系的。

// 输入格式
// 输入的第一行包含一个整数 n，表示小朋友的个数。

// 第二行包含 n 个整数 H1,H2,…,Hn，分别表示每个小朋友的身高。

// 输出格式
// 输出一行，包含一个整数，表示小朋友的不高兴程度和的最小值。

// 数据范围
// 1≤n≤100000,
// 0≤Hi≤1000000
// 输入样例：
// 3
// 3 2 1
// 输出样例：
// 9
// 样例解释
// 首先交换身高为3和2的小朋友，再交换身高为3和1的小朋友，再交换身高为2和1的小朋友，每个小朋友的不高兴程度都是3，总和为9。


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10; // 树状数组是要以x坐标最大值为界，所以是这个
int n;
int h[N], tr[N]; // h数组保存从控制台读取的每个数，tr维护的是每个数出现的次数
int sum[N]; // sum保存下标为i位置前面有多少数比他大，后面有多少数比他小，二者之和

int lowbit(int x){
    return x & -x;
}

void add(int x, int v){
    for(int i = x; i < N; i += lowbit(i)) tr[i] += v;
}

int query(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &h[i]), h[i]++; // 题目给出的高度最小值是0，所以让所有都自增1，保证他们都是大于0的
    // 查询在下标i前比h[i]高的
    for(int i = 0; i < n; i++){
        sum[i] = query(N - 1) - query(h[i]); // 获取了保存在sum中
        add(h[i], 1); // 然后把它放入树状数组
    }
    // 先把tr重置为0
    memset(tr, 0, sizeof tr);
    // 查询在下标i后比h[i]低的
    for(int i = n - 1; i >= 0; i--){
        sum[i] += query(h[i] - 1);
        add(h[i], 1);
    }
    
    LL res = 0;
    for(int i = 0; i < n; i++) res += (LL)sum[i] * (sum[i] + 1) / 2; // 1 + 2 + ... + sum[i] = sum[i] * (sum[i] + 1) / 2
    // 因为可能会爆int，所以需要用longlong存储
    
    cout << res << endl;
    
    return 0;
}