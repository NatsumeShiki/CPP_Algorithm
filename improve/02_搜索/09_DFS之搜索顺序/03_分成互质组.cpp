// 给定 n
//  个正整数，将它们分组，使得每组中任意两个数互质。

// 至少要分成多少个组？

// 输入格式
// 第一行是一个正整数 n
// 。

// 第二行是 n
//  个不大于10000的正整数。

// 输出格式
// 一个正整数，即最少需要的组数。

// 数据范围
// 1≤n≤10
// 输入样例：
// 6
// 14 20 33 117 143 175
// 输出样例：
// 3


#include<iostream>
using namespace std;

const int N = 10;
int n;
int p[N];
int group[N][N]; // 记录的是下标
bool st[N];
int ans = N;

int gcd(int a, int b){ // 判断两个数是否互质
    return b ? gcd(b, a % b) : a;
}

bool check(int group[], int gc, int i){
    for(int j = 0; j < gc; j++)
        if(gcd(p[group[j]], p[i]) > 1) // 如果最大公因数大于1，说明两个数不互质
            return false;
            
    return true;
}

void dfs(int g, int gc, int tc, int start){ // 第几组 当前组内下标 当前一共有多少个元素 当前组从那个点开始搜
    if(g >= ans) return; // 如果当前组数大于等于ans，拿继续往下走不会得到更优解，返回
    if(tc == n) ans = g; // 如果满足tc == n而且还走到了这一步，说明g一定小于ans
     
    bool flag = true; // 判断从start开始的数后面是否有可以装进第g组中
    for(int i = start; i < n; i++)
        if(!st[i] && check(group[g], gc, i)){ // 如果第i个数还没有存并且判断group[g]数组中每个数是否与p[i]互质
            st[i] = true;
            group[g][gc] = i; // 将p[i]存进group[g]数组中
            dfs(g, gc + 1, tc + 1, i + 1); // 继续dfs下一个数
            st[i] = false; // 还原状态
            
            flag = false; // 表示可以存进group[g]数组中，不需要再开一个数组
        }
        
    if(flag) dfs(g + 1, 0, tc, 0); // 表述p[i]这个点无法存进group[g]数组中，必须新开一个数组
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i];
    
    dfs(1, 0, 0, 0);
    
    cout << ans << endl;
    
    return 0;
}