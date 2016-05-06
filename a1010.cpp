/*************************************************************************
  > File Name: 1010.cpp
  > Author: Shadow Hu
  > Mail: shadow_hu1441@163.com
  > Created Time: 2016年05月06日 星期五 15时42分59秒
 ************************************************************************/
 
#include<iostream>
#include<string>
#include<cctype>
#include<cmath>
using namespace std;
 
 
 
unsigned long long convert(string num, unsigned long long rad){
    int dig, k = 0;
    unsigned long long sum = 0;
    for(auto i = num.rbegin(); i != num.rend(); ++i){
        if(isdigit(*i))
            dig = (*i) - '0';
        else
            dig = (*i) - '0' - 39;
        sum += dig*pow(rad, k);
        ++k;
    }
    return sum;
}
 
//const long long MAX = convert("zzzzzzzzzz", 5);
const unsigned long long MAX = 10000000000000000;
 
int main(){
    int tag;
    string a,b;
    unsigned long long rad, deca, decb, temp, low = 1, high = MAX, mid;
    cin>>a>>b>>tag;
    cin>>rad;
 
    if(tag == 1){
        deca = convert(a, rad);
        if(b.size() == 1){
            deca == convert(b, 1) ? cout<<"1" : cout<<"Impossible";
            return 0;
        }
 
        while(low <= high){
            mid = (low+high)/2;
            temp = convert(b, mid);
            if(temp == deca){
                cout<<mid;
                return 0;
            }
            else if(temp > deca){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
    }
    else{
        decb = convert(b, rad);
        if(a.size() == 1){
            decb == convert(a, 1) ? cout<<"1" : cout<<"Impossible";
            return 0;
        }
 
        while(low <= high){
            mid = (low+high)/2;
            temp = convert(a, mid);
            if(temp == decb){
                cout<<mid;
                return 0;
            }
            else if(temp > decb){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
    }
    cout<<"Impossible";
    //cout<<MAX<<" "<<endl;
    return 0;
}
