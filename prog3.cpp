#include <iostream>
using namespace std;
class Student{
    int reg_no;
    char name[100];
    float marks[5];

    public:
    void input();
    void display();
    void total();
    void percentage();
    void getInfo(int regno,int Student[5]);
};
void Student :: input(){
    cout << "Enter Regno "<<endl;
    cin >> reg_no;
    cout<<"Enter name"<<endl;
    cin >> name;
    cout << "Enter the marks for 5 subjects "<<endl;
    for(int i=0;i<5;i++){
        cin>>marks[i];
    }



}
void Student :: total(){
    float t =0;
    for(int i=0;i<5;i++){
        t+=marks[i];
    }
    cout << " The total marks found is "<<t<<endl;
}
void Student :: percentage(){
    float t =0;
    for(int i=0;i<5;i++){
        t+=marks[i];
    }
    float val = (t/5) * 100;
    cout << " The total marks found is "<<val<<endl;
}

void Student :: getInfo(int r,int Student[5]){


}


void Student :: display(){
    cout<<"Information"<<endl;
    cout <<"Regno : "<<reg_no<<endl;

    cout<<"Name :"<<name<<endl;
    cout << "The marks for 5 subjects "<<endl;
    for(int i=0;i<5;i++){
        cout<<"Mark "<<i+1 <<marks[i]<<endl;
    }

}
int main(){
    Student st[5];
    for(int i=0;i<5;i++){
        st[i].input();
    }
    for(int i=0;i<5;i++){
        st[i].display();
    }
    for(int i=0;i<5;i++){
        cout << "Your total marks is "<< endl;
        st[i].total();
        cout<<"Your percentage is "<< endl;
        st[i].percentage();
    }


    return 0;


}
