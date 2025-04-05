#include <bits/stdc++.h>
using namespace std;

vector<string> process_test_cases(int t, vector<tuple<int, int, vector<vector<int>>>> &cases) {
    vector<string> output;
    
    for (auto &case_data : cases) {
        int n, m;
        vector<vector<int>> d;
        tie(n, m, d) = case_data;
        
        for (int i = 0; i < n; i++) {
            sort(d[i].begin(), d[i].end());
        }
        
        vector<pair<int, int>> min_card;
        for (int i = 0; i < n; i++) {
            min_card.push_back({d[i][0], i});
        }
        sort(min_card.begin(), min_card.end());
        
        vector<int> player_order;
        for (auto &p : min_card) {
            player_order.push_back(p.second + 1);  // Store 1-based player index
        }

        bool is_valid = true;
        int current_top_card = -1;

        for (int round = 0; round < m; round++) {
            for (int player : player_order) {
                int player_idx = player - 1;
                if (!d[player_idx].empty() && d[player_idx][0] > current_top_card) {
                    current_top_card = d[player_idx].front();
                    d[player_idx].erase(d[player_idx].begin());
                } else {
                    is_valid = false;
                    break;
                }
            }
            if (!is_valid) break;
        }

        if (is_valid) {
            stringstream ss;
            for (int i = 0; i < n; i++) {
                ss << player_order[i] << " ";
            }
            output.push_back(ss.str());
        } else {
            output.push_back("-1");
        }
    }
    
    return output;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<tuple<int, int, vector<vector<int>>>> cases;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> player_decks(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> player_decks[i][j];
            }
        }
        cases.push_back({n, m, player_decks});
    }

    vector<string> results = process_test_cases(t, cases);
    for (const string &result : results) {
        cout << result << "\n";
    }

    return 0;
}
