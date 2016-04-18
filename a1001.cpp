#include<iostream>
#include<string>
using namespace std;

int main(){
  int a,b,c;
  cin>>a>>b;
  c = a+b;
  string s, res;
  s = to_string(c);
  int count = 0;
  auto i = s.end();
  for(i = s.end()-1; i != s.begin()-1;--i){
    if(isdigit(*i) == true)//数字
    {
      count++;
      if(count%3 == 1 && count != 1){
        res = "," + res;
      }
      res = *i + res;
    }
    else{    //负号
      res = *i + res;
    }
  }
  cout<<res;
  return 0;
}
