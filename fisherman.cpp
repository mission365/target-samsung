#include<bits/stdc++.h>
using namespace std;

//check for all comination of gates
vector<vector<int>> gateComb = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0}
};

int n;

//place optimally near the index of gate
int place(int gate, int cnt, vector<int>&vis){
    int d = 0;

    //place all people from gate.
    for(int i=0; i<cnt; i++){
        //if the index of gate is free place here
        if(!vis[gate]){
            d+= 1;
            vis[gate] = 1;
            continue;
        }

        //check nearest free place both in left and right
        int l = gate - 1, r = gate + 1;

        while(l>=0 and vis[l])l--;
        while(r<n and vis[r]) r++;

        //if left is valid and closer to the gate place it. here +1 is for entering the first fishing spot from gate
        if(l<r and l>=0){
            vis[l] = 1;
            d += gate - l + 1;
        }
        else{
            vis[r] = 1;
            d+= r - gate + 1;
        }
    }
    return d;
}
int main(){
    cin>>n;

    vector<int>gate(3), people(3);
    for(auto &it: gate)cin>>it;
    for(auto &it: people)cin>>it;
    int ans = INT_MAX;

    for(int i=0; i<6; i++){
        int d = 0;
        vector<int>vis(n, 0);

        //check for all comination of gate
        for(auto &it: gateComb[i]){
            d += place(gate[it] - 1, people[it], vis);
        }
        ans = min(ans, d);
    }
    cout<<ans<<"\n";
}
