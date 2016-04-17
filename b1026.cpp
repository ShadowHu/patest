#include<iostream>
#include<cmath>
using namespace std;
 
int main(){
     
    float c1,c2;
    cin>>c1>>c2;
    float sumSec = (c2 - c1)/100.0;
    int hour = sumSec/3600;
    int minute = (sumSec - (hour*3600))/60;
    float second = sumSec - (hour*3600) - minute*60;
    if(hour < 10)
        cout<<"0"<<hour<<":";
    else
        cout<<hour<<":";
    if(minute < 10)
        cout<<"0"<<minute<<":";
    else
        cout<<minute<<":";
    if(second < 10)
        cout<<"0"<<round(second);
    else
        cout<<round(second);
    return 0;
}
