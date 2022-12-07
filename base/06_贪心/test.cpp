#include <iostream>
#include <cstdlib>
#include<math.h>
using namespace std;
/********* Start *********/
//请在此处完成Triangle的声明
class Triangle{
    public:
        Triangle(double x=1, double y=1, double z=1);
        double Perimeter();
        double Area();  
        bool isFlag;
    private:
        double a,b,c;  
};

Triangle::Triangle(double x = 1, double y = 1, double z = 1){
    a = x, b = y, c = z;
    if(a + b > c && a + c > b && b + c > a) isFlag = true;
    else {
        isFlag = false;
        cout << "不能构成三角形" << endl;
    }
}
double Triangle::Perimeter(){
    if(!isFlag) return 0;
    return a + b + c;
}
double Triangle::Area(){
    if(!isFlag) return 0;
    double p = (a + b + c) / 2;
    return pow(p * (p - a) * (p - b) * (p - c), 0.5);
}
