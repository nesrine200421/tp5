#include <iostream>
#include <cmath>

class Complexe {
private:
    double Re; 
    double Img; 
public:
    Complexe(double r = 0.0, double i = 0.0) : Re(r), Img(i) {}
    void afficher() const {
        std::cout << Re << " + " << Img << "i" << std::endl;
    }
    double module() const {
        return std::sqrt(Re * Re + Img * Img);
    }
    Complexe conjugue() const {
        return Complexe(Re, -Img);
    }
    Complexe operator+(const Complexe& other) const {
        return Complexe(Re + other.Re, Img + other.Img);
    }

    Complexe operator+(double valeur) const {
        return Complexe(Re + valeur, Img);
    }
    friend Complexe operator+(double valeur, const Complexe& complexe) {
        return Complexe(valeur + complexe.Re, complexe.Img);
    }

    Complexe operator*(const Complexe& other) const {
        return Complexe(Re * other.Re - Img * other.Img, Re * other.Img + Img * other.Re);
    }

    Complexe operator*(double valeur) const {
        return Complexe(Re * valeur, Img * valeur);
    }

    friend Complexe operator*(double valeur, const Complexe& complexe) {
        return Complexe(valeur * complexe.Re, valeur * complexe.Img);
    }
};

int main() {
    Complexe c1(3, 4); 
    Complexe c2(1, 2);

    Complexe somme = c1 + c2;
    Complexe produit = c1 * c2;
    Complexe sommeDouble = c1 + 5.0;
    Complexe produitDouble = c1 * 2.0;

    std::cout << "c1: ";
    c1.afficher();
    std::cout << "c2: ";
    c2.afficher();
    std::cout << "Somme (c1 + c2): ";
    somme.afficher();
    std::cout << "Produit (c1 * c2): ";
    produit.afficher();
    std::cout << "Somme (c1 + 5.0): ";
    sommeDouble.afficher();
    std::cout << "Produit (c1 * 2.0): ";
    produitDouble.afficher();
    return 0;
}
