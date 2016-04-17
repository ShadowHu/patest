#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>
using namespace std;
 
int main(){
    char a;
    int h;
    cin>>h>>a;
    string s(h,a);
    float l = h/2.0;
    //cout<<l<<endl;
    //cout<<int(l);
    if(l - int(l) >= 0.5)
        l = int(l) + 1;
    for(int i = 0; i < l;++i){
        if(i == 0)
            cout<<s<<endl;
        else if(i == l-1)
            cout<<s;
        else{
            cout<<a;
            cout<<setfill(' ')<<setw(h-1)<<a<<endl;
        }
    }
     
    return 0;
}
