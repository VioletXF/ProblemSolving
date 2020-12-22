#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int L;
    int S[50];
    int n;
    cin>>L;
    for(int i=0;i<L;i++){
        cin>>S[i];
    }
    int left = 1000;
    int right = 1000;
    cin>>n;
    for(int i=0;i<L;i++){
        if(S[i]-n<=0){
            left = min(left, n-S[i]);
        }
        if(S[i]-n>=0){
            right = min(right, S[i]-n);
        }
    }
    if(left==1000){
        left = 1;
    } else {
        left=n-left+1;
    }
    if(right!=1000){
        right=n+right-1;
    }
    if(right<=left){
        cout<<0;
    } else {
        cout<<(n-left+1)*(right-n+1)-1;
    }

}