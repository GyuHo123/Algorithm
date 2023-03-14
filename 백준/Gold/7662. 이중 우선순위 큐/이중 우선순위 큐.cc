#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 1000001

using namespace std;

struct p{
    int num, idx;
};

class cmp{
public:
    bool operator()(const p& p1, const p& p2){
        return p1.num < p2.num;
    }
};

class cmp1{
public:
    bool operator()(const p& p1, const p& p2){
        return p1.num > p2.num;
    }
};

int t, n, has[MAXN], temp;
char c;

p p1;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    while (t--) {
        priority_queue<p, vector<p>, cmp1> minHeap;
        priority_queue<p, vector<p>, cmp> maxHeap;

        cin >> n;

        loop(i, 1, n) {
            cin >> c;
            if (c == 'I') {
                cin >> temp;
                p1.num = temp;
                p1.idx = i;
                maxHeap.push(p1);
                minHeap.push(p1);
                has[i] = 1;
            }
            if (c == 'D') {
                cin >> temp;
                if (temp == 1) {
                    while (!maxHeap.empty() && !has[maxHeap.top().idx]) {
                        maxHeap.pop();
                    }
                    if(!maxHeap.empty()){
                        has[maxHeap.top().idx] = 0;
                        maxHeap.pop();
                    }
                } else {
                    while (!minHeap.empty() && !has[minHeap.top().idx]) {
                        minHeap.pop();
                    }
                    if(!minHeap.empty()) {
                        has[minHeap.top().idx] = 0;
                        minHeap.pop();
                    }
                }
            }
        }
        while (!maxHeap.empty() && !has[maxHeap.top().idx]) {
            maxHeap.pop();
        }
        while (!minHeap.empty() && !has[minHeap.top().idx]) {
            minHeap.pop();
        }

        if(maxHeap.empty() && minHeap.empty()) cout << "EMPTY" << endl;
        else cout << maxHeap.top().num << " " << minHeap.top().num << endl;
    }
}

