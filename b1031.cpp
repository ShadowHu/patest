#include<iostream>
#include<string>
#include<vector>
#include<cctype>
using namespace std;
 
 
     
 
int main(){
     
    int n;
    string s;
    vector<string> vec;
     
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>s;
        vec.push_back(s);
    }
     
    int sum,k,flag,pass = 0;
    char e;
    int arr[17];
    int weight[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char check[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    for(auto i = vec.begin(); i != vec.end();++i){
        e = (*i)[17];
        sum = 0;
        flag=0;
        for(k = 0;k < 17;++k){
            if(!isdigit((*i)[k])){
                flag = 1;
            }
            arr[k] = (*i)[k] - '0';
            sum += arr[k]*weight[k];
             
        }
        if(flag == 1){
            cout<<*i<<endl;
            pass = 1;
        }else{
        sum %= 11;
        if(check[sum] != e){
            cout<<*i<<endl;
            pass = 1;
        }
        }
    }
    if(pass == 0){
        cout<<"All passed";
    }
    return 0;
}
