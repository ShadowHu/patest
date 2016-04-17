/*************************************************************************
	> File Name: b1011.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年04月17日 星期日 21时04分52秒
 ************************************************************************/

#include<iostream>
using namespace std;

int main(){
     
    int iter;
    long a,b,c;
     
    cin>>iter;
     
    for(int i=1;i <= iter;i++){
        cin>>a>>b>>c;
         
        if(a+b>c){
            cout<<"Case #"<<i<<": true"<<endl;
        }
        else{
            cout<<"Case #"<<i<<": false"<<endl;
        }
    }
     
    return 0;
}
