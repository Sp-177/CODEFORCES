#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int t;cin>>t;
    while(t--){
    string ans="";
    for(int i=0;i<3;i++){
        string s;cin>>s;
        ans+=s[0];
    }
    cout<<ans<<endl;
    }

    return 0;
}
