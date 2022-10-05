#include<iostream>
using namespace std;
#include<ctime>
#include<stack>

// 打印数组
void PrintArray(int* arr, int n){
  for(int i = 0; i < n; i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

// 直接插入排序
void InsertSort(int* arr, int n){
  // i最大是倒数第二个数的下标
  for(int i = 0; i < n - 1; i++){
    int end = i;
    int tmp = arr[end + 1];
    while(end >= 0){
      // 如果arr[end]的值比tmp大，让它后移一位
      if(arr[end] > tmp){
        arr[end + 1] = arr[end];
        end--;
      }else{
        // 如果arr[end]的值比tmp小，跳出循环
        break;
      }
    }
    // 让end+1上面的值变为tmp
    arr[end + 1] = tmp;
  }
}

// 希尔排序
void ShellSort(int* arr, int n){
  int gap = n;

  while(gap > 1){

    // gap > 1 都是预排，让他的顺序接近有序
    // gap = 1 时，实质上就是直接插入排序
    // gap /= 2;
    gap = gap / 3 + 1; // 要让最后一次排序的时候gap为1

    for(int i = 0; i < n - gap; i++){
      int end = i;
      int tmp = arr[end + gap];
      while(end >= 0){
        if(arr[end] > tmp){
          arr[end + gap] = arr[end];
          end -= gap;
        }else{
          break;
        }
      }
      arr[end + gap] = tmp;
    }
  }

}

// 向下调整算法
void AdjustDown(int* arr, int n, int root){
  // 默认左子节点为孩子
  int parent = root;
  int child = parent * 2 + 1;
  // 如果child比数组的长度小，就可以向下调整
  while(child < n){
    // 如果右子节点的数小于左子节点的数，让child++，但是前提必须有右子节点
    if(child + 1 < n && arr[child + 1] < arr[child]){
      child++;
    }
    if(arr[child] < arr[parent]){
      // 如果子节点的数比父节点小，让他们交换
      swap(arr[child], arr[parent]);
      // 让原来的子节点变成父节点，继续向下调整
      parent = child;
      child = parent * 2 + 1;
    }else{
      // 如果子节点的数大于父节点的数，跳出循环
      break;
    }
  }
}

// 堆排序
void HeapSort(int* arr, int n){
  // leftChild = parent * 2 + 1
  // rightChild = parent * 2 + 1
  for(int i = (n - 1 - 1) / 2; i >= 0; i--){
    AdjustDown(arr, n, i);
  }

  // int end = n - 1;
  // while(end > 0){
  //   swap(arr[0], arr[end]);
  //   AdjustDown(arr, end, 0);
  //   end--;
  // }
}

// 直接选择排序
void SelectSort(int * arr, int n){
  // for(int i = 0; i < n; i++){
  //   int min = i;
  //   for(int j = i + 1; j < n; j++){
  //     if(arr[j] < arr[min]){
  //       min = j;
  //     }
  //   }
  //   swap(arr[i], arr[min]);
  // }

  int begin = 0, end = n - 1;
  while(begin < end){
    int minIndex = begin, maxIndex = begin;
    for(int i = begin; i <= end; i++){
      if(arr[i] < arr[minIndex]){
        minIndex = i;
      }
      if(arr[i] > arr[maxIndex]){
        maxIndex = i;
      }
    }
    
    swap(arr[begin], arr[minIndex]);
    if(maxIndex == begin){
      maxIndex = minIndex;
    }
    swap(arr[end], arr[maxIndex]);
    begin++;
    end--;
  }
}

// 冒泡排序
void BubbleSort(int* arr, int n){
  // for(int i = 0; i < n - 1; i++){
  //   for(int j = 0; j < n - 1 - i; j++){
  //     if(arr[j] > arr[j + 1]){
  //       swap(arr[j], arr[j + 1]);
  //     }
  //   }
  // }

  for(int i = 0; i < n; i++){
    bool isChange = false;
    for(int j = 1; j < n - i; j++){
      if(arr[j - 1] > arr[j]){
        swap(arr[j - 1], arr[j]);
        isChange = true;
      }
    }
    if(!isChange){
      break;
    }
  }
}

// 三数取中
int GetMidIndex(int* arr, int left, int right){
  int mid = (left + right) >> 2;
  if(arr[left] < arr[mid]){
    if(arr[mid] < arr[right]){
      return mid;
    }else if(arr[left] > arr[right]){
      return left;
    }else{
      return right;
    }
  }else{
    // arr[mid] <= arr[left]
    if(arr[left] < arr[right]){
      return left;
    }else if(arr[right] < arr[mid]){
      return mid;
    }else{
      return right;
    }
  }
}

// 快速排序——挖坑法
int PartSort1(int* arr, int left, int right){

  int index = GetMidIndex(arr, left, right);
  swap(arr[left], arr[index]);
  
  int begin = left, end = right;
  int pivot = begin;
  int key = arr[pivot];
  while(begin < end){
    // 右边找小
    while(begin < end && arr[end] >= key){
      end--;
    }
    // 把小的放到坑位，自己形成坑
    arr[pivot] = arr[end];
    pivot = end;

    // 左边找大
    while(begin < end && arr[begin] <= key){
      begin++;
    }
    // 把大的放到坑位，自己形成坑
    arr[pivot] = arr[begin];
    pivot = begin;
  }
  pivot = begin;
  arr[pivot] = key;

  return pivot;
}

// 快速排序——左右指针法
int PartSort2(int* arr,int left, int right){

  int index = GetMidIndex(arr, left, right);
  swap(arr[left], arr[index]);

  int begin = left, end = right;
  int keyi = begin;

  while(begin < end){
    while(begin < end && arr[end] >= arr[keyi]){
      end--;
    }
    while(begin < end && arr[begin] <= arr[keyi]){
      begin++;
    }
    swap(arr[begin], arr[end]);
  }
  swap(arr[keyi], arr[begin]);

  return begin;
}

// 快速排序——前后指针法
int PartSort3(int* arr, int left, int right){

  int index = GetMidIndex(arr, left, right);
  swap(arr[left], arr[index]);

  int keyi = left;
  int prev = left;
  int cur = prev + 1;
  while(cur <= right){
    // if(arr[cur] < arr[keyi]){
    //   prev++;
    //   swap(arr[prev], arr[cur]);
    // }
    if(arr[cur] < arr[keyi] && ++prev != cur){
      swap(arr[prev], arr[cur]);
    }
    cur++;
  }
  swap(arr[keyi], arr[prev]);

  return prev;
}

// 快速排序
void QuickSort(int* arr, int left, int right){

  if(left >= right){
    return;
  }
  
  // int keyIndex = PartSort1(arr, left, right);
  // int keyIndex = PartSort2(arr, left, right);
  int keyIndex = PartSort3(arr, left, right);

  // 此时数组被分成了 [begin, pivot - 1] pivot [pivot + 1, right]
  // QuickSort(arr, left, keyIndex - 1);
  // QuickSort(arr, keyIndex + 1, right);

  // 小区间优化
  if(keyIndex - 1 - left > 10){
    QuickSort(arr, left, keyIndex - 1);
  }else{
    InsertSort(arr + left, keyIndex - 1 - left + 1);
  }
  if(right - ( keyIndex + 1 ) > 10){
    QuickSort(arr, keyIndex + 1, right);
  }else{
    InsertSort(arr + keyIndex + 1, right - ( keyIndex + 1 ) + 1);
  }
}

void _MergeSort(int* arr, int left, int right, int* tmp){
  if(left >= right){
    return;
  }

  int mid = (left + right) >> 1;

  _MergeSort(arr, left, mid, tmp);
  _MergeSort(arr, mid + 1, right, tmp);

  int begin1 = left, end1 = mid;
  int begin2 = mid + 1, end2 = right;
  int index = left;

  while(begin1 <= end1 && begin2 <= end2){
    if(arr[begin1] < arr[begin2]){
      tmp[index++] = arr[begin1++];
    }else{
      tmp[index++] = arr[begin2++];
    }
  }

  while(begin1 <= end1){
    tmp[index++] = arr[begin1++];
  }
  while(begin2 <= end2){
    tmp[index++] = arr[begin2++];
  }

  for(int i = left; i <= right; i++){
    arr[i] = tmp[i];
  }
}

// 归并排序
void MergeSort(int* arr, int n){
  int* tmp = (int*)malloc(sizeof(int) * n);

  _MergeSort(arr, 0, n, tmp);

  free(tmp);
}

// 快速排序非递归
void QuickSortNonR(int* arr, int n){
  stack<int> stk;

  stk.push(n - 1);
  stk.push(0);

  while(!stk.empty()){
    int left = stk.top();
    stk.pop();

    int right = stk.top();
    stk.pop();

    int keyIndex = PartSort1(arr, left, right);

    // 此时区间分成三部分 [left, keyIndex - 1] keyIndex [keyIndex + 1, right]
    if(right > keyIndex + 1){
      stk.push(right);
      stk.push(keyIndex + 1);
    }
    if(keyIndex - 1 > left){
      stk.push(keyIndex - 1);
      stk.push(left);
    }


  }
}

// 归并排序非递归
void MergeSortNonR(int* arr, int n){
  int* tmp = (int*)malloc(sizeof(int) * n);
  int gap = 1;
  while(gap < n){
    for(int i = 0; i < n; i += 2 * gap){
      // [i, i + gap - 1] [i + gap, i + 2 * gap - 1]
      int begin1 = i, end1 = i + gap - 1;
      int begin2 = i + gap, end2 = i + 2 * gap - 1;
      int index = i;

      // 如果第二组已经越界，则跳出循环
      if(begin2 >= n){
        break;
      }

      // 如果第二组长度不够，修正右边界
      if(end2 >= n){
        end2 = n - 1;
      }

      while(begin1 <= end1 && begin2 <= end2){
        if(arr[begin1] < arr[begin2]){
          tmp[index++] = arr[begin1++];
        }else{
          tmp[index++] = arr[begin2++];
        }
      }

      while(begin1 <= end1){
        tmp[index++] = arr[begin1++];
      }
      while(begin2 <= end2){
        tmp[index++] = arr[begin2++];
      }

      for(int j = i; j <= end2; j++){
        arr[j] = tmp[j];
      }
    }

    // for(int j = 0; j < n; j++){
    //   arr[j] = tmp[j];
    // }

    gap *= 2;
  }
  
}

void testOP(){
  srand((unsigned int)time(NULL));

  const int N = 1000000;

  int* a1 = (int*)malloc(sizeof(int) * N);
  int* a2 = (int*)malloc(sizeof(int) * N);
  int* a3 = (int*)malloc(sizeof(int) * N);
  int* a4 = (int*)malloc(sizeof(int) * N);
  int* a5 = (int*)malloc(sizeof(int) * N);
  int* a6 = (int*)malloc(sizeof(int) * N);
  int* a7 = (int*)malloc(sizeof(int) * N);

  for(int i = 0; i < N; i++){
    a1[i] = rand();
    a2[i] = a1[i];
    a3[i] = a1[i];
    a4[i] = a1[i];
    a5[i] = a1[i];
    a6[i] = a1[i];
    a7[i] = a1[i];
  }

  int begin1 = clock();
  // InsertSort(a1, N);
  int end1 = clock();

  int begin2 = clock();
  ShellSort(a2, N);
  int end2 = clock();

  int begin3 = clock();
  HeapSort(a3, N);
  int end3 = clock();

  int begin4 = clock();
  // SelectSort(a4, N);
  int end4 = clock();

  int begin5 = clock();
  // BubbleSort(a5, N);
  int end5 = clock();

  int begin6 = clock();
  QuickSort(a6, 0, N - 1);
  int end6 = clock();

  int begin7 = clock();
  QuickSort(a7, 0, N);
  int end7 = clock();

  cout << "InsertSort:" << end1 - begin1 << endl;
  cout << "ShellSort:" << end2 - begin2 << endl;
  cout << "HeapSort:" << end3 - begin3 << endl;
  cout << "SelectSort:" << end4 - begin4 << endl;
  cout << "BubbleSort:" << end5 - begin5 << endl;
  cout << "QuickSort:" << end6 - begin6 << endl;
  cout << "QuickSortNonR:" << end7 - begin7 << endl;


  free(a1);
  free(a2);
  free(a3);
  free(a4);
  free(a5);
  free(a6);
  free(a7);
}

void TestInsertSort(){
  int arr[] = { 4, 9, 2, 6, 1, 8, 7, 3, 5, 0 };
  InsertSort(arr, sizeof(arr) / sizeof(int));
  PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestShellSort(){
  int arr[] = { 4, 9, 2, 6, 1, 8, 7, 3, 5, 0 };
  ShellSort(arr, sizeof(arr) / sizeof(int));
  PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestHeapSort(){
  int arr[] = { 4, 9, 2, 6, 1, 8, 7, 3, 5, 0 };
  HeapSort(arr, sizeof(arr) / sizeof(int));
  PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestSelectSort(){
  int arr[] = { 4, 9, 2, 6, 1, 8, 7, 3, 5, 0 };
  SelectSort(arr, sizeof(arr) / sizeof(int));
  PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestBubbleSort(){
  int arr[] = { 4, 9, 2, 6, 1, 8, 7, 3, 5, 0 };
  BubbleSort(arr, sizeof(arr) / sizeof(int));
  PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestQuickSort(){
  int arr[] = { 4, 9, 2, 6, 1, 8, 7, 3, 5, 0 };
  QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
  PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestMergeSort(){
  int arr[] = { 4, 9, 2, 6, 1, 8, 7, 3, 5, 0 };
  MergeSort(arr, sizeof(arr) / sizeof(int) - 1);
  PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestQuickNonR(){
  int arr[] = { 4, 9, 2, 6, 1, 8, 7, 3, 5, 0 };
  QuickSortNonR(arr, sizeof(arr) / sizeof(int));
  PrintArray(arr, sizeof(arr) / sizeof(int));
}

void TestMergeSortNonR(){
  int arr[] = { 4, 9, 2, 6, 1, 8, 7, 3, 5, 0};
  MergeSortNonR(arr, sizeof(arr) / sizeof(int));
  PrintArray(arr, sizeof(arr) / sizeof(int));
}

int main(){

  // TestInsertSort();
  TestShellSort();
  // TestHeapSort();
  // TestSelectSort();
  // TestBubbleSort();
  // TestQuickSort();
  // TestMergeSort();
  // TestQuickNonR();
  // TestMergeSortNonR();

  // testOP();

  return 0;
}