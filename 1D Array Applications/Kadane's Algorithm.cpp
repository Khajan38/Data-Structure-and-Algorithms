#include <iostream>
#include <vector>
using namespace std;

//Brute Force Approach -> Time : O(n^3), Space : O(1)
int maxSubarraySum_1(vector <int> &nums) {
     int maxi {INT_MIN}, size = nums.size();
     for (int i = 0; i < size; i++) 
          for (int j = i; j < size; j++) {
               int sum = 0;
               for (int k = i; k <= j; k++)
                    sum += nums[k];
               maxi = max(maxi, sum);
          }
     return maxi;
}

//Brute Force Approach Optimized-> Time : O(n^2), Space : O(1)
int maxSubarraySum_2(vector <int> &nums) {
     int maxi {INT_MIN}, size = nums.size();
     for (int i = 0; i < size; i++){
          int sum = 0;
          for (int j = i; j < size; j++){
               sum += nums[j];
               maxi = max(maxi, sum);
          }
     }
     return maxi;
}

//Kadane's Algorithm -> Time : O(n), Space : O(1)
int maxSubarraySum_3(vector<int>& nums) {
     int max_ending_here {nums[0]}, max_so_far {nums[0]}, size = nums.size();
     for (int i = 1; i < size; i++){
          max_ending_here = max(nums[i], max_ending_here + nums[i]);
          max_so_far = max(max_so_far, max_ending_here);
     }
     return max_so_far;
}

int main(){
     vector <int> nums {7, 2, -6, 0, 1, -5, 2}; int size = nums.size();
     cout<<"\nArray  : ["; for (int i = 0; i < size; i++) cout<<nums[i]<<", "; cout<<"\b\b]"<<endl;
     int maxSum = maxSubarraySum_1(nums);
     cout<<"Maximum Sum : "<<maxSum<<endl;
     maxSum = maxSubarraySum_2(nums);
     cout<<"Maximum Sum : "<<maxSum<<endl;
     maxSum = maxSubarraySum_3(nums);
     cout<<"Maximum Sum : "<<maxSum<<endl;
     return 0;
}