#include <iostream>
#include <vector>
using namespace std;

//Brute Force -> Time : O(nlog(n)), Space : O(1)
//Use Quick Sort or Merge Sort

//Two Pointer -> Time : O(n), Space : O(1)
void SortColors_1(vector<int>& nums) {
     int size = nums.size();
     int i {0}, j {size - 1};
     while (i <= j){
          if (nums[i] < 2) {i++; continue;}
          if (nums[j] == 2) {j--; continue;}
          swap(nums[i++], nums[j--]);
     }
     j = i - 1; i = 0;
     while (i <= j){
          if (nums[i] == 0) {i++; continue;}
          if (nums[j] == 1) {j--; continue;}
          swap(nums[i++], nums[j--]);
     }
}

//Dutch National Flag Algorithm -> Time : O(n), Space : O(1)
//Uses 3 pointers to seperate the colours where k moves between i and j pointers and sorts array
void SortColors_2(vector<int>& nums) {
     int size = nums.size();
     int i {0}, j {size - 1}, k {0};
     while (k <= j){
          if (nums[k] == 0) swap(nums[i++], nums[k++]);
          else if (nums[k] == 1) k++;
          else swap(nums[k], nums[j--]);
     }
}

int main(){
     vector <int> nums {1, 2, 1, 0, 0, 1, 2, 0}; int size = nums.size();
     SortColors_2(nums);
     cout<<"\nArray : "; for(int i = 0; i < size; i++) cout<<nums[i]<<" "; cout<<endl;
     return 0;
}