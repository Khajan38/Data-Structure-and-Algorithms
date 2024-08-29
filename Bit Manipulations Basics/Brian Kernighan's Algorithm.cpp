#include <iostream>
using namespace std;

//Count Set Bits -> Time : O(n*log(n)), Space : O(1)
int countSetBits_1 (int n){
     int count = 0;
     for (; n > 0; n--){
          int temp = n;
          while (temp > 0){
               temp &= temp - 1;
               count++;
          }
     }
     return count;
}

//Count Set Bits -> Time : O(log(n)), Space : O(1)
int countSetBits_2 (int n){
     int count = 0;
     for (int i = 0; (1 << i) <= n; i++){
          int one_cycle = 1 << (i); //alternative for pow(2, i+1)
          int completeCycles = n /(2 * one_cycle); //Total completed cycles
          count += completeCycles * one_cycle + max(0, (n % (2 *one_cycle)) - one_cycle + 1);
     }
     return count;
}


int main() {
     int n;
     cout<<"\nEnter the value of n : "; cin>>n;
     cout<<"Total set bits from 0 to "<<n<<" is "<<countSetBits_1(n)<<endl;
     return 0;
}