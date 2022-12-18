// 给定三个整数数组

// A=[A1,A2,…AN],
// B=[B1,B2,…BN],
// C=[C1,C2,…CN],

// 请你统计有多少个三元组 (i,j,k) 满足：

// 1≤i,j,k≤N
// Ai<Bj<Ck
// 输入格式
// 第一行包含一个整数 N。

// 第二行包含 N 个整数 A1,A2,…AN。

// 第三行包含 N 个整数 B1,B2,…BN。

// 第四行包含 N 个整数 C1,C2,…CN。

// 输出格式
// 一个整数表示答案。

// 数据范围
// 1≤N≤105,
// 0≤Ai,Bi,Ci≤105
// 输入样例：
// 3
// 1 1 1
// 2 2 2
// 3 3 3
// 输出样例：
// 27

// 使用前缀和
/*
暴力做法是枚举ABC，时间复杂度是O(n^3)，就是10^15，绝对会TLE
所以进行优化，使用前缀和
可以只枚举B数组，然后让A中比B[i]小的数乘以C中比C[i]大的数，就是i这个位置的三元组数量，所以现在问题就是怎么快速求比B[i]小的和大的
可以从控制台读取A数据后，遍历它，用cnt来记录i这个数据出现了几次，然后求cnt的前缀和，就表示小于等于i出现了几次
同样这么处理C
然后用as数组来保存A中比B[i]小的数据的数目，用cs数组来保存C中比C[i]大的数据的数目
最后遍历B数组，让as[i]和cs[i]相乘累加就是结果
*/
#include<iostream>
#include<cstring>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n;
int a[N], b[N], c[N];
int as[N]; // as[i]表示在A[]中有多少数小于B[i]
int cs[N]; // cs[i]表示在C[]中有多少数大于B[i]
int cnt[N], s[N]; // cnt记录每个i出现的次数，s是cnt的前缀和

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]), a[i]++; // 因为A[i]最小是0，但是前缀和会出现i-1，所以让他们所有数都加1可以不用处理特殊情况
    for(int i = 0; i < n; i++) scanf("%d", &b[i]), b[i]++;
    for(int i = 0; i < n; i++) scanf("%d", &c[i]), c[i]++;
    
    for(int i = 0; i < n; i++) cnt[a[i]]++; // 记录每个i出现的次数
    for(int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i]; // 求前缀和
    for(int i = 0; i < n; i++) as[i] = s[b[i] - 1]; // 求A[]中每个比B[i]小的数据的数目，保存在下标为i
    
    memset(cnt, 0, sizeof cnt);
    memset(s, 0, sizeof s);
    for(int i = 0; i < n; i++) cnt[c[i]]++;
    for(int i = 1; i < N; i++) s[i] = s[i - 1] + cnt[i];
    for(int i = 0; i < n; i++) cs[i] = s[N - 1] - s[b[i]];
    
    LL res = 0;
    for(int i = 0; i < n; i++) res += (LL)as[i] * cs[i]; // 相乘累加
    
    cout << res << endl;
    
    return 0;
}

// 使用排序+二分
/*
从控制台读取ABC后，将A，C排序，然后枚举B，然后使用二分查找A中有多少个数是小于B[i]的，C中有多少个数是大于B[i]的，然后相乘累加，结果就是答案
*/
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int A[N], B[N], C[N];
int n;

int findA(int x){
    int l = 0, r = n - 1;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(A[mid] >= x) r = mid - 1;
        else l = mid;
    }
    if(A[l] >= x) return 0;
    return l + 1;
}

int findC(int x){
    int l = 0, r = n - 1;
    while(l < r){
        int mid = l + r >> 1;
        if(C[mid] <= x) l = mid + 1;
        else r = mid;
    }
    if(C[l] <= x) return 0;
    return n - l;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    for(int i = 0; i < n; i++) cin >> B[i];
    for(int i = 0; i < n; i++) cin >> C[i];
    sort(A, A + n);
    sort(C, C + n);
    
    LL res = 0;
    for(int i = 0; i < n; i++){
        res += (LL)findA(B[i]) * findC(B[i]);
    }
    cout << res << endl;
    return 0;
}