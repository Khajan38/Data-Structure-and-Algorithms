#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Brute Force -> Time : O(nlog(n)), Space : O(1)
//Sort the array and find n/2 element
int MajorityElement_1(vector<int>& nums){
     int size = nums.size();
     sort(nums.begin(), nums.end());
     return nums[size/2];
}

//Hashing -> Time : O(n), Space : O(n)
int majorityElement_2(vector<int>& nums){
     int size = nums.size(), count = 1, element = nums[0];
     for (int i = 1; i < size; i++){
          if (count == 0)element = nums[i];
          if (nums[i] == element) count++;
          else count--;
     }
     return element;
}

//Moorey's Voting Algorithm -> Time : O(n), Space : O(1)
int MajorityElement_3(vector<int>& nums){
     int size = nums.size(), count = 1, element = nums[0];
     for (int i = 1; i < size; i++){
          if (count == 0)element = nums[i];
          if (nums[i] == element) count++;
          else count--;
     }
     return element;
}

int main(){
     vector <int> nums {2,2,1,1,1,2,2};
     cout<<"\nMajority Element : "<<MajorityElement_3(nums)<<endl;
     return 0;
}