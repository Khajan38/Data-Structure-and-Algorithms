#include <iostream>
#include <memory>
using namespace std;

//Merge Sorted Arrays -> Time : O(max(n1, n2)), Space : O(n1+n2)
//Merging is process of combining 2 sorted arrays into one with no elements repeating
int * Merge_Array (const int arr1[], const int arr2[], int n1, int n2){
     int * arr {new int [n1 + n2]};
     int i = 0, j = 0, k = 0;
     for (; i < n1 && j < n2;){
          if(arr1[i] < arr2[j]) arr[k++] = arr1[i++];
          else if (arr1[i] > arr2[j]) arr[k++] = arr2[j++];
          else {arr[k++] = arr1[i++]; j++;}
     }
     for (; i < n1; i++, k++) arr[k] = arr1[i];
     for (; j < n2; j++, k++) arr[k] = arr2[j];
     //Can also resize the array
     int * resized_arr {new int [k]};
     for (int t = 0; t < k; t++) resized_arr[t] = arr[t];
     delete [] arr;
     return resized_arr;
}

//Merge Arrays -> Time : O(max(n1, n2)), Space : O(n1+n2)
//In this Indv. arrays can be unsorted and final arrays typically contains all elements
int * Merge_Array (const int arr1[], const int arr2[], int n1, int n2){
     int * arr {new int [n1 + n2]}, size = (n1 > n2)? n1 : n2;
     for (int i = 0; i < size; i++) {
          if (i < n1) arr[i] = arr1[i];
          if (i < n2) arr[n1+i] = arr2[i];
     }
     return arr;
}

//Copy Arrays -> Time : O(n), Space : O(n)
int * Copy_Array (const int arr[], int n){
     int * carr {new int [n]};
     for (int i = 0; i < n; i++) carr[i] = arr[i];
     return carr;
}

//Compare Arrays -> Time : O(n), Space : O(n)
bool Compare_Array (const int arr1[], const int arr2[], int n1, int n2){
     if (n1 != n2) return false;
     for (int i = 0; i < n1; i++) 
          if (arr1[i] != arr2[i]) return false;
     return true;
}

int main(){
     int n1, n2;
     cout<<"\nEnter no. of elements in Array 1 : "; cin>>n1;
     cout<<"Enter no. of elements in Array 2 : "; cin>>n2;
     int arr1[n1], arr2[n2];
     cout<<"Enter the elements in Array 1: ";
     for (int i = 0; i < n1; i++) cin>>*(arr1+i);
     cout<<"Enter the elements in Array 2: ";
     for (int i = 0; i < n2; i++) cin>>*(arr2+i);
     int * arr = Copy_Array(arr1, n1);
     cout<<"\nCopied Array : ";
     for (int i = 0; i < n1; i++) cout<<arr[i]<<" "; cout<<endl;
     delete[] arr;
     if (Compare_Array(arr1, arr2, n1, n2)) cout<<"\nArray 1 and 2 are equal..."<<endl;
     else cout<<"\nArray 1 and 2 are not equal..."<<endl;
     delete[] arr;
     arr = Merge_Array(arr1, arr2, n1, n2);
     cout<<"\nMerged Array : ";
     for (int i = 0; i < n1 + n2; i++) cout<<arr[i]<<" "; cout<<endl;
     delete[] arr;
     return 0;
}