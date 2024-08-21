#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

//Brute Force Approach -> Time : O(n), Space : O(n)
vector <int> all_divisors_1 (int n){
     vector <int> divisors {};
     for (int i = 1; i <= n; i++)
          if (n % i == 0) divisors.push_back(i);
     return divisors;
}

//Optimized Approach -> Time : O(sqrt(n)), Space : O(sqrt(n))
vector <int> all_divisors_2 (int n){
     vector <int> divisor {};
     int limit = sqrt(n);
     for (int i = 1; i <= limit; i++)
          if (n % i == 0) {
               divisor.push_back(i); 
               int other = n / i;
               if (i != other) divisor.push_back(other);
          }
     return divisor;
}

//Brute Force Approach -> Time : O(n), Space : O(1)
bool isprime_1 (int n){
     if (n <= 1) return false;
     for (int i = 2; i < n; i++)
          if (n % i == 0) return false;
     return true;
}

//Optimized Approach -> Time : O(sqrt(n)), Space : O(1)
bool isprime_2 (int n){
     if (n <= 1) return false;
     if (n % 2 == 0) return false;
     int limit = sqrt(n);
     for (int i = 3; i <= limit; i += 2)
          if (n % i == 0) return false;
     return true;
}

int main(){
     int n;
     cout<<"\nEnter the number : ";
     cin>>n;
     cout<<"\nPrime Number ? : "<<(isprime_2(n)? "Yes" : "No");
     vector <int> divisors {all_divisors_2(n)};
     cout<<"\nDivisors : "; for (int i : divisors) cout<<i<<" "; cout<<endl;
     return 0;
}