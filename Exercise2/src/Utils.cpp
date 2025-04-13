#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> 

void CalcolaValoreFinale() {
    using namespace std;

    ifstream file("data.txt");
    if (file.fail()) {
        cerr << "Errore nell'apertura del file" << endl;
        return;
    }

    double S = 0;
    int n = 0;
    string riga, valore;


    getline(file, riga);
    stringstream stream1(riga);
    getline(stream1, valore, ';');
    stream1 >> S;


    getline(file, riga);
    stringstream stream2(riga);
    getline(stream2, valore, ';');
    stream2 >> n;

    
    double* w = new double[n];
    double* r = new double[n];

  
    getline(file, riga);


    for (int i = 0; i < n; ++i) {
        getline(file, riga);
        stringstream stream3(riga);
        string valorew, valorer;
        getline(stream3, valorew, ';');
        getline(stream3, valorer, ';');
        stringstream valorew_double(valorew);
        stringstream valorer_double(valorer);
        valorew_double >> w[i];
        valorer_double >> r[i];
    }

    double tasso = 0.0;
    for (int i = 0; i < n; ++i) {
        tasso += w[i] * r[i];
    }

    double valore_finale = S * (1 + tasso);
	//STAMPA SCHERMO
    cout << setprecision(2);
    cout << "S=" << S << ", n=" << n << endl;

    cout << "w=[";
    for (int i = 0; i < n; ++i) {
        cout << w[i];
        if (i != n - 1) cout << " ";
    }
    cout << "]" << endl;

    cout << "r=[";
    for (int i = 0; i < n; ++i) {
        cout << r[i];
        if (i != n - 1) cout << " ";
    }
    cout << "]" << endl;

    cout << setprecision(4);
    cout << "Tasso di rendimento: " << tasso << endl;

    cout << setprecision(2);
    cout << "Valore finale: " << valore_finale << endl;

    //STAMPA FILE
    ofstream ofs("result.txt");
    if (ofs.fail()) {
        cerr << "Errore nell'apertura di result.txt" << endl;
        return;
    }

    ofs << setprecision(2);
    ofs << "S=" << S << ", n=" << n << endl;

    ofs << "w=[";
    for (int i = 0; i < n; ++i) {
        ofs << w[i];
        if (i != n - 1) ofs << " ";
    }
    ofs << "]" << endl;

    ofs << "r=[";
    for (int i = 0; i < n; ++i) {
        ofs << r[i];
        if (i != n - 1) ofs << " ";
    }
    ofs << "]" << endl;

    ofs << setprecision(4);
    ofs << "Tasso di rendimento: " << tasso << endl;

    ofs << setprecision(2);
    ofs << "Valore finale: " << valore_finale << endl;
}
