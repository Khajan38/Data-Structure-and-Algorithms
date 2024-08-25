#include <iostream>
using namespace std;

//Merge Sort -> Time : O(nlog(n)), Space : O(n + log(n))
void Merge (int * arr, int start, int pivot, int end){
     int temp_arr[end - start + 1];
     for (int i = 0; i < end - start + 1; i++)
          temp_arr[i] = arr[start + i];
     int i = 0, j = pivot - start + 1, k = start; 
     while (i <= pivot - start && j <= end - start) 
          if (temp_arr[i] <= temp_arr[j]) arr[k++] = temp_arr[i++];
          else if (temp_arr[i] > temp_arr[j]) arr[k++] = temp_arr[j++];
     while (i <= pivot - start) arr[k++] = temp_arr[i++];
     while (j <= end - start) arr[k++] = temp_arr[j++];
}
void Merge_Sort (int * arr, int start, int end){
     if (start >= end) return;
     int mid = (start + end)/2;
     Merge_Sort(arr, start, mid);
     Merge_Sort(arr, mid + 1, end);
     Merge(arr, start, mid, end);
}

int main(){
     int n;
     cout<<"\nEnter no. of elements in Array : "; cin>>n;
     int arr[n];
     cout<<"Enter the elements in Array : ";
     for (int i = 0; i < n; i++) cin>>*(arr+i);
     Merge_Sort(arr, 0, n - 1);
     cout<<"\nArray : "; for (int i = 0; i < n; i++) cout<<arr[i]<<" "; cout<<endl;
     return 0;
}