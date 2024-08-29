#include <iostream>
using namespace std;

//Check Set Bit -> Time -> O(1), Space : O(1)
//If a bit is set, it has a value of 1.

void chk_set_bit_1 (int n, int bit_position){
     int bitmask = (1<<bit_position); 
     /*Gives bitmask as 1000.... upto bit position
     
     And operation with this bitmask gives 0 if bit is not set, non-zero number otherwise
     if  n = 1010 as binary and 
     bit position = 1, then, bitmask = 10 and hence (n & bitmask) = 0010 = non-zero => bit is set
     bit position = 2, then, bitmask = 100 and hence (n & bitmask) = 0000 = zero => bit is not set*/

     if (n & bitmask) cout<<"\nBit is set"; 
     else cout<<"\nBit is not set";
}

void chk_set_bit_2 (int n, int bit_position){
     n >>= bit_position; 
     /*Gives number right shifted upto bit position
     And operation of this with 1 gives 0 if bit is not set, 1 otherwise
     if  n = 1010 as binary and 
     bit position = 1, then, n = 101 and hence (n & 1) = 001 = 1 => bit is set
     bit position = 2, then, n = 10 and hence (n & 1) = 00 = zero => bit is not set*/
     if (n & 1) cout<<"\nBit is set"; 
     else cout<<"\nBit is not set";
}

//Set Bit -> Time -> O(1), Space : O(1)
//If a bit is set, it has a value of 1.
void set_bit (int & n, int bit_position){
     int bitmask = (1<<bit_position);
     //Gives bitmask as 1000.... upto bit position
     n |= bitmask;
     /*If  n = 1010 as binary and 
     bit position = 1, then, bitmask = 10 and hence (n | bitmask) = 1010
     bit position = 2, then, bitmask = 100 and hence (n | bitmask) = 1110*/
}

//CLear Bit -> Time -> O(1), Space : O(1)
//If a bit is clear, it has a value of 0.
void clear_bit (int & n, int bit_position){
     int bitmask = (1<<bit_position);
     bitmask = ~bitmask;
     /*Gives bitmask as 1000.... upto bit position and then its complement as 111110111....
     
     And operation with this bitmask gives 0 if bit is not set, non-zero number otherwise
     if  n = 1010 as binary and 
     bit position = 1, then, bitmask = 10 -> 11...101 and hence (n & bitmask) = 1000
     bit position = 2, then, bitmask = 100 -> 11...1011 and hence (n & bitmask) = 1010*/

     n &= bitmask;
}

//Toggle Bit -> Time -> O(1), Space : O(1)
void toggle_bit (int & n, int bit_position){
     int bitmask = (1<<bit_position);
     /*Gives bitmask as 1000.... upto bit position
     
     if  n = 1010 as binary and 
     bit position = 1, then, bitmask = 10 and hence (n ^ bitmask) = 1000
     bit position = 2, then, bitmask = 100 and hence (n ^ bitmask) = 1110*/

     n ^= bitmask;
}

int main(){
     int a, b;
     const int consta = a;
     cout<<"\nEnter Number : "; cin>>a;
     cout<<"Enter Setting Bit Position : "; cin>>b;
     chk_set_bit_1(a, b);
     set_bit(a, b); cout<<"\nNumber after setting : "<<a;
     a = consta;
     cout<<"Enter CLearing Bit Position : "; cin>>b;
     chk_set_bit_2(a, b);
     clear_bit(a,b); cout<<"\nNumber after clearing : "<<a<<endl;
     a = consta;
     cout<<"Enter Toggling Bit Position : "; cin>>b;
     chk_set_bit_1(a, b);
     toggle_bit(a,b); cout<<"\nNumber after toggling : "<<a<<endl;
     return 0;
}