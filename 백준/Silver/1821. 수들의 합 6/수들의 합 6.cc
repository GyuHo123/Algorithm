#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

bool check_bottom_value(vector<int> top_row, int F) {
    vector<int> current_row = top_row;
    vector<int> next_row;
    while (current_row.size() > 1) {
        next_row.clear();
        for (int i = 0; i < current_row.size() - 1; i++) {
            next_row.push_back(current_row[i] + current_row[i + 1]);
        }
        current_row = next_row;
    }
    return current_row[0] == F;
}

int main() {
    int N, F;
    cin >> N >> F;

    vector<int> top_row(N);

    for(int i = 0; i < N; i++){
        top_row[i] = i + 1;
    }

    do {
        if (check_bottom_value(top_row, F)) {
            for (int num : top_row) {
                cout << num << " ";
            }
            cout << endl;
            return 0;
        }
    } while (next_permutation(top_row.begin(), top_row.end()));
}
