#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int t;
    cin>>t;
    while (t--) {
        int width, height, dist;
        cin>>width>>height>>dist;

        if (dist <= width && dist <= height) {
            cout<<"0 0 "<<dist<<" 0\n0 0 0 "<<dist<<'\n';
            continue;
        }

        int s = int((dist / sqrt(2)) + 1);
        if (s <= width && s <= height) {
            cout<<"0 0 "<<s<<" "<<s<<'\n';
            cout<<"0 "<<s<<" "<<s<<" 0\n";
            continue;
        }

        cout<<"0 0 "<<width<<" "<<height<<'\n';
        cout<<"0 "<<height<<" "<<width<<" 0\n";
    }
    return 0;
}
