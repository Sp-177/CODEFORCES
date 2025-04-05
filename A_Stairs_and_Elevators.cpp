#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long n,m,cl,ce,v;
cin>>n>>m>>cl>>ce>>v;
vector<long long> stairs_sec(cl), elevator_sec(ce);
for(long long i=0;i<cl;i++)cin>>stairs_sec[i];for(long long i=0;i<ce;i++)cin>>elevator_sec[i];
long long q;cin>>q;
sort(stairs_sec.begin(),stairs_sec.end());sort(elevator_sec.begin(),elevator_sec.end());

auto solve=[&](long long src_f, long long src_r, long long dst_f, long long dst_r)->long long{

if(src_f==dst_f)return abs(src_r-dst_r);

auto bs=[&](vector<long long >&arr,long long speed)->long long{
if(arr.size()==0)return LLONG_MAX;
long long sum=LLONG_MAX,len=arr.size();
auto it=lower_bound(arr.begin(),arr.end(),src_r);
long long index1=-1,index2=-2,index3=-3;
if(it==arr.end())index2=len-1;
else index2=it-arr.begin();
index1=index2-1;
index3=index2+1;
if(0<=index1&&index1<len){
long long carrier_sec=arr[index1];
long long time=abs(carrier_sec-src_r)+abs(carrier_sec-dst_r)+(abs(dst_f-src_f) +speed-1)/speed;

sum=min(sum,time);
}
if(0<=index2&&index2<len){
    long long carrier_sec=arr[index2];
long long time=abs(carrier_sec-src_r)+abs(carrier_sec-dst_r)+(abs(dst_f-src_f) +speed-1)/speed;
sum=min(sum,time);

}
if(0<=index3&&index3<len){
    long long carrier_sec=arr[index3];
long long time=abs(carrier_sec-src_r)+abs(carrier_sec-dst_r)+(abs(dst_f-src_f) +speed-1)/speed;
sum=min(sum,time);

}

return sum;
};

return min(bs(stairs_sec,1),bs(elevator_sec,v));
};
while(q--){
    long long x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    cout<<solve(x1,y1,x2,y2)<<endl;
}

return 0;
}