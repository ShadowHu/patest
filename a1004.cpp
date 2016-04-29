/*************************************************************************
	> File Name: a1004.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年04月24日 星期日 18时12分53秒
 ************************************************************************/
//求每层的叶子结点数

#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

const int maxSize = 100;

typedef struct ArcNode{
    string adjvex;
    struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
    ArcNode *firstarc;
    string data;
}VNode;

typedef struct AGraph{
    VNode adjlist[maxSize];
    int n,e,m;
}AGraph;

VNode* findinlist(ArcNode *p, AGraph *g){
    int j;
    for(j = 0; j < g->m; ++j){
        if(g->adjlist[j].data == p->adjvex){
            return &(g->adjlist[j]);
        }
    }
    return NULL;
}

void f(AGraph *g){
    /*int i,j,u;
    int leaf[maxSize] = {0};
    int floor = 0;
    ArcNode *p;
    bool have = true;
    int maxfloor = 0;
    for(i = 0; i < m;++i){
        p = g->adjlist[i].firstarc;
        while(p->set == true && p != NULL)
            p = p->nextarc;
        while(have == true && p->set == false && p != NULL){
            p->set = true;
            have = false;
            for(j = 0; j < m; ++j){
                if(g->adjlist[j].data == p->adjvex){
                    have = true;
                    u = j;
                }
            }
            if(have == false){
                ++leaf[floor];
            }
            else{
                p = g->adjlist[u].firstarc;
                ++floor;
            }
        }
    }
    for()*/
    int i;
    vector<string> samefloor;
    samefloor.push_back(g->adjlist[0].data);
    int floor = 0;
    int leaf[maxSize] = {0};
    if(g->m == 0){
        cout<<"1";
        return;
    }
    for(i = 0; i < g->m;++i){
        if(g->adjlist[i].data == samefloor[0])
            ++floor;
        samefloor.clear();
        ArcNode *p = g->adjlist[i].firstarc;
        while( p != NULL ){
            if(findinlist(p, g) == NULL){
                ++leaf[floor];
            }
            else{
                samefloor.push_back(findinlist(p,g)->data);
            }
            p = p->nextarc;
        }

    }
    for(i = 0;i <= floor;++i){
        if(i != floor){
            cout<<leaf[i]<<" ";
        }
        else{
            cout<<leaf[i];
        }
    }
}

int main(){
    AGraph g;
    cin>>g.n>>g.m;
    int i,j,chnum;
    string fa, ch;
    ArcNode *p, *q;

    for(i = 0;i < g.m;++i){//初始化鄰接表
        cin>>fa;
        cin>>chnum;
        (g.adjlist[i]).data = fa;
        p = (ArcNode*)malloc(sizeof(ArcNode));
        cin>>ch;
        p->adjvex = ch;
        (g.adjlist[i]).firstarc = p;
        for(j = 1; j < chnum;++j){
            q = (ArcNode*)malloc(sizeof(ArcNode));
            cin>>ch;
            q->adjvex = ch;
            //q->nextarc = p->nextarc;
            
            p->nextarc = q;
            //p->nextarc = q;
            //p = p->nextarc;
        }
        p->nextarc = NULL;
    }

    f(&g);


    return 0;
}
