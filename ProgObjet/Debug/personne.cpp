#include "personne.h"
#include <iostream>
using namespace std;

Personne::Personne() {

};

Personne::Personne(string n, string p, string e) {
	nom = n;
	prenom = p;
	email = e;
	
};

Personne::~Personne() {
	
}

string Personne::getNom() const {
	return nom;
};

string Personne::getPrenom() const {
	return prenom;
};

string Personne::getEmail() const {
	return email;
};

void Personne::setNom(string n) {
	nom = n;
};

void Personne::setPrenom(string p) {
	prenom = p;
};

void Personne::setEmail(string e) {
	email = e;
};


void Personne::Affiche() const {
	cout << "Nom : " << nom << endl;
	cout << "Prenom : " << prenom << endl;
	cout << "Email : " << email << endl;
}