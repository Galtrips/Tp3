#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Professeur.h"
#include "Etudiant.h"

using namespace std;

class PTUT {
private:
	string Sujet;
	Professeur* prof;
	vector<Etudiant*> etu;
public:
	PTUT() { ; };
	PTUT(string s, Professeur* p, Etudiant* e1, Etudiant* e2, Etudiant* e3, Etudiant* e4) {
		Sujet = s;
		prof = p;
		etu.push_back(e1);
		etu.push_back(e2);
		etu.push_back(e3);
		etu.push_back(e4);
	}
	string getSujet() const {
		return Sujet;
	}
	Professeur* getProf() const {
		return prof;
	}
	vector<Etudiant*> getVec() const {
		return etu;
	}

	void setSujet(string s);
	void setProf(Professeur* p);
	void addEtu(Etudiant* e);

	void Affiche();
};