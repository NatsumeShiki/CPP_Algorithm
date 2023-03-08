// 我们有 n
//  个字符串，每个字符串都是由 a∼z
//  的小写英文字母组成的。

// 如果字符串 A
//  的结尾两个字符刚好与字符串 B
//  的开头两个字符相匹配，那么我们称 A
//  与 B
//  能够相连（注意：A
//  能与 B
//  相连不代表 B
//  能与 A
//  相连）。

// 我们希望从给定的字符串中找出一些，使得它们首尾相连形成一个环串（一个串首尾相连也算），我们想要使这个环串的平均长度最大。

// 如下例：

// ababc
// bckjaca
// caahoynaab
// 第一个串能与第二个串相连，第二个串能与第三个串相连，第三个串能与第一个串相连，我们按照此顺序相连，便形成了一个环串，长度为 5+7+10=22
// （重复部分算两次），总共使用了 3
//  个串，所以平均长度是 223≈7.33
// 。

// 输入格式
// 本题有多组数据。

// 每组数据的第一行，一个整数 n
// ，表示字符串数量；

// 接下来 n
//  行，每行一个长度小于等于 1000
//  的字符串。

// 读入以 n=0
//  结束。

// 输出格式
// 若不存在环串，输出”No solution”，否则输出最长的环串的平均长度。

// 只要答案与标准答案的差不超过 0.01
// ，就视为答案正确。

// 数据范围
// 1≤n≤105
// 输入样例：
// 3
// intercommunicational
// alkylbenzenesulfonate
// tetraiodophenolphthalein
// 0
// 输出样例：
// 21.66

#include<iostream>
#include<cstring>
using namespace std;

const int N = 700, M = 100010;
int n;
int h[N], e[M], w[M], ne[M], idx;
double dist[N];
int q[N], cnt[N];
bool st[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(double mid){
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    
    int hh = 0, tt = 0;
    for(int i = 0; i < 676; i++){
        q[tt++] = i;
        st[i] = true;
    }
    
    int count = 0;
    while(hh != tt){
        int t = q[hh++];
        if(hh == N) hh = 0;
        st[t] = false;
        
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] < dist[t] + w[i] - mid){
                dist[j] = dist[t] + w[i] - mid;
                cnt[j] = cnt[t] + 1;
                if(++count > 10000) return true;
                if(cnt[j] >= N) return true;
                if(!st[j]){
                    q[tt++] = j;
                    if(tt == N) tt = 0;
                    st[j] = true;
                }
            }
        }
    }
    
    return false;
}

int main(){
    char str[1010];
    while(scanf("%d", &n), n){
        memset(h, -1, sizeof h);
        idx = 0;
        for(int i = 0; i < n; i++){
            scanf("%s", str);
            int len = strlen(str);
            if(len >= 2){
                int left = (str[0] - 'a') * 26 + str[1] - 'a';
                int right = (str[len - 2] - 'a') * 26 + str[len - 1] - 'a';
                add(left, right, len);
            }
        }
        
        if(!check(0)) puts("No solution");
        else{
            double l = 0, r = 1000;
            while(r - l > 1e-4){
                double mid = (l + r) / 2;
                if(check(mid)) l = mid;
                else r = mid;
            }
            printf("%lf\n", r);
        }
    }
    
    return 0;
}