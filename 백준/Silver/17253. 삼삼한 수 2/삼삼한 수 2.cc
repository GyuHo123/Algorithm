#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long long N;
    cin >> N;
    if(N == 0){
        cout << "NO";
        exit(0);
    }
    vector<unsigned long long> three;
    unsigned long long sam = 1;
    while (sam < LLONG_MAX / 3) {
        three.push_back(sam);
        sam *= 3;
    }
    three.push_back(sam);
    for (int i = three.size() - 1; i >= 0; i--) {
        if (N >= three[i]) {
            N -= three[i];
        }
    }

    if (N == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
