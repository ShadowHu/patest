#include<iostream>
#include <iomanip>
using namespace std;
 
int main(){
    int n;
    float demand;
    cin>>n>>demand;
    float yb[3][n];
    for(int i = 0;i < n;++i){ //库存
        cin>>yb[0][i];
    }
 
    for(int i = 0;i < n;++i){
        cin>>yb[2][i];//总价
        yb[1][i] = yb[2][i]/yb[0][i];//单价
    }
     
    int max;
    float sum = 0;
    while(demand > 0){
        max = 0;
        for(int i = 0;i < n;++i){
            if(yb[1][i] > yb[1][max])
                max = i;
        }
        if(demand > yb[0][max]){
            demand -= yb[0][max];
            sum    += yb[2][max];
            yb[1][max] = 0;
        }
        else{
            sum += demand*(yb[2][max] / yb[0][max]);
            demand = 0;
        }
    }
    //cout<<sum;
    cout<<fixed<<setprecision(2)<<sum;
     
    return 0;
}
