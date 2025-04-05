#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int query(int a,int b){cout<<"? "<<a<<" "<<b<<endl;int x;cin>>x;return x;}
void answer(int x){cout<<"! "<<x<<endl;}
int main(){
int t;cin>>t;
while(t--){
    // for(int i=0;i<=t;i++){int x;cin>>x;}
int low=2,high=999;
for(int i=0;i<10;i++){
    int mid=(low+high)/2;
    int x=query(low,mid);
    int actual=low*mid;
    if(x>actual){
        high=mid;
    }
    else{
        low=mid;
    }
}
answer(high);
}
return 0;
}