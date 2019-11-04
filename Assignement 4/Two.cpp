#include <iostream>
using namespace std;

const float PI = 3.141592654;

void calc(float height, float radius, float &volume, float &surfaceArea);

int main()
{
    float height;
    float radius;
    float volume;
    float surfaceArea;

    cout<<"Enter can radius (inches): ";
    cin>>radius;
    cout<<"Enter can height (inches): ";
    cin>>height;

    calc(height, radius, volume, surfaceArea);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(3);

    cout<<"Can surface area = "<<surfaceArea<<endl;
    cout<<"Can volume = "<<volume<<endl;

    return 0;
}

void calc(float height, float radius, float &volume, float &surfaceArea)
{
    volume = PI*(radius*radius)*height;
    surfaceArea = (2*PI*(radius*radius) + (2*PI*radius*height));
}
