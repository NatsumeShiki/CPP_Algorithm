// Tyvj已经一岁了，网站也由最初的几个用户增加到了上万个用户，随着Tyvj网站的逐步壮大，管理员的数目也越来越多，现在你身为Tyvj管理层的联络员，希望你找到一些通信渠道，使得管理员两两都可以联络（直接或者是间接都可以）。本题中所涉及的通信渠道都是 双向 的。

// Tyvj是一个公益性的网站，没有过多的利润，所以你要尽可能的使费用少才可以。

// 目前你已经知道，Tyvj的通信渠道分为两大类，一类是必选通信渠道，无论价格多少，你都需要把所有的都选择上；还有一类是选择性的通信渠道，你可以从中挑选一些作为最终管理员联络的通信渠道。

// 数据保证给出的通信渠道可以让所有的管理员联通。

// 注意： 对于某两个管理员 u,v
// ，他们之间可能存在多条通信渠道，你的程序应该累加所有 u,v
//  之间的必选通行渠道。

// 输入格式
// 第一行两个整数 n，m
//  表示Tyvj一共有 n
//  个管理员，有 m
//  个通信渠道;

// 第二行到 m+1
//  行，每行四个非负整数，p,u,v,w
//  当 p=1
//  时，表示这个通信渠道为必选通信渠道；当 p=2
//  时，表示这个通信渠道为选择性通信渠道；u,v,w
//  表示本条信息描述的是 u，v
//  管理员之间的通信渠道，u
//  可以收到 v
//  的信息，v
//  也可以收到 u
//  的信息，w
//  表示费用。

// 输出格式
// 一个整数，表示最小的通信费用。

// 数据范围
// 1≤n≤2000

// 1≤m≤10000
// 输入样例：
// 5 6
// 1 1 2 1
// 1 2 3 1
// 1 3 4 1
// 1 4 1 1
// 2 2 5 10
// 2 2 5 5
// 输出样例：
// 9

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 2010, M = 10010;
struct edge{
    int a, b, w;
    bool operator < (const edge &t)const{
        return w < t.w;
    }
}e[M];
int p[N];
int n, m;
int res, cnt;

int find(int x){
    if(x != p[x]) p[x] =  find(p[x]);
    return p[x];
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = i;
    for(int i = 0; i < m; i++){
        int t, a, b, w;
        cin >> t >> a >> b >> w;
        if(t == 1){
            res += w;
            a = find(a), b = find(b);
            if(a != b) p[a] = b;
        }else e[cnt++] = {a, b, w};
    }
    
    sort(e, e + cnt);
    for(int i = 0; i < cnt; i++){
        int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
        if(a != b){
            res += w;
            p[a] = b;
        }
    }
    
    cout << res << endl;
    
    return 0;
}