#include<iostream>
#include<string>
#include<cmath>
using namespace std;
 
int main(){
     
    char mark;
    int num;
    cin>>num>>mark;
    string out;
    string t;
     
    int top = sqrt((num+1)*2) - 1;
    if(top % 2 == 0)
        --top;
     
    for(int i = top; i >= top*(-1); i -= 2){
        if( i == -1)
            continue;
        out = string(abs(i),mark);
        t = string((top - abs(i))/2, ' ');
        cout<<t<<out<<endl;
    }
     
    cout<< num - (((top+1)*(top+1))/2-1);
     
    return 0;
}
