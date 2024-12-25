#include <iostream>
#include <string>
using namespace std;

class Etudiant {
private:
    static int compteurMatricules;
    int matricule;
    string nom;
    int nbrNotes;
    float *tabNotes;
public:
    Etudiant() : matricule(++compteurMatricules), nom("Inconnu"), nbrNotes(0), tabNotes(nullptr) {}

    Etudiant(string nom, int nbrNotes) : matricule(++compteurMatricules), nom(nom), nbrNotes(nbrNotes) {
        tabNotes = new float[nbrNotes]; 
    }
    ~Etudiant() {
        delete[] tabNotes; 
    }
    Etudiant(const Etudiant &e) : matricule(++compteurMatricules), nom(e.nom), nbrNotes(e.nbrNotes) {
        tabNotes = new float[nbrNotes];
        for (int i = 0; i < nbrNotes; i++) {
            tabNotes[i] = e.tabNotes[i];
        }
    }

    int getMatricule() const { return matricule; }
    void setNom(string nom) { this->nom = nom; }
    string getNom() const { return nom; }
    void setNbrNotes(int nbr) { 
        nbrNotes = nbr;
        delete[] tabNotes;
        tabNotes = new float[nbrNotes]; 
    }
    int getNbrNotes() const { return nbrNotes; }
    void saisie() {
        cout << "Saisir les " << nbrNotes << " notes de l'étudiant " << nom << ": " << endl;
        for (int i = 0; i < nbrNotes; i++) {
            cout << "Note " << i + 1 << ": ";
            cin >> tabNotes[i];
        }
    }

    void affichage() const {
        cout << "Matricule: " << matricule << endl;
        cout << "Nom: " << nom << endl;
        cout << "Nombre de notes: " << nbrNotes << endl;
        cout << "Notes: ";
        for (int i = 0; i < nbrNotes; i++) {
            cout << tabNotes[i] << " ";
        }
        cout << endl;
    }
    float moyenne() const {
        float total = 0;
        for (int i = 0; i < nbrNotes; i++) {
            total += tabNotes[i];
        }
        return total / nbrNotes;
    }
    bool admis() const {
        return moyenne() >= 10;
    }
    static bool comparer(const Etudiant &e1, const Etudiant &e2) {
        return e1.moyenne() == e2.moyenne();
    }
};
int Etudiant::compteurMatricules = 0;

int main() {
    Etudiant etudiant1("John Doe", 3); 
    etudiant1.saisie(); 
    etudiant1.affichage(); 
    Etudiant etudiant2("Jane Smith", 3); 
    etudiant2.saisie();
    etudiant2.affichage();
    if (Etudiant::comparer(etudiant1, etudiant2)) {
        cout << "Les deux étudiants ont la même moyenne." << endl;
    } else {
        cout << "Les moyennes des deux étudiants sont différentes." << endl;
    }
    cout << "Etudiant 1 " << (etudiant1.admis() ? "admis" : "non admis") << endl;
    cout << "Etudiant 2 " << (etudiant2.admis() ? "admis" : "non admis") << endl;

    return 0;
}
