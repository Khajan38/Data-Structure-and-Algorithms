#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
     int count = 0;
     int finalPositionOfSnake(int n, vector<string>& commands) {
          if (commands.size() == 0) return count;
          if (commands.back() == "UP") count -= n;
          else if (commands.back() == "DOWN") count += n;
          else if (commands.back() == "LEFT") count -= 1;
          else count += 1;
          commands.pop_back();
          return finalPositionOfSnake(n, commands);
     }
};
int main(){
     Solution A;
     vector <string> command {"DOWN","RIGHT","UP"};
     cout<<A.finalPositionOfSnake(3, command);
     return 0;
}