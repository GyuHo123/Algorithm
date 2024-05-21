#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_map<string, int> counts;
    set<string> types(gems.begin(), gems.end());

    int total_types = types.size();
    int left = 0, right = 0;
    unordered_map<string, int> window;
    vector<int> answer = {1, int(gems.size())}; 
    int min_length = int(gems.size());

    while (right < gems.size()) {
        window[gems[right]]++;
        right++; 

        while (window.size() == total_types) {
            if (right - left < min_length) {
                min_length = right - left;
                answer = {left + 1, right};
            }
            window[gems[left]]--;
            if (window[gems[left]] == 0) {
                window.erase(gems[left]);
            }
            left++;
        }
    }
    return answer;
}
