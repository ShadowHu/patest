/*************************************************************************
	> File Name: a1008.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年05月06日 星期五 10时12分49秒
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i, e;
    vector<int> ele;
    for(i = 0; i < n;++i){
        cin>>e;
        ele.push_back(e);
    }
    int now = 0, time = 0;
    for(auto j = ele.begin(); j != ele.end();++j){
        if(*j - now > 0){
            time += 6*(*j-now);
            time += 5;
            now = *j;
        }
        else{
            time += 4*(now-*j);
            time += 5;
            now = *j;
        }
    }

    cout<<time;
    return 0;
}
