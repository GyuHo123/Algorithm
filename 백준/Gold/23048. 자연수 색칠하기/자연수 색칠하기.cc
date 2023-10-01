#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> colors(N + 1, 0);
    int nextColor = 1;

    for (int i = 2; i <= N; i++) {
        if (colors[i] == 0) {
            colors[i] = nextColor;
            nextColor++;

            for (int j = i * 2; j <= N; j += i) {
                if (colors[j] == 0) {
                    colors[j] = colors[i];
                }
            }
        }
    }

    cout << nextColor<< endl;

    for (int i = 1; i <= N; i++) {
        cout << colors[i] + 1 << " ";
    }
}
