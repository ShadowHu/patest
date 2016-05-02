/*************************************************************************
	> File Name: a1004.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年04月24日 星期日 18时12分53秒
 ************************************************************************/
//求每层的叶子结点数,目前的問題在於，輸入的例子如果不按照一層接着一層來就不行

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

const int maxSize = 100;

struct ArcNode{
    int adjvex;
    int arcfl;
    struct ArcNode *nextarc = NULL;
};

struct VNode{
    ArcNode *firstarc;
    int data;
    int fl;
};

struct AGraph{
    VNode adjlist[maxSize];
    int n,e,m;
};

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
    int i;
    g->adjlist[0].fl = 0;
    int floor = 0;
    int leaf[maxSize] = {0};
    
    if(g->m == 0){
        cout<<g->n;
        return;
    }
    for(i = 0; i < g->m;++i){
        ArcNode *p = g->adjlist[i].firstarc;
        while( p != NULL ){
            p->arcfl = g->adjlist[i].fl + 1;
            floor = floor > p->arcfl?floor:p->arcfl;
            if(findinlist(p, g) == NULL){
                ++leaf[p->arcfl];
            }
            else{
                findinlist(p,g)->fl = p->arcfl;
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
    int fa, ch;
    ArcNode *q;

    for(i = 0;i < g.m;++i){//初始化鄰接表
        cin>>fa;
        cin>>chnum;
        (g.adjlist[i]).data = fa;
        cin>>ch;
        (g.adjlist[i]).firstarc = new ArcNode;
        (g.adjlist[i]).firstarc->adjvex = ch;
        ArcNode *p = (g.adjlist[i]).firstarc;
        for(j = 1; j < chnum;++j){
            q = new ArcNode;
            cin>>ch;
            q->adjvex = ch;
            p->nextarc = q;
            p = q;
        }
    }

    f(&g);

    return 0;
}
