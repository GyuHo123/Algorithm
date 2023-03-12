#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define MAXN 100001

using namespace std;

string p, arrStr;
bool rev;
int t, n, tempRes, cnt;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    deque<int> dq;
    cin >> t;
    while(t--) {
        dq.clear();
        rev = cnt = 0;
        cin >> p;
        cin >> n;
        cin >> arrStr;
        for(auto x : arrStr){
            if(x == ',' || x == ']'){
                dq.push_back(tempRes);
                tempRes = 0;
            }
            else if(x != '['){
                tempRes *= 10;
                tempRes += x - '0';
            }
        }

        for(auto x : p){
            if(!dq.empty()) {
                if (x == 'R') rev = !rev;
                if (rev && x == 'D') {
                    dq.pop_back();
                    cnt++;
                }
                else if (x == 'D') {
                    dq.pop_front();
                    cnt++;
                }
            }
            else if(x == 'D'){
                cout << "error" << endl;
                goto end;
            }
        }
        if(arrStr == "[]" && cnt == 0) {
            cout << "[]" << endl;
            continue;
        }
        if(dq.empty() && cnt > n) {
            cout << "error" << endl;
            continue;
        }
        cout << '[';
        if(rev) {
            for(int i = dq.size() - 1; i >= 0; i--){
                cout << dq[i];
                if(!i) cout << "]";
                else cout << ",";
            }
        }
        else if(dq.size() == 0){
            cout << "]" << endl;
            continue;
        }
        else{
            LOOP(i, 0, dq.size()){
                cout << dq[i];
                if(i == dq.size() - 1) cout << ']';
                else cout << ",";
            }
        }
        cout << endl;
        end:;
    }
}