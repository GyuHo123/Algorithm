#include <bits/stdc++.h>

using namespace std;

vector<string> answer;
map<string, vector<string>> m1;

bool dfs(string curr, int tickets){
    if(tickets + 1 == answer.size()) return 1;
    
    for (auto& dest : m1[curr]) {
        if (dest == "") continue;
        string next = dest;
        dest = "";
        answer.push_back(next);

        if (dfs(next, tickets)) return true;

        answer.pop_back();
        dest = next;
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    

    for(auto t: tickets){
        m1[t[0]].push_back(t[1]);
    }
    
    for(auto& [key, value]: m1){
        sort(value.begin(), value.end());
    }

    answer.push_back("ICN");
    dfs("ICN", tickets.size());
    return answer;
}