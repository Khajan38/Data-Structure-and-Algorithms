#include <iostream>
#include <vector>
using namespace std;

//Brute Force -> Time : O(n^3), Space : O(1)
int longSubarray_1 (vector <int> nums, int sum){
     int  length {-1}, index {-1}, size = nums.size();
     for (int i = 0; i < size; i++)
          for (int j = i; j < size; j++){
               int temp_sum = 0;
               for (int k = i; k <= j; k++)
                    temp_sum += nums[k];
               if (temp_sum == sum) {
                    int temp_length = j - i + 1;
                    if (length < temp_length){length = temp_length; index = i;}
               }
          }
     if (length != -1)
          cout<<"\nSubarray : "; for(int i = 0; i < length; i++) cout<<nums[index+i]<<" ";
     cout<<endl;
     return length;
}

//Brute Force Optimized -> Time : O(n^2), Space : O(1)
int longSubarray_2 (vector <int> nums, int sum){
     int  length {-1}, index {-1}, size = nums.size();
     for (int i = 0; i < size; i++){
          int temp_sum = 0;
          for (int j = i; j < size; j++){
               temp_sum += nums[j];
               if (temp_sum == sum) {
                    int temp_length = j - i + 1;
                    if (length < temp_length){length = temp_length; index = i;}
               }
          }
     }
     if (length != -1)
          cout<<"\nSubarray : "; for(int i = 0; i < length; i++) cout<<nums[index+i]<<" ";
     cout<<endl;
     return length;
}

//Hashing -> Time : O(n), Space : O(n)


int main(){
     vector <int> nums {10, 5, 2, 7, 1, 9};
     int k = 15;
     cout<<longSubarray_2(nums, k)<<" is the length of the substring..."<<endl;
     return 0;
}