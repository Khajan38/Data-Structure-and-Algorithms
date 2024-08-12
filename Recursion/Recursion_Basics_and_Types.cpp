#include <iostream>
#include <vector>
using namespace std;

//Using Recursion Tools : static and global variable
int binary_no = 0; //Global varible
void binary_conv_3(int a){ //To convert whole numbers to binary
     static int place_value = 1;
     if (a == 0) return; //Base Condition
     binary_no += (a%2)*place_value;
     place_value *= 10; //Changing static variables
     binary_conv_3(a/2); //Rescusive Call
}

//Head Recursion -> Time : O(log(n)), Space : O(log(n)), Calls = n + 1
int binary_conv_1(int a, int place_value = 1){ //To convert whole numbers to binary
     if (a == 0) return 0; //Base Condition
     int binary_no = binary_conv_1(a/2 , place_value*10) + (a%2)*place_value; //Head Recursion - Rescusive Call
     return binary_no;
}

//Tail Recursion -> Time : O(log(n)), Space : O(1), Calls = n + 1
int binary_conv_2(int a, int binary_no = 0, int place_value = 1){ //To convert whole numbers to binary
     if (a == 0) return binary_no; //Base Condition and binary_no as accumulator
     return binary_conv_2(a/2, binary_no + (a%2)*place_value, place_value*10); //Tail Recursion - Rescusive Call
}

//Tree Recursion -> Time : O(2^n), Space : O(n)
int Fibonacci(int n){ //Gives nth Fibonacci Numbe
     if (n == 0 || n == 1) return n; //Base Condition
     return Fibonacci(n - 1) + Fibonacci(n - 2); //Tree Recursion - Recursive Call
}

//Optimised Tree Recursion -> Time : O(n), Space : O(n)
vector <int> memorization {0, 1};
int treeFibonacci(int n) { //Gives nth Fibonacci Number
    if (memorization.size() >= n) return memorization[n - 1]; //Base Condition
    memorization.push_back(treeFibonacci(n - 1) + treeFibonacci(n - 2)); //Tree Recursion - Recursive Call
    return memorization[n - 1];
}

//Indirect Recursion -> Time : O(n) Space : O(1), where n is size of array
void even(int * arr); // Forward declaration
void odd(int * arr); // Forward declaration
void check(int * arr) { //Check even and odd
     if (*arr == 0){return;} //Base Condition
     if ((*arr)%2 == 0) even(arr);
     else odd(arr);
}
void even(int * arr){ //For even cases
     cout<<"("<<*arr<<" : Even)"<<" ";
     check(++arr); //Indirect Recursion - Circular Relation
}
void odd(int * arr){ //For odd cases
     cout<<"("<<*arr<<" : Odd)"<<" ";
     check(++arr); //Indirect Recursion - Circular Relation
}

//Nested Recursion -> Time : O(log(n)), Space : O(log(n))
int nestedRecursion(int n){
     if (n > 100) {return n;} 
     return nestedRecursion(nestedRecursion(n + 10));
}

int main(){
     cout<<binary_conv_1(10)<<endl;
     cout<<binary_conv_2(10)<<endl;
     binary_conv_3(10);
     cout<<binary_no<<endl;
     cout<<treeFibonacci(10)<<endl;
     int arr[] {39, 65, 78, 89, 24, 56, 0};
     check(arr); cout<<endl;
     cout<<nestedRecursion(78)<<endl;
     return 0;
}