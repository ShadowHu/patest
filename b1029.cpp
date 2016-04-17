#include<iostream>
#include<string>
#include<cctype>
using namespace std;
 
int main(){
     
    string input, realInput;
    cin>>input>>realInput;
     
    auto iterInput = input.begin();
    auto iterReal = realInput.begin();
    string res;
    int flag;
    string c;
    while(iterInput != input.end()){
            if(*iterInput == *iterReal){
                ++iterInput;
                ++iterReal;
            }
            else{
                flag = 0;
                for(auto i : res){
                    if(toupper(*iterInput) == toupper(i)){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 1){
                     
                    ++iterInput;
                    continue;
                     
                     
                }
                res = res + *iterInput;
                c = toupper(*iterInput);
                cout<<c;
                ++iterInput;
            }
    }
     
    return 0;
}
