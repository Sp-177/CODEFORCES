#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);
auto query=[&](int i,int j)->long long{
    cout<<"? "<<i<<" "<<j<<endl;
    long long mul;cin >> mul;
    return mul;
};

int arr[]={4, 8, 15, 16, 23, 42};
long long mux[6][6];
for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
        mux[i][j]=arr[i]*arr[j];
    }
}
long long ans[4];
for(int i=1;i<=4;i++){
    ans[i-1]=query(i,i+1);
}
int a=0,b=0,c=0,d=0;
for(int i=0;i<6;i++){
    for(int j=0;j<6;j++)if(ans[0]==mux[i][j]){a=arr[i];b=arr[j];break;}
    if(a!=0)break;
}
for(int i=0;i<6;i++){
    for(int j=0;j<6;j++)if(ans[1]==mux[i][j]){c=arr[i];d=arr[j];break;}
    if(c!=0)break;
}
int a_0=0;
if(a==c||a==d){
    a_0=ans[0]/a;
}
else if(b==c||b==d){
    a_0=ans[0]/b;
}
// cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
auto answer=[&](long long ans[],int a_0)->void{
    map<int,int>m;
    m[a_0]++;
    cout<<"! "<<a_0<<" ";
    for(int i=0;i<4;i++){
        int arr_i=ans[i]/a_0;
        cout<<arr_i<<" ";
        a_0=arr_i;
        m[arr_i]++;
    }
    for(int i=0;i<6;i++){
        if(m.find(arr[i])==m.end()){cout<<arr[i]<<endl;break;}
    }
    
};
answer(ans,a_0);
return 0;
}