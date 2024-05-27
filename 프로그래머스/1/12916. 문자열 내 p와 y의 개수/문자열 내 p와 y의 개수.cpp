#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    cin >> s;

    int p = 'p';
    int P = 'P';
    int Y = 'Y';
    int y = 'y';
    int pcnt = 0;
    int ycnt = 0;

    for(auto t: s){
        if(t == p || t == P) pcnt++;
        else if(t == y || t == Y) ycnt++; 
    }

    if(pcnt != ycnt) answer = false;

    return answer;
}