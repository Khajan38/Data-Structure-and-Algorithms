#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void swaps(int &a, int &b){if (a == b) return; a^=b; b^=a; a^=b;}
int partition (vector <int> & nums, int start, int end){
     int pivot = nums[end];
     int i = start, j = end - 1;
     while (i <= j){
          if (nums[i] < pivot) {i++; continue;}
          if (nums[j] > pivot) {j--; continue;}
          swaps(nums[i++], nums[j--]);
     }
     swaps(nums[i], nums[end]);
     return i;
}
void QuickSort (vector <int> &nums, int start, int end){
     if (start >= end) return;
     int pivot = partition(nums, start, end);
     QuickSort(nums, start, pivot - 1);
     QuickSort(nums, pivot + 1, end);
}

//Brute Force -> Time : O(n^2), Space : O(1)
vector<int> TwoSum_1(vector<int>& nums, int target) {
     int size = nums.size(), comp = target - nums[0];
     for (int i = 0, j = size - 1; i < size && j >= i; j--){
          if (j == i) {j = size - 1; i++; comp = target - nums[i];}
          if (nums[j] == comp) return {i, j};
     }
     return {};
}

//Hashing -> Time : O(n), Space : O(n)
vector<int> TwoSum_2 (vector<int>& nums, int target) {
     int size = nums.size();
     unordered_map <int, int> hash;
     for (int i = 0; i < size; i++){
          int comp = target - nums[i];
          unordered_map <int, int> ::iterator itr = hash.find(comp);
          if (itr != hash.end()) return{itr->second, i};
          hash[nums[i]] = i;
     }
     return {};
}

//Two Pointer -> Time : O(nlog(n)), Space : O(1)
//Can give only elements since index are changed after sorting
vector<int> TwoSum_3 (vector<int>& nums, int target) {
     int size = nums.size();
     QuickSort(nums, 0, size - 1);
     for (int i = 0, j = size - 1; j >= i;){
          int tsum = nums[i] + nums[j];
          if (tsum == target) return {nums[i], nums[j]};
          else if (tsum < target) i++;
          else j--;
     }
     return {};
}

int main(){
     vector <int> nums {7, 2, 6, 0, 1, 5, 2}; int size = nums.size();
     cout<<"\nArray  : ["; for (int i = 0; i < size; i++) cout<<nums[i]<<", "; cout<<"\b\b]"<<endl;
     vector <int> twoSum = TwoSum_1(nums, 7);
     cout<<"Elements : "<<nums[twoSum[0]]<<", "<<nums[twoSum[1]]<<endl;
     twoSum = TwoSum_2(nums, 7);
     cout<<"Elements : "<<nums[twoSum[0]]<<", "<<nums[twoSum[1]]<<endl;
     twoSum = TwoSum_3(nums, 7);
     cout<<"Elements : "<<twoSum[0]<<", "<<twoSum[1]<<endl;
     return 0;
}