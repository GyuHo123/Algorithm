#include <bits/stdc++.h>

using namespace std;

struct p{
    int x, y;
};

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end());
    int end1 = routes[0][1];
    answer++;
    for(auto t: routes){
        if(end1 < t[0]){
            answer++;
            end1 = t[1];
        }
        if(end1 >= t[1]) end1 = t[1];
    }
    return answer;
}