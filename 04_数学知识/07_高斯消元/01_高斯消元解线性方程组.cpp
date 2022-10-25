
// 输入一个包含 n 个方程 n 个未知数的线性方程组。

// 方程组中的系数为实数。

// 求解这个方程组。

// 下图为一个包含 m 个方程 n 个未知数的线性方程组示例：


// 输入格式
// 第一行包含整数 n。

// 接下来 n 行，每行包含 n+1 个实数，表示一个方程的 n 个系数以及等号右侧的常数。

// 输出格式
// 如果给定线性方程组存在唯一解，则输出共 n 行，其中第 i 行输出第 i 个未知数的解，结果保留两位小数。

// 如果给定线性方程组存在无数解，则输出 Infinite group solutions。

// 如果给定线性方程组无解，则输出 No solution。

// 数据范围
// 1≤n≤100,
// 所有输入系数以及常数均保留两位小数，绝对值均不超过 100。

// 输入样例：
// 3
// 1.00 2.00 -1.00 -6.00
// 2.00 1.00 -3.00 -9.00
// -1.00 -1.00 2.00 7.00
// 输出样例：
// 1.00
// -2.00
// 3.00


/* 
  初等行列变换：
    1.把某一行乘一个非零的数
    2.交换某两行
    3.把某行的若干倍加到某一行
  高斯消元：
    枚举每一列c
    1. 找到绝对值最大的一行
    2. 将改行换到最上面
    3. 将改行的第一个非0元素变成1
    4. 将下面所有行的第c列消成0
    此时构造出了上三角矩阵
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 110;
const double eps = 1e-6; // 这个是用来确定某一个浮点数是否为0的，因为浮点数的0不一定是0.00000，而是0.000000000000001，所以要确定一个精度来判断某一个浮点数是不是0

int n;
double a[N][N]; // 保存矩阵

int guess(){
    int c, r;
    for(c = 0, r = 0; c < n; c++){
      // 下面这几行代码是为了在第c列找一个数，这个数的绝对值在这一列是最大的
        int t = r;
        for(int i = r; i < n; i++)
            if(fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        // 如果下面这个判断是true的话，表示在第r行下面的这一列都是0，此时无法找大绝对值最大的一行，所以进行下一列循环，只让c自增，而r不增加
        if(fabs(a[t][c]) < eps) continue;
        
        for(int i = c; i <= n; i++) swap(a[t][i], a[r][i]); // 将第r行和第t行交换
        for(int i = n; i >= c; i--) a[r][i] /= a[r][c]; // 将这一行所有元素都除以 a[r][c]，保证了对角线的这个坐标的系数是1，并且要从后往前除，因为如果
                                                        // 从左往右除的话会把先把a[r][c]给除以自己，变成1，后面再除以a[r][c]结果是没有变化的 
        // 下面这一段代码的目的是为了把第r行下面的在第c列的所有数都变成0
        for(int i = r + 1; i < n; i++) 
            if(fabs(a[i][c]) > eps) // 如果这个数已经是0了就不需要再减了
                for(int j = n; j >= c; j--) // 同样，这一行也是要从后往前进行操作，因为后面每一个数都要减去上一行乘以a[i][c]，而a[i][c]本身最后也是要变成0的
                    a[i][j] -= a[r][j] * a[i][c];
        r++; // 走到这一步说明可以进行下一行的操作了
    }
    if(r < n){ // 如果r小于n，说明有某一列是没有找到绝对值最大的，都是0，此时r不会自增，所以也就导致了r < n
        for(int i = r; i < n; i++) // 从第r行开始，此时每一行的第0-n个元素都是0，所以如果第n + 1个元素不是0，就会出现 0 = 非0 的情景，差生了矛盾，此时说明无解
            if(fabs(a[i][n]) > eps)
                return -1; // 无解
        // 如果从第r行开始的每一行的第0-n+1 个元素都是0，说明会产生无穷多组解
        return 1; // 无穷多组解 
    }
    // 走到这一步说明有唯一一组解，此时的矩阵是上三角行的
    // 从最后一行开始进行，从这一行的第i+1列往后走，每走一次，就让这一行元素的最后一个元素减去当前这个元素乘以下面这一行的最后一个元素
    for(int i = n - 1; i >= 0; i--)
        for(int j = i + 1; j < n; j++)
            a[i][n] -= a[i][j] * a[j][n];
    
    return 0; // 有唯一解
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n + 1; j++)
            cin >> a[i][j];
    // 这里规定，如果guess函数的返回值为0，表示有唯一解，返回为1，表示有无穷多组解，返回值为-1，表示无解
    int t = guess();
    if(t == 0) // 唯一解
        for(int i = 0; i < n; i++) // 这里做判断是因为可能会出现 -0.00，所以要分开处理
        if(fabs(a[i][n]) < eps) puts("0.00"); 
        else printf("%.2lf\n", a[i][n]);
    else if(t == 1) puts("Infinite group solutions"); // 无穷多组解
    else puts("No solution"); // 无解
    
    return 0;
}