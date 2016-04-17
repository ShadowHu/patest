/*************************************************************************
	> File Name: b1021.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年04月17日 星期日 22时26分55秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
 
int main(){
    string num;
    cin>>num;
     
    int a[10] = {0,0,0,0,0,0,0,0,0,0};
     
     
    for(auto i : num){
        a[i - '0']++;
    }
     
    int j = 0;
    for(auto item : a){
        if(item != 0){
            cout<<j<<":"<<item<<endl;
        }
        j++;
    }
     
    return 0;
}
