#include <iostream>
using namespace std;
struct Circle{
    int x, y, r;
};
int isInside(int x, int y, Circle c){
    return ( (x-c.x)*(x-c.x) + (y-c.y)*(y-c.y) ) < (c.r * c.r);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;
        int n;
        cin>>n;
        int cnt = 0;
        while(n--){
            Circle c;
            cin>>c.x>>c.y>>c.r;
            if(isInside(x1, y1, c) + isInside(x2, y2, c) == 1){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
}