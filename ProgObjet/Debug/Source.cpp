#include <iostream>
#include <fstream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <vector>
#include <string>
#include "Etudiant.h"
#include "Professeur.h"
#include "PTUT.h"


using namespace std;

void init_etu(vector<Etudiant*>& le, const char* Titre) {
	ifstream entree(Titre, ios::in);
	if (!entree) {
		cout << "Probleme d'ouverture !" << endl;
	}
	else {
		char lignes[300];
		while (!entree.eof()) {
			entree.getline(lignes, 300, ',');
			string ne = lignes;
			entree.getline(lignes, 300, ',');
			string ng = lignes;
			entree.getline(lignes, 300, ',');
			string prenom = lignes;
			entree.getline(lignes, 300);
			string nom = lignes;
			string email = nom + "." + prenom + "@gmail.com";
			le.push_back(new Etudiant(nom, prenom, email, ne, ng));
		}
	}
}

void init_prof(vector<Professeur*>& lp, const char* Titre) {
	ifstream entree(Titre, ios::in);
	if (!entree) {
		cout << "Probleme d'ouverture !" << endl;
	}
	else {
		char lignes[300];
		while (!entree.eof()) {
			entree.getline(lignes, 300, ',');
			string prenom = lignes;
			entree.getline(lignes, 300);
			string nom = lignes;
			string email = nom + "." + prenom + "@gmail.com";
			string acronyme;
			acronyme = string("") + prenom[0] + nom[0] + nom[1];
			//acronyme += nom[0];
			//acronyme += nom[1];
			lp.push_back(new Professeur(nom, prenom, email, acronyme));
		}
	}
}

void dprof(vector<Professeur*>& lp) {
	for (Professeur* prof : lp) {
		delete prof;
	}
}

void detu(vector<Etudiant*>& le) {
	for (Etudiant* etu : le) {
		delete etu;
	}
}

Professeur* searchProf(vector<Professeur*>& lp, string acronyme) {
	for (Professeur* prof : lp) {
		if (prof->getAcronyme() == acronyme) {
			return prof;
		}
	}
	return nullptr;
}

Etudiant* searchEtu(vector<Etudiant*>& le, string num) {
	for (Etudiant* etu : le) {
		if (etu->getNum() == num) {
			return etu;
		}
	}
	return nullptr;
}

void init_PTUT(vector<PTUT*>& lp, vector<Etudiant*>& le, vector<Professeur*>& lp2, const char* Titre) {
	ifstream entree(Titre, ios::in);
	if (!entree) {
		cout << "Probleme d'ouverture !" << endl;
	}
	else {
		char lignes[300];
		while (!entree.eof()) {
			entree.getline(lignes, 300, ',');
			string sujet = lignes;
			entree.getline(lignes, 300, ',');
			string acronyme = lignes;
			entree.getline(lignes, 300, ',');
			string etu1 = lignes;
			entree.getline(lignes, 300, ',');
			string etu2 = lignes;
			entree.getline(lignes, 300, ',');
			string etu3 = lignes;
			entree.getline(lignes, 300);
			string etu4 = lignes;

			Professeur* p = searchProf(lp2, acronyme);
			Etudiant* e1 = searchEtu(le, etu1);
			Etudiant* e2 = searchEtu(le, etu2);
			Etudiant* e3 = searchEtu(le, etu3);
			Etudiant* e4 = searchEtu(le, etu4);
			
			lp.push_back(new PTUT(sujet, p, e1, e2, e3, e4));
		}
	}
}

void dtut(vector<PTUT*>& lp) {
	for (PTUT* tut : lp) {
		tut->Affiche();
		delete tut;
	}
}


int main(int argc, char* argv[]){

	vector<PTUT*> ListePTUT;
	vector<Etudiant*> ListeEtudiants;
	vector<Professeur*> ListeProfesseur;

	init_etu(ListeEtudiants, "Etudiants.csv");
	init_prof(ListeProfesseur, "Encadrants.csv");
	init_PTUT(ListePTUT,ListeEtudiants, ListeProfesseur, "PTUT.csv");
	
	dtut(ListePTUT);
	dprof(ListeProfesseur);
	detu(ListeEtudiants);


	return 0;
}