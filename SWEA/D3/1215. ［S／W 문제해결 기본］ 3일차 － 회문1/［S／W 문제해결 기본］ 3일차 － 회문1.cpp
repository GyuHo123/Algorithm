#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 회문 검사 함수
bool isPalindrome(const vector<vector<char>>& arr, int x, int y, int n, bool isHorizontal) {
    for (int i = 0; i < n / 2; i++) {
        if (isHorizontal) {
            if (arr[x][y + i] != arr[x][y + n - 1 - i]) {
                return false;
            }
        } else {
            if (arr[x + i][y] != arr[x + n - 1 - i][y]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int test_case = 1; test_case <= 10; test_case++) {
        int n;
        cin >> n;

        vector<vector<char>> arr(8, vector<char>(8));
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                cin >> arr[i][j];
            }
        }

        int cnt = 0;

        // 가로 검사
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j <= 8 - n; j++) {
                if (isPalindrome(arr, i, j, n, true)) {
                    cnt++;
                }
            }
        }

        // 세로 검사
        for (int i = 0; i <= 8 - n; i++) {
            for (int j = 0; j < 8; j++) {
                if (isPalindrome(arr, i, j, n, false)) {
                    cnt++;
                }
            }
        }

        cout << "#" << test_case << " " << cnt << "\n";
    }

    return 0;
}
