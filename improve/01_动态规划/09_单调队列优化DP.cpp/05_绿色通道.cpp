// 高二数学《绿色通道》总共有 n
//  道题目要抄，编号 1,2,…,n
// ，抄第 i
//  题要花 ai
//  分钟。

// 小 Y 决定只用不超过 t
//  分钟抄这个，因此必然有空着的题。

// 每道题要么不写，要么抄完，不能写一半。

// 下标连续的一些空题称为一个空题段，它的长度就是所包含的题目数。

// 这样应付自然会引起马老师的愤怒，最长的空题段越长，马老师越生气。

// 现在，小 Y 想知道他在这 t
//  分钟内写哪些题，才能够尽量减轻马老师的怒火。

// 由于小 Y 很聪明，你只要告诉他最长的空题段至少有多长就可以了，不需输出方案。

// 输入格式
// 第一行为两个整数 n,t
// 。

// 第二行为 n
//  个整数，依次为 a1,a2,…,an
// 。

// 输出格式
// 输出一个整数，表示最长的空题段至少有多长。

// 数据范围
// 0<n≤5×104
// ,
// 0<ai≤3000
// ,
// 0<t≤108
// 输入样例：
// 17 11
// 6 4 5 2 5 3 4 5 2 3 4 5 2 3 6 3 5
// 输出样例：
// 3

/*
这道题是具有二分的性质的，二分最长空题段，如果该长度的空题段要使用的时间不超过给定的时间，则最长空题段是小于等于它的，因此通过二分，直到获得满足时间
不超过指定时间范围的空题段
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 50010;
int n, t;
int q[N], f[N], w[N]; // q是单调队列，f是1-n最小代价，w是代价

bool check(int gap){
    int hh = 0, tt = 0;
    for(int i = 1; i <= n; i++){
        if(q[hh] < i - gap - 1) hh++; // 因为是空题段 长度为gap，所以在i位置使用的单调队列是从i - gap - 1 到i - 1的
        f[i] = f[q[hh]] + w[i]; // 计算最小代价
        while(hh <= tt && f[q[tt]] >= f[i]) tt--; 
        q[++tt] = i;
    }
    int res = 1e9;
    for(int i = n; i >= n - gap; i--) res = min(res, f[i]); // 计算最少花费时间是多少，因为间隔是gap，所以i-gap位置也算
    
    return res <= t; // 最少花费时间小于等于t，返回true
}

int main(){
    cin >> n >> t;
    for(int i = 1; i <= n; i++) cin >> w[i];
    
    int l = 0, r = n;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid; // 返回true表示mid长度的空题段花费时间小于等于t
        else l = mid + 1;
    }
    cout << l << endl;
    
    return 0;
}