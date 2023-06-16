#include<iostream>
#include<cstring>
using namespace std;

void ShellSort(int r[], int n){
  int i, j, d, tmp;
  d = n / 2;
  while(d > 0){
    for(i = d; i < n ;i++){
      tmp = r[i];
      j = i - d;
      while(j >= 0 && tmp < r[j]){
        r[j + d] = r[j];
        j -= d;
      }
      r[j + d] = tmp;
    }
    d /= 2;
  }
}

int Partition(int r[], int s, int t){
  int i = s, j = t;
  int base = r[i];
  while(i < j){
    while(j > i && r[j] >= base) j--;
    if(i < j){
      r[i] = r[j];
      i++;
    }
    while(i < j && r[i] < base) i++;
    if(i < j){
      r[j] = r[i];
      j--;
    }
  }
  r[i] = base;
  return i;
}

void QuickSort(int r[], int s, int t){
	if (s < t){
		int pivot = Partition(r, s, t);
		QuickSort(r, s, pivot - 1); 
		QuickSort(r, pivot + 1, t);   
	}
}

void Print(int a[], int n){
  for(int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}

int main() {
  int n = 10;
	int a1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int a2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int a3[] = {6, 3, 9, 5, 8, 1, 2, 7, 0, 4};
	int b1[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int b3[] = {6, 3, 9, 5, 8, 1, 2, 7, 0, 4};
	puts("原始数组: ");
	Print(a1, n);
	Print(a2, n);
	Print(a3, n);

	cout << "经过希尔排序："<<endl;
  ShellSort(a1, n);
	ShellSort(a2, n);
	ShellSort(a3, n);
	Print(a1, n);
	Print(a2, n);
	Print(a3, n);

	cout << "经过快速排序："<<endl;
  QuickSort(b1, 0, n - 1);
	QuickSort(b2, 0, n - 1);
	QuickSort(b3, 0, n - 1);
	Print(b1, n);
	Print(b2, n);
	Print(b3, n);

  return 0;
}