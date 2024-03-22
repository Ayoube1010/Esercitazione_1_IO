#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


double mappaturaPunto(double valore) {

    return (valore - 1) * (2 - (-1)) / (5 - 1) + (-1);
}


int main()
{
    ifstream inputFile("data.csv");
    if (!inputFile.is_open()) {
        cerr << "ERRORE! il file non è aperto correttamente." << endl;
        return 0;
    }

    ofstream outputFile("result.csv");
    if (!outputFile.is_open()) {
        cerr << "ERRORE! il file non è aperto correttamente." << endl;
        return 0;
    }

    double valore;
    double somma = 0;

    // Legge i valori dal file, calcola la media e scrive il risultato
    for (int i = 1; inputFile >> valore; ++i) {
        somma += mappaturaPunto(valore);
        double mean = somma / i;
        outputFile << i << " " << scientific << setprecision(16) << mean << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
