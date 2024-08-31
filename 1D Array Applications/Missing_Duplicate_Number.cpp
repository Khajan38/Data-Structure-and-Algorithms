#include <iostream>
#include <vector>
using namespace std;

//Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

//Sum of Natural Numbers -> Time : O(n), Space : O(1)
int missingNumber(vector<int>& nums) {
     int size = nums.size(), asum = size * (size + 1)/2, fsum = 0;
     for (int i = 0; i < size; i++)
          fsum += nums[i];
     return asum - fsum;
}

//Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

//XOR Implementation -> Time : O(n), Space : O(1)
int singleNumber(vector<int>& nums) {
     long long alone {nums[0]};
     unsigned long size {nums.size()};
     for (unsigned long i = 1; i < size; i++)
          alone ^= nums[i];
     return alone;
}

int main(){
     vector <int> nums {0, 2, 3, 4, 7, 1, 5};
     cout<<missingNumber(nums);
     nums = {4,1,2,1,2};
     cout<<singleNumber(nums);
     return 0;
}