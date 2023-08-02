// Hanks ��ʿ�� BT��Bio-Tech�����＼���������֪��ר�ң����Ķ������� Hankson��

// ���ڣ��ոշ�ѧ�ؼҵ� Hankson ����˼��һ����Ȥ�����⡣

// �����ڿ����ϣ���ʦ��������������������� c1
//  �� c2
//  �����Լ������С��������

// ���� Hankson ��Ϊ�Լ��Ѿ���������������Щ֪ʶ������ʼ˼��һ������Լ�����͡��󹫱�����֮������ġ������⡱����������������ģ�

// ��֪������ a0,a1,b0,b1
// ����ĳδ֪������ x
//  ���㣺

// x
//  �� a0
//  �����Լ���� a1
// ��
// x
//  �� b0
//  ����С�������� b1
// ��
// Hankson �ġ������⡱����������������������� x
// ��

// ���Լ�˼��֮�������������� x
//  ����Ψһ���������ܲ����ڡ�

// �����ת����ʼ�������������������� x
//  �ĸ�����

// ���������������������⡣

// �����ʽ
// �����һ��Ϊһ�������� n
// ����ʾ�� n
//  ���������ݡ�

// �������� n
//  ��ÿ��һ���������ݣ�Ϊ�ĸ������� a0��a1��b0��b1
// ��ÿ��������֮����һ���ո������

// �������ݱ�֤ a0
//  �ܱ� a1
//  ������b1
//  �ܱ� b0
//  ������

// �����ʽ
// ����� n
//  �С�

// ÿ���������ݵ�������ռһ�У�Ϊһ��������

// ����ÿ�����ݣ��������������� x
// ������� 0
// ��

// ������������ x
// ����������������� x
//  �ĸ�����

// ���ݷ�Χ
// 1��n��2000
// ,
// 1��a0,a1,b0,b1��2?109
// ����������
// 2
// 41 1 96 288
// 95 1 37 1776
// ���������
// 6
// 2

/*
�ȳ�ʼ��������Ȼ��d�ֽ���������p1^c1 + p2^c2 + ... + pn^cn ����ʽ��Ȼ��ʹ��dfs�����е�Լ����������һ�������У�
a��x�����Լ����b��c��x����С��������d����ôֻ��Ҫ���� gcd(a, x) == b && c * x / gcd(c, x) == d ���������˵��x�����������Ҫ��ģ�res++
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 50010;
int primes[N], cnt;
bool st[N];
struct Factor{
    int p, s;
}factor[1601];
int fcnt;
int dividor[N], dcnt;
int n;

void init(int n){
    for(int i = 2; i <= n; i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j = 0; primes[j] * i <= n; j++){
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

void dfs(int u, int p){
    if(u == fcnt){
        dividor[dcnt++] = p;
        return;
    }
    for(int i = 0; i <= factor[u].s; i++){
        dfs(u + 1, p);
        p *= factor[u].p;
    }
}

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    init(N - 1);
    
    cin >> n;
    while(n--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        fcnt = 0;
        int t = d;
        for(int i = 0; primes[i] <= t / primes[i]; i++){
            int p = primes[i];
            if(t % p == 0){
                int s = 0;
                while(t % p == 0) t /= p, s++;
                factor[fcnt++] = {p, s};
            }
        }
        
        if(t > 1) factor[fcnt++] = {t, 1};
        
        dcnt = 0;
        dfs(0, 1);
        
        int res = 0;
        for(int i = 0; i < dcnt; i++){
            int x = dividor[i];
            if(gcd(a, x) == b && (LL)c * x / gcd(c, x) == d) res++;
        }
        cout << res << endl;
    }
    
    
    return 0;
}