#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto query = [&](int l, int r) -> vector<int> {
            cout << "? " << l << " " << r << endl;
            vector<int> a(r - l + 1);
            for (int i = 0; i < r - l + 1; i++) cin >> a[i];
            return a;
        };
        auto answer = [&](int index) -> void { cout << "! " << index << endl; };
        auto predicate_funct = [&](vector<int> &arr,int low, int mid) -> bool { 
            int left = 0;
            for (int i = 0; i < arr.size(); i++) {
                if (low<=arr[i]&&arr[i] <= mid) left++; 
            }
            // cout<<mid<<left<<endl;
            return ((left&1)==1);
        };
        int low = 1, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            // cout<<low<<" "<<mid<<" "<<high<<endl;
            vector<int> left = query(low, mid);
            bool check = predicate_funct(left, low,mid); 
            if (check) {
                high = mid;
                // cout<<" "<<high<<endl;
            } else {
                low=mid+1;
            }
            
        }
        answer(high);
    }
    return 0;
}
