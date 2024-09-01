#include <iostream>
#include <vector>
#include <unordered_map>
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
int longSubarray_3 (vector <int> nums, int sum){
     unordered_map <int, int> hash; int size = nums.size();
     int tsum {0}, length{0}, index {-1};
     for (int i = 0; i < size; i++){
          tsum += nums[i];
          if (hash.find(tsum) == hash.end()) hash [tsum] = i;
          if (tsum == sum) {length = i + 1; index = 0;}
          else if (hash.find(tsum - sum) != hash.end()) {
               length = max(length, i - hash[tsum - sum]); 
               if (length == i - hash[tsum - sum]) index = hash[tsum - sum] + 1;}
     }
     cout<<"\nHash Map : ";for (pair i : hash) cout<<i.first<<":"<<i.second<<" ";
     if (length != 0)
          cout<<"\nSubarray : "; for(int i = 0; i < length; i++) cout<<nums[index+i]<<" ";
     cout<<endl;
     return length;
}

//Two Pointer Approach -> Time : O(n), Space : O(1)
//Used only when all elements are non negative
int longSubarray_4 (vector <int> nums, int sum){
     int size = nums.size(), tsum {0}, length{0}, index {0};
     int i = 0, j = 0;
     while (i < size && j < size){
          tsum += nums[i];
          while (tsum > sum && j <= i) {tsum -= nums[j]; j++; continue;}
          if (tsum == sum){
               if(length < (i - j + 1)) {length = i - j + 1; index = j;}}
          i++;
     }
     if (length != 0)
          cout<<"\nSubarray : "; for(int i = 0; i < length; i++) cout<<nums[index+i]<<" ";
     cout<<endl;
     return length;
}

int main(){
     vector <int> nums {10, 5, 2, 7, 1, 2};
     int k = 15;
     cout<<longSubarray_1(nums, k)<<" is the length of the substring..."<<endl;
     cout<<longSubarray_2(nums, k)<<" is the length of the substring..."<<endl;
     cout<<longSubarray_3(nums, k)<<" is the length of the substring..."<<endl;
     cout<<longSubarray_4(nums, k)<<" is the length of the substring..."<<endl;
     return 0;
}