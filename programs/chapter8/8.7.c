#include <stdio.h>
#include <math.h>

#define infmin 0.00001
#define pi 3.1415926

double abso(double a) {
    a > 0 ? a : -a;
}

double min(double a, double b) {
    return a > b ? b : a;
}

struct POINT {
    double x, y;

    POINT() {
        this->x = 0;
        this->y = 0;
    }

    POINT(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

struct LINE {
    POINT s, e;

    LINE() {
        this->s.x = 0;
        this->s.y = 0;
        this->e.x = 0;
        this->e.y = 0;
    }

    LINE(POINT a, POINT b) {
        this->s.x = a.x;
        this->s.y = a.y;
        this->e.x = b.x;
        this->e.y = b.y;
    }
};

struct RECT {
    POINT lt, rb;
};
struct CIRCLE {
    POINT c;
    double r;
};

//(1)

double distance(POINT a, POINT b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool inrec(POINT a, RECT b) {
    return (a.x > b.lt.x && a.x < b.rb.x && a.y > b.rb.y && a.y < b.lt.y);
}

bool incircle(POINT a, CIRCLE b) {
    return (distance(a, b.c) < b.r);
}

bool online(POINT a, LINE l) {
    return (distance(a, l.e) + distance(a, l.s) - distance(l.e, l.s) < infmin);
}

double distance(POINT a, LINE l) {
    double cross = (l.s.x - l.e.x) * (a.x - l.e.x) + (l.s.y - l.e.y) * (a.y - l.e.y);
    if (cross <= 0) return sqrt((a.x - l.e.x) * (a.x - l.e.x) + (a.y - l.e.y) * (a.y - l.e.y));

    double d2 = (l.s.x - l.e.x) * (l.s.x - l.e.x) + (l.s.y - l.e.y) * (l.s.y - l.e.y);
    if (cross >= d2) return sqrt((a.x - l.s.x) * (a.x - l.s.x) + (a.y - l.s.y) * (a.y - l.s.y));

    double r = cross / d2;
    double px = l.e.x + (l.s.x - l.e.x) * r;
    double py = l.e.y + (l.s.y - l.e.y) * r;
    return sqrt((a.x - px) * (a.x - px) + (py - a.y) * (py - a.y));
}

double distance(POINT a, CIRCLE b) {
    return abso(distance(a, b.c) - b.r);
}

double distance(POINT a, RECT b) {
    return min(min(min(distance(a, LINE(b.lt, POINT(b.rb.x, b.lt.y))), distance(a, LINE(b.lt, POINT(b.lt.x, b.rb.y)))),
                   distance(a, LINE(b.rb, POINT(b.lt.x, b.rb.y)))), distance(a, LINE(b.rb, POINT(b.rb.x, b.lt.y))));
}

//(2)

POINT direction(LINE a) {
    return POINT(a.s.x - a.e.x, a.s.y - a.e.y);
}

bool parallel(LINE a, LINE b) {
    return direction(a).x * direction(b).y - direction(a).y * direction(b).x < infmin;
}

bool inter(LINE a, LINE b, POINT *c) {
    if (parallel(a, b)) return false;
    else {
        *c = POINT(((a.s.x - a.e.x) * (b.s.y * b.e.x - b.s.x * b.e.y) -
                    (b.s.x - b.e.x) * (a.s.y * a.s.x - a.s.x * a.e.y)) /
                   ((a.s.y - a.e.y) * (b.s.x - b.e.x) - (b.s.y - b.e.y) * (a.s.x - a.e.x)),
                   ((a.s.y - a.e.y) * (b.s.y * b.e.x - b.s.x * b.e.y) -
                    (b.s.y - b.e.y) * (a.s.y * a.e.x - a.s.x * a.e.y)) /
                   ((a.s.y - a.e.y) * (b.s.x - b.e.x) - (b.s.y - b.e.y) * (a.s.x - a.e.x)));
        return true;
    }
}

bool inter(LINE a, RECT b, POINT *c, POINT *d) {
    LINE l1 = LINE(b.lt, POINT(b.lt.x, b.rb.y));
    LINE l2 = LINE(b.lt, POINT(b.rb.x, b.lt.y));
    LINE l3 = LINE(b.rb, POINT(b.lt.x, b.rb.y));
    LINE l4 = LINE(b.rb, POINT(b.rb.x, b.lt.y));
    POINT p1, p2, p3, p4;
    inter(a, l1, &p1);
    inter(a, l2, &p2);
    inter(a, l3, &p3);
    inter(a, l4, &p4);
    if (online(p1, l1)) {
        *c = p1;
        if (online(p2, l2)) {
            *d = p2;
            return true;
        } else if (online(p3, l3)) {
            *d = p3;
            return true;
        } else if (online(p4, l4)) {
            *d = p4;
            return true;
        }
    } else if (online(p2, l2)) {
        *c = p1;
        if (online(p3, l3)) {
            *d = p3;
            return true;
        } else if (online(p4, l4)) {
            *d = p4;
            return true;
        }
    } else if (online(p3, l3)) {
        *c = p1;
        if (online(p4, l4)) {
            *d = p4;
            return true;
        }
    }
}

inline POINT Vector(POINT A, POINT B) {
    return {B.x - A.x, B.y - A.y};
}

double cross(POINT A, POINT B, POINT P) {
    POINT AB = Vector(A, B);
    POINT AP = Vector(A, P);
    return AB.x * AP.y - AB.y * AP.x;
}

inline double dis2(POINT a, POINT b) {
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

double disLine(POINT A, POINT B, POINT P) {
    return fabs(cross(A, B, P)) / sqrt(dis2(A, B));
}

double dot(POINT A, POINT B, POINT P) {
    POINT AB = Vector(A, B);
    POINT AP = Vector(A, P);
    return AB.x * AP.x + AB.y * AP.y;
}

POINT Vbase(POINT A, POINT B, POINT O, double r) {
    double base = sqrt(r * r - disLine(A, B, O) * disLine(A, B, O));
    POINT AB = Vector(A, B);
    POINT e = {AB.x / sqrt(dis2(A, B)), AB.y / sqrt(dis2(A, B))};
    return {e.x * base, e.y * base};
}

POINT prxy(POINT A, POINT B, POINT O) {
    POINT AO = Vector(A, O);
    POINT AB = Vector(A, B);
    double l = dot(A, B, O) / sqrt(dis2(A, B));
    POINT e = {AB.x / sqrt(dis2(A, B)), AB.y / sqrt(dis2(A, B))};
    POINT Apr = {e.x * l, e.y * l};
    return {A.x + Apr.x, A.y + Apr.y};
}

bool inter(LINE a, CIRCLE b, POINT *c, POINT *d) {
    double dis = distance(b.c, a);
    if (dis < b.r) {
        POINT Base = Vbase(a.e, a.s, b.c, b.r);
        POINT pr = prxy(a.e, a.s, b.c);
        POINT x1 = {Base.x + pr.x, Base.y + pr.y};
        POINT x2 = {pr.x - Base.x, pr.y - Base.y};
        return true;
    } else return false;
}

//(3)

double area(RECT a) {
    return fabs((a.lt.x - a.rb.x) * (a.lt.y - a.rb.y));
}
// (4)
double area(CIRCLE a){
    return pi*a.r*a.r;
}

bool inter(CIRCLE a,CIRCLE b){
    double d=distance(a.c,b.c);
    if (d>a.r+b.r) return true;
    if (d<min(a.r,b.r)) return true;
    else return false;
}

bool contain(CIRCLE a,CIRCLE b){
    double d=distance(a.c,b.c);
    if (d<min(a.r,b.r)) return true;
}

int main() {

    return 0;
}
