#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void answer(int x, int y) {
    cout << "! " << x << " " << y << endl;
}

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        auto query = [&](long long x, long long y) -> long long {
            cout << "? " << x << " " << y << endl;
            long long d;
            cin >> d;
            return d;
        };
        
        long long d1 = query(1, 1);
        if (d1 == 0) {
            answer(1, 1);
            continue;
        long long y1=min(1+d1,m),x1=d1-y1+2;
        }
        long long d2 = query(x1,y1 );
        if (d2 == 0) {
            answer(x1, y1);
            continue;
        }
        long long x2=min(1+d1,n),y2=d1-x2+2;
        long long d3 = query(x2, y2);
        if (d3 == 0) {
            answer(x2, y2);
            continue;
        }
        
        long long d4 = query(x1 + (d2 / 2), y1 - (d2 / 2));
        if (d4 == 0) {
            answer(x1 + (d2 / 2), y1- (d2 / 2));
            continue;
        } else {
            answer(x2 - (d3 / 2), y2+ (d3 / 2));
        }
    }

    return 0;
}
