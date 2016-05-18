/*************************************************************************
	> File Name: a1015.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年05月18日 星期三 20时16分56秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int avert(int num, int radix){
    int res = 0;
    while(num != 0){
        res = res*radix + num%radix;
        num = num/radix;
    }
    return res;
}

bool prime(int num){
    int i;
    if(num == 1)
        return false;
    if(num == 2)
        return true;
    for(i = 2; i <= sqrt(num);++i){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int num, radix, i;
    while(true){
        cin>>num;
        if(num <= 0) break;
        cin>>radix;
        if(prime(num)){
            num = avert(num, radix);
            if(prime(num))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        else
            cout<<"No"<<endl;
    }

    return 0;
}
