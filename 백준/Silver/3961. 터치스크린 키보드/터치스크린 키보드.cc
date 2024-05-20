#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)

using namespace std;

string s[3];

int t, l;
string fword, cword;

bool cmp(pair<string, int> p1, pair<string, int> p2){
    if(p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main(){
    s[0] = "qwertyuiop";
    s[1] = "asdfghjkl";
    s[2] = "zxcvbnm";

    cin >> t;

    while(t--){
        vector<pair<string, int>> answerv;
        int fx = 0, fy = 0, cx, cy, tdist;
        cin >> fword >> l;
        loop(i, 0, l - 1){
            cin >> cword;
            tdist = 0;
            loop(j, 0, cword.size() - 1){
                if(cword[j] == fword[j]) continue;
                loop(k, 0, 2){
                    size_t pos = s[k].find(fword[j]);
                    if (pos != string::npos) {
                        fx = k;
                        fy = pos;
                    }
                    pos = s[k].find(cword[j]);
                    if (pos != string::npos) {
                        cx = k;
                        cy = pos;
                    }
                }
                tdist += abs(fx - cx) + abs(fy - cy);
            }
            answerv.push_back({cword, tdist});
        }
        sort(answerv.begin(), answerv.end(), cmp);
        for(auto t: answerv){
            cout << t.first << " " << t.second << endl;
        }
    }
}
