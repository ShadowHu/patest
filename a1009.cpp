/*************************************************************************
	> File Name: a1009.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年05月06日 星期五 10时36分51秒
 ************************************************************************/

#include<iostream>
#include<iomanip>
#include<map>
using namespace std;

int main(){
    int n1,n2;
    int i,ex;
    double co;
    map<int, double> poly1;
    map<int, double> poly2;
    map<int, double> res;
    cin>>n1;
    for(i = 0;i < n1;++i){
        cin>>ex>>co;
        poly1[ex] = co;
    }
    cin>>n2;
    for(i = 0;i < n2;++i){
        cin>>ex>>co;
        poly2[ex] = co;
    }
    
    for(auto j = poly1.begin(); j != poly1.end();++j){
        for(auto k = poly2.begin(); k != poly2.end();++k){
            ex = j->first + k->first;
            co = j->second * k->second;
            if(res.find(ex) == res.end()){
                res[ex] = co;
            }
            else{
                res[ex] += co;
            }
        }
    }
    int zero = -1;//把0减去
    for(auto &x: res){
        if(x.second == 0){
            zero = x.first;
        }
    }
    if(res.find(zero) != res.end())
        res.erase(res.find(zero));
    cout<<res.size();
    for(auto j = res.rbegin(); j != res.rend();++j ){
        cout<<" "<<j->first<<" "<<fixed<<setprecision(1)<<j->second;
    }

    return 0;
}
