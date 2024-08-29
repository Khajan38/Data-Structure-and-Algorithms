#include <iostream>
using namespace std;

//Swap Numbers -> Time -> O(1), Space : O(1)
void swap (int & a, int & b){
     cout<<"Initial values : "<<a<<", "<<b<<endl;
     a  =  a ^ b; b = a ^ b; a = a ^ b;
     cout<<"Swapped values : "<<a<<", "<<b<<endl;
}

int main(){
     int a, b;
     cout<<"\nEnter first number : "; cin>>a;
     cout<<"Enter second number : "; cin>>b;

     return 0;
}