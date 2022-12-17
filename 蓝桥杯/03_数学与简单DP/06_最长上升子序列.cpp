// 给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。

// 输入格式
// 第一行包含整数 N。

// 第二行包含 N 个整数，表示完整序列。

// 输出格式
// 输出一个整数，表示最大长度。

// 数据范围
// 1≤N≤1000，
// −109≤数列中的数≤109
// 输入样例：
// 7
// 3 1 2 1 8 5 6
// 输出样例：
// 4

// 我的写法
/*
状态表示f[i]:
  集合：所有以第i个数为结尾的上升子序列
  属性：Max
状态计算：f[i] = max(f[j] + 1) j = 0,1,2,3,...,i-1
时间复杂度是O(n^2)，n是小等于1000的，所以平方后是1e6，可以通过的
通俗的说就是先用一个数组保存控制台读入的数据，再创建一个数组用来保存从开头到最后一个数据每个以当前数据为结尾的最大子序列长度，然后在从中选择最大值输出
比如说现在要求第i个数为结尾的最大子序列，那么我们就要从前i-1个数中查找比a[i]小的数，然后再从这些数中获得最大的上升子序列，加上1表示a[i]当前这个数即可
*/
#include<iostream>
using namespace std;

const int N = 1010;
int a[N], f[N]; // a数组保存从控制台读入的数据，f数组保存以第i个数为结尾的最大子序列长度

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i]; // 从控制台读取数据保存到a数组中
    for(int i = 0; i < n; i++){
        int res = 0; // 用res来保存从前i-1个数中a[j]<a[i]并且f[j]最大的数
        for(int j = 0; j < i; j++){
            if(a[j] < a[i] && f[j] > res) res = f[j];
        }
        f[i] = res + 1; // 获取了前面的最大子序列后再加上1就是以第i个数为结尾的最大子序列长度
    }
    int res = 0;
    for(int i = 0; i < n; i++) res = max(res, f[i]); // 再从这些最大子序列长度中获取最大值即可
    cout << res << endl;
    return 0;
}

// 老师的写法
// 区别就在于我是先获取前i-1个数中的最大子序列长度，最后才加1，而老师是边获取边加1，嘛没差啦
// #include<iostream>
// using namespace std;

// const int N = 1010;
// int a[N], f[N];

// int main(){
//     int n;
//     cin >> n;
//     for(int i = 0; i < n; i++) cin >> a[i];
//     for(int i = 0; i < n; i++){
//         f[i] = 1; // 只有a[i]一个数
//         for(int j = 0; j < i; j++){
//             if(a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
//         }
//     }
//     int res = 0;
//     for(int i = 0; i < n; i++) res = max(res, f[i]);
//     cout << res << endl;
//     return 0;
// }

/*
如果要获取路径，需要再创建一个数组g，用来保存从0~i-1中既要大于a[i]，而且f[j]也要是最大值的那个下标，保存到g[i]中，这样，在遍历完了之后，获取最大子序列的那个
下标，然后可以从后往前输出，按照g保存的轨迹
*/
#include<iostream>
using namespace std;

const int N = 1010;
int a[N], f[N], g[N];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        f[i] = 1; // 只有a[i]一个数
        g[i] = 0; // 一开始都保存0，表示前面没有数了
        for(int j = 0; j < i; j++){
            if(a[j] < a[i] && f[j] + 1 > f[i]){
                f[i] = f[j] + 1; // 找到了更大的那个最大子序列，既要保存这个长度+1
                g[i] = j; // 也要保存它的下标，以便于根据它来往前查找轨迹
            }
        }
    }
    int k = 0; // k表示最大子序列的最后一个数据的下标
    for(int i = 0; i < n; i++)
        if(f[i] > f[k])
            k = i;
    // 根据这个最大子序列的最后一个下标，从后往前遍历，可以用一个容器来保存，也可以直接从后往前输出
    for(int i = 0, len = f[k]; i < len; i++){
        cout << a[k] << " "; 
        k = g[k]; // k = g[k] 表示以k为结尾的最大子序列它的上一个数的下标，跳转到那里
    }
    return 0;
}