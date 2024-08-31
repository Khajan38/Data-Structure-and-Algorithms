#include <iostream>
using namespace std;

//Brute Force -> Time: O(n*pivot), Space : O(1)
void Rotation_1 (int * arr, int n, int pivot, int direction){
     pivot = pivot % n; // Normalize pivot to be within array bounds
     if (pivot == 0) return; // No rotation needed if pivot is 0
     if (direction == 1) pivot = n - pivot + 2;
     for (int i = 0; i < pivot - 1; i++){
          int temp = arr[0];
          for (int j = 0; j < n - 1; j++)
               arr[j] = arr[j + 1];
          arr[n-1] = temp;
     }
}

//Alternate Array -> Time: O(n), Space : O(n)
void Rotation_2 (int * arr, int n, int pivot, int direction){
     pivot = pivot % n; // Normalize pivot to be within array bounds
     if (pivot == 0) return; // No rotation needed if pivot is 0
     int * new_arr = new int [n];
     if (direction == 1) pivot = n - pivot + 2;
     for (int i = 0; i < n; i++) new_arr[i] = arr[i];
     for (int i = 0; i < n; i++){
          if (i <= n - pivot) arr[i] = new_arr[pivot + i - 1];
          else arr[i] = new_arr[i - n + pivot - 1];
     }
     delete [] new_arr;
}

//Reversal Method -> Time: O(n), Space : O(1)
void Reversal (int * arr, int front, int end){
     for (int i = front, j = end; i < j; i++, j--){
          int temp = arr[j];
          arr[j] = arr[i];
          arr[i] = temp;
     }
}
void Rotation_3 (int * arr, int n, int pivot, int direction){
     pivot = pivot % n; // Normalize pivot to be within array bounds
     if (pivot == 0) return; // No rotation needed if pivot is 0
     if (direction == 1) pivot = n - pivot + 2;
     Reversal(arr, 0, pivot - 2);
     Reversal(arr, pivot - 1, n - 1);
     Reversal(arr, 0, n - 1);
}

int main(){
     int n;
     cout<<"\nEnter no. of elements in Array : "; cin>>n;
     int arr[n];
     cout<<"Enter the elements in Array : ";
     for (int i = 0; i < n; i++) cin>>*(arr+i);
     Rotation_3(arr, n, 8, -1);
     cout<<"\nArray : "; for (int i = 0; i < n; i++) cout<<arr[i]<<" "; cout<<endl;
     Rotation_3(arr, n, 8, 1);
     cout<<"\nArray : "; for (int i = 0; i < n; i++) cout<<arr[i]<<" "; cout<<endl;
     return 0;
}