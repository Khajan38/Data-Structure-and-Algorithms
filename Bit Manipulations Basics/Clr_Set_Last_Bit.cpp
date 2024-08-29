#include <iostream>
using namespace std;

//Clear Last Set Bit -> Time : O(log(n)), Space : O(1)
void clr_LstSetBit_1 (int & n){
     int i = 0, bitmask = 1;
     while (bitmask <= n){
          bitmask = 1<<i; i++;
          if (n & bitmask) {n &= (~bitmask); break;}
     }
}

//Clear Last Set Bit -> Time : O(1), Space : O(1)
void clr_LstSetBit_2 (int & n){
     /*Since, for any number n, (n - 1) has last set bit altered as 0. So by taking AND operation with n, it makes first set bit = 0, E.g. -
     n = 10 = 1010, (n - 1) = 9 = 1001
     Thus n & (n - 1) = 1000 = 8*/
     n &= n - 1;
}

//Clear Last Set Bit -> Time : O(log(n)), Space : O(1)
void set_LstClrBit_1 (int & n){
     int bitmask = 1;
     while (true) {
          if (n & bitmask) bitmask <<= 1;
          else {n ^= bitmask; break;}
     }
}

//Clear Last Set Bit -> Time : O(1), Space : O(1)
void set_LstClrBit_2 (int & n){
     /*Since, for any number n, (n + 1) has last clr bit altered as 1. So by taking OR operation with n, it makes first clr bit = 1, E.g. -
     n = 10 = 1010, (n + 1) = 11 = 1011
     Thus n | (n + 1) = 1011 = 11*/
     n |= n + 1;
}

int main(){
     int n;
     cout<<"\nEnter the number : "; cin>>n;
     clr_LstSetBit_1(n);
     set_LstClrBit_1(n);
     cout<<"New number : "<<n<<endl;
     return 0;
}