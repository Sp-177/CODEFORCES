#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int>parent;
    vector<int>size;
    DSU(int n,int arr[]){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++)parent[i]=i;
        for(int i=0;i<n;i++)size[i]=arr[i];
    }
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    void uni(int x,int y){
        int px=find(x);
        int s_x=max(size[px],size[x]);
        int py=find(y);
        int s_y=max(size[py],size[y]);
        if(s_x<=s_y){
            parent[px]=py;parent[x]=py;parent[y]=py;parent[py]=py;
            size[px]=s_y;size[x]=s_y;size[py]=s_y;size[y]=s_y;
        }
        else{   
             parent[py]=px;parent[y]=px;parent[x]=px;parent[px]=px;
            size[px]=s_x;size[x]=s_x;size[py]=s_x;size[y]=s_x;

        }
        
    }
};

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
int t;cin>>t;
while(t--){
    int n;cin >> n;
    int heights[n]; 
    for(int i=0;i<n;i++)cin>>heights[i];
    pair<int,int> min_height[n],max_height[n];
    min_height[n-1].first=heights[n-1];
    min_height[n-1].second=n-1;
    for(int i=n-2;i>=0;i--){
        min_height[i].first=min(min_height[i+1].first,heights[i]);
        if(min_height[i].first<min_height[i+1].first){
            min_height[i].second=i;
        }else{
            min_height[i].second=min_height[i+1].second;
        }
    }
    max_height[0].first=heights[0];
    max_height[0].second=0;
    
    DSU *obj=new DSU(n,heights);

    for(int i=0;i<n;i++){
        int curr_height=heights[i];
        if(i+1<n){
            int mini=min_height[i+1].first,mini_i=min_height[i+1].second;
            if(curr_height>mini){
                obj->uni(i,mini_i);
            }
            if(i-1>=0){
                int maxi=max_height[i-1].first,maxi_i=max_height[i-1].second;
                if(mini<maxi){
                    obj->uni(mini_i,maxi_i);
                }
            }

        }
        if(i-1>=0){
            if(i-1>=0){
                int maxi=max_height[i-1].first,maxi_i=max_height[i-1].second;
                if(curr_height<maxi){
                    obj->uni(i,maxi_i);
                }
                if(i+1<n){
                    int mini=min_height[i+1].first,mini_i=min_height[i+1].second;
                    if(maxi>mini){
                        obj->uni(maxi_i,mini_i);
                    }
                }
                if(maxi<heights[i]){
                    max_height[i].first=heights[i];
                    max_height[i].second=i;
                }
                else{
                    max_height[i].first=maxi;
                    max_height[i].second=maxi_i;
                }
            }
           
        }
    }
    for(int i=0;i<n;i++){
        cout<<heights[obj->find(i)]<<" ";
    }
    cout<<endl;
}

return 0;
}