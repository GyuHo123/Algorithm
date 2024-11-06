#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    int size = answers.size();
    
    vector<int> student1 = {1, 2, 3, 4, 5};
    vector<int> student2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> student3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int stusol[3] = {0, 0, 0}; 
    
    for(int i = 0; i < size; i++) {
        if(answers[i] == student1[i % student1.size()]) stusol[0]++;
        if(answers[i] == student2[i % student2.size()]) stusol[1]++;
        if(answers[i] == student3[i % student3.size()]) stusol[2]++;
    }
    
    int max_score = max({stusol[0], stusol[1], stusol[2]});
    vector<int> result;
    for(int i = 0; i < 3; i++) {
        if(stusol[i] == max_score) result.push_back(i + 1);
    }
    
    return result;
}
