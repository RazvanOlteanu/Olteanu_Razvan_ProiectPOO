#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <string>
using namespace std;

// Domeniul - RESTAURANT

class Rezervare {

public:

	const int idRezervare;
	static  int nrTotalComenzi;
	char* numeClient; 
	string nrTelefon;
	string dataRezervare;
	int masaRezervare;
	float durataRezervare; // cate ore stai
	
	static int getNrTotalComenzi() {
		return nrTotalComenzi;
	}

	Rezervare() : idRezervare(nrTotalComenzi++){
		
		this->numeClient = new char[strlen("Razvan") + 1];
		strcpy(this->numeClient, "Razvan");
		this->nrTelefon = "0724048358";
		this->dataRezervare = "8 august";
		this->masaRezervare = 5;
		this->durataRezervare = 1;

	}

	Rezervare(string nrTelefon,string dataRezervare) : idRezervare(nrTotalComenzi){
		nrTotalComenzi++;
		this->numeClient = new char[strlen("Anonim") + 1];
		strcpy(this->numeClient, "Anonim");
		this->nrTelefon = nrTelefon;
		this->dataRezervare = dataRezervare;
		this->masaRezervare = 5;
		this->durataRezervare = 1;

	}

	Rezervare(const char* numeClient,string nrTelefon,int masaRezervare, float durataRezervare) : idRezervare(nrTotalComenzi) {
		nrTotalComenzi++;
		this->numeClient = new char[strlen(numeClient) + 1];
		strcpy(this->numeClient, numeClient);
		this->nrTelefon = nrTelefon;
		this->dataRezervare = "8 august";
		this->masaRezervare = masaRezervare;
		this->durataRezervare = durataRezervare;

	}

	~Rezervare() {
		delete[] numeClient;
	}

	void afisareRezervare() {
		cout<< "Clientul cu numele "
			<< numeClient << " avand numarul de telefon "
			<< nrTelefon << " a facut o rezervare pe data de "
			<< dataRezervare << " la masa "
			<< masaRezervare << " cu durata de servire de " 
			<< durataRezervare << " ore " 
			<< endl;
	}
};

int Rezervare::nrTotalComenzi = 0;

class Meniu {

public:

	const int idMeniu;
	static int nrTotalMeniuri;
	char* numeMeniu;
	float pret;
	int durataMeniu; // cat dureaza prepararea in minute
	string descriereMeniu;
	
	static int getNrTotalMeniuri() {
		return nrTotalMeniuri;
	}

	Meniu() : idMeniu(nrTotalMeniuri++){
		this->numeMeniu = new char[strlen("Pizza") + 1];
		strcpy(this->numeMeniu, "Pizza");
		this->pret = 100;
		this->durataMeniu = 30;
		this->descriereMeniu = "Carnivora";

	}

	Meniu(float pret,int durataMeniu) : idMeniu(nrTotalMeniuri){
		nrTotalMeniuri++;
		this->numeMeniu = new char[strlen("Supa") + 1];
		strcpy(this->numeMeniu, "Supa");
		this->pret = pret;
		this->durataMeniu = durataMeniu;
		this->descriereMeniu = "de legume";

	}

	Meniu(const char* numeMeniu,float pret, string descriereMeniu) : idMeniu(nrTotalMeniuri){
		nrTotalMeniuri++;
		this->numeMeniu = new char[strlen(numeMeniu) + 1];
		strcpy(this->numeMeniu, numeMeniu);
		this->pret = pret;
		this->durataMeniu = 45;
		this->descriereMeniu = descriereMeniu;

	}

	~Meniu() {
		delete[] numeMeniu;
	}

	void afisareMeniu() {
	   cout << numeMeniu << ", " 
			<< descriereMeniu << " are pretul de " 
			<< pret << " RON " << "cu durata de preparare de "
			<< durataMeniu << " minute "
			<< endl;
	}

};

int Meniu::nrTotalMeniuri = 0;

class Ospatar {

public:

	const int idOspatar;
	static int nrTotalOspatari;
	char* nume;
	int varsta;
	int experienta; // ani
	float salariu;
	float bacsis;
	int meseServite; // intr-o zi 
	
	static int getNrTotalOspatari() {
		return nrTotalOspatari;
	}

	Ospatar() : idOspatar(nrTotalOspatari++) {
		this->nume = new char[strlen("Andrei") + 1];
		strcpy(this->nume, "Andrei");
		this->varsta = 25;
		this->experienta = 2;
		this->salariu = 3500;
		this->bacsis = 100;
		this->meseServite = 15;

	}

	Ospatar(const char* nume, int varsta) : idOspatar(nrTotalOspatari){
		nrTotalOspatari++;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;
		this->experienta = 7;
		this->salariu = 5000;
		this->bacsis = 150;
		this->meseServite = 20;

	}

	Ospatar(const char* nume, int varsta,int experienta, float salariu, float bacsis,int meseServite) : idOspatar(nrTotalOspatari) {
		nrTotalOspatari++;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;
		this->experienta = experienta;
		this->salariu = salariu;
		this->bacsis = bacsis;
		this->meseServite = meseServite;
	}

	~Ospatar() {
		delete[] nume;
	}

	void afisareOspatar() {
	   cout << "Ospatarul cu numele "
			<< nume << " are varsta de "
			<< varsta << " ani, experienta de "
			<< experienta << " ani, salariu pe luna de "
			<< salariu << " RON, face bacsis de "
			<< bacsis << " RON pe zi" << " si are o medie de "
			<< meseServite << " mese servite pe zi"
			<< endl;
	}

};

int Ospatar::nrTotalOspatari = 0;

void main() {

	Rezervare rez1;
	rez1.afisareRezervare();
	Rezervare rez2("0729988258","9 mai");
	rez2.afisareRezervare();
	Rezervare rez3("Marius", "0795157349",8,2);
	rez3.afisareRezervare();

	cout << endl;

	Meniu m1;
	m1.afisareMeniu();
	Meniu m2(55.5,50);
	m2.afisareMeniu();
	Meniu m3("Special", 100, "gatit cu ingreiente de calitate");
	m3.afisareMeniu();

	cout << endl;

	Ospatar o1;
	o1.afisareOspatar();
	Ospatar o2("Vlad", 30);
	o2.afisareOspatar();
	Ospatar o3("Dorel", 50, 20, 5500, 100, 8);
	o3.afisareOspatar();

}