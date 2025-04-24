#include <iostream>
#include <string.h>
//#include <bits/stdc++.h>

using namespace std;
int isPalindrome(string str) {
  
    // Stores the reverse of the string s
    string rev = str;

    // Reverse the string
    reverse(rev.begin(), rev.end());

    // If rev is equal to str
    if (str == rev)
        return 1;
      
    // If rev is NOT equal to str
    else
        return 0;
}

int main(){
    int times;
    cin >> times;
    string s1, s2, s3;
    for(int i = 0; i < times; i++){
        cin >> s1 >> s2;
        s3 = s1 + s2;
        if (isPalindrome(s1)){
            cout << "String one is a palindrome.\n"; 
        }
        else {
            cout << "String one is not a palindrome.\n";
        }
        if (isPalindrome(s2)){
            cout << "String two is a palindrome.\n"; 
        }
        else {
            cout << "String two is not a palindrome.\n";
        }
        if (isPalindrome(s3)){
            cout << "String three is a palindrome.\n"; 
        }
        else {
            cout << "String three is not a palindrome.\n";
        }
    }
}