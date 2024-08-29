#include <iostream>
using namespace std;

//Check Power of 2 -> Time : O(1), Space : O(1)
bool chk_PowerOf2 (int n){
     if (n == 0) return false; //0 is neither even nor odd
     /*A number which is exponent of 2, has only 1 bit set. 
     So on clearinhg this bit, integer becomes 0*/
     if (n & (n - 1)) return false; 
     return true;
}

//Check Even or Odd -> Time : O(1), Space : O(1)
bool chk_Even (int n){
     /*Since for any odd number the binary is having set 0th index bit, clear otherwise, so on AND operation with 1, even number gives 0 while odd gives 1*/
     if (n & 1) return false;
     return true;
}

//No. of Set Bits -> Time : O(log(n)), Space : O(1)
int cnt_SetBits (int n){
     int count = 0;
     while (n > 0){n &= n - 1; count++;}
     return count;
}

int main(){
     int n;
     cout<<"\nEnter the number : "; cin>>n;
     cout<<"Is a Power of 2 : "<<((chk_PowerOf2 (n))? "Yes" : "No")
         <<"\nType : "<<((chk_Even(n))? "Even" : "Odd")
         <<"\nNumber of Set Bits : "<<cnt_SetBits(n)<<endl;
     return 0;
}