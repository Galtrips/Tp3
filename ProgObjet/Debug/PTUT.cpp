#include "PTUT.h"
#include <iostream>
#include <string>
using namespace std;


void PTUT::setSujet(string s) {
	Sujet = s;
}

void PTUT::setProf(Professeur* p) {
	prof = p;
}

void PTUT::addEtu(Etudiant* e) {
	if (etu.size() < 4) {
		etu.push_back(e);
	}
	else {
		cout << "Il y a deja 4 etudiant pour le sujet : " << Sujet << ". Impossible d'integrer " << e->getPrenom() << " " << e->getNom() << endl;
	}
}

void PTUT::Affiche() {
	cout << "--------------" << endl;
	cout << "Sujet : " << Sujet << endl;
	cout << "Professeur : " << (prof == nullptr ? "NULL" : prof->getNom()+"."+ prof->getPrenom()) << endl;
	cout << "Etudiants :" << endl;
	for (Etudiant* i : etu) {
		cout << (i == nullptr ? "NULL" : i->getPrenom()+" "+ i->getNom()) << endl;
	}
	cout << "--------------" << endl;
}