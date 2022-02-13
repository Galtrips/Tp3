#include <string>
#include <iostream>
#include "Professeur.h"
using namespace std;

Professeur::Professeur(string n, string p, string e, string a): Personne(n,p,e) {
	acronyme = a;
}


void Professeur::Affiche() {
	cout << "--------------" << endl;
	cout << "Acronyme : " << acronyme << endl;
	Personne::Affiche();
	cout << "--------------" << endl;
}