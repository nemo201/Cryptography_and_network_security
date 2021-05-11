#include <iostream>
#include<string>
using namespace std;

string encrypt(string s, int key){
    string result;
    for(int i=0; i<s.size(); i++){
        //for uppercase
        if(isupper(s[i]))
            result += (s[i]+key-'A')%26+'A';
        //for lowercase
        else
            result += (s[i]+key-'a')%26+'a';
    }
    return result;
}

string decrypt(string s, int key){
    string result;
    for(int i=0; i<s.length(); i++){
        //for uppercase
        if(isupper(s[i]))
            result += (s[i]-key-'A'+26)%26+'A';
        //for lowercase
        else
            result += (s[i]-key-'a'+26)%26+'a';
    }
    return result;
}

int main(){
    string s;
    int key,opt;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter key: ";
    cin >> key;
    cout << "Select 1 to Encrypt or Select 2 to Decrypt" << endl;
    cin >> opt;
    if(opt == 1)
        cout << encrypt(s,key) << endl;
    else if(opt == 2)
        cout << decrypt(s,key) << endl;
    else
        cout << "Wrong choice" << endl;
    return 0;
}
