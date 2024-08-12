#include <iostream>
#include <vector>
using namespace std;

void Tower_of_Hanoi_1(int n, vector<int> &Source, vector<int> &Middle, vector<int> &Destination, char sourceLabel, char middleLabel, char destinationLabel){
     if (n == 1){
          Destination.push_back(Source.back());
          cout << "\n\tMoved Disk " << Source.back() << " from Tower " << sourceLabel << " to Tower " << destinationLabel;
          Source.pop_back();
          return;
     }
     Tower_of_Hanoi_1(n - 1, Source, Destination, Middle, sourceLabel, destinationLabel, middleLabel);
     Destination.push_back(Source.back());
     cout <<"\n\tMoved Disk " << Source.back() << " from Tower " << sourceLabel << " to Tower " << destinationLabel;
     Source.pop_back();
     Tower_of_Hanoi_1(n - 1, Middle, Source, Destination, middleLabel, sourceLabel, destinationLabel);
}

void Tower_of_Hanoi_2(int n, char source = 'A', char auxillary = 'B', char destination = 'C'){
     if (n == 1){
          cout<<"\n\tMoved Disk " <<n<<" from Tower "<<source<< " to Tower "<<destination;
          return;
     }
     Tower_of_Hanoi_2(n - 1, source, destination, auxillary);
     n -= 1; cout<<"\n\tMoved Disk " <<n<<" from Tower "<<source<< " to Tower "<<destination;
     Tower_of_Hanoi_2(n, auxillary, source, destination);
}

void printTower(const vector<int> &tower, char label){
     cout << "\n\tTower " << label << " -> ";
     for (size_t i = 0; i < tower.size(); ++i){
          cout << tower[i];
          if (i < tower.size() - 1)
               cout << ", ";
     }
}

int main(){
     vector<int> Source{3, 2, 1}, Middle{}, Destination{};
     char sourceLabel = 'A', middleLabel = 'B', destinationLabel = 'C';

     cout<<"\nBefore Solving : ";
     printTower(Source, sourceLabel);
     printTower(Middle, middleLabel);
     printTower(Destination, destinationLabel); cout<<endl;

     cout<<"\nProcess : ";
     Tower_of_Hanoi_1(Source.size(), Source, Middle, Destination, sourceLabel, middleLabel, destinationLabel);

     cout<<"\n\nAfter Solving : ";
     printTower(Source, sourceLabel);
     printTower(Middle, middleLabel);
     printTower(Destination, destinationLabel);  cout<<endl;

     cout<<"\nProcess : ";
     Tower_of_Hanoi_2(3, 'A', 'B', 'C'); cout<<endl;

     return 0;
}
