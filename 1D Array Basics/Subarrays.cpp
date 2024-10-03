#include <iostream>
#include <array>
using namespace std;

//Subarrays are continuous portions of an array that are taken indeoendently. These are different from subsets or subsequences as these contains contiguous elements of an array.

//Subarrays -> Time : O(n), Space : O(1)
void subarrays (array <int, 3> arr){
     int size = arr.size();
     cout<<"\nSubarrays : "; 
     //The total number of subarrays is size * (size + 1) / 2
     for (int i = 0; i < size; i++){ //For defining start of subarray
          for (int j = i; j < size; j++){ //For defining end of the subarray
               cout<<"\n[";
               for (int k = i; k <= j; k++) //For iterating through i->j of current subarray defined
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