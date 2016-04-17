#include<iostream>
using namespace std;
 
int Search(int a[], int item, int n){ //在数组a中查找数字n，返回n的个数
    int k = 0;
    for(int i = 0;i < item;++i){
        if(a[i] == n){
            ++k;
        }
    }
    return k;
}
 
int main(){
     
    int n;
    cin>>n;
    int scores[n];
    for(int i = 0;i < n;++i){
        cin>>scores[i];
    }
    int k;
    cin>>k;
    int check[k];
    for(int i = 0;i < k;++i){
        cin>>check[i];
    }
     
    for(int i = 0;i < k;++i){
        cout<<Search(scores, n, check[i]);
        if(i < k - 1){
            cout<<" ";
        }
    }
     
    return 0;
}
