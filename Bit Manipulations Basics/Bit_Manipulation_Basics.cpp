#include <iostream>
using namespace std;
int main(){
     int a = 10, b = -3; 
     //10 : 00000000000000000000000000001001 (2s representation of positive number)
     //-3 : 11111111111111111111111111111101 (2s representation of negative number)
     cout<<"\nBitwise AND : "<<(a & b)
         <<"\nBitwise OR : "<<(a | b)
         <<"\nBitwise NOT : "<<(~a)<<", "<<(~b) //Gives 1s complement
         <<"\nBitwise Right Shift : "<<(a>>3)<<", "<<(b>>1) //Denotes division by 2^n
         <<"\nBitwise Left Shift : "<<(a<<3)<<", "<<(b<<1) //Denotes multipiclation by 2^n
         <<"\nBitwise XOR : "<<(a^b)<<endl; //Odd 1 detector 
    
    cout<<"\nXOR Properties :"
        <<"\n\t1. a^a = "<<(a^a)<<" = always 0"
        <<"\n\t2. a^0 = "<<(a^0)<<" = always a"
        <<"\n\t3. a^1 = "<<(a^1)<<" = always ~a (without sign change)"<<endl;
     return 0;
}