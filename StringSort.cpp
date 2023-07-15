#include<iostream>
#include<bits\stdc++.h>
using namespace std;
int main(){
    string c;
    cin>> c;
    sort(c.begin(),c.end());
    for(int i=0;i<c.length();i++){
        cout<<c[i];

    }
}