/*************************************************************************
	> File Name: a1006.cpp
	> Author: Shadow Hu 
	> Mail: shadow_hu1441@163.com
	> Created Time: 2016年05月02日 星期一 23时11分52秒
 ************************************************************************/

#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int i;
    string s1, s2, s3;
    vector<string> vec;
    map<string, vector<string> > m;
    for(i = 0; i < n;++i){
        cin>>s1>>s2>>s3;
        vec.push_back(s2);
        vec.push_back(s3);
        m.insert(pair<string,vector<string> > (s1, vec));
        vec.clear();
    }

    string unlockHour, unlockMin, unlockSec;
    string lockHour, lockMin, lockSec;
    int uh, um, us, lh, lm, ls;
    int firHour = 24, firMin = 60, firSec = 60;
    int lastHour = 0, lastMin = 0, lastSec = 0;
    string unlock, lock;
    for(auto it = m.begin(); it != m.end(); ++it){
        unlockHour = (it->second)[0].substr(0, 2); uh = stoi(unlockHour);
        unlockMin = (it->second)[0].substr(3, 2); um = stoi(unlockMin);
        unlockSec = (it->second)[0].substr(6, 2); us = stoi(unlockSec);
        lockHour = (it->second)[1].substr(0,2); lh = stoi(lockHour);
        lockMin = (it->second)[1].substr(3, 2); lm = stoi(lockMin);
        lockSec = (it->second)[1].substr(6, 2); ls = stoi(lockSec);
        if( (uh < firHour) || (uh == firHour && um < firMin) || (uh == firHour && um == firMin && us < firSec)){
            unlock = it->first;
            firHour = uh;
            firMin = um;
            firSec = us;
        }
        if( (lh > lastHour) || (lh == lastHour && lm > lastMin) || (lh == lastHour && lm == lastMin && ls > lastSec)){
            lock = it->first;
            lastHour = lh;
            lastMin = lm;
            lastSec = ls;
        }

        //cout<<uh<<" "<<um<<" "<<us<<endl;
        //cout<<lh<<" "<<lm<<" "<<ls<<endl;
    }

    cout<<unlock<<" "<<lock;
    return 0;
}
