#pragma once
#include <string>
#include <iostream>
using namespace std;

class Personne {
protected:
	string nom;
	string prenom;
	string email;
public:
	Personne();
	Personne(string n, string p, string e);
	~Personne();

	string getNom() const;
	string getPrenom() const;
	string getEmail() const;

	void setNom(string n);
	void setPrenom(string p);
	void setEmail(string e);

	

	void Affiche() const;
};
