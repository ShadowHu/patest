/*************************************************************************
	> File Name: a1005.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年05月02日 星期一 21时16分09秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
#include<sstream>
using namespace std;

int main(){
    string s;
    cin>>s;
    map<int, string> m;
    int num = 0;
    for(auto i: s){
        num += stoi(string(&i));
    }
    m.insert(pair<int, string> (0,"zero"));
    m.insert(pair<int, string> (2,"two"));
    m.insert(pair<int, string> (3,"three"));
    m.insert(pair<int, string> (4,"four"));
    m.insert(pair<int, string> (5,"five"));
    m.insert(pair<int, string> (6,"six"));
    m.insert(pair<int, string> (7,"seven"));
    m.insert(pair<int, string> (8,"eight"));
    m.insert(pair<int, string> (9,"nine"));
    m.insert(pair<int, string> (1,"one"));
    stringstream ss;
    string snum;
    ss<<num;
    ss>>snum;
    int o;
    for(int j = 0; j < snum.size(); ++j){
        o = snum[j] - '0';
        auto out = m.find(o);
        if(j != snum.size() - 1){    
            cout<<out->second<<" ";
        }
        else cout<<out->second;
    }
    return 0;
}
