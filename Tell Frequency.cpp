#include <iostream>
#include <memory>
#include <map>
using namespace std;

//Brute Force Approach -> Time : O(n*q), Space : O(q)
int * frequency_1 (int arr[], int queries[], int n, int q){
     int * frequencies = new (int [q]) {0};
     for (int i = 0; i < q; i++)
          for (int j = 0; j < n; j++)
               if (arr[j] == queries[i]) frequencies[i]++;
     return frequencies;
}

//Array Hashing -> Time : O(n), Space : O(n)
int * frequency_2 (int arr[], int queries[], int n, int q){
     int * frequencies = new (int [q]) {0};
     int hash [n] = {0};
     for (int i = 0; i < n; i++)
          hash[arr[i]]++;
     for (int i = 0; i < q; i++)
          frequencies[i] = hash[queries[i]];
     return frequencies;
}

//Map Hashing -> Time : O(n+q), Space : O(q)
int * frequency_3 (int arr[], int queries[], int n, int q){
     int * frequencies = new (int [q]) {0};
     map <int, int> hash {};
     for (int i = 0; i < n; i++)
          hash[arr[i]]++;
     for (int i = 0; i < q; i++)
          frequencies[i] = hash[queries[i]];
     return frequencies;
}

int main(){
     int n, q;
     cout<<"\nEnter no. of elements : "; cin>>n;
     int arr[n];
     cout<<"Enter Array Elements : "; for (int i = 0; i < n; i++) cin>>arr[i];
     cout<<"\nEnter no. of queries : "; cin>>q;
     int queries[q];
     cout<<"Enter Queries : "; for (int i = 0; i < q; i++) cin>>queries[i];
     int * frequencies = frequency_3(arr, queries, n, q);
     cout<<"\nFrequencies : "; 
     for(int i = 0; i < q; i++) cout<<queries[i]<<" -> "<<frequencies[i]<<"   "; cout<<endl;
     delete [] frequencies;
     return 0;
}