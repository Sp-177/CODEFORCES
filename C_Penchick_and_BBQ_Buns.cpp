#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    long long t;cin>>t;
    while(t--){
        int n;cin>>n;
        if((n&1)&&(n>=27)){
            int arr[]={1,2,2,3,3,4,4,5,5,1,6,6,7,7,8,8,9,9,10,10,11,11,12,13,13,1,12};
            for(int i=0;i<27;i++)cout<<arr[i]<<" ";
            int fill=14;
            for(int i=27;i<n;i+=2){
                cout<<fill<<" "<<fill<<" ";
                fill++;
            }
        cout<<endl; 
        
       }
       else if(n%2==0){
        long long fill=1;
        for(long long i=0;i<n/2;i++){
            cout<<fill<<" "<<fill<<" ";
            fill++;
        }
        cout<<endl;
       }
       else cout<<-1<<endl;

    }
}


