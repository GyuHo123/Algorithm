#include<iostream>

using namespace std;

int fac(int a);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int x = 0; int result = 1;
    cin >> x;
    if(x != 0) result = fac(x);
    cout << result;
}

int fac(int a)
{
    if(a > 2)
    {
       a *= fac(a-1);
    }
    return a;
}

