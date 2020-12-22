#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int num;
    int m=0,n=1000000;
    cin>>num;
    for(int i=0;i<num;i++){
        int temp;
        cin>>temp;
        m = max(m,temp);
        n = min(n,temp);
    }
    cout<<m*n;
}