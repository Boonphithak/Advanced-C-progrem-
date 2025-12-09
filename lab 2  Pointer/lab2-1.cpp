#include <iostream>
#include <string>
using namespace std;

int main() {
    char a[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
    char b[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
    
    string mess = "AbbeF";
    char temp;
    for (int i = 0; i < mess.length(); i++) {
        temp = mess[i] ;
        if ((int)mess[i] > 90){
            cout << b[(int)temp - (int)'a'];
         
        }else {
            cout << a[(int)temp - (int)'A'];
        }
    }
  
    return 0;
}