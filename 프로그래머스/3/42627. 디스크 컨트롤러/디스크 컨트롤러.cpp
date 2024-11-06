#include <bits/stdc++.h>

using namespace std;

struct Job {
    int request_time;
    int duration;
    
    bool operator>(const Job& other) const {
        return duration > other.duration;
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    priority_queue<Job, vector<Job>, greater<Job>> pq;
    int current_time = 0;
    int total_time = 0;
    int index = 0;
    int job_count = jobs.size();
    
    while (index < job_count || !pq.empty()) {
        while (index < job_count && jobs[index][0] <= current_time) {
            pq.push({jobs[index][0], jobs[index][1]});
            index++;
        }
        if (!pq.empty()) {
            Job job = pq.top();
            pq.pop();
            current_time += job.duration;
            total_time += current_time - job.request_time;
        } else {
            current_time = jobs[index][0];
        }
    }
    return total_time / job_count;
}
