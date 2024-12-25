#include <iostream>
#include <cmath>

class Point {
private:
    double x, y;

public:
    Point(double px = 0.0, double py = 0.0) : x(px), y(py) {}
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double px) { x = px; }
    void setY(double py) { y = py; }
    void afficher() const {
        std::cout << "(" << x << ", " << y << ")";
    }
    void translater(double dx, double dy) {
        x += dx;
        y += dy;
    }
};
class Cercle {
private:
    double rayon;
    Point centre;

public:
    Cercle(double r, const Point& p) : rayon(r), centre(p) {}
    Cercle(double r, double px, double py) : rayon(r), centre(Point(px, py)) {}
    void afficher() const {
        std::cout << "Cercle de rayon " << rayon << " et de centre ";
        centre.afficher();
        std::cout << std::endl;
    }
    double getRayon() const { return rayon; }
    void setRayon(double r) { rayon = r; }
    Point getCentre() const { return centre; }
    void translater(double dx, double dy) {
        centre.translater(dx, dy);
    }
    double surface() const {
        return M_PI * rayon * rayon;
    }
    double perimetre() const {
        return 2 * M_PI * rayon;
    }
    bool estEgal(const Cercle& autre) const {
        return rayon == autre.rayon &&
               centre.getX() == autre.getCentre().getX() &&
               centre.getY() == autre.getCentre().getY();
    }
    bool contient(const Point& p) const {
        double distance = std::sqrt(
            std::pow(p.getX() - centre.getX(), 2) +
            std::pow(p.getY() - centre.getY(), 2));
        return distance <= rayon;
    }
};

int main() {
    Cercle c1(1, 10, 10);
    std::cout << "Caractéristiques du cercle : ";
    c1.afficher();
    std::cout << "Périmètre : " << c1.perimetre() << std::endl;
    std::cout << "Surface : " << c1.surface() << std::endl;
    c1.setRayon(c1.getRayon() * 2);
    std::cout << "Après doublement du rayon :" << std::endl;
    std::cout << "Périmètre : " << c1.perimetre() << std::endl;
    std::cout << "Surface : " << c1.surface() << std::endl;
    c1.translater(-10, -10);
    std::cout << "Après déplacement du centre à l'origine : ";
    c1.afficher();
    Point p1(1, 1);
    if (c1.contient(p1)) {
        std::cout << "Le point (1,1) est à l'intérieur du cercle." << std::endl;
    } else {
        std::cout << "Le point (1,1) est à l'extérieur du cercle." << std::endl;
    }
    Point p2(3, 3);
    if (c1.contient(p2)) {
        std::cout << "Le point (3,3) est à l'intérieur du cercle." << std::endl;
    } else {
        std::cout << "Le point (3,3) est à l'extérieur du cercle." << std::endl;
    }
    Cercle c2(2, 0, 0);
    if (c1.estEgal(c2)) {
        std::cout << "Les deux cercles sont égaux." << std::endl;
    } else {
        std::cout << "Les deux cercles sont différents." << std::endl;
    }

    return 0;
}
