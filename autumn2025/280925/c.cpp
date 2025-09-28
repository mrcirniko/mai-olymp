#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isPointInSections(double ix, double iy, ll xl, ll yl, ll xr, ll yr, ll xll, ll yll, ll xrr, ll yrr) {
    if (((ix <= xr && ix >= xl ) || (ix <= xr && ix >= xl )) && ((iy <= yr && iy >= yl ) || (iy <= yr && iy >= yl ))) {
        return false;
    }
    if (((ix <= xrr && ix >= xll ) || (ix <= xrr && ix >= xll )) && ((iy <= yrr && iy >= yll ) || (iy <= yrr && iy >= yll ))) {
        return false;
    }

    return true;
}

bool isSectionsIntersect(double a1, double b1, ll xl, ll yl, ll xr, ll yr, ll xll, ll yll, ll xrr, ll yrr) {
    double a2 = (double)(abs(yl - yr)) / (abs(xr - xl));
    double b2 = yl - a1 * xl;

    double ix = (b2 - b1) / (a1 - a2);
    double iy = a1 * ix + b1;

    return isPointInSections(ix, iy, xl, yl, xr, yr, xll, yll, xrr, yrr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t,x1,x2,y1,y2,xl,xr,yl,yr;
    cin >> t;
    for (ll i = 0; i < t; ++i) {
        cin >> xl >> yl >> xr >> yr >> x1 >> y1 >> x2 >> y2;

        double a1 = (double)(abs(yl - yr)) / (abs(xr - xl));// вход отрезок: y = a1*x + b1
        double b1 = yl - a1 * xl;
        
        //проверим для каждой грани прямоугольника пересечение с отрезком:
        double xll = x1;
        double yll = y1;
        double xrr = x1;
        double yrr = y2;

        if (!isSectionsIntersect(a1, b1, xl, yl, xr, yr, xll, yll, xrr, yrr)) {
            cout << "STOP" << '\n';
            continue;
        }

        xll = x1;
        yll = y1;
        xrr = x2;
        yrr = y1;

        if (!isSectionsIntersect(a1, b1, xl, yl, xr, yr, xll, yll, xrr, yrr)) {
            cout << "STOP" << '\n';
            continue;
        }


        xll = x2;
        yll = y1;
        xrr = x2;
        yrr = y2;

        if (!isSectionsIntersect(a1, b1, xl, yl, xr, yr, xll, yll, xrr, yrr)) {
            cout << "STOP" << '\n';
            continue;
        }

        xll = x1;
        yll = y2;
        xrr = x2;
        yrr = y2;

        if (!isSectionsIntersect(a1, b1, xl, yl, xr, yr, xll, yll, xrr, yrr)) {
            cout << "STOP" << '\n';
            continue;
        }
        cout << "OK" << '\n';
    }

}