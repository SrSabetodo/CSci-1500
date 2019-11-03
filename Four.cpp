#include <iostream>
using namespace std;

double calc(double n,int q);

int main()
{
    int q;
    double n;

    cout<<"Enter a number n: ";
    cin>>n;
    cout<<"Enter a power q: ";
    cin>>q;

    cout<<"The sum = "<<calc(n,q);

    return 0;
}

double calc(double n,int q)
{
    double sum = n;

    for(int i=1;i<q;i++)
    {
        sum = sum*n;
    }
    
return sum;
}