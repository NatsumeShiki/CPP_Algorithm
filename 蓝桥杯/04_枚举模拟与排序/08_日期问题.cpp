// 小明正在整理一批历史文献。这些历史文献中出现了很多日期。

// 小明知道这些日期都在1960年1月1日至2059年12月31日。

// 令小明头疼的是，这些日期采用的格式非常不统一，有采用年/月/日的，有采用月/日/年的，还有采用日/月/年的。

// 更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。

// 比如02/03/04，可能是2002年03月04日、2004年02月03日或2004年03月02日。

// 给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？

// 输入格式
// 一个日期，格式是”AA/BB/CC”。

// 即每个’/’隔开的部分由两个 0-9 之间的数字（不一定相同）组成。

// 输出格式
// 输出若干个不相同的日期，每个日期一行，格式是”yyyy-MM-dd”。

// 多个日期按从早到晚排列。

// 数据范围
// 0≤A,B,C≤9
// 输入样例：
// 02/03/04
// 输出样例：
// 2002-03-04
// 2004-02-03
// 2004-03-02

// 通过枚举时间范围内的每个数，查看是否与输出相符，如果为true，就输出
#include<iostream>
using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 返回该年月日是否符合规范
bool check_valid(int year, int month, int day){
    if(month == 0 || month > 12) return false;
    if(day == 0) return false;
    if(month != 2){
        if(day > days[month])
            return false;
    }else{
        int leap = year % 100 && year % 4 == 0 || year % 400 == 0;
        if(day > 28 + leap) 
            return false;
    }
    return true;
}

int main(){
    
    int a, b, c;
    scanf("%d/%d/%d", &a, &b, &c);
    for(int date = 19600101; date <= 20591231; date++){
        int year = date / 10000, month = date / 100 % 100, day = date % 100;
        if(!check_valid(year, month, day)) continue;
        
        if(year % 100 == a && month == b && day == c || // 年日月
           month == a && day == b && year % 100 == c || // 月日年
           day == a && month == b && year % 100 == c)   // 日月年
           printf("%d-%02d-%02d\n", year, month, day);
    }
    
    return 0;
}