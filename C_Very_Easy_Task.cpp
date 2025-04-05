#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);  
cin.tie(NULL);                      
long long n,x,y;cin >> n >> x >> y ;
long long low=min(x,y),high=1e18;
auto  predicate_funt = [&](long long mid)->bool{
    long long x_p=(mid-min(x,y))/x,y_p=(mid-min(x,y))/y;
    return (max(0LL,x_p)+max(0LL,y_p)>=(n-1));
};
while(low<=high){
    long long mid=(low+high)/2;
    if(predicate_funt(mid)){
        high=mid-1;
    }
    else low=mid+1;
}
cout << low <<endl;

return 0;
}