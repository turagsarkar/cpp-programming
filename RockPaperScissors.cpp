#include<iostream>
using namespace std; 
int main()
{
    string str1 , str2;
    cout<<"Player One Turn :" << endl;
    cin >> str1 ;
    cout<< "Player One :" <<str1<< endl;
    cout<<"Player Two Turn :" << endl;
    cin >> str2 ;
    cout<< "Player Two : \n" <<str2<<endl;
    if (str1=="Rock"&& str2=="Rock")
    {
        cout<<"DRAW";
    }
    else if (str1=="Rock" && str2=="paper")
    {
        cout<<" PLAYER TWO WIN" ; 

    }
    else if (str1=="Rock" && str2=="Scissors")
    {
        cout<<" PLAYER ONE WIN" ; 

    }
     else if (str1=="Scissors" && str2=="Scissors")
    {
        cout<<" DRAW" ; 

    }
    else if (str1=="paper" && str2=="paper")
    {
        cout<<" DRAW" ; 

    }
      else if (str1=="Scissors" && str2=="paper")
    {
        cout<<" PLAYER ONE WIN" ;
    }
      else if (str1=="Scissors" && str2=="Rock")
    {
        cout<<" PLAYER TWO WIN" ;
    }
      else if (str1=="paper" && str2=="Rock")
    {
        cout<<" PLAYER ONE WIN" ;
    }
      else if (str1=="paper" && str2=="Scissors")
    {
        cout<<" PLAYER TWO WIN" ;
    }

}