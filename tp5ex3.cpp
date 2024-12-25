#include <iostream>
#include <cmath> 
using namespace std;

class Point {
private:
    float x, y;

public:
    Point(float x = 0, float y = 0) : x(x), y(y) {}
    Point(const Point& p) : x(p.x), y(p.y) {}
    void affiche() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    friend bool comparer(const Point& p1, const Point& p2);
    friend float distance(const Point& p1, const Point& p2);
    friend Point milieu(const Point& p1, const Point& p2);
};
bool comparer(const Point& p1, const Point& p2) {
    return (p1.x == p2.x && p1.y == p2.y);
}
float distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
Point milieu(const Point& p1, const Point& p2) {
    return Point((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}
int main() {
    Point p1(2.0, 3.0);
    Point p2(4.0, 7.0);

    cout << "Point 1 : ";
    p1.affiche();
    cout << "Point 2 : ";
    p2.affiche();
    if (comparer(p1, p2)) {
        cout << "Les points sont identiques." << endl;
    } else {
        cout << "Les points sont différents." << endl;
    }
    cout << "Distance entre les deux points : " << distance(p1, p2) << endl;
    Point pMilieu = milieu(p1, p2);
    cout << "Point milieu : ";
    pMilieu.affiche();

    return 0;
}
