#include <iostream>
#include <cmath>
using namespace std;

//Brute Force -> Time : O(log(n)), Space : O(1)
bool armstrong (int n){
     int sum_digits {0}, no_digits = log10(n) + 1;
     for (int temp = n; temp > 0; temp /= 10) sum_digits += pow(temp % 10, no_digits);
     if (n == sum_digits) return true;
     return false;
}

int main(){
     int n;
     cout<<"\nEnter the number : ";
     cin>>n;
     cout<<"Armstrong Number ? : "<<(armstrong(n)? "Yes" : "No")<<endl;
     return 0;
}