#include <iostream>
using namespace std;

class Rectangle {
  int length, breadth;
  public :
    void perimeter();
    void area();
    void setdim();
    void getdim();

};

void Rectangle::setdim(){
  cout<<"Enter the length and breadth"<<endl;
   cin >> length >> breadth;
}
void Rectangle::getdim(){
  cout<<length<<" "<<breadth<<endl;
}
void Rectangle::perimeter(){
  cout<<"The Perimeter is "<<2*(length+breadth)<<endl;
}
void Rectangle::area(){
  cout<<"The Area is "<<length*breadth<<endl;
}

int main(){
  Rectangle r1;
  r1.setdim();
  r1.getdim();
  r1.perimeter();
  r1.area();
}
