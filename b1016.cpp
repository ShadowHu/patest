/*************************************************************************
	> File Name: b1016.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年04月17日 星期日 22时20分35秒
 ************************************************************************/

#include<iostream>
using namespace std;
 
int funP(int a, int da){
    int ia;
    int na = 0;
     
    while(a!=0){
        ia = a%10;
        if(ia == da)
            na++;
        a = a/10;
    }
    int pa = 0;
    for(int i = 0;i < na;i++){
        pa = pa*10 + da;
    }
    return pa;
}
 
int main(){
    int a, b, da, db;
    cin>>a>>da>>b>>db;
     
    cout<<funP(a,da)+funP(b,db);
     
    return 0;
}
