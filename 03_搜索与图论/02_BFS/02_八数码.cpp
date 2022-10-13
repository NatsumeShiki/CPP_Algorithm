// 在一个 3×3 的网格中，1∼8 这 8 个数字和一个 x 恰好不重不漏地分布在这 3×3 的网格中。

// 例如：

// 1 2 3
// x 4 6
// 7 5 8
// 在游戏过程中，可以把 x 与其上、下、左、右四个方向之一的数字交换（如果存在）。

// 我们的目的是通过交换，使得网格变为如下排列（称为正确排列）：

// 1 2 3
// 4 5 6
// 7 8 x
// 例如，示例中图形就可以通过让 x 先后与右、下、右三个方向的数字交换成功得到正确排列。

// 交换过程如下：

// 1 2 3   1 2 3   1 2 3   1 2 3
// x 4 6   4 x 6   4 5 6   4 5 6
// 7 5 8   7 5 8   7 x 8   7 8 x
// 现在，给你一个初始网格，请你求出得到正确排列至少需要进行多少次交换。

// 输入格式
// 输入占一行，将 3×3 的初始网格描绘出来。

// 例如，如果初始网格如下所示：

// 1 2 3 
// x 4 6 
// 7 5 8 
// 则输入为：1 2 3 x 4 6 7 5 8

// 输出格式
// 输出占一行，包含一个整数，表示最少交换次数。

// 如果不存在解决方案，则输出 −1。

// 输入样例：
// 2 3 4 1 5 x 7 6 8
// 输出样例
// 19

#include<iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

int bfs(string start){
  string end = "12345678x"; // 这个是结束的时候的字符串
  queue<string> q;
  unordered_map<string, int> d;

  q.push(start); // 先把一开始的字符串push进队列
  d[start] = 0;

  int dx[4] = {-1, 0, 1, 0}, dy[4] = { 0, -1, 0, 1 }; // 用于模拟上下左右

  while(q.size()){
    auto t = q.front(); // 取出队列第一个
    q.pop(); // 删除队头元素

    int distance = d[t]; // 得到从一开始字符串到这一步的次数

    if(t == end) return distance; // 如果字符串与end相同，说明这就是最短路径，返回答案

    int k = t.find('x'); // 从字符串中找到字符 x 的下标
    int x = k / 3, y = k % 3; // 计算字符 x 在井字中的位置，它的x、y坐标，都是从0开始，最大是2

    for(int i = 0; i < 4; i++){ // 分别计算上下左右的位置
      int a = x + dx[i], b = y + dy[i]; // 得到下一步上下左右后的坐标
      if(a >= 0 && a < 3 && b >= 0 && b < 3){ // 如果在范围内
        swap(t[k], t[a * 3 + b]); // 先把这个字符和x交换
        if(!d.count(t)){ // 如果d中没有记录这个字符串，就说明这是第一次得到
          d[t] = distance + 1; // 计算走到这一步的次数
          q.push(t); // 把这个字符串放进队列中
        }
        swap(t[k], t[a * 3 + b]); // 恢复原状
      }
    }
  }

  return -1;
}

int main(){
  string start;
  for(int i = 0; i < 9; i++){ // 拼接字符串
    char c;
    cin >> c;
    start += c;
  }
  cout << bfs(start) << endl;

  return 0;
}