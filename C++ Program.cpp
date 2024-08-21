#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s){
        string rev {""};
        for (int i = 0; s[i] != '\0'; i++) 
            if (s[i]) rev += s[i];
        s = rev;
        cout<<"s : "<<s<<endl;
        for (int i = 0, j = rev.size() - 1; i < j; i++, j--)
            swap(rev[i], rev[j]);
        cout<<"rev : "<<rev<<endl;
        if (s == rev) return true;
        return false;
    }
};
int main(){
     Solution A;
     cout<<"Is palindrome : "<<A.isPalindrome("A man, a plan, a canal: Panama");
     cout<<static_cast <int> ('a' - 'A');
     return 0;
}