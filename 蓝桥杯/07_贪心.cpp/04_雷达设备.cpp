// 假设海岸是一条无限长的直线，陆地位于海岸的一侧，海洋位于另外一侧。

// 每个小岛都位于海洋一侧的某个点上。

// 雷达装置均位于海岸线上，且雷达的监测范围为 d，当小岛与某雷达的距离不超过 d 时，该小岛可以被雷达覆盖。

// 我们使用笛卡尔坐标系，定义海岸线为 x 轴，海的一侧在 x 轴上方，陆地一侧在 x 轴下方。

// 现在给出每个小岛的具体坐标以及雷达的检测范围，请你求出能够使所有小岛都被雷达覆盖所需的最小雷达数目。

// 输入格式
// 第一行输入两个整数 n 和 d，分别代表小岛数目和雷达检测范围。

// 接下来 n 行，每行输入两个整数，分别代表小岛的 x，y 轴坐标。

// 同一行数据之间用空格隔开。

// 输出格式
// 输出一个整数，代表所需的最小雷达数目，若没有解决方案则所需数目输出 −1。

// 数据范围
// 1≤n≤1000,
// −1000≤x,y≤1000
// 输入样例：
// 3 2
// 1 2
// -3 1
// 2 1
// 输出样例：
// 2

// 听了大佬的讲解自己写出来的代码
/*
思路：
  1.获取所有点的坐标后，把在海岸线上能够侦测到这个坐标的位置保存下来，用{l, r}来保存
  2.按照r的顺序从小到大排序
  3.遍历每一个{l, r}，用一个right来保存一个雷达放的位置
  4.如果l是大于right，就表明需要多一个雷达，然后把right赋值为r
  5.按照4向后遍历，最终就得到了需要多少个雷达
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 1010;

int n, d;
struct Segment{
    double l, r;
    bool operator < (const Segment& t) const{
        return r < t.r;
    }
}segs[N];

int main(){
    cin >> n >> d;
    int x, y;
    bool flag = false;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        double gap = d * d - y * y;
        if(gap < 0){
            flag = true;
            break;
        }
        segs[i] = {x - sqrt(gap), x + sqrt(gap)};
    }
    
    if(flag) cout << "-1" << endl;
    else {
        sort(segs, segs + n);
        
        int cnt = 0;
        double right;
        for(int i = 0; i < n; i++){
            if(!i){
                right = segs[i].r;
                cnt++;
            }else if(segs[i].l < right) continue;
            else if(segs[i].r > right){
                right = segs[i].r;
                cnt++;
            }
        }
        
        cout << cnt << endl;
    }

    
    return 0;
}

// 大佬的代码
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const int N = 1010;

int n, d;
struct Segment{ // 一个点能被侦察到的位置
    double l, r;
    bool operator < (const Segment &t) const{
        return r < t.r;
    }
}seg[N];

int main(){
    
    scanf("%d%d", &n, &d);
    
    bool failed = false;
    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d%d", &x, &y);
        if(y > d) failed = true; // 表明这个点不能被侦察到
        else{
            double len = sqrt(d * d - y * y);
            seg[i] = {x - len, x + len};
        }
    }
    
    if(failed){
        puts("-1");
    }else{
        sort(seg, seg + n);
        
        int cnt = 0;
        double last = -1e20;
        for(int i = 0; i < n; i++){
            if(last < seg[i].l){
                cnt++;
                last = seg[i].r;
            }
        }
        printf("%d\n", cnt);
    }
    
    return 0;
}