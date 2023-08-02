// BSNY ��ѧ�Ȳ����к͵ȱ����У�����֪ǰ����ʱ���Ϳ���֪���ǵȲ����л��ǵȱ����С�

// ���ڸ��� ���� ���е�ǰ����������Ҫô�ǵȲ����У�Ҫô�ǵȱ����У���������� k
//  ���ֵ��

// ����� k
//  ���ֵ̫�󣬶���ȡģ 200907
// ��

// �����ʽ
// ��һ��һ������ T
// ����ʾ�� T
//  ��������ݣ�

// ����ÿ��������ݣ�����ǰ���� a,b,c
// ��Ȼ������ k
// ��

// �����ʽ
// ����ÿ�����ݣ������ k
//  ��ȡģ 200907
//  ��ֵ��

// ���ݷ�Χ
// 1��T��100
// ,
// 1��a��b��c��109
// ,
// 1��k��109
// ����������
// 2
// 1 2 3 5
// 1 2 4 5
// ���������
// 5
// 16

#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mod = 200907;

LL qmi(LL a, LL b){
    LL res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int a, b, c, k;
        cin >> a >> b >> c >> k;
        if(b - a == c - b){
            LL len = b - a;
            cout << (a + len % mod * (k - 1) % mod) % mod << endl;
        }else{
            int len = b / a;
            cout << (LL)a * qmi(len, k - 1) % mod << endl;
        }
    }
    
    return 0;
}