// 随着白天越来越短夜晚越来越长，我们不得不考虑铲雪问题了。

// 整个城市所有的道路都是双向车道,道路的两个方向均需要铲雪。因为城市预算的削减，整个城市只有 1 辆铲雪车。

// 铲雪车只能把它开过的地方（车道）的雪铲干净，无论哪儿有雪，铲雪车都得从停放的地方出发，游历整个城市的街道。

// 现在的问题是：最少要花多少时间去铲掉所有道路上的雪呢？

// 输入格式
// 输入数据的第 1
//  行表示铲雪车的停放坐标 (x,y)
// ，x,y
//  为整数，单位为米。

// 下面最多有4000行，每行给出了一条街道的起点坐标和终点坐标，坐标均为整数，所有街道都是笔直的，且都是双向车道。

// 铲雪车可以在任意交叉口、或任何街道的末尾任意转向，包括转 U
//  型弯。

// 铲雪车铲雪时前进速度为 20
//  千米/时，不铲雪时前进速度为 50
//  千米/时。

// 保证：铲雪车从起点一定可以到达任何街道。

// 输出格式
// 输出铲掉所有街道上的雪并且返回出发点的最短时间，精确到分钟，四舍五入到整数。

// 输出格式为”hours:minutes”，minutes不足两位数时需要补前导零。
// 具体格式参照样例。

// 数据范围
// ?106≤x,y≤106

// 所有位置坐标绝对值不超过 106
// 。

// 输入样例：
// 0 0
// 0 0 10000 10000
// 5000 -10000 5000 10000
// 5000 10000 10000 10000
// 输出样例：
// 3:55
// 样例解释
// 输出结果表示共需3小时55分钟。

/*
整个城市所有的道路都是双向车道,道路的两个方向均需要铲雪，所以如果建边的话每个点的出度和入度都是相同的，也就是所有点的度数都为偶数，是一个欧拉回路
所以结论就是将所有边的长度加起来乘以2就是总共的距离，然后计算时间即可
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

double a1, a2, b1, b2;
double x, y;

int main(){
    cin >> x >> y;
    double dis = 0;
    while(cin >> a1 >> b1 >> a2 >> b2){
        x = (a2 - a1) * (a2 - a1);
        y = (b2 - b1) * (b2 - b1);
        dis += sqrt(x + y);
    }
    dis = dis * 2 / 1000 / 20;
    int hour = (int)dis;
    int minute = ((dis - hour) * 60 + 0.5);
    
    printf("%d:%02d\n", hour, minute);
    
    return 0;
}

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;



int main(){
    double x1, x2, y1, y2;
    cin >> x1 >> y1;
    double sum = 0;
    while(cin >> x1 >> y1 >> x2 >> y2){
        double dx = x2 - x1;
        double dy = y2 - y1;
        sum += sqrt(dx * dx + dy * dy);
    }
    
    sum *= 2;
    int minutes = round(sum / 1000 / 20 * 60);
    int hours = minutes / 60;
    minutes %= 60;
    
    printf("%d:%02d\n", hours, minutes);
    
    return 0;
}