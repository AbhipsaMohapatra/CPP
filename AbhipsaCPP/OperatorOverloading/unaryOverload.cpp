#include <iostream>
using namespace std;

class matrix{
    float  mat[2][2];

    public:
      void pushVal(){
        cout<<"Enter the data "<<endl;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cin>>mat[i][j];
            }
        }
      }
      void display(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n"<<endl;
        }

      }
      void operator++(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                mat[i][j]++;
               
            }
            
        }

      }
      void operator+(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                mat[i][j]++;
               
            }
            
        }

      }
      
      void operator--(){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                mat[i][j]--;
               
            }
            
        }

      }
};
int main(){
    matrix m;
    m.pushVal();
    m.display();
    ++m;
    m.display();
    --m;
    //m+; //error
   
    
    m.display();
    return 0;

}

