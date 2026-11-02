#include <iostream>
#include <clocale>
using namespace std;

int main() {
    setlocale(LC_ALL,".UTF8");
    int a,b;
    bool f=true;
    cin >> a;
    if (a!=0){
        cin >> b;
        while (f && (b!=0) && (a!=b) ){
            if (a<b){
                a=b;
            }
            else{
                f = false;
            }
        if (f){
            cout<<"Последовательность возрастает";
        
        }
        else {
            cout<<"Последовательность не возрастает";

        }
        }
    }
    else{
        cout<<"Ошибка ввода";1

    }
    return 0;
}