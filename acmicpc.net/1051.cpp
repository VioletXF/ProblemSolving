#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    int arr[50][50];
    int N, M;
    cin>>N>>M;
    int maxLength = min(N, M);
    for (int i = 0; i < N; i++){
        string temp;
        cin >> temp;
        for (int j = 0; j < M; j++)
            arr[i][j] = temp[j] - '0';
    }

    int current = 0;
    for(int len=1;len<=maxLength;len++){
        int offset = len-1;
        for(int y=0;y<N-len+1;y++){
            for(int x=0;x<M-len+1;x++){
                int num = arr[y][x];
                if(arr[y+offset][x] == num
                && arr[y][x+offset] == num
                && arr[y+offset][x+offset] == num){
                    current = max(len, current);
                }
            }
        }
    } 
    cout<<current*current;
}