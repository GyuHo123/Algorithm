#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>

#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

    
deque<int> dq;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    
    bool minus = 0;
    
    for(auto t: operations){
        
        cout << t << endl;
        string temp;
        if(t[0] == 'I'){
            loop(i, 2, t.size() - 1){
                if(t[2] == '-') minus = 1;
                temp += t[i];
            }
            int pushnum = stoi(temp);
            dq.push_back(pushnum);
            sort(dq.begin(), dq.end());
        }
        if(t[0] == 'D' && !dq.empty()){
            if(t[2] == '1') dq.pop_back();
            else if(t[2] == '-') dq.pop_front();
        }
    }
    if(dq.empty()){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }
    return answer;
}