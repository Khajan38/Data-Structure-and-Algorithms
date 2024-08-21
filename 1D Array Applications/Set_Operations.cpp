#include <iostream>
#include <memory>
using namespace std;

//Note that Sets elements are unique.. However, here we are not making an Set Data Structure but an array and hence our primary focus is on Operating Set : Union, Intersection, Difference and Memebership. So, we asssume an single array is treated as set and originally have all unique elements.

//Set Union -> Time : O(smalln^2 + bign*log(smalln)), Space :O(n1+n2)
int Union (int *arr, int *arr1, int *arr2, int n1, int n2){
     int smalln, bign, *smallarr, *bigarr;
     (n1 > n2)? ({smalln = n2; bign = n1; smallarr = arr2; bigarr = arr1;}) : ({smalln = n1; bign = n2; smallarr = arr1; bigarr = arr2;});
     for (int i = 0; i < smalln; i++) arr[i] = smallarr[i];
     for (int i = 1; i < smalln; i++){ //Sorting smaller array
          int temp = arr[i], j = i;
          for (; arr[j] < arr[j - 1] && j > 0; j--)
               arr[j] = arr[j - 1];
          arr[j] = temp;
     }
     int count = 0;
     for (int i = 0; i < bign; i++){
          int target = bigarr[i]; bool found = false;
          for (int low = 0, high = smalln - 1; low <= high;){
               int middle = (low + high)/2;
               if (arr[middle] == target) {found = true; break;}
               else if (arr[middle] > target) high = middle - 1;
               else low = middle + 1;
          }
          if (found == false) {arr[smalln + count] = bigarr[i]; count++;}
     }
     return (smalln + count);
}

//Set Intersection -> Time : O(smalln^2 + bign*log(smalln)), Space :O(n1+n2)
int Intersection (int *arr, int *arr1, int *arr2, int n1, int n2){
     int smalln, bign, *smallarr, *bigarr;
     (n1 > n2)? ({smalln = n2; bign = n1; smallarr = arr2; bigarr = arr1;}) : ({smalln = n1; bign = n2; smallarr = arr1; bigarr = arr2;});
     for (int i = 1; i < smalln; i++){//Sorting smaller array
          int temp = smallarr[i], j = i;
          for (; smallarr[j] < smallarr[j - 1] && j > 0; j--)
               smallarr[j] = smallarr[j - 1];
          smallarr[j] = temp;
     }
     int count = 0;
     for (int i = 0; i < bign; i++){
          int target = bigarr[i]; bool found = false;
          for (int low = 0, high = smalln - 1; low <= high;){
               int middle = (low + high)/2;
               if (smallarr[middle] == target) {found = true; break;}
               else if (smallarr[middle] > target) high = middle - 1;
               else low = middle + 1;
          }
          if (found == true) {arr[count] = bigarr[i]; count++;}
     }
     return (count);
}

//Set Difference -> Time : O(smalln^2 + bign*log(smalln)), Space :O(n1+n2)
int Difference (int *arr, int *arr1, int *arr2, int n1, int n2){
     int smalln, bign, *smallarr, *bigarr;
     (n1 > n2)? ({smalln = n2; bign = n1; smallarr = arr2; bigarr = arr1;}) : ({smalln = n1; bign = n2; smallarr = arr1; bigarr = arr2;});
     for (int i = 1; i < smalln; i++){//Sorting smaller array
          int temp = smallarr[i], j = i;
          for (; smallarr[j] < smallarr[j - 1] && j > 0; j--)
               smallarr[j] = smallarr[j - 1];
          smallarr[j] = temp;
     }
     int count = 0;
     for (int i = 0; i < bign; i++){
          int target = bigarr[i]; bool found = false;
          for (int low = 0, high = smalln - 1; low <= high;){
               int middle = (low + high)/2;
               if (smallarr[middle] == target) {found = true; break;}
               else if (smallarr[middle] > target) high = middle - 1;
               else low = middle + 1;
          }
          if (found == false) {arr[count] = bigarr[i]; count++;}
     }
     return (count);
}

//Membership -> Time : O(log(n)), Space :O(1)
bool Membership (int *arr, int n, int element){
     for (int i = 0, j = n - 1; i <= j;){
          int middle = (i + j)/2;
          if (arr[middle] == element) return true;
          else if (arr[middle] > element) j = middle - 1;
          else i = middle + 1;
     }
     return false;
}

int main(){
     int n1, n2; 
     cout<<"\nEnter no. of elements in Array 1 : "; cin>>n1;
     cout<<"Enter no. of elements in Array 2 : "; cin>>n2;
     int arr1[n1], arr2[n2]; 
     cout<<"Enter the elements in Array 1 : ";
     for (int i = 0; i < n1; i++) cin>>*(arr1+i);
     cout<<"Enter the elements in Array 2 : ";
     for (int i = 0; i < n2; i++) cin>>*(arr2+i);
     int * arr = new int [n1 + n2];
     int arrn = Union(arr, arr1, arr2, n1, n2);
     cout<<"Union of Array : ";
     for (int i = 0; i < arrn; i++) cout<<arr[i]<<" "; cout<<endl;
     arrn = Intersection(arr, arr1, arr2, n1, n2);
     cout<<"Intersection of Array : ";
     for (int i = 0; i < arrn; i++) cout<<arr[i]<<" "; cout<<endl;
     arrn = Difference(arr, arr1, arr2, n1, n2);
     cout<<"Difference of Array : ";
     for (int i = 0; i < arrn; i++) cout<<arr[i]<<" "; cout<<endl;
     cout<<"\nEnter the element : "; cin>>arrn;
     bool member = Membership(arr1, n1, arrn);
     if (arrn) cout<<"Is a Member..";
     else cout<<"Not a Member...";
     delete [] arr;
     return 0;
}