#include <iostream>
using namespace std;
int sum(int n){
    return n*(n+1)/2;
}
int main(){
    int N, L;
    cin>>N>>L;
    for(int i=L;i<=100;i++){
        // N == start + (start+1) + (start+2) + ... + (start+(L-1))
        // N == start * L + sum(L-1)
        // start == (N-sum(L-1))/L
        int sumL = sum(i-1);
        int start = (N-sumL)/i;
        if(start>=0&&(N-sumL)%i==0){
            for(int k=start;k<start+i;k++){
                cout<<k<<" ";
            }
            return 0;
        }
    }
    cout<<-1;
}