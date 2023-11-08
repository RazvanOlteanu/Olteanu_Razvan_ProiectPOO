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
	bool status;

public:

	//get-eri si set-eri

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
		if (this->nrTelefon.length() > 9) {
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

	void setMasaRezervare(int masaRezervare) {
		if (this->masaRezervare > 0) {
			this->masaRezervare = masaRezervare;
		}
	}

	float getDurataRezervare() {
		return this->durataRezervare;
	}

	void setDurataRezervare(float durataRezervare) {
		if (this->durataRezervare > 0) {
			this->durataRezervare = durataRezervare;
		}
	}

	bool getStatus() {
		return this->status;
	}

	void setStatus(bool status) {
		if (this->status == true || this->status == false) {
			this->status = status;
		}
	}

	// Constructorul de copiere

	Rezervare(Rezervare& r1) : idRezervare(nrTotalComenzi++) {
		this->numeClient = new char[strlen(r1.numeClient) + 1];
		strcpy(this->numeClient, r1.numeClient);
		this->nrTelefon = r1.nrTelefon;
		this->dataRezervare = r1.dataRezervare;
		this->masaRezervare = r1.masaRezervare;
		this->durataRezervare = r1.durataRezervare;
		this->status = r1.status;
	}

	// Constructorul fara parametrii

	Rezervare() : idRezervare(nrTotalComenzi++) {

		this->numeClient = new char[strlen("Razvan") + 1];
		strcpy(this->numeClient, "Razvan");
		this->nrTelefon = "0724048358";
		this->dataRezervare = "8 august";
		this->masaRezervare = 5;
		this->durataRezervare = 1;
		this->status = true;
	}

	// Constructori cu parametrii

	Rezervare(string nrTelefon, string dataRezervare) : idRezervare(nrTotalComenzi) {
		nrTotalComenzi++;
		this->numeClient = new char[strlen("Anonim") + 1];
		strcpy(this->numeClient, "Anonim");
		this->nrTelefon = nrTelefon;
		this->dataRezervare = dataRezervare;
		this->masaRezervare = 5;
		this->durataRezervare = 1;
		this->status = false;
	}

	Rezervare(const char* numeClient, string nrTelefon, int masaRezervare, float durataRezervare) : idRezervare(nrTotalComenzi) {
		nrTotalComenzi++;
		this->numeClient = new char[strlen(numeClient) + 1];
		strcpy(this->numeClient, numeClient);
		this->nrTelefon = nrTelefon;
		this->dataRezervare = "8 august";
		this->masaRezervare = masaRezervare;
		this->durataRezervare = durataRezervare;
		this->status = true;
	}

	// Destructorul

	~Rezervare() {
		delete[] numeClient;
	}

	void afisareRezervare() {
		cout << "Clientul cu numele "
			<< numeClient << " avand numarul de telefon "
			<< nrTelefon << " a facut o rezervare pe data de "
			<< dataRezervare << " la masa "
			<< masaRezervare << " cu durata de servire de "
			<< durataRezervare << " ore,"
			<< (status ? " in desfasurare" : " terminat")
			<< endl;
	}

	// Supraincarcare Operatori

	Rezervare operator=(const Rezervare& r) {
		if (this != &r) {
			this->numeClient = new char[strlen(r.numeClient) + 1];
			strcpy(this->numeClient, r.numeClient);
			this->nrTelefon = r.nrTelefon;
			this->dataRezervare = r.dataRezervare;
			this->masaRezervare = r.masaRezervare;
			this->durataRezervare = r.durataRezervare;
			this->status = r.status;
			return *this;
		}
	}

	Rezervare operator!() {
		Rezervare copie = *this;
		copie.status = !copie.status;
		return copie;
	}

	friend ostream& operator<<(ostream& ost, const Rezervare& r);
	friend istream& operator>>(istream& ist, Rezervare& r);
};

ostream& operator<<(ostream& ost, const Rezervare& r) {
	ost << "Clientul cu numele "
		<< r.numeClient << " avand numarul de telefon "
		<< r.nrTelefon << " a facut o rezervare pe data de "
		<< r.dataRezervare << " la masa "
		<< r.masaRezervare << " cu durata de servire de "
		<< r.durataRezervare << " ore "
		<< (r.status ? "in desfasurare" : "terminat")
		<< endl;
	return ost;
}

istream& operator>>(istream& ist, Rezervare& r) {
	cout << " Nume client: ";
	ist >> r.numeClient;
	cout << " Nr de Telefon: ";
	ist >> r.nrTelefon;
	cout << " Data rezervare: ";
	ist >> r.dataRezervare;
	cout << " Masa rezervare: ";
	ist >> r.masaRezervare;
	cout << " Durata rezervare: ";
	ist >> r.durataRezervare;
	cout << "Status rezervare: ";
	ist >> r.status;
	return ist;
}

int Rezervare::nrTotalComenzi = 0;

class Meniu {

private:

	const int idMeniu;
	static int nrTotalMeniuri;
	char* numeMeniu;
	float pret;
	int durataMeniu; // cat dureaza prepararea in minute
	string descriereMeniu;
	bool vegan;

public:

	// get-eri si set-eri

	static int getNrTotalMeniuri() {
		return nrTotalMeniuri;
	}

	char* getNumeMeniu() {
		return this->numeMeniu;
	}

	void setNumeMeniu(char* numeMeniuNou) {
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

	bool getVegan() {
		return this->vegan;
	}

	void setVegan(bool vegan) {
		if (this->vegan == true || this->vegan == false) {
			this->vegan = vegan;
		}
	}

	// Constructorul de copiere

	Meniu(Meniu& meniu1) : idMeniu(nrTotalMeniuri++) {
		this->numeMeniu = new char[strlen(meniu1.numeMeniu) + 1];
		strcpy(this->numeMeniu, meniu1.numeMeniu);
		this->pret = meniu1.pret;
		this->durataMeniu = meniu1.durataMeniu;
		this->descriereMeniu = meniu1.descriereMeniu;
		this->vegan = meniu1.vegan;
	}

	// Constructorul fara parametrii

	Meniu() : idMeniu(nrTotalMeniuri++) {
		this->numeMeniu = new char[strlen("Pizza") + 1];
		strcpy(this->numeMeniu, "Pizza");
		this->pret = 100;
		this->durataMeniu = 30;
		this->descriereMeniu = "Carnivora";
		this->vegan = false;
	}

	// Constructori cu parametrii

	Meniu(float pret, int durataMeniu) : idMeniu(nrTotalMeniuri) {
		nrTotalMeniuri++;
		this->numeMeniu = new char[strlen("Supa") + 1];
		strcpy(this->numeMeniu, "Supa");
		this->pret = pret;
		this->durataMeniu = durataMeniu;
		this->descriereMeniu = "de legume";
		this->vegan = true;
	}

	Meniu(const char* numeMeniu, float pret, string descriereMeniu) : idMeniu(nrTotalMeniuri) {
		nrTotalMeniuri++;
		this->numeMeniu = new char[strlen(numeMeniu) + 1];
		strcpy(this->numeMeniu, numeMeniu);
		this->pret = pret;
		this->durataMeniu = 45;
		this->descriereMeniu = descriereMeniu;
		this->vegan = false;
	}

	// Destructorul

	~Meniu() {
		delete[] numeMeniu;
	}

	void afisareMeniu() {
		cout << numeMeniu << ", "
			<< descriereMeniu << " are pretul de "
			<< pret << " RON " << "cu durata de preparare de "
			<< durataMeniu << " minute, fiind "
			<< (vegan ? " vegan" : " normal")
			<< endl;
	}

	// Supraincarcare operatori

	Meniu operator=(const Meniu& m) {
		if (this != &m) {
			if (numeMeniu != NULL) {
				this->numeMeniu = new char[strlen(m.numeMeniu) + 1];
				strcpy(this->numeMeniu, m.numeMeniu);
			}
			this->pret = m.pret;
			this->durataMeniu = m.durataMeniu;
			this->descriereMeniu = m.descriereMeniu;
			this->vegan = m.vegan;
			return *this;
		}
	}

	Meniu operator!() {
		Meniu copie = *this;
		copie.vegan = !copie.vegan;
		return copie;
	}

	friend ostream& operator<<(ostream& ost, const Meniu& m);
	friend istream& operator>>(istream& ist, Meniu& m);
};

ostream& operator<<(ostream& ost, const Meniu& m) {
	cout << m.numeMeniu << ", "
		<< m.descriereMeniu << " are pretul de "
		<< m.pret << " RON " << "cu durata de preparare de "
		<< m.durataMeniu << " minute, fiind "
		<< (m.vegan ? " vegan" : " normal")
		<< endl;
	return ost;
}

istream& operator>>(istream& ist, Meniu& m) {
	cout << " Nume meniu: ";
	ist >> m.numeMeniu;
	cout << " Pret: ";
	ist >> m.pret;
	cout << " Durata meniu: ";
	ist >> m.durataMeniu;
	cout << " Descriere meniu: ";
	ist >> m.descriereMeniu;
	cout << "Felul meniului: ";
	ist >> m.vegan;
	return ist;
}

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
	bool disponibil;

public:

	// get-eri si set-eri

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

	bool getDisponibil() {
		return this->disponibil;
	}

	void setDisponibil(bool disponibil) {
		if (this->disponibil == true || this->disponibil == false) {
			this->disponibil = disponibil;
		}
	}

	// Constructorul de copiere

	Ospatar(Ospatar& ospatar1) :idOspatar(nrTotalOspatari) {
		this->nume = new char[strlen(ospatar1.nume) + 1];
		strcpy(this->nume, ospatar1.nume);
		this->varsta = ospatar1.varsta;
		this->experienta = ospatar1.experienta;
		this->salariu = ospatar1.salariu;
		this->bacsis = ospatar1.bacsis;
		this->meseServite = ospatar1.meseServite;
		this->disponibil = ospatar1.disponibil;
	}

	// Constructorul fara parametrii

	Ospatar() : idOspatar(nrTotalOspatari++) {
		this->nume = new char[strlen("Andrei") + 1];
		strcpy(this->nume, "Andrei");
		this->varsta = 25;
		this->experienta = 2;
		this->salariu = 3500;
		this->bacsis = 100;
		this->meseServite = 15;
		this->disponibil = true;
	}

	// Constructori cu parametrii

	Ospatar(const char* nume, int varsta) : idOspatar(nrTotalOspatari) {
		nrTotalOspatari++;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->varsta = varsta;
		this->experienta = 7;
		this->salariu = 5000;
		this->bacsis = 150;
		this->meseServite = 20;
		this->disponibil = false;
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
		this->disponibil = true;
	}

	// Destructorul

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
			<< meseServite << " mese servite pe zi, fiind "
			<< (disponibil ? " disponibil" : " indisponibil")
			<< endl;
	}

	friend void procesareRezervare(Ospatar& ospatar, Rezervare& rezervare, Meniu& meniu);
	friend void medieBacsis(Ospatar& ospatar);

	// Supraincarcare operatori

	Ospatar operator=(const Ospatar& o) {
		if (this != &o) {
			this->nume = new char[strlen(o.nume) + 1];
			strcpy(this->nume, o.nume);
			this->varsta = o.varsta;
			this->experienta = o.experienta;
			this->salariu = o.salariu;
			this->bacsis = o.bacsis;
			this->meseServite = o.meseServite;
			this->disponibil = o.disponibil;
			return *this;
		}
	}

	Ospatar operator!() {
		Ospatar copie = *this;
		copie.disponibil = !copie.disponibil;
		return copie;
	}

	friend ostream& operator<<(ostream& ost, const Ospatar& o);
	friend istream& operator>>(istream& ist, Ospatar& o);
};

ostream& operator<<(ostream& ost, const Ospatar& o) {
	cout << "Ospatarul cu numele "
		<< o.nume << " are varsta de "
		<< o.varsta << " ani, experienta de "
		<< o.experienta << " ani, salariu pe luna de "
		<< o.salariu << " RON, face bacsis de "
		<< o.bacsis << " RON pe zi" << " si are o medie de "
		<< o.meseServite << " mese servite pe zi, fiind "
		<< (o.disponibil ? " disponibil" : " indisponibil")
		<< endl;
	return ost;
}

istream& operator>>(istream& ist, Ospatar& o) {
	cout << " Nume ospatar: ";
	ist >> o.nume;
	cout << " Varsta: ";
	ist >> o.varsta;
	cout << " Experienta: ";
	ist >> o.experienta;
	cout << " Salariu: ";
	ist >> o.salariu;
	cout << " Bacsis: ";
	ist >> o.bacsis;
	cout << " Mese servite: ";
	ist >> o.meseServite;
	cout << " Disponibilitate ";
	ist >> o.disponibil;
	return ist;
}

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

	cout << endl;

	rez1 = rez2;
	rez1.afisareRezervare();

	cout << endl;

	m1 = m3;
	m1.afisareMeniu();

	cout << endl;

	o2 = o3;
	o2.afisareOspatar();

	cout << rez2;
	cout << m3;
	cout << o2;

	cin >> rez3;
	cout << rez3;

	cin >> m2;
	cout << m2;

	cin >> o3;
	cout << o3;

	Rezervare rv[3];
	Meniu mv[3];
	Ospatar ov[3];

	for (int i = 0; i <= 2; i++) {
		cin >> rv[i];
	}

	for (int i = 0; i <= 2; i++) {
		cin >> mv[i];
	}

	for (int i = 0; i <= 2; i++) {
		cin >> ov[i];
	}

	for (int i = 0; i <= 2; i++) {
		cout << rv[i] << "\n";
	}

	cout << "\n";

	for (int i = 0; i <= 2; i++) {
		cout << mv[i] << "\n";
	}

	cout << "\n";

	for (int i = 0; i <= 2; i++) {
		cout << ov[i] << "\n";
	}

	cout << "\n";

	Meniu mm[2][2];

	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			cin >> mm[i][j];
		}
	}

	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			if (j != 1)
				cout << mm[i][j] << " || ";
			else
				cout << mm[i][j];
		}
		cout << "\n";
	}

	return 0;
}