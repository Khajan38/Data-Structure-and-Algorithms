#include <iostream>
using namespace std;

//Brute Force Approach -> Time : O(min(n1, n2)), Space  : O(1)
int GCD_1(int n1, int n2){
     if (n1 == 0) return n2;
     if (n2 == 0) return n1;
     int n {min(n1, n2)};
     for (int i = n; i > 1; i--)
          if (n1 % i == 0 && n2 % i == 0)
               return i;
     return 1;
}

//Euclidian Subtraction Algorithm -> Time : O(min(n1, n2)), Space : O(1)
int GCD_2(int n1, int n2){
     if (n2 == 0) return n1;
     while (n1 != 0){
          if (n1 >= n2) n1 -= n2;
          else swap(n1, n2);
     }
     return n2;
}

//Euclidian Algorithm -> Time : O(log(min(n1, n2))), Space : O(1)
int GCD_3(int n1, int n2){
     while (n2 != 0){
          n1 %= n2;
          swap(n1, n2);
     }
     return n1;
}

//(m*n)/HCF Approach : Time : O(log(min(n1, n2))), Space : O(1)
int LCM(int n1, int n2){
     int temp_n1 = n1, temp_n2 = n2;
     while (temp_n2 != 0){
          temp_n1 %= temp_n2;
          swap(temp_n1, temp_n2);
     }
     int HCF {temp_n1};
     return (n1 * n2)/HCF;
}

int main(){
     int n1, n2;
     cout<<"\nEnter the first number : "; cin>>n1;
     cout<<"Enter the second number : "; cin>>n2;
     cout<<"\nHCF("<<n1<<", "<<n2<<") : "<<GCD_3(n1, n2);
     cout<<"\nLCM("<<n1<<", "<<n2<<") : "<<LCM(n1, n2)<<endl;
     return 0;
}