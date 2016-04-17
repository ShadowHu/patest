/*************************************************************************
	> File Name: b1017.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年04月17日 星期日 22时39分04秒
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
 
int main(){
    string a,resa;
    resa = "";
    int b,resb;
    cin>>a>>b;
    int temp = 0;
    int first = 0;
     
    for(auto i : a){
        temp = temp*10 + (i - '0');
        resb = temp/b;
        temp = temp%b;
        //cout<<resb<<" ";
        if(first == 0 && (i-'0') < b){
            first = 1;
            continue;
        }
        else{
            first = 1;
            resa = resa + to_string(resb);
        }
    }
    cout<<resa<<" "<<temp;
     
    return 0;
}
