// Addition of 2 complex numbers using friend function

#include <iostream>
using namespace std;
class complex;
class D{
    public:
     void display(complex &x);

};

class complex {
   float real;
   float img;

   public:
   
     complex();
     complex(float i,float j);
     complex(complex &obj);
     complex operator+(complex &x);
     friend void D::display(complex &x);




};
complex::complex(){
    real=0.0f;
    img=0.0f;
}
complex::complex(float i,float j){
    real=i;
    img=j;
}
complex::complex(complex &obj){
    real=obj.real;
    img=obj.img;
}

complex complex :: operator+(complex &x){
    complex sum;
    sum.real=real+x.real;
    sum.img=img+x.img;
    return sum;
}

// We need to follow the sequence after complex we need to use the display method
void D::display(complex &x){
    cout<<x.real<<" + "<<x.img<<"i"<<endl;
}

int main(){
    complex a;
    complex b(2.0f,3.0f);
    complex c(b);
    a=b+c; // a=b.operator+(c)
    D dis;
    dis.display(b);
    dis.display(c);
    dis.display(a);
    
    return 0;
}