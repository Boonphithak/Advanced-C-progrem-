#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int A[10]= {10,2,2,5,6,7,9,4,5,0} , x;

    for (const auto &x:A){
        cout << x << " ";
    };
    sort(begin(A), end(A));
    cout << "\nAfter sortig:(Ascemding order)\n";
    for (const auto &x:A){
        cout << x << " ";
    };
    sort(A,A + 10, greater<int>());
    cout << "\nAfter sortig:(Descending order)\n";
    for (const auto &x:A){
        cout << x << " ";
    };
   



}