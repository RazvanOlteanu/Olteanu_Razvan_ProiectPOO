#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
using namespace std;

// Domeniul - RESTAURANT

class Rezervare {

private:

	const int idRezervare;
	static int nrTotalComenzi;
	char* numeClient;
	string nrTelefon;
	string dataRezervare;
	int masaRezervare;
	float durataRezervare; // cate ore stai

public:

	static int getNrTotalComenzi() {
		return nrTotalComenzi;
	}

	char* getNumeClient() {
		return this->numeClient;
	}

	void setNumeClient(const char* numeClientNou) {
		if (this->numeClient != NULL) {
			delete[]this->numeClient;
		}
		this->numeClient = new char[strlen(numeClientNou) + 1];
		strcpy(this->numeClient, numeClientNou);
	}

	string getNrTelefon() {
		return this->nrTelefon;
	}

	void setNrTelefon(string NrTelefon) {
		if (this->nrTelefon.length() < 0) {
			this->nrTelefon = nrTelefon;
		}
	}

	string getDataRezervare() {
		return this->dataRezervare;
	}

	void setDataRezervare(string dataRezervare) {
		if (this->dataRezervare.length() > 0) {
			this->dataRezervare = dataRezervare;
		}
	}

	int getMasaRezervare() {
		return this->masaRezervare;
	}

	void setMasaRezervare() {
		if (this->masaRezervare > 0) {
			this->masaRezervare = masaRezervare;
		}
	}

	float getDurataRezervare() {
		return this->durataRezervare;
	}

	void setDurataRezervare() {
		if (this->durataRezervare > 0) {
			this->durataRezervare = durataRezervare;
		}
	}

	Rezervare(Rezervare& r1) : idRezervare(nrTotalComenzi++) {
		this->numeClient = new char[strlen(r1.numeClient) + 1];
		strcpy(this->numeClient, r1.numeClient);
		this->nrTelefon = r1.nrTelefon;
		this->dataRezervare = r1.dataRezervare;
		this->masaRezervare = r1.masaRezervare;
		this->durataRezervare = r1.durataRezervare;
	}

	Rezervare() : idRezervare(nrTotalComenzi++) {

		this->numeClient = new char[strlen("Razvan") + 1];
		strcpy(this->numeClient, "Razvan");
		this->nrTelefon = "0724048358";
		this->dataRezervare = "8 august";
		this->masaRezervare = 5;
		this->durataRezervare = 1;
	}

	Rezervare(string nrTelefon, string dataRezervare) : idRezervare(nrTotalComenzi) {
		nrTotalComenzi++;
		this->numeClient = new char[strlen("Anonim") + 1];
		strcpy(this->numeClient, "Anonim");
		this->nrTelefon = nrTelefon;
		this->dataRezervare = dataRezervare;
		this->masaRezervare = 5;
		this->durataRezervare = 1;
	}

	Rezervare(const char* numeClient, string nrTelefon, int masaRezervare, float durataRezervare) : idRezervare(nrTotalComenzi) {
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
		cout << "Clientul cu numele "
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

private:

	const int idMeniu;
	static int nrTotalMeniuri;
	char* numeMeniu;
	float pret;
	int durataMeniu; // cat dureaza prepararea in minute
	string descriereMeniu;

public:

	static int getNrTotalMeniuri() {
		return nrTotalMeniuri;
	}

	char* getNumeMeniu() {
		return this->numeMeniu;
	}

	void setNumeClient(char* numeMeniuNou) {
		if (this->numeMeniu != NULL) {
			delete[]this->numeMeniu;
		}
		this->numeMeniu = new char[strlen(numeMeniuNou) + 1];
		strcpy(this->numeMeniu, numeMeniuNou);
	}

	float getPret() {
		return this->pret;
	}

	void setPret(float pret) {
		if (this->pret > 0) {
			this->pret = pret;
		}
	}

	int getDurataMeniu() {
		return this->durataMeniu;
	}

	void setDurataMeniu(int durataMeniu) {
		if (this->durataMeniu > 0) {
			this->durataMeniu = durataMeniu;
		}
	}

	string getDescriereMeniu() {
		return this->descriereMeniu;
	}

	void setDescriereMeniu(string descriereMeniu) {
		if (this->descriereMeniu.length() > 0) {
			this->descriereMeniu = descriereMeniu;
		}
	}

	Meniu(Meniu& meniu1) : idMeniu(nrTotalMeniuri++) {
		this->numeMeniu = new char[strlen(meniu1.numeMeniu) + 1];
		strcpy(this->numeMeniu, meniu1.numeMeniu);
		this->pret = meniu1.pret;
		this->durataMeniu = meniu1.durataMeniu;
		this->descriereMeniu = meniu1.descriereMeniu;
	}

	Meniu() : idMeniu(nrTotalMeniuri++) {
		this->numeMeniu = new char[strlen("Pizza") + 1];
		strcpy(this->numeMeniu, "Pizza");
		this->pret = 100;
		this->durataMeniu = 30;
		this->descriereMeniu = "Carnivora";
	}

	Meniu(float pret, int durataMeniu) : idMeniu(nrTotalMeniuri) {
		nrTotalMeniuri++;
		this->numeMeniu = new char[strlen("Supa") + 1];
		strcpy(this->numeMeniu, "Supa");
		this->pret = pret;
		this->durataMeniu = durataMeniu;
		this->descriereMeniu = "de legume";
	}

	Meniu(const char* numeMeniu, float pret, string descriereMeniu) : idMeniu(nrTotalMeniuri) {
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

private:

	const int idOspatar;
	static int nrTotalOspatari;
	char* nume;
	int varsta;
	int experienta; // ani
	float salariu;
	float bacsis;
	int meseServite; // intr-o zi 

public:

	static int getNrTotalOspatari() {
		return nrTotalOspatari;
	}

	char* getNume() {
		return this->nume;
	}

	void setNume(char* numeNou) {
		if (this->nume != NULL) {
			delete[]this->nume;
		}
		this->nume = new char[strlen(numeNou) + 1];
		strcpy(this->nume, numeNou);
	}

	int getVarsta() {
		return this->varsta;
	}

	void setVarsta(int varsta) {
		if (this->varsta >= 18) {
			this->varsta = varsta;
		}
	}

	int getExperienta() {
		return this->experienta;
	}

	void setExperienta(int experienta) {
		if (this->experienta > 0) {
			this->experienta = experienta;
		}
	}

	float getSalariu() {
		return this->salariu;
	}

	void setSalariu(float salariu) {
		if (this->salariu >= 1000) {
			this->salariu = salariu;
		}
	}

	float getBacsis() {
		return this->bacsis;
	}

	void setBacsis(float bacsis) {
		if (this->bacsis >= 50) {
			this->bacsis = bacsis;
		}
	}

	int getMeseServite() {
		return this->meseServite;
	}

	void setMeseServite(int meseServite) {
		if (this->meseServite > 0) {
			this->meseServite = meseServite;
		}
	}

	Ospatar(Ospatar& ospatar1) :idOspatar(nrTotalOspatari) {
		this->nume = new char[strlen(ospatar1.nume) + 1];
		strcpy(this->nume, ospatar1.nume);
		this->varsta = ospatar1.varsta;
		this->experienta = ospatar1.experienta;
		this->salariu = ospatar1.salariu;
		this->bacsis = ospatar1.bacsis;
		this->meseServite = ospatar1.meseServite;
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

	Ospatar(const char* nume, int varsta) : idOspatar(nrTotalOspatari) {
		nrTotalOspatari++;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;
		this->experienta = 7;
		this->salariu = 5000;
		this->bacsis = 150;
		this->meseServite = 20;
	}

	Ospatar(const char* nume, int varsta, int experienta, float salariu, float bacsis, int meseServite) : idOspatar(nrTotalOspatari) {
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

	friend void procesareRezervare(Ospatar& ospatar, Rezervare& rezervare, Meniu& meniu);

	friend void medieBacsis(Ospatar& ospatar);
};

int Ospatar::nrTotalOspatari = 0;

void procesareRezervare(Ospatar& ospatar, Rezervare& rezervare, Meniu& meniu) {
	float costTotal = meniu.getPret() * rezervare.getDurataRezervare();
	costTotal += ospatar.bacsis;
	cout << "Costul total pentru clientul "
		<< rezervare.getNumeClient() << " de la masa "
		<< rezervare.getMasaRezervare() << " este de "
		<< costTotal << " RON " << endl;
}

void medieBacsis(Ospatar& ospatar) {
	float medie = 1.0 * ospatar.bacsis / ospatar.meseServite;
	cout << "Ospatarul " << ospatar.nume << " a castigat in medie " << medie << " lei";
}

int main() {

	Rezervare rez1;
	rez1.afisareRezervare();
	Rezervare rez2("0729988258", "9 mai");
	rez2.afisareRezervare();
	Rezervare rez3("Marius", "0795157349", 8, 2);
	rez3.afisareRezervare();

	Rezervare r1 = rez2;
	Rezervare r2(rez2);
	r1.afisareRezervare();

	cout << endl;

	Meniu m1;
	m1.afisareMeniu();
	Meniu m2(55.5, 50);
	m2.afisareMeniu();
	Meniu m3("Special", 100, "gatit cu ingreiente de calitate");
	m3.afisareMeniu();

	Meniu meniu1 = m2;
	Meniu meniu2(m2);
	meniu1.afisareMeniu();

	cout << endl;

	Ospatar o1;
	o1.afisareOspatar();
	Ospatar o2("Vlad", 30);
	o2.afisareOspatar();
	Ospatar o3("Dorel", 50, 20, 5500, 100, 8);
	o3.afisareOspatar();

	Ospatar ospatar1 = o3;
	Ospatar ospatar2(o1);
	ospatar1.afisareOspatar();

	cout << endl;

	procesareRezervare(o3, rez1, m2);
	medieBacsis(o1);
}