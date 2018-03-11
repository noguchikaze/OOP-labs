#include<bits/stdc++.h>
using namespace  std;

typedef struct{
    double real;
    double image;
}Cplex;

int qout(Cplex x);    //quotient of x and its conjugation
Cplex complexOperation(Cplex a, Cplex b, char c);
void printComplex(Cplex* re);

int main(int argc, char* argv[])
{
    Cplex a, b;
    // promotes the user to input data
    cout<<"Enter the real and imaginary part of the first Complex number: ";
    cin>>a.real>>a.image;
    cout<<"\nEnter the real and imaginary part of the second Complex number: ";
    cin>>b.real>>b.image;
    cout<<endl;
    cout<<"First Complex number: "<<a.real<<"+"<<a.image<<endl;
    cout<<"Second Complex number: "<<b.real<<"+"<<b.image<<endl;
    // store the results of diff. operation
    Cplex results[4];
    results[0] = complexOperation(a, b, '+');
    results[1] = complexOperation(a, b, '-');
    results[2] = complexOperation(a, b, '*');
    results[3] = complexOperation(a, b, '/');
    printComplex(results);

    return 0;
}

int quot(Cplex x)
{
  return x.real*x.real + x.image*x.image;
}
Cplex complexOperation(Cplex a, Cplex b, char c)
{
  Cplex clone;
  if(c=='+')
  {
    clone.real = a.real + b.real;
    clone.image = a.image + b.image;
  }
  else if(c=='-')
  {
    clone.real = a.real - b.real;
    clone.image = a.image - b.image;
  }
  else if(c=='*')
  {
    clone.real = (a.real * b.real) - (a.image * b.image);
    clone.image = a.real * b.image + a.image * b.real;
  }
  else if(c=='/')
  {
    clone.real = (a.real * b.real + a.image * b.image)/quot(b);
    clone.image = (-(a.real * b.image)+(a.image * b.real))/quot(b);
  }
  return clone;
}
void printComplex(Cplex* re)
{
  cout<<"============================="<<endl;
  cout<<"The output results:"<<endl;
  cout<<"A+B= "<<re[0].real<<"+"<<re[0].image<<"i"<<endl;
  cout<<"A-B= "<<re[1].real<<"-"<<re[1].image<<"i"<<endl;
  cout<<"A*B= "<<re[2].real<<"*"<<re[2].image<<"i"<<endl;
  cout<<"A/B= "<<re[3].real<<"/"<<re[3].image<<"i"<<endl;
}
