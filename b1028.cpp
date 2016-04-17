#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
 
int Year(string s){
    int y = 0,i,j;
    for(i = 0,j =3; i < 4 && j >= 0;++i,--j){
        y = y + (s[i] - '0')*pow(10,j);
    }
    return y;
}
 
int Month(string s){
    int m = 0,i,j;
    for(i = 5,j =1; i < 7 && j >= 0;++i,--j){
        m = m + (s[i] - '0')*pow(10,j);
    }
    return m;
}
 
int Day(string s){
    int d = 0,i,j;
    for(i = 8,j =1; i < 10 && j >= 0;++i,--j){
        d = d + (s[i] - '0')*pow(10,j);
    }
    return d;
}
 
// int main(){
    // string s;
    // cin>>s;
    // cout<<year(s)<<" "<<month(s)<<" "<<day(s);
    // return 0;
// }
int main(){
     
    int n;
    cin>>n;
    vector<vector<string>> people(n);
    string s;
    for(int i = 0; i < n; ++i){
        cin>>s;
        people[i].push_back(s);
        cin>>s;
        people[i].push_back(s);
    }
    int oldYear = 2014, oldMonth = 12, oldDay = 31;
    int youYear = 1000, youMonth = 1, youDay = 1;
    int year, month, day;
    int real = 0;
    string oldest, youngest;
    for(auto person = people.begin(); person != people.end();++person){
        year = Year((*person)[1]);
        month = Month((*person)[1]);
        day = Day((*person)[1]);
        if((year > 2014 || (year == 2014 && month >9) || (year == 2014 && month == 9 && day >6)) || (2014 - year > 200 || (2014 - year == 200 && month < 9) || (2014 - year == 200 && month == 9 && day <6))){
            continue;
        }
        ++real;
        if(year < oldYear || (year == oldYear && month < oldMonth) || (year == oldYear && month == oldMonth && day < oldDay)){
            oldest = (*person)[0];
            oldYear = year;
            oldMonth = month;
            oldDay = day;
        }
        if(year > youYear || (year == youYear && month > youMonth) || (year == youYear && month == youMonth && day > youDay)){
            youngest = (*person)[0];
            youYear = year;
            youMonth = month;
            youDay = day;
        }
         
    }
     
    cout<<real<<" "<<oldest<<" "<<youngest;
 
     
    return 0;
}
