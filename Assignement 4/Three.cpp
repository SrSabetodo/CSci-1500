#include <iostream>
using namespace std;

void numBills(int changeDue, int &oneBills, int &fiveBills, int &tenBills, int &twentyBills); 
void coins(float changeDue, int &quarters, int &dimes, int &nickles, int &pennys);

int main()
{
    float purAmount; //amount spent on item
    float tendAmount; //cash given
    
    int billsAmount; //integer of amount due such that only bills are here
    float changeDue; //float portion of amount left

    char resp; //to keep the loop running

/*====variables for numBills====*/
    int oneBills;
    int fiveBills;
    int tenBills;
    int twentyBills;

/*=====variables for coins=====*/
    int quarters = 0;
    int dimes = 0;
    int nickles = 0;
    int pennys = 0;

    do
    {
    cout<<"Enter purchase amount: $";
    cin>>purAmount;
    cout<<"Enter amount tendered: $";
    cin>>tendAmount;

    billsAmount = tendAmount - purAmount; //this is to get an integer than we can use for calculating bills
    changeDue = (tendAmount - purAmount) - billsAmount; //this is so we get whats left on the right side of the decimal point 

    numBills(billsAmount, oneBills, fiveBills, tenBills, twentyBills);
    coins(changeDue, quarters, dimes, nickles, pennys);

    cout<<"Bills: "<<endl;
    cout<<twentyBills<<" - $20's  "<<tenBills<<" - $10's  "<<fiveBills<<" - $5's  "<<oneBills<<" - $1's"<<endl;
    cout<<"Coins: "<<endl;
    cout<<quarters<<" - quarters(s)  "<<dimes<<" - dimes(s)  "<<nickles<<" - nickle(s)  "<<pennys<<" - penny(ies)"<<endl;
    
    cout<<"Continue (y or n)? ";
    cin>>resp;
    }
    while(resp == 'y');
    
    return 0;
}

void numBills(int billsAmount, int &oneBills, int &fiveBills, int &tenBills, int &twentyBills)
{
    twentyBills = billsAmount/20;
    tenBills    = (billsAmount - (twentyBills*20))/10;
    fiveBills   = (billsAmount - ((twentyBills*20)+(tenBills*10)))/5;
    oneBills    = (billsAmount - ((twentyBills*20)+(tenBills*10)+(fiveBills*5)))/1;
}

void coins(float changeDue, int &quarters, int &dimes, int &nickles, int &pennys)
{
    quarters = changeDue/0.25;
    dimes    = (changeDue - (quarters*0.25))/0.1;
    nickles  = (changeDue - ((quarters*0.25)+(dimes*0.1)))/0.05;
    pennys   = (changeDue - ((quarters*0.25)+(dimes*0.1)+(nickles*0.05)))/0.01;
}