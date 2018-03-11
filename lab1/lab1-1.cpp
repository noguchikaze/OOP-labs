//write a program that prompts the user for the radius of the circle
//then calls inline function circleArea to calculate the area of the circle
#include<iostream>
#include<stdlib.h>
#define PI 3.14159
using namespace std;

inline double circleArea(int x){return PI*x*x;}

int main()
{
    int rad;  //radius
    cout<<"Enter the radius of the circle: ";
    cin>>rad;
    cout<<"\nThe area of the circle is "<<circleArea(rad)<<endl;
    return 0;
}
