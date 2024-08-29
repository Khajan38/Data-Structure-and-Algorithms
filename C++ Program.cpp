#include <iostream>
#include <vector>
using namespace std;

void Subarray (vector <int> arr, int end = 0, int cur = 0, bool brk = false){
     if (cur == arr.size()) return;
     cout<<"\n["; for (int i = cur; i < end; i++) cout<<arr[i]<<", "; cout<<"\b\b]";
     if (end == arr.size()) return;
     else if (brk == true) return;
     Subarray (arr, end + 1, cur, true);
     Subarray (arr, end + 1, cur);
}

using namespace std;
int main(){
     vector <int> arr {1, 2, 3};
     int size = arr.size();
     cout<<"\nSubarrays : "<<endl;
     Subarray(arr);
     return 0;
}