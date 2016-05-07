/*************************************************************************
	> File Name: a1011.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年05月07日 星期六 22时14分58秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main(){
    int i ,j;
    int f[3];
    double a[3];
    double t, max = 0;
    for(j = 0; j < 3; ++j){
        max = 0;
        for(i = 1; i <= 3; ++i){
            cin>>t;
            if(t > max){
                max = t;
                a[j] = t;
                f[j] = i;
            }
        }
    }

    double res = 1;
    for(i = 0; i < 3;++i){
        switch(f[i]){
            case 1:
                cout<<"W"<<" ";
                break;
            case 2:
                cout<<"T"<<" ";
                break;
            case 3:
                cout<<"L"<<" ";
                break;
        }
        res *= a[i];
    }

    res = (res*0.65 - 1)*2;
//    res = (res*100 + 0.5)/100.0;
    cout<<fixed<<setprecision(2)<<res;
//    cout<<res;
    return 0;
}
