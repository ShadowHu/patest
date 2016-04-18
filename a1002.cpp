#include<iostream>
#include<vector>
#include<list>
#include<iomanip>
using namespace std;


int main(){
    
    vector<float> poly;
    list<vector<float> > a;
    list<vector<float> > b;

    int ka, kb;
    float ex, co;
    cin>>ka;
    for(int i = 0; i < ka; ++i){
        cin>>ex>>co;
        poly.push_back(ex);
        poly.push_back(co);
        a.push_back(poly);
        poly.clear();
    }

    cin>>kb;
    for(int i = 0; i < kb; ++i){
        cin>>ex>>co;
        poly.push_back(ex);
        poly.push_back(co);
        b.push_back(poly);
        poly.clear();
    }

    auto ia = a.begin();
    auto ib = b.begin();
    while( ia != a.end() && ib != b.end() ){ //定位a，移动b的迭代器，把b插入a
        if( (*ib)[0] > (*ia)[0] ){
            a.insert(ia, *ib); 
            ++ib;
        }
        else if( (*ib)[0] == (*ia)[0] ){
            (*ia)[1] += (*ib)[1];
            ++ib;
        }
        else{
            ++ia;
        }
    }

    if(ia == a.end()){
        a.insert(a.end(), ib, b.end());
    }
    
    for(auto i = a.begin(); i != a.end(); ++i){
        if((*i)[1] == 0)
            i = a.erase(i);
    }
    if(a.size() == 0)
        cout<<a.size();
    else
        cout<<a.size()<<" ";

    for(auto i = a.begin(); i != a.end(); ++i){
        cout<<fixed<<setprecision(0)<<(*i)[0]<<" ";
        cout<<fixed<<setprecision(1)<<(*i)[1];
        if(i != --a.end())
            cout<<" ";
    }

    return 0;

}
