#include <iostream>
#include <array>
using namespace std;

//Subarrays -> Time : O(n), Space : O(1)
void subarrays (array <int, 3> arr){
     int size = arr.size();
     cout<<"\nSubarrays : "; 
     //The total number of subarrays is size * (size + 1) / 2
     for (int i = 0; i < size; i++){
          for (int j = i; j < size; j++){
               cout<<"\n[";
               for (int k = i; k <= j; k++)
                    cout<<arr[k]<<", ";
               cout<<"\b\b]";
          }
     }
}

int main(){
     array <int, 3> arr {12, 34, 53};
     subarrays(arr);
     return 0;
}