#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 501
#define MAX_M 6001
#define INF 987654321
using namespace std;

int N,M;
vector<pair<pair<int, int>,int>> edges;

bool bellman(vector<long long> &dists){
    dists[1]=0;
    for(int i=1;i<=N-1;i++){
        for(int k=0;k<edges.size();k++){
            int start = edges[k].first.first;
            int end = edges[k].first.second;
            int time = edges[k].second;
            if(dists[start]==INF)continue;
            if(dists[end]>dists[start]+time){
                dists[end] = dists[start]+time;
            }
        }
    }
    //check negative loop
    for(int i=0;i<edges.size();i++){
        int start = edges[i].first.first;
        int end = edges[i].first.second;
        int time = edges[i].second;
        if(dists[start]==INF)continue;
        if(dists[end]>dists[start]+time) return false;
    }
    return true;
}
int main(){
    vector<long long> dists(MAX_M, INF);
    cin>>N>>M;
    while(M--){
        int start,end,time;
        cin>>start>>end>>time;
        edges.push_back(make_pair(make_pair(start,end),time));
    }
    bool is_valid = bellman(dists);
    if(is_valid){
        for(int i=2;i<=N;i++){
            if(dists[i]==INF){
                cout<<-1<<"\n";
            } else {
                cout<<dists[i]<<"\n";
            }
        }
    } else {
        cout<<-1;
    }
}