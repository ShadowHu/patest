#include<iostream>
#include<string>
#include<cctype>
using namespace std;
 
/*
broken:7+IE.
sen:   7_This_is_a_test.
 
out:   _hs_s_a_tst
*/
 
int main(){
 
string broken, sen, out;
cin>>broken>>sen;
bool flag;
bool up = false;
 
for(auto i = sen.begin();i != sen.end();++i){
    flag = false;
    for(auto j = broken.begin();j != broken.end();++j){
        if(tolower(*j) == tolower(*i)){
            flag = true;
            break;
        }
        else if(*j == '+'){
            up = true;
        }
    }
    if(up == true && ( (*i)>='A' && (*i)<= 'Z'))
        continue;
    if(flag == false){
        out += *i;
    }
}
if(out.empty() == 1)
    cout<<endl;
else
    cout<<out;
 
return 0;
}
