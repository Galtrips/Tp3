#include "Etudiant.h"
#include <iostream>
#include <string>

Etudiant::Etudiant(string n, string p, string e, string ne, string ng):Personne(n,p,e) {
	netudiant = ne;
	ngroupe = ng;
	
}

Etudiant::~Etudiant() {
	
}


void Etudiant::Affiche() {
	cout << "--------------" << endl;
	cout << "Numero Etudiant : " << netudiant << endl;
	Personne::Affiche();
	cout << "Numero de groupe : " << ngroupe << endl;
	cout << "--------------" << endl;
}