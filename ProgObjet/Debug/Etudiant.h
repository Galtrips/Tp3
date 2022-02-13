#pragma once
#include <string>
#include <iostream>
#include "personne.h"


using namespace std;

class Etudiant :public Personne {
private:
	string netudiant;
	string ngroupe;
public:
	Etudiant(string n, string p, string e, string ne, string ng);
	~Etudiant();
	string getNum() const {
		return netudiant;
	}
	void Affiche();
};