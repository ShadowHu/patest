#include<iostream>
#include<vector>
using namespace std;
 
int main(){
    int a, b, d, res, dig;
    cin>>a>>b>>d;
     
    vector<int> fin;
    res = a + b;
    while(res != 0){
        fin.push_back(res%d);
        res = res/d;
    }
    for(int i = fin.size()-1;i >= 0;--i){
        cout<<fin[i];
    }
     
    return 0;
}
