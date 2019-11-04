#include <iostream>
using namespace std;

int date(int number, int &month, int &day, int &year);

int main()
{
    int month=0, day=0, year=0;

    int number;

    cout<<"enter date: MMDDYYYY: ";

    cin>>number;

    date(number, month, day, year);

    cout<<"date = "<<month<<"/"<<day<<"/"<<year<<endl;

    return 0;
}

int date(int number, int &month, int &day, int &year)
{
    month = number/1000000;
    day = (number%1000000)/10000;
    year = number%10000;
}