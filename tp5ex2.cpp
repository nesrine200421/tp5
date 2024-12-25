#include <iostream>
#include <cmath> 
using namespace std;

class Vecteur3d {
private:
    float x, y, z;

public:
    Vecteur3d(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    float getX() const { return x; }
    float getY() const { return y; }
    float getZ() const { return z; }

    void setX(float x) { this->x = x; }
    void setY(float y) { this->y = y; }
    void setZ(float z) { this->z = z; }

    void afficher() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

    static Vecteur3d somme(const Vecteur3d& v1, const Vecteur3d& v2) {
        return Vecteur3d(v1.getX() + v2.getX(), v1.getY() + v2.getY(), v1.getZ() + v2.getZ());
    }

    static float produitScalaire(const Vecteur3d& v1, const Vecteur3d& v2) {
        return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
    }

    static bool coïncide(const Vecteur3d& v1, const Vecteur3d& v2) {
        return (v1.getX() == v2.getX() && v1.getY() == v2.getY() && v1.getZ() == v2.getZ());
    }

    float norme() const {
        return sqrt(x * x + y * y + z * z);
    }

    static Vecteur3d normax(const Vecteur3d& v1, const Vecteur3d& v2) {
        return (v1.norme() > v2.norme()) ? v1 : v2;
    }

    static Vecteur3d* normaxAdresse(const Vecteur3d& v1, const Vecteur3d& v2) {
        return (v1.norme() > v2.norme()) ? new Vecteur3d(v1) : new Vecteur3d(v2);
    }

    static Vecteur3d& normaxReference(const Vecteur3d& v1, const Vecteur3d& v2) {
        static Vecteur3d result = (v1.norme() > v2.norme()) ? v1 : v2;
        return result;
    }
};

int main() {
    Vecteur3d v1(1.0, 2.0, 3.0);
    Vecteur3d v2(4.0, 5.0, 6.0);
    cout << "V1: ";
    v1.afficher();
    cout << "V2: ";
    v2.afficher();
    Vecteur3d v3 = Vecteur3d::somme(v1, v2);
    cout << "Somme de V1 et V2: ";
    v3.afficher();
    cout << "Produit scalaire de V1 et V2: " << Vecteur3d::produitScalaire(v1, v2) << endl;
    cout << "V1 et V2 coïncident ? " << (Vecteur3d::coïncide(v1, v2) ? "Oui" : "Non") << endl;
    cout << "Norme de V1: " << v1.norme() << endl;
    cout << "Norme de V2: " << v2.norme() << endl;
    Vecteur3d vMax = Vecteur3d::normax(v1, v2);
    cout << "Vecteur avec la plus grande norme: ";
    vMax.afficher();
    Vecteur3d* vMaxAdresse = Vecteur3d::normaxAdresse(v1, v2);
    cout << "Vecteur avec la plus grande norme (par adresse): ";
    vMaxAdresse->afficher();
    delete vMaxAdresse;  
    Vecteur3d& vMaxReference = Vecteur3d::normaxReference(v1, v2);
    cout << "Vecteur avec la plus grande norme (par référence): ";
    vMaxReference.afficher();

    return 0;
}
