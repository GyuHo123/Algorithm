#include <bits/stdc++.h>
#define endl '\n'
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define LOOP(i, s, n) for(int i = s; i < n; i++)
#define ll long long

using namespace std;

double ax, ay, bx, by, cx, cy, dx, dy, ex, ey, fx, fy;
double tri_area;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy >> ex >> ey >> fx >> fy;
        if(ax == 0.0 && ay == 0.0 && bx == 0.0 && by == 0.0 && cx == 0.0 && cy == 0.0 && dx == 0.0 && dy == 0.0 && ex == 0.0 && ey == 0.0 && fx == 0.0 && fy == 0.0) break;
        tri_area = 0.5 * abs(
            (dx * ey + ex * fy + fx * dy) - (dy * ex + fy * dx + ey * fx)
        );
        double abc_area = abs((ax * by + bx * cy + cx * ay) - (ay * bx + by * cx + cy * ax));
        double rate = tri_area / abc_area;
        double ac_x = cx - ax, ac_y = cy - ay;
        double ac_x_rate = ac_x * rate, ac_y_rate = ac_y * rate; 
        double hx = ax + ac_x_rate, hy = ac_y_rate + ay;
        double gx = hx + bx - ax, gy= hy + by - ay;

        printf("%.3lf %.3lf %.3lf %.3lf\n", gx , gy , hx , hy);
    }
}
