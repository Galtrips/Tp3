#pragma once
#include <iostream>
#include <string>
#include "personne.h"

class Professeur :public Personne {
private:
	string acronyme;
public:
	Professeur(string n, string p, string e, string a);
	string getAcronyme() const {
		return acronyme;
	}
	void Affiche();
};
