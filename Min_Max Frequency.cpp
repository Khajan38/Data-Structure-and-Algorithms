#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Map Hashing -> Time: O(n), Space: O(n)
pair<int, int> min_max(vector<int> &arr, int n){
     map<int, int> frequency;
     for (int i = 0; i < n; i++)
          frequency[arr[i]]++;
     auto it = frequency.begin();
     pair<int, int> max_freq{it->first, it->second};
     pair<int, int> min_freq{it->first, it->second};
     for (auto &entry : frequency){
          if (entry.second > max_freq.second)
               max_freq = {entry.first, entry.second};
          else if (entry.second < min_freq.second)
               min_freq = {entry.first, entry.second};
     }
     return {max_freq.first, min_freq.first}; // return max and min frequency elements
}

int main(){
     int n;
     cout<<"\nEnter no. of elements : "; cin>>n;
     vector <int> arr (n);
     cout<<"Enter Array Elements : "; 
     for (int i = 0; i < n; i++) cin >> arr[i];
     pair<int, int> result = min_max(arr, n);
     cout << "Element with max frequency: " << result.first << endl;
     cout << "Element with min frequency: " << result.second << endl;
     return 0;
}