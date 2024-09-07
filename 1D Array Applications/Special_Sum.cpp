#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//Brute Force -> Time : O(n^2), Space : O(1)
vector <int> maxSpecialSum_1 (int * arr, int n){
    int specialSum {INT_MIN}, index = -1;
    for(int i = 0; i < n; i++){
        int sum {0}, j {i}, k = 1, sum_k {k};
        while (true){
            sum += arr[j]; j++;
            if (j - i == sum_k) {
                k++; sum_k += k;
                if (k + j > n) break;
            }
        }
        if (sum > specialSum){specialSum = sum; index = i;}
    }
    return {specialSum, index};
}

//Hashing -> Time : O(n), Space : O(n)
vector <int> maxSpecialSum_2 (int * arr, int n){
    vector <int> sum; sum.push_back(0);
    for (int i = 0; i < n; i++){
        static int summer = 0;
        summer += arr[i];
        sum.push_back(summer);
    }
    int specialSum{INT_MIN}, index{-1};
    for (int i = 0; i < n; i++){
        int k = (-1 + static_cast <int> (sqrt(8*(n - i) + 1)))/2; 
        int upper_bound = (k)*(k + 1) /2 + i;
        int summer = sum[upper_bound] - sum[i];
        if (summer > specialSum){specialSum = summer; index = i;}
    }
    return {specialSum, index};
}

int main(){
    int n;
    cout<<"\nEnter the number of elements : "; cin>>n;
    int arr[n];
    cout<<"Enter the elements : ";
    for (int i = 0; i < n; i++) cin>>arr[i];
    vector <int> specialSum = maxSpecialSum_1(arr, n);
    cout<<"Maximum Special Sum : "<<specialSum[0]<<" at index : "<<specialSum[1];
    specialSum = maxSpecialSum_2(arr, n);
    cout<<"\nMaximum Special Sum : "<<specialSum[0]<<" at index : "<<specialSum[1]<<endl;
}