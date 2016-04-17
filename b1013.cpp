/*************************************************************************
	> File Name: b1013.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年04月17日 星期日 22时19分00秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
 
int yon(int a){
     
    for(double i = 2;i<=sqrt(double(a));i++){
        if(a%int(i) == 0)
            return 0;
    }
    return 1;
}
 
int main(){
     
    int m, n;
    cin>>m>>n;
    int item = 1;
    int ss = 0;
    while(true){
        ++item;
        if(yon(item) == 1){
            ++ss;
            if(ss>=m && ss<n){
                if((ss-m-9)% 10==0 && ss != m){
                    cout<<item<<endl;
                    continue;
                }
                else{
                cout<<item<<" ";
                continue;
                }
            }
            else if(ss == n){
                cout<<item;
                continue;
            }
            else if(ss>n)
                break;
        }
    }
    return 0;
}
