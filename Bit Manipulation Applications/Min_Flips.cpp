#include <iostream>
using namespace std;

//Min Flips -> Time : O(max(log n1, log n2)), Space : O(1)
int minFlips_1 (unsigned int n1, unsigned int n2){
     /*Getting signed integer as unsigned, the binary representation following the 2s complement is transferred to the unsigned integer, so for
     signed n1 = -10 in main 
     unsigned n1 = 4294967286 which is 2s Complement*/
     int count{0};
     for (; n1 > 0 || n2 > 0; n1 >>= 1, n2 >>= 1)
          if ((n1 & 1) != (n2 & 1)) count++;
     return count;
}

//Min Flips -> Time : O(log(max(n1, n2))), Space : O(1)
int minFlips_2 (unsigned int n1, unsigned int n2){
     unsigned int xor_result = n1 ^ n2;
     int count = 0;
     while (xor_result){
          count += (xor_result & 1);
          xor_result >>= 1;
     }
     return count;
}

int main(){
     int n1, n2;
     cout<<"\nEnter the First Number : "; cin>>n1;
     cout<<"Enter the Second Number : "; cin>>n2;
     cout<<"Total number of flips : "<<minFlips_1(n1, n2);
     cout<<"\nTotal number of flips : "<<minFlips_2(n1, n2)<<endl;
     return 0;
}