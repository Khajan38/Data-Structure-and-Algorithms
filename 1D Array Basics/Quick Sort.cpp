#include <iostream>
using namespace std;

//Quick Sort -> Time : θ(n*log(n)), O(n^2), Space : O(log(n))
void swap (int * i, int * j){
     int temp = *i;
     *i = *j;
     *j = temp;
}
int partition (int * arr, int start, int end){
     int pivot = arr[end];
     int i = start;
     for (int j = end - 1; i <= j; ){
          if (arr[i] < pivot) {i++; continue;}
          if (arr[j] > pivot) {j--; continue;}
          swap(&arr[i++], &arr[j--]);
     }
     swap(&arr[end], &arr[i]);
     return i;
}

void Quick_Sort (int * arr, int start, int end){
     if (start >= end) return;
     int pivot = partition(arr, start, end);
     Quick_Sort(arr, start, pivot - 1);
     Quick_Sort(arr, pivot + 1, end);
}

int main(){
     int n;
     cout<<"\nEnter no. of elements in Array : "; cin>>n;
     int arr[n];
     cout<<"Enter the elements in Array : ";
     for (int i = 0; i < n; i++) cin>>*(arr+i);
     Quick_Sort(arr, 0, n - 1);
     cout<<"\nArray : "; for (int i = 0; i < n; i++) cout<<arr[i]<<" "; cout<<endl;
     return 0;
}