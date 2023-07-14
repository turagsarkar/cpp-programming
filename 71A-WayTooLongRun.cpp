#include<iostream>
#include<bits/stdc++.h>
using namespace std ; 
int main(){
    int i,n,count = 0 ; 
    cin>>n;
    string s ; 
    for (i=0; i<n ; i++){
        cin>>s;
    if ( s.length()>10){
        cout<<s[0]<<s.length()-2<<s[s.length()-1]<<endl;
    }
    else{
        cout<<s<<endl; 
    }
    }
    
}