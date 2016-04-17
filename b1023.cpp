#include<iostream>
using namespace std;
 
int main(){
    int a[10];
    for(int i = 0;i<10;++i){
        cin>>a[i];
    }
    int haveZero = 0;
    if(a[0] != 0)
        haveZero = 1;
     
    int first = 0;
    for(int i = 1;i < 10;++i){
        if(haveZero == 0){
            for(int j = 0;j < a[i];++j){
                cout<<i;
            }
        }
        else{
            if(first == 0 && a[i] != 0){
                cout<<i;
                for(int j = 0;j < a[0];++j)
                    cout<<"0";
                for(int j = 0;j < a[i]-1;++j)
                    cout<<i;
                first = 1;
            }
            else if(first == 1){
                for(int j = 0;j < a[i];++j)
                    cout<<i;
            }
        }
    }
     
    return 0;
}
