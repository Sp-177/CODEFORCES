#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
int n;cin>>n;
if(n<3)cout<<-1<<endl;
else if(n==3)cout<<210<<endl;
else{
    vector<string >arr={"50","80","170","20","200","110"};
    n-=4;
    int index=n%6;
    cout<<'1';
    for(int i=1;i<n+4-arr[index].length();i++){
        cout<<'0';
    }
    cout<<arr[index]<<endl;
}

return 0;
}