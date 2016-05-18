/*************************************************************************
	> File Name: a1012.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年05月07日 星期六 23时30分34秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){
    int n,m,i,j,k;
    cin>>n>>m;

    map<string, int> id;
    int a[2000][4];
    string s;
    string sub = "ACME";
    for(i = 0;i < n; ++i){
        cin>>s;
        id[s] = i;
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        a[i][0] = (a[i][1]+a[i][2]+a[i][3])/3;
    }
    
    int rank[2000][4];
    for(i = 0; i < 4; ++i){
        int have[101] = {0};
        for(j = 0; j < n; ++j){
            for(k = 0;k < a[j][i];++k){
                ++have[k];
            }
        }
        for(j = 0; j < n; ++j){
            rank[j][i] = have[a[j][i]] + 1;
        }
    }

    int ind, su, min;
    for(i = 0; i < m; ++i){
        cin>>s;
        if(id.find(s) == id.end()){
            cout<<"N/A"<<endl;
        }
        else{
            ind = (id.find(s))->second;
            min = 2001;
            for(j = 0; j < 4;++j){
                if(rank[ind][j] < min){
                    min = rank[ind][j];
                    su = j;
                }
            }
            cout<<min<<" "<<sub[su]<<endl;
        }
    }

    return 0;
}
