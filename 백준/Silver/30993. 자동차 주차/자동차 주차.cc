#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int N, A, B, C;
    
    cin >> N >> A >> B >> C;

    long long total_permutations = factorial(N);

    long long valid_permutations = total_permutations / (factorial(A) * factorial(B) * factorial(C));

    cout << valid_permutations << endl;
}
