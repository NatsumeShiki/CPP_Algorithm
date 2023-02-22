// 给定一个空数组 V
//  和一个整数数组 a1,a2,…,an
// 。

// 现在要对数组 V
//  进行 n
//  次操作。

// 第 i
//  次操作的具体流程如下：

// 从数组 V
//  尾部插入整数 0
// 。
// 将位于数组 V
//  末尾的 ai
//  个元素都变为 1
// （已经是 1
//  的不予理会）。
// 注意：

// ai
//  可能为 0
// ，即不做任何改变。
// ai
//  可能大于目前数组 V
//  所包含的元素个数，此时视为将数组内所有元素变为 1
// 。
// 请你输出所有操作完成后的数组 V
// 。

// 输入格式
// 第一行包含整数 T
// ，表示共有 T
//  组测试数据。

// 每组数据第一行包含整数 n
// 。

// 第二行包含 n
//  个整数 a1,a2,…,an
// 。

// 输出格式
// 每组数据输出一行结果，表示所有操作完成后的数组 V
// ，数组内元素之间用空格隔开。

// 数据范围
// 1≤T≤20000
// ,
// 1≤n≤2×105
// ,
// 0≤ai≤n
// ,
// 保证一个测试点内所有 n
//  的和不超过 2×105
// 。

// 输入样例：
// 3
// 6
// 0 3 0 0 1 3
// 10
// 0 0 0 1 0 5 0 0 0 2
// 3
// 0 0 0
// 输出样例：
// 1 1 0 1 1 1
// 0 1 1 1 1 1 0 0 1 1
// 0 0 0

// 自己的代码
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int a[N];
int s[N];
int n;

int main(){
    int t;
    cin >> t;
    while(t--){
        memset(s, 0, sizeof s);
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            if(!a[i]) continue;
            s[max(1, i - a[i] + 1)]++;
            s[i + 1]--;
        }
        for(int i = 1; i <= n; i++){
            s[i] += s[i - 1];
            if(s[i] > 0) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }

    return 0;
}


// 大佬的代码
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int s[N];
int n;

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        memset(s, 0, (n + 1) * 4);
        for(int i = 1; i <= n; i++){
            int a;
            cin >> a;
            int l = max(i - a + 1, 1), r = i;
            s[l]++, s[r + 1]--;
        }
        for(int i = 1; i <= n; i++){
            s[i] += s[i - 1];
            cout << !!s[i] << " ";
        }
        puts("");
    }

    return 0;
}