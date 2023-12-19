#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include<fstream>

using namespace std;

// Domeniul - RESTAURANT

class Persoana {
protected:
	char* nume;
	int varsta;
	float inaltime;
	float greutate;
public:
	virtual void cresteVarsta() = 0;

	Persoana() {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->varsta = 25;
		this->inaltime = 182;
		this->greutate = 75;
	}

	Persoana(int varsta, float greutate) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		this->varsta = varsta;
		this->inaltime = 180;
		this->greutate = greutate;
	}

	Persoana(Persoana& p1) {
		this->nume = new char[strlen(p1.nume) + 1];
		strcpy(this->nume, p1.nume);
		this->varsta = p1.varsta;
		this->inaltime = p1.inaltime;
		this->greutate = p1.greutate;
	}

	virtual ~Persoana() {
		cout << "Apel destructor Persoana" << endl;
		if (nume != NULL) {
			delete[]this->nume;
		}
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
		if (varsta >= 18) {
			this->varsta = varsta;
		}
	}

	float getInaltime() {
		return this->inaltime;
	}

	void setInaltime(float inaltime) {
		if (inaltime > 150) {
			this->varsta = varsta;
		}
	}

	float getGreutate() {
		return this->greutate;
	}

	void setGreutate(float greutate) {
		if (greutate > 40) {
			this->greutate = greutate;
		}
	}
};

class Firma {
protected:
	string industrie;
	string nume;
	long long cifraDeAfaceri;
	string patron;
public:
	virtual void cresteCifraDeAfaceri() = 0;

	Firma() {
		this->industrie = "Horeca";
		this->nume = "GenericName";
		this->cifraDeAfaceri = 1000000;
		this->patron = "Berlusconi";
	}

	Firma(string industrie, long long cifraDeAfaceri) {
		this->industrie = industrie;
		this->nume = "Hanul_Cu_Tei";
		this->cifraDeAfaceri = cifraDeAfaceri;
		this->patron = "Don_Giovanni";
	}

	Firma(Firma& f1) {
		this->industrie = f1.industrie;
		this->nume = f1.nume;
		this->cifraDeAfaceri = f1.cifraDeAfaceri;
		this->patron = f1.patron;
	}

	virtual ~Firma() {
		cout << "Apel destructor Persoana" << endl;
	}

	string getIndustrie() {
		return this->industrie;
	}

	void setIndustrie(string industrie) {
		if (industrie.length() > 0) {
			this->industrie = industrie;
		}
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string nume) {
		if (nume.length() > 3) {
			this->nume = nume;
		}
	}

	long long getCifraDeAfaceri() {
		return this->cifraDeAfaceri;
	}

	void setCifraDeAfaceri(long long cifraDeAfaceri) {
		if (cifraDeAfaceri > 0) {
			this->cifraDeAfaceri = cifraDeAfaceri;
		}
	}

	string getPatron() {
		return this->patron;
	}

	void setPatron(string patron) {
		if (patron.length() > 3) {
			this->patron = patron;
		}
	}
};


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
		if (nrTelefon.length() > 9) {
			this->nrTelefon = nrTelefon;
		}
	}

	string getDataRezervare() {
		return this->dataRezervare;
	}

	void setDataRezervare(string dataRezervare) {
		if (dataRezervare.length() > 0) {
			this->dataRezervare = dataRezervare;
		}
	}

	int getMasaRezervare() {
		return this->masaRezervare;
	}

	void setMasaRezervare(int masaRezervare) {
		if (masaRezervare > 0) {
			this->masaRezervare = masaRezervare;
		}
	}

	float getDurataRezervare() {
		return this->durataRezervare;
	}

	void setDurataRezervare(float durataRezervare) {
		if (durataRezervare > 0) {
			this->durataRezervare = durataRezervare;
		}
	}

	bool getStatus() {
		return this->status;
	}

	void setStatus(bool status) {
		if (status == true || status == false) {
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
			if (this->numeClient != NULL) {
				delete this->numeClient;
			}
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
	friend ofstream& operator<<(ofstream& ost, const Rezervare& r);
	friend ifstream& operator>>(ifstream& ist, Rezervare& r);

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

ofstream& operator<<(ofstream& ost, const Rezervare& r) {

	ost << r.numeClient << " " << r.nrTelefon << " " << r.dataRezervare << " " << r.masaRezervare << " " << r.durataRezervare << " ";
	ost << r.status << " ";
	ost << endl;
	return ost;
}

ifstream& operator>>(ifstream& ist, Rezervare& r) {
	ist >> r.numeClient;
	ist >> r.nrTelefon;
	ist >> r.dataRezervare;
	ist >> r.masaRezervare;
	ist >> r.durataRezervare;
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
		if (pret > 0) {
			this->pret = pret;
		}
	}

	int getDurataMeniu() {
		return this->durataMeniu;
	}

	void setDurataMeniu(int durataMeniu) {
		if (durataMeniu > 0) {
			this->durataMeniu = durataMeniu;
		}
	}

	string getDescriereMeniu() {
		return this->descriereMeniu;
	}

	void setDescriereMeniu(string descriereMeniu) {
		if (descriereMeniu.length() > 0) {
			this->descriereMeniu = descriereMeniu;
		}
	}

	bool getVegan() {
		return this->vegan;
	}

	void setVegan(bool vegan) {
		if (vegan == true || vegan == false) {
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
	friend ofstream& operator<<(ofstream& ost, const Meniu& m);
	friend ifstream& operator>>(ifstream& ist, Meniu& m);
};

ostream& operator<<(ostream& ost, const Meniu& m) {
	ost << m.numeMeniu << ", "
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

ofstream& operator<<(ofstream& ost, const Meniu& m) {
	ost << m.numeMeniu << " " << m.descriereMeniu << " " << m.pret << " " << m.durataMeniu << " " << m.vegan;
	ost << endl;
	return ost;
}

ifstream& operator>>(ifstream& ist, Meniu& m) {
	ist >> m.numeMeniu;
	ist >> m.descriereMeniu;
	ist >> m.pret;
	ist >> m.durataMeniu;
	ist >> m.vegan;
	return ist;
}

int Meniu::nrTotalMeniuri = 0;

class Ospatar : public Persoana {
protected:
	const int idOspatar;
	static int nrTotalOspatari;
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

	int getExperienta() {
		return this->experienta;
	}

	void setExperienta(int experienta) {
		if (experienta > 0) {
			this->experienta = experienta;
		}
	}

	float getSalariu() {
		return this->salariu;
	}

	void setSalariu(float salariu) {
		if (salariu >= 1000) {
			this->salariu = salariu;
		}
	}

	float getBacsis() {
		return this->bacsis;
	}

	void setBacsis(float bacsis) {
		if (bacsis >= 50) {
			this->bacsis = bacsis;
		}
	}

	int getMeseServite() {
		return this->meseServite;
	}

	void setMeseServite(int meseServite) {
		if (meseServite > 0) {
			this->meseServite = meseServite;
		}
	}

	bool getDisponibil() {
		return this->disponibil;
	}

	void setDisponibil(bool disponibil) {
		if (disponibil == true || disponibil == false) {
			this->disponibil = disponibil;
		}
	}

	// Constructorul de copiere

	Ospatar(const Ospatar& ospatar1) : idOspatar(nrTotalOspatari) {
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

	Ospatar() : Persoana(), idOspatar(nrTotalOspatari++) {
		this->experienta = 2;
		this->salariu = 3500;
		this->bacsis = 100;
		this->meseServite = 15;
		this->disponibil = true;
	}

	// Constructori cu parametrii

	Ospatar(const char* nume, int varsta) : Persoana(), idOspatar(nrTotalOspatari) {
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
	friend ofstream& operator<<(ofstream& ost, const Ospatar& o);
	friend ifstream& operator>>(ifstream& ist, Ospatar& o);

	void cresteVarsta() override {
		cout << "Varsta si experienta ospatarului " << nume << " au crescut!" << endl;
		this->varsta++;
		this->experienta++;
	}
};


class Picol :public Ospatar {
private:
	int aniUcenicie;
public:
	int getAniUcenicie() {
		return this->aniUcenicie;
	}

	void setAniUcenicie(int aniUcenicie) {
		if (this->aniUcenicie > 0) {
			this->aniUcenicie = aniUcenicie;
		}
	}

	Picol() : Ospatar() {
		this->nume = new char[strlen("Andrei") + 1];
		strcpy(this->nume, "Andrei");
		this->varsta = 25;
		this->experienta = 2;
		this->salariu = 3500;
		this->bacsis = 100;
		this->meseServite = 15;
		this->disponibil = true;
		this->aniUcenicie = 2;
	}

	Picol(int varsta, float bacsis) : Ospatar() {
		this->nume = new char[strlen("Andrei") + 1];
		strcpy(this->nume, "Andrei");
		this->varsta = varsta;
		this->experienta = 2;
		this->salariu = 3500;
		this->bacsis = bacsis;
		this->meseServite = 15;
		this->disponibil = true;
		this->aniUcenicie = 2;
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
			<< " si avand " << aniUcenicie << " ani de ucenicie"
			<< endl;
	}
};

class Debarasator :public Ospatar {
private:
	int maxFarfurii;
public:
	int getMaxFarfurii() {
		return this->maxFarfurii;
	}

	void setMaxFarfurii(int maxFarfurii) {
		if (this->maxFarfurii > 0) {
			this->maxFarfurii = maxFarfurii;
		}
	}

	Debarasator() : Ospatar() {
		this->nume = new char[strlen("Andrei") + 1];
		strcpy(this->nume, "Andrei");
		this->varsta = 25;
		this->experienta = 2;
		this->salariu = 3500;
		this->bacsis = 100;
		this->meseServite = 15;
		this->disponibil = true;
		this->maxFarfurii = 10;
	}

	Debarasator(int varsta, float bacsis) : Ospatar() {
		this->nume = new char[strlen("Andrei") + 1];
		strcpy(this->nume, "Andrei");
		this->varsta = varsta;
		this->experienta = 2;
		this->salariu = 3500;
		this->bacsis = bacsis;
		this->meseServite = 15;
		this->disponibil = true;
		this->maxFarfurii = 12;
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
			<< " si poate cara maxim " << maxFarfurii << " farfurii"
			<< endl;
	}
};

class Restaurant : public Firma {
protected:
	int nrMeniuri;
	Meniu* meniuri;
	vector <Ospatar> ospatari;
	int capacitate;

public:

	Meniu* getMeniuri() {
		return this->meniuri;
	}

	void setMeniuri(Meniu* meniuri, int nrMeniuri) {
		if (nrMeniuri > this->nrMeniuri) {
			delete[]this->meniuri;
			this->meniuri = new Meniu[nrMeniuri];
		}
		for (int i = 0; i < nrMeniuri; i++) {
			this->meniuri[i] = meniuri[i];

		}
	}

	int getNrMeniuri() {
		return this->nrMeniuri;
	}

	void setNrMeniuri(int nrMeniuri) {
		if (nrMeniuri > 0) {
			this->nrMeniuri = nrMeniuri;
		}
	}

	vector<Ospatar> getOspatari() {
		return this->ospatari;
	}

	void setOspatari(Ospatar* ospatari, int nrOspatari) {
		if (nrOspatari > 0) {
			this->ospatari.clear();
			for (int i = 0; i < nrOspatari; i++) {
				this->ospatari.push_back(ospatari[i]);
			}
		}
	}

	int getCapacitate() {
		return this->capacitate;
	}

	void setCapacitate(int capacitate) {
		if (capacitate > 0) {
			this->capacitate = capacitate;
		}
	}

	// Constructorul de copiere

	Restaurant(Restaurant& res1) {
		this->nrMeniuri = res1.nrMeniuri;
		this->meniuri = new Meniu[res1.nrMeniuri];
		this->ospatari = res1.ospatari;
		this->nume = res1.nume;
		this->cifraDeAfaceri = res1.cifraDeAfaceri;
		this->capacitate = res1.capacitate;
		this->patron = res1.patron;
	}

	// Constructorul fara parametri

	Restaurant() {
		this->nrMeniuri = 2;
		this->meniuri = new Meniu[nrMeniuri];
		for (int i = 0; i < nrMeniuri; i++) {
			this->meniuri[i] = Meniu();
		}

		for (int i = 0; i < 2; i++) {
			this->ospatari.push_back(Ospatar());
		}

		this->nume = "Taverna";
		this->cifraDeAfaceri = 1000000;
		this->capacitate = 100;
		this->patron = "Giovanni";
	}

	friend ostream& operator<<(ostream& ost, const Restaurant& res);
	friend istream& operator>>(istream& ist, Restaurant& res);
	friend ofstream& operator<<(ofstream& ost, const Restaurant& res);
	friend ifstream& operator>>(ifstream& ist, Restaurant& res);

	Restaurant operator++() {
		this->cifraDeAfaceri += 10000;
		this->capacitate += 10;
		return *this;
	}

	void cresteCifraDeAfaceri() override {
		cout << "Cifra de afaceri a crescut!" << endl;
		this->cifraDeAfaceri = this->cifraDeAfaceri + 50000;
	}
};

ostream& operator<<(ostream& ost, const Restaurant& res) {
	ost << "Restaurantul "
		<< res.nume << " al carui patron este "
		<< res.patron << " are o cifra de afaceri de "
		<< res.cifraDeAfaceri << "EURO, capacitatea de "
		<< res.capacitate << " locuri, iar vectorul de meniuri este: ";
	for (int i = 0; i < res.nrMeniuri; i++) {
		ost << res.meniuri[i];
		ost << "\n";
	}
	ost << " respectiv vectorul de ospatari: ";
	for (int i = 0; i < res.ospatari.size(); i++) {
		ost << res.ospatari[i];
		ost << "\n";
	}
	return ost;
}

istream& operator>>(istream& ist, Restaurant& res) {
	cout << "Nume restaurant: ";
	ist >> res.nume;
	cout << "Nume patron: ";
	ist >> res.patron;
	cout << "Cifra de afaceri: ";
	ist >> res.cifraDeAfaceri;
	cout << "Capacitate: ";
	ist >> res.capacitate;
	cout << "Meniuri: ";
	for (int i = 0; i < res.nrMeniuri; i++) {
		ist >> res.meniuri[i];
		cout << "\n";
	}
	cout << "Ospatari: ";
	for (int i = 0; i < res.ospatari.size(); i++) {
		ist >> res.ospatari[i];
		cout << "\n";
	}
	return ist;
}

ofstream& operator<<(ofstream& ost, const Restaurant& res) {
	ost << res.nume << " " << res.patron << " " << res.cifraDeAfaceri << " " << res.capacitate << endl;
	for (int i = 0; i < res.nrMeniuri; i++) {
		ost << res.meniuri[i];
	}
	for (int i = 0; i < res.ospatari.size(); i++) {
		ost << res.ospatari[i];
	}
	return ost;
}

ifstream& operator>>(ifstream& ist, Restaurant& res) {
	ist >> res.nume;
	ist >> res.patron;
	ist >> res.cifraDeAfaceri;
	ist >> res.capacitate;
	for (int i = 0; i < res.nrMeniuri; i++) {
		ist >> res.meniuri[i];
	}
	for (int i = 0; i < res.ospatari.size(); i++) {
		ist >> res.ospatari[i];
	}
	return ist;
}

ostream& operator<<(ostream& ost, const Ospatar& o) {
	ost << "Ospatarul cu numele "
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

ofstream& operator<<(ofstream& ost, const Ospatar& o) {
	ost << o.nume << " " << o.varsta << " " << o.experienta << " " << o.salariu << " " << o.bacsis << " " << o.meseServite << " " << o.disponibil;
	ost << endl;
	return ost;
}

ifstream& operator>>(ifstream& ist, Ospatar& o) {
	ist >> o.nume;
	ist >> o.varsta;
	ist >> o.experienta;
	ist >> o.salariu;
	ist >> o.bacsis;
	ist >> o.meseServite;
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

	/*Rezervare rez1;
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

	Restaurant restaurant1;
	Restaurant restaurant2;

	restaurant1.setCapacitate(500);
	cout << restaurant1.getCapacitate();

	cout << endl;

	restaurant1.setCifraDeAfaceri(1000000);
	cout << restaurant1.getCifraDeAfaceri();

	cout << endl;

	Meniu men[1];
	men[0] = Meniu();

	Ospatar osp[1];
	osp[0] = Ospatar();

	restaurant1.setMeniuri(men, 1);
	for (int i = 0; i < restaurant1.getNrMeniuri(); i++) {
		cout << restaurant1.getMeniuri()[i];
		cout << endl;
	}

	restaurant1.setNrMeniuri(2);
	cout << restaurant1.getNrMeniuri();
	cout << endl;

	restaurant1.setNume("Anonim");
	cout << restaurant1.getNume();
	cout << endl;

	restaurant1.setOspatari(osp, 1);
	cout << endl;

	restaurant1.setPatron("Pescobar");
	cout << restaurant1.getPatron();
	cout << endl;

	cout << restaurant1;
	cin >> restaurant2;

	++restaurant1;
	cout << restaurant1;

	Rezervare r5("0736945826", "17iunie");
	ifstream fisIn("rezervari.txt", ios::in);
	fisIn >> r5;

	ofstream fisOut("rezervariOut.txt", ios::out);
	fisOut << r5;
	fisIn.close();
	fisOut.close();

	Restaurant restaurant5;
	ifstream fisierIn("restaurante.txt", ios::in);
	fisierIn >> restaurant5;

	ofstream fisierOut("restauranteOut.txt", ios::out);
	fisierOut << restaurant5;
	fisierIn.close();
	fisierOut.close();

	Meniu meniu5;
	ifstream fIn("meniuri.dat", ios::in | ios::binary);
	fIn.read((char*)&meniu5, sizeof(Meniu));

	ofstream fOut("meniuriOut.dat", ios::out | ios::binary);
	fOut.write((char*)&meniu5, sizeof(Meniu));
	fIn.close();
	fOut.close();

	Ospatar ospatar5;
	ifstream fis_in("ospatari.dat", ios::in | ios::binary);
	fis_in.read((char*)&ospatar5, sizeof(Ospatar));

	ofstream fis_out("ospatariOut.dat", ios::out | ios::binary);
	fis_out.write((char*)&ospatar5, sizeof(Ospatar));
	fis_in.close();
	fis_out.close();*/

	/*Picol p1;
	Ospatar* p1p = &p1;

	p1p->afisareOspatar();
	p1.afisareOspatar();

	Debarasator d1;
	Ospatar* d1p = &d1;

	d1p->afisareOspatar();
	d1.afisareOspatar();*/

	Ospatar o20, o21, o22, o23, o24, o25, o26, o27, o28, o29;
	Persoana* persoane[10];
	persoane[0] = &o20;
	persoane[0]->cresteVarsta();

	persoane[1] = &o21;
	persoane[1]->cresteVarsta();

	persoane[2] = &o22;
	persoane[2]->cresteVarsta();

	persoane[3] = &o23;
	persoane[3]->cresteVarsta();

	persoane[4] = &o24;
	persoane[4]->cresteVarsta();

	persoane[5] = &o25;
	persoane[5]->cresteVarsta();

	persoane[6] = &o26;
	persoane[6]->cresteVarsta();

	persoane[7] = &o27;
	persoane[7]->cresteVarsta();

	persoane[8] = &o28;
	persoane[8]->cresteVarsta();

	persoane[9] = &o29;
	persoane[9]->cresteVarsta();

	return 0;
}