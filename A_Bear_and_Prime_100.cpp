
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);
auto query=[&](int num)->string{
    cout<<num<<endl;
    string resp;
    cin>>resp;
    return resp;
};
auto answer=[&](int num)->void{
    if(num>1)cout<<"composite"<<endl;
    else cout<<"prime"<<endl;
    return ;
};    
int arr[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
int cnt=0;
for(int i:arr){
    string resp=query(i);
    if(resp=="yes"){
        cnt++;
        if(i*i<=100&&query(i*i)=="yes"){cnt++;break;}
    }
    if(cnt>1)break;
}
answer(cnt);
return 0;
}