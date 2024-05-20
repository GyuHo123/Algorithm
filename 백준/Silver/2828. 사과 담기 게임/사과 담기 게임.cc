#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, J;
    cin >> N >> M;
    cin >> J;

    int apples[J];
    for (int i = 0; i < J; i++) {
        cin >> apples[i];
    }

    int currentLeft = 1;
    int currentRight = M;
    int totalDistance = 0;

    for (int i = 0; i < J; i++) {
        int applePosition = apples[i];
        if (applePosition < currentLeft) {
            totalDistance += (currentLeft - applePosition);
            currentRight -= (currentLeft - applePosition);
            currentLeft = applePosition;
        } else if (applePosition > currentRight) {
            totalDistance += (applePosition - currentRight);
            currentLeft += (applePosition - currentRight);
            currentRight = applePosition;
        }
    }

    cout << totalDistance << endl;
}
