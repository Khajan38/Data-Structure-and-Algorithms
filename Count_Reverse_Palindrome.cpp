#include <iostream>
#include <cmath>
using namespace std;

//Brute Force Approach -> Time : O(log(n)), Space : O(1)
int no_digits_1 (int n){
     int digits{0};
     for (; n > 0; n /= 10) digits++;
     return digits;
}

//Log Function Approach -> Time : O(1), Space : O(1)
int no_digits_2 (int n){
     return log10(n) + 1;
}

//Reverse a number -> O(log(n)), Space : O(1)
int reverse (int n){
     int rev_no{0};
     for (; n > 0; n /= 10) rev_no = rev_no * 10 + n % 10;
     return rev_no;
}

//Palindrome number -> O(log(n))), Space : O(1)
bool palindrome_1 (int n){
     int rev = reverse(n);
     if (rev == n) return true;
     return false;
}

//Palindrome number -> O(log(n)), Space : O(1)
bool palindrome_2 (int n){
     for (int j = log10(n); j > 1; n/= 10, j /= 100){
          int first = n % 10;
          int last = n / pow(10, j);
          if (first != last) return false;
     }
     return true;
}

int main(){
     int n;
     cout<<"\nEnter the number : ";
     cin>>n;
     cout<<"\nNo. of digits : "<<no_digits_2(n);
     cout<<"\nReversed Number : "<<reverse(n);
     cout<<"\nPalindrome Number ? : "<<(palindrome_2(n)? "Yes" : "No")<<endl;
     return 0;
}