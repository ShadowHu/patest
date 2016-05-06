/*************************************************************************
  > File Name: a1010.cpp
  > Author: Shadow Hu 
  > Mail: shadow_hu1441@163.com
  > Created Time: 2016年05月06日 星期五 15时42分59秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
using namespace std;



long long convert(string num, int rad){
    int dig, k = 0;
    long long sum = 0;
    for(auto i = num.rbegin(); i != num.rend(); ++i){
        if(isdigit(*i)){
            dig = (*i) - '0';
        }
        else{
            dig = (*i) - '0' - 39;
        }
        sum += dig*pow(rad, k);
        ++k;
    }
    return sum;
}

const long long MAX = 10000000;

int main(){
    int tag, rad;
    string a,b;
    cin>>a>>b>>tag>>rad;
    long long deca, decb;
    int i;

    if(tag == 1){
        deca = convert(a, rad);
        for(i = 1; i < MAX;++i){
            if(convert(b, i) == deca){
                cout<<i;
                return 0;
            }
            else if(convert(b, i) > deca){
                cout<<"Impossible";
                break;    
            }
        }
    }
    else{
        decb = convert(b, rad);
        for(i = 1; i < MAX;++i){
            if(convert(a, i) == decb){
                cout<<i;
                return 0;
            }
            else if(convert(a, i) > decb){    
                cout<<"Impossible";
                break;
            }
        }
    }
    return 0;
}
