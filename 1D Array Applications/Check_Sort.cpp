#include <iostream>
using namespace std;

//Check Sorted -> Time : O(n), Space : O(1)
bool Check_Sorted (int arr[], int n){
     for (int i = 0; i < n - 1; i++)
          if (arr[i] > arr[i+1]) return false;
     return true;
}

//All Negatives Left -> Time : O(n), Space : O(1)
void negativeleft_1 (int arr[], int n){
     int count = 0;
     for (int i = 0; i < n; i++)
          if (arr[i] < 0){
               int temp = arr[i];
               arr[i] = arr[count];
               arr[count++] = temp;
          }
     return;
}

//All Negatives Left : Two Pointer Method -> Time : O(n), Space : O(1)
void negativeleft_2 (int arr[], int n){
     int front = 0, end = n - 1;
     for(front, end; front < end; ){
          if (arr[front] < 0) front++;
          if (arr[end] > 0) end--;
          if (arr[front] > 0 && arr[end] < 0) swap(arr[front], arr[end]);
     }
}

int main(){
     int n; 
     cout<<"\nEnter no. of elements : "; cin>>n;
     int arr[n]; cout<<"Enter the elements : ";
     for (int i = 0; i < n; i++) cin>>*(arr+i);
     if (Check_Sorted(arr, n)) cout<<"Array is Sorted..."<<endl;
     else cout<<"Array is not sorted..."<<endl;
     negativeleft_2(arr, n);
     cout<<"Array : ";
     for (int i = 0; i < n; i++) cout<<arr[i]<<" "; cout<<endl;
     return 0;
}