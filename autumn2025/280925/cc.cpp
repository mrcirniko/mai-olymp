#include <bits/stdc++.h>

using namespace std;

using ll = long long;

bool isSegmentsIntersect(ll ax, ll ay, ll bx, ll by, ll cx, ll cy, ll dx, ll dy) {
    ll i1 = (bx-ax) * (cy-ay) - (by-ay) * (cx-ax);
    ll i2 = (bx-ax) * (dy-ay) - (by-ay) * (dx-ax);
    ll i3 = (dx-cx) * (ay-cy) - (dy-cy) * (ax-cx);
    ll i4 = (dx-cx) * (by-cy) - (dy-cy) * (bx-cx);

    if ((i1 > 0 && i2 < 0 || i1 < 0 && i2 > 0) && (i3 > 0 && i4 < 0 || i3 < 0 && i4 > 0)) {
        return true;
    }


    if (i1==0 && min(ax, bx) <= cx && cx <= max(ax, bx) && min(ay, by) <= cy && cy <= max(ay, by)) {
        return true;
    }

    if (i2==0 && min(ax, bx) <= dx && dx <= max(ax, bx) && min(ay, by) <= dy && dy <= max(ay, by)) {
        return true;
    }

    if (i3==0 && min(cx, dx) <= ax && ax <= max(cx, dx) && min(cy, dy) <= ay && ay <= max(cy, dy)) {
        return true;
    }

    if (i4==0 && min(cx, dx) <= bx && bx <= max(cx, dx) && min(cy, dy) <= by && by <= max(cy, dy)) {
        return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t,x1,x2,y1,y2,xl,xr,yl,yr;
    cin >> t;
    for (ll i = 0; i < t; ++i) {
        cin >> xl >> yl >> xr >> yr >> x1 >> y1 >> x2 >> y2;

        if (xr < xl) {
            swap(xl, xr);
        }
        if (yr < yl) {
            swap(yl, yr);
        }

        if ((xl <= x1 && x1 <= xr && yl <= y1 && y1 <= yr) || (xl <= x2 && x2 <= xr && yl <= y2 && y2 <= yr)) {
            cout << "STOP" << '\n';
            continue;
        }

        ll rx1 = xl;
        ll ry1 = yl;
        ll rx2 = xr;
        ll ry2 = yl;
        ll rx3 = xr;
        ll ry3 = yr;
        ll rx4 = xl;
        ll ry4 = yr;


        if (isSegmentsIntersect(x1, y1, x2, y2, rx1, ry1, rx2, ry2)) {
            cout << "STOP" << '\n';
            continue;
        }
        if (isSegmentsIntersect(x1, y1, x2, y2, rx2, ry2, rx3, ry3)) {
            cout << "STOP" << '\n';
            continue;
        }
        if (isSegmentsIntersect(x1, y1, x2, y2, rx3, ry3, rx4, ry4)) {
            cout << "STOP" << '\n';
            continue;
        }
        if (isSegmentsIntersect(x1, y1, x2, y2, rx4, ry4, rx1, ry1)) {
            cout << "STOP" << '\n';
            continue;
        }
        cout << "OK" << '\n';
    }
}