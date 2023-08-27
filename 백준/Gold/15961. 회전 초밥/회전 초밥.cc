#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> belt(N * 2);
    loop(i, 0, N-1) {
        cin >> belt[i];
        belt[i + N] = belt[i];
    }

    int answer = 0;
    vector<int> count(d + 1);

    count[c]++;
    answer++;

    LOOP(i, 0, k) {
        if (count[belt[i]] == 0) {
            answer++;
        }
        count[belt[i]]++;
    }

    int maxCount = answer;

    loop(start ,1 ,N){
        int end = start + k - 1;

        count[belt[start - 1]]--;
        if (count[belt[start - 1]] == 0) {
            answer--;
        }

        if (count[belt[end]] == 0) {
            answer++;
        }

        count[belt[end]]++;

        maxCount = max(maxCount, answer);
    }

    cout << maxCount << endl;
}
