#include <iostream>
using namespace std;
int arr[30][30]={};
int ncr(int n, int r){
    if(r==0)return 1;
    if(n==r)return 1;
    int left, right;
    if(arr[n][r])return arr[n][r];
    return arr[n][r] = ncr(n-1,r-1)+ncr(n-1,r);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M;
        cin>>N>>M;
        cout<<ncr(M,N)<<"\n";
    }
}