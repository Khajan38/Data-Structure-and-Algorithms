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

int main(){
     vector <int> nums {0, 2, 3, 4, 7, 1, 5};
     cout<<missingNumber(nums);
     return 0;
}