//2019-08-05 02:29:38
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    cout<<min({x,y,abs(x-w),abs(y-h)});
}
