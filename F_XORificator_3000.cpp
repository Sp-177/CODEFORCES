#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long findXOR(long long n)
{
    long long mod = n % (4*1LL);

    // If n is a multiple of 4*1LL
    if (mod == 0LL)
        return n;

    // If n % 4*1LL gives remainder 1LL
    else if (mod == 1LL)
        return 1LL;

    // If n % 4*1LL gives remainder 2*1LL
    else if (mod == 2*1LL)
        return n + 1LL;

    // If n % 4*1LL gives remainder 3*1LL
    else 
        return 0LL;
}

// Function to return the XOR of elements
// from the range [l, r]
long long findXOR(long long l, long long r)
{
    return (findXOR(l - 1LL) ^ findXOR(r));
}

// Driver code
int main()
{
int t;cin>>t;
while(t--){
    long long l,r,i,k;cin>>l>>r>>i>>k;
    if(i==0LL){cout<<0<<endl;continue;}
    long long div=1LL<<i;
    long long x=0;
    for(long long j=0;j<=sqrt(r);j+=div){

        long long num=j+(k%div);
        if(num>=l&&num<=r)x^=num;
        long long num2=r/j+();

    }

    cout << (findXOR(l, r)^x)<<endl;


}}