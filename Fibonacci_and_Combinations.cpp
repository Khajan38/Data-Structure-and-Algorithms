#include <iostream>
using namespace std;

//Fibonacci Series -> Time : O(2^n), Space : O(n)
int Fibonacci(int n){
     if (n == 0 || n == 1) return n;
     return Fibonacci(n - 1) + Fibonacci(n - 2);
}

//Combinations -> Time : O(n+2) or O(n), Space : O(n) or O(1)
int factorial(int n, int r = 0){
     if (n == r + 1) return r + 1;
     return n * factorial(n - 1, r);
}
float Combinations_1(int n, int r){
     if (2*r < n) return (static_cast <float>(factorial(n, n - r))/factorial(r));
     return (static_cast <float> (factorial(n, r))/factorial(n - r));
}

//Combinations -> Time : O(2^n), Space : O(n)
float Combinations_2(int n, int r){
     if (r == 0 || n == r) return 1;
     return Combinations_2(n - 1, r - 1) + Combinations_2(n - 1, r);
}

int main(){
     cout<<Fibonacci(10)<<endl;
     cout<<Combinations_1(5, 3)<<endl;
     cout<<Combinations_2(5, 3)<<endl;
     return 0;
}