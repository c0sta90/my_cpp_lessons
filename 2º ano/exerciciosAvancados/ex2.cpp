#include <iostream>
using namespace std;

int input;

int sum1(int n){
    int s = 0;
    while (n > 0){
        s++;
        n--;
    }
    return s;
}

int sum2(){
    int s = 0;
    while (input > 0){
        s++;
        input--;
    }
    return s;
}

int sum3(){
    int s = 0;
    for (int i = input; i > 0; i--) s++;
    return s;
}

int main(){

    input = 5 ;
    cout << sum1(input) << endl;
    cout << sum2() << endl;
    cout << sum3() << endl;
    return 0;
}