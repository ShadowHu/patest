#include<iostream>
#include<string>
using namespace std;
 
 
int main(){
     
    string s;
    cin>>s;
    int p = 0, pa = 0, pat = 0;
    for(auto i : s){
        if(i == 'P')
            ++p;
        else if(i == 'A'){
            pa += p;
            pa %= 1000000007;
        }
        else{
            pat += pa;
            pat %= 1000000007;
        }
    }
    cout<<pat;
     
    return 0;
}
