/*************************************************************************
	> File Name: a1003.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年04月19日 星期二 21时42分53秒
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int maxSize = 500;
const int inf = 10000000;

class AGraph{
public:
    int a[maxSize][maxSize];
    int n,e;
    int team[maxSize];
};

void f(AGraph g, int c1, int c2){
    int dist[g.n];
    vector<int> path;
    int people[g.n];
    int i, j;
    int set[g.n];
    vector<int> U;//U里面放路径一样的点

    for(i = 0; i < g.n; ++i){
        dist[i] = g.a[c1][i];
        if(dist[i] < inf)
            people[i] = g.team[c1] + g.team[i];
        set[i] = 0;
    }
    set[c1] = 1;
    path.push_back(dist[c2]);
    
    int u, min;
    for(i = 0; i < g.n; ++i){//i只是循环的次数
        min = inf;
        U.clear();
        for(j = 0; j < g.n; ++j){//找到距离起点最短的那个点
            if(dist[j] < min && set[j] != 1){
                min = dist[j];
            }
        }
        for(j = 0; j < g.n; ++j){//距离起点最短的点可能有多个
            if(dist[j] == min)
                U.push_back(j);
        }
        for(auto u: U){
            set[u] = 1;
            for(j = 0; j < g.n;++j){//以刚才的点为中间点，计算起点到别的点的最短距离
                if(dist[u]+g.a[u][j]<=dist[j] && u != j){
                    dist[j] = dist[u] + g.a[u][j];
                    if(people[u] + g.team[j] > people[j]){
                        people[j] = people[u] + g.team[j];
                    }
                    if(j == c2){
                        path.push_back(dist[j]);
                    }
                }
            }
        }
    }
    sort(path.begin(), path.end());
    cout<< count(path.begin(), path.end(), *(path.begin()))<<" "<<people[c2];
}

int main(){
    AGraph g;
    cin>>g.n>>g.e;
    int c1, c2;
    cin>>c1>>c2;
    int i, j, t1, t2, t3;
    for(i = 0; i < g.n;++i)
        cin>>g.team[i];
    for(i = 0; i < g.n;++i){
        for(j = 0;j < g.n;++j){
            if( i == j )
                g.a[i][j] = 0;
            else
                g.a[i][j] = inf;
        }
    }
    for(i = 0; i < g.e;++i){
        cin>>t1>>t2>>t3;
        g.a[t1][t2] = t3;
        g.a[t2][t1] = t3;
    }

    f(g, c1, c2);

    return 0;
}
