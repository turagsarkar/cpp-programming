#include<iostream>
#include<bits\stdc++.h>
using namespace std; 
int main(){
    string t , s ;
    cin>>t;
    cin>>s;
    reverse(s.begin(),s.end());
    if(s==t){
        cout<<"YES"<<endl;
    }
    else{
    cout<<"NO"<<endl;
    }
}
