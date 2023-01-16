// 某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。

// 但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。

// 某天，雷达捕捉到敌国的导弹来袭。

// 由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。

// 输入导弹依次飞来的高度（雷达给出的高度数据是不大于30000的正整数，导弹数不超过1000），计算这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

// 输入格式
// 共一行，输入导弹依次飞来的高度。

// 输出格式
// 第一行包含一个整数，表示最多能拦截的导弹数。

// 第二行包含一个整数，表示要拦截所有导弹最少要配备的系统数。

// 数据范围
// 雷达给出的高度数据是不大于 30000 的正整数，导弹数不超过 1000。

// 输入样例：
// 389 207 155 300 299 170 158 65
// 输出样例：
// 6
// 2

// 我自己写的算出每个最长子序列，但是这么做是错误的
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N], f[N], fa[N], sum[N], st[N];

int main(){
    int n = 1;
    while(cin >> a[n]) n++;
    n--;
    
    int res = 0, cnt = 0, target = 0;
    while(true){
        cnt++;
        res = 0, target = 0;
        for(int i = n; i; i--){
            if(st[i]) continue;
            f[i] = 1, fa[i] = -1;
            
            for(int j = n; j > i; j--){
                if(st[j]) continue;
                if(a[j] < a[i] && f[i] < f[j] + 1){
                    f[i] = f[j] + 1;
                    fa[i] = j;
                }
            }
            if(f[i] > res){
                res = f[i];
                target = i;
            }
        } 
        for(int i = target; i != -1; i = fa[i]){
            sum[cnt]++;
            st[i] = cnt;
        }
        bool flag = true;
        for(int i = 1; i <= n; i++)
            if(st[i] == 0){
                flag = false;
                break;
            }
        if(flag) break;
    }
    for(int i = 1; i <= cnt; i++) 
        res = max(res, sum[i]);
    cout << res << endl;
    cout << cnt << endl;
    return 0;
}

// 大佬的代码
/*
贪心流程：
  从前往后扫描每个数，对于每个数
    情况1：如果现有的子序列的结尾都小于当前数，则创建新子序列
    情况2：将当前数放到结尾大于等于它的最小的子序列后面
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int a[N], f[N], g[N]; // a保存导弹的高度，f保存最长不上升子序列，g保存每个系统最低高度
int n;

int main(){
    while(cin >> a[n]) n++;

    int res= 0;
    for(int i = 0; i < n; i++){
        f[i] = 1;
        for(int j = 0; j < i; j++)
            if(a[j] >= a[i])
                f[i] = max(f[i], f[j] + 1);
        res = max(f[i], res);
    }
    cout << res << endl;
    
    int cnt = 0; // cnt保存拦截导弹系统数目
    for(int i = 0; i < n; i++){
        int k = 0; 
        while(k < cnt && g[k] < a[i]) k++; // g数组是递增的，所以找到第一个大于等于a[i]的数，保证了这个数是大于等于它的里面最小的数，把它接在后面
        g[k] = a[i];
        if(k >= cnt) cnt++;
    }
    cout << cnt << endl;

    return 0;
}