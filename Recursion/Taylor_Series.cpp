#include <iostream>
using namespace std;

//Taylor Exapansion -> Time : O(log(n) + n) = O(n), Space : O(n) or O(1)
int fact(int n, int accumulator = 1){
     if (n == 1 || n == 0) return accumulator;
     return fact(n - 1, accumulator * n);
}
int exponentation(int n, int exponent){
     if (exponent == 0) return 1;
     else if (exponent == 2) return n * n;
     if (exponent % 2 == 0) return exponentation(n*n, exponent/2);
     else return exponentation(n*n, exponent/2) * n;
}
float Taylor_e_1(int x, int n, float accumulator = 0){
     if (n == -1) return accumulator;
     return Taylor_e_1(x, n - 1, accumulator + static_cast <float>(exponentation(x, n))/fact(n));
}

//Taylor Series by Horner's Rule -> Time : O(n), Space : O(n)
float Taylor_e_2(int x, int n_1, int n = 1){
     if (n == n_1 + 1) return 1;
     return (1 + (static_cast <float> (x)/n)*(Taylor_e_2(x, n_1, n + 1)));
}

int main(){
     cout<<Taylor_e_1(2, 3)<<endl;
     cout<<Taylor_e_2(2, 3)<<endl;
     return 0;
}