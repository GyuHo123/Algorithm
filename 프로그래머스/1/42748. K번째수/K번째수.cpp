#include <bits/stdc++.h>
#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto t: commands){
        vector<int> temp;
        int st = t[0];
        int en = t[1];
        int idx = t[2];
        cout << endl;
        loop(i, st - 1, en - 1){
            temp.push_back(array[i]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[idx - 1]);
    }
    return answer;
}