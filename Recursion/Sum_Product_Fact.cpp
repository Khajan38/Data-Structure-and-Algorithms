#include <iostream>
#include <vector>
using namespace std;

//All Approaches Complexities -> Time : O(n) Space : O(1)
int sum_numbers (int n, int sum = 0){ //n numbers sum
     if (n == 0) return sum;
     else if (n > 0) return sum_numbers(n-1, sum + n); //Tail Recursion for positive numbers
     return sum_numbers(n+1, sum + n); //Tail Recursion for negative numbers
}

int sum_array_numbers (vector <int> vec, int n = 0, int sum = 0){ //Series element sum
     if (n == 0) return sum;
     return sum_array_numbers(vec, n - 1, sum + vec[n - 1]); //Tail Recursion for group of numbers
}

int product_numbers (int n, int product = 1){ //n numbers sum
     if (n == 0) return product;
     else if (n > 0) return product_numbers(n-1, product * n); //Tail Recursion for Factorial
     return product_numbers(n+1, product * n); //Tail Recursion for negative numbers
}

int product_array_numbers (vector <int> vec, int n = 0, int product = 1){ //Series element sum
     if (n == 0) return product;
     return product_array_numbers(vec, n - 1, product * vec[n - 1]); //Tail Recursion for group of numbers
}

int exponent_numbers (int n, int exponent, int accumulator = 1){ //n numbers sum
     if (exponent == 0) return 1;
     else if (exponent == 1) return accumulator * n;
     return exponent_numbers(n, exponent - 1, accumulator * n); //Tail Recursion for exponentition operator
}

//Optimised approaches Complexities -> Time : O(log(n)) Space : O(1)
int optimised_exponent_numbers (int n, int exponent){
     if (exponent == 0) return 1;
     else if (exponent == 2) return n*n;
     if (exponent % 2 == 0) return optimised_exponent_numbers(n*n, exponent/2);
     else return optimised_exponent_numbers(n*n, exponent/2) * n;
}

int main(){
     cout<<sum_numbers(5)<<endl;
     cout<<sum_numbers(-5)<<endl;
     cout<<product_numbers(5)<<endl;
     cout<<product_numbers(-5)<<endl;
     cout<<exponent_numbers(2, 3)<<endl;
     cout<<exponent_numbers(-2, 3)<<endl;
     cout<<optimised_exponent_numbers (2, 3)<<endl;
     vector <int> vec {1, 2, 3, 4, 5};
     cout<<sum_array_numbers(vec, 5)<<endl;
     cout<<product_array_numbers(vec, 5)<<endl;
     return 0;
}