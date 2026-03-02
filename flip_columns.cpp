#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m,k,ans=INT_MIN;
    unordered_map<string,int>freq;
    cin>>n>>m>>k;
    
    for(int i=0;i<n;i++){
        int zeroes=0;
        string tmp="";
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            
            if(x==0)zeroes++;
            
            tmp+='0'+x;
        }
        if(zeroes<=k and (k-zeroes)%2==0)
            freq[tmp]++;
    }
    
    for(auto it:freq){
        if(it.second>ans)ans=it.second;
    }
    
    cout<<ans<<endl;
    
    return 0;
}
