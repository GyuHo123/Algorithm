#include <iostream>
#include <vector>
#include <set>
using namespace std;

bool isLucky(int n) {
    if (n == 0) return 0;
    while (n > 0) {
        int digit = n % 10;
        if (digit != 5 && digit != 8) return 0;
        n /= 10;
    }
    return 1;
}

int countUniqueLuckyNumbers(vector<int>& A, vector<int>& B, vector<int>& C) {
    set<int> sums;
    for (int a : A) {
        for (int b : B) {
            for (int c : C) {
                sums.insert(a + b + c);
            }
        }
    }

    int count = 0;
    for (int sum : sums) {
        if (isLucky(sum)) {
            count++;
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, M, K;
        
        cin >> N;
        vector<int> A(N);
        for (int& a : A) cin >> a;
        
        cin >> M;
        vector<int> B(M);
        for (int& b : B) cin >> b;

        cin >> K;
        vector<int> C(K);
        for (int& c : C) cin >> c;
        cout << countUniqueLuckyNumbers(A, B, C) << "\n";
    }
}