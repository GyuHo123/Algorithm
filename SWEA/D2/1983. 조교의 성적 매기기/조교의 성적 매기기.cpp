#include <algorithm>
#include <iostream>
#include <string>
#include <bits/ranges_algo.h>
#define MAXN 101
#define loop(i, s, n) for(int i = s; i <= n; i++)

struct p {
    int score, num;
};

bool cmp(p p1, p p2) {
    return p1.score > p2.score;
}

using namespace std;

int t, n, k;
p score[MAXN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;

    loop(i, 1, t) {
        cin >> n >> k;
        cout << "#" << i << " ";
        int score1, score2, score3, seperate = n / 10, grade;

        loop(i, 1, n) {
            cin >> score1 >> score2 >> score3;
            score[i].score = score1 * 0.35 + score2 * 0.45 + score3 * 0.20;
            score[i].num = i;
        }

        sort(score, score + n, cmp);

        loop(i, 0, n) {
            if(score[i].num == k) {
                grade = i / seperate;
                break;
            }
        }

        switch(grade) {
            case 0:
                cout << "A+" << endl;
            break;
            case 1:
                cout << "A0" << endl;
            break;
            case 2:
                cout << "A-" << endl;
            break;
            case 3:
                cout << "B+" << endl;
            break;
            case 4:
                cout << "B0" << endl;
            break;
            case 5:
                cout << "B-" << endl;
            break;
            case 6:
                cout << "C+" << endl;
            break;
            case 7:
                cout << "C0" << endl;
            break;
            case 8:
                cout << "C-" << endl;
            break;
            default:
                cout << "D0" << endl;
        }
    }
}