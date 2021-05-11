#include <iostream>
using namespace std;

bool prime(int n){
    bool p = true;
    if(n==0 || n==1)
        p=false;
    else{
        for(int i=2; i<n/2; i++){
            if(n%i==0){
                p=false;
                break;
            }
        }
    }
    return p;
}

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;
    prime(n) ? cout << "Prime\n" : cout << "Not a prime\n";
    return 0;
}
