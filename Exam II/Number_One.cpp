#include <iostream>
using namespace std;

int fact(int number);

int main()
{
    int number;

    cout<<"Enter number between 2 & 10"<<endl;
    do
    {
        cin>>number;
        if( (number<2)||(number>10) ){cout<<"Please enter a number between 2 & 10: ";}
    } 
    while ( (number<2)||(number>10) );

    cout<<" n = "<<number<<endl;
    cout<<"n! = "<<fact(number)<<endl;
   
    return 0;
}

int fact(int number)
{
    int sum=1;

    for(int i=1;i<number;i++)
    {
        sum = sum + sum*i;
    }
    return sum;
}