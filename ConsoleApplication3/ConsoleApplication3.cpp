#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string Crta = "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n";
string ArapskiRimski(int x) {
	switch (x)
	{
	case 1: 
		return "I";
		break;
	case 5:
		return "V";
		break;
	case 10:
		return "X";
		break;
	case 50:
		return "L";
		break;
	case 100:
		return "C";
		break;
	case 500:
		return "D";
		break;
	case 1000:
		return "M";
		break;
	case 5000:
		return "_V";
		break;
	case 10000:
		return "_X";
		break;
	case 50000:
		return "_L";
		break;
	case 100000:
		return "_C";
		break;
	case 500000:
		return "_D";
		break;
	case 1000000:
		return "_M";
		break;
	default:
		return "Greska";
		break;
	}
}
void ProvjeraIntUnos(int& a) {
	if (!cin >> a) {
		cout << "Greska tokom unosa!!!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Ponovi unos" << endl;
		cin >> a;
		system("cls");
		if (!cin >> a)
			ProvjeraIntUnos(a);
	}
}
bool ProvjeraUslovaUnosa(int a, int b  = 1) {
	if (((a <= 0) || (a > 3999)) && (b == 1)) {
		if (a <= 0)
			cout << "Uneseni broj mora biti veci ili jednak 1" << endl;
		else
			cout << "Uneseni broj mora biti manji od 3999" << endl;
		return true;
	}
	else if (((a <= 0) || (a > 3999999)) && (b == 2)) {
		if (a <= 0)
			cout << "Uneseni broj mora biti veci ili jednak 1" << endl;
		else
			cout << "Uneseni broj mora biti manji od 3999999" << endl;
		return true;
	}
	return false;
}
int ValidacijaUnosa(int x, int y = 1) {
	if (y == 1) {
		if (ProvjeraUslovaUnosa(x)) {
			while ((x <= 0) || (x > 3999)) {
				cout << "Ponovite unos !!!" << endl;
				cin >> x;
				ProvjeraIntUnos(x);
				cout << endl;
				ProvjeraUslovaUnosa(x);
			}
		}
	}
	else {
		if (ProvjeraUslovaUnosa(x, 2)) {
			while ((x <= 0) || (x > 3999999)) {
				cout << "Ponovite unos !!!" << endl;
				cin >> x;
				ProvjeraIntUnos(x);
				cout << endl;
				ProvjeraUslovaUnosa(x, 2);
			}
		}
	}
	return x;
}
string Konv(int Broj) {
	int* NizBrojeva;
	int NekiBroj = Broj;
	int ctr = 0;
	while (NekiBroj != 0) {
		NekiBroj % 10;
		NekiBroj /= 10;
		ctr++;
	}
	NizBrojeva = new int[ctr];
	NekiBroj = Broj;
	int ctr2 = 0;
	while (NekiBroj != 0) {
		NizBrojeva[ctr2] = NekiBroj % 10;
		NekiBroj /= 10;
		ctr2++;
	}
	int* ObrnutiNiz = new int[ctr];
	int TempCtr = ctr - 1;
	for (int i = 0; i < ctr; i++) {
		ObrnutiNiz[i] = NizBrojeva[TempCtr];
		TempCtr--;
	}
	delete[] NizBrojeva;
	string Konvertovano = "";
	ctr2 -= 1;
	for (int i = 0; i < ctr; i++) {
		if ((ObrnutiNiz[i] == 1))
			Konvertovano += ArapskiRimski(pow(10, ctr2));
		else if ((ObrnutiNiz[i] == 5)) {
			if (ctr2 == 3)
				Konvertovano += ArapskiRimski(5 * (pow(10, ctr2 - 1)));
			Konvertovano += ArapskiRimski(5 * (pow(10, ctr2)));
		}
		else if ((ObrnutiNiz[i] == 4)) {
			Konvertovano += ArapskiRimski(pow(10, ctr2));
			Konvertovano += ArapskiRimski(5 * pow(10, ctr2));
		}
		else if ((ObrnutiNiz[i] == 9)) {
			Konvertovano += ArapskiRimski(pow(10, ctr2));
			Konvertovano += ArapskiRimski(pow(10, ctr2 + 1));
		}
		else {
			if ((ObrnutiNiz[i] < 4)) {
				int temp = ObrnutiNiz[i];
				while (temp > 0) {
					Konvertovano += ArapskiRimski(pow(10, ctr2));
					temp--;
				}
			}
			else {
				int temp = ObrnutiNiz[i] - 5;
				Konvertovano += ArapskiRimski(5 * pow(10, ctr2));
				while (temp > 0) {
					Konvertovano += ArapskiRimski(pow(10, ctr2));
					temp--;
				}
			}
		}
		ctr2--;
	}
	delete[] ObrnutiNiz;
	return Konvertovano;
}
void KonverzijaAraRim(int x = 1) {
	int UneseniBroj;
	if (x == 1) {
		cout << "Unesi neki broj 1 - 3999" << endl;
		cin >> UneseniBroj;
		ProvjeraIntUnos(UneseniBroj);
		cout << endl;
		UneseniBroj = ValidacijaUnosa(UneseniBroj);
		cout << Konv(UneseniBroj) << endl;
	}
	else {
		cout << "Unesi neki broj 1 - 3999999" << endl;
		cin >> UneseniBroj;
		ProvjeraIntUnos(UneseniBroj);
		cout << endl;
		UneseniBroj = ValidacijaUnosa(UneseniBroj, 2);
		cout << Konv(UneseniBroj) << endl;
	}
}
void UnosKorekcijaStinga(string& a) {
	a.erase(remove(a.begin(), a.end(), ' '), a.end());
	for_each(a.begin(), a.end(), [](char& c) {
		c = ::toupper(c);
		});
	cout << "Unos gotov" << endl;
}
bool ProvjeraUnosaSlova(char a) {
	switch (a)
	{
	case 'I':
	case 'V':
	case 'X':
	case 'L':
	case 'C':
	case 'D':
	case 'M':
	case '_V':
	case '_X':
	case '_L':
	case '_C':
	case '_D':
	case '_M':
		return true;
		break;
	default:
		return false;
		break;
	}
}
int RimskiArapski(char c) {
	switch (c) {
	case 'I':
		return 1;
		break;
	case 'V':
		return 5;
		break;
	case 'X':
		return 10;
		break;
	case 'L':
		return 50;
		break;
	case 'C':
		return 100;
		break;
	case 'D':
		return 500;
		break;
	case 'M':
		return 1000;
		break;
	case '_V':
		return 5000;
		break;
	case '_X':
		return 10000;
		break;
	case '_L':
		return 50000;
		break;
	case '_C':
		return 100000;
		break;
	case '_D':
		return 500000;
		break;
	case '_M':
		return 1000000;
		break;
	default: 
		return 0;
		break;
	}
}
void KonverzijaRimAra() {
	string RimString = ""; int ctrIsti = 0;
	cout << "Unesi rimski broj" << endl;
	getline(cin, RimString);
	UnosKorekcijaStinga(RimString);
	bool CtrGreska = true;
	for (int i = 0; i < RimString.length(); i++) {
		if (!ProvjeraUnosaSlova(RimString[i])) {
			CtrGreska = false;
			break;
		}
	}
	if (CtrGreska) {
		int AraBroj = 0;
		for (int i = 0; i < RimString.length(); i++) {
			int prvi = RimskiArapski(RimString[i]), drugi = RimskiArapski(RimString[i + 1]);
			if (drugi > prvi) {
				AraBroj += (drugi - prvi);
				i++;
			}
			else {
				AraBroj += prvi;
				if (prvi == drugi)
					ctrIsti++;
			}
		}
		if (ctrIsti > 2) {
			cout << "UNESENI BROJ NE POSTOJI !!!" << endl;
			return;
		}
		cout << "ISPIS KONVERTOVANOG BROJA " << AraBroj << endl;
	}
}
void Menu() {
	int Izbor = 4;
	while (Izbor != 0) {
		cout << Crta;
		cout << "\t(1) Konverzija Arapski - Rimski u opsegu 1 - 3999 " << endl;
		cout << "\t(2) Konverzija Arapski - Rimski u opsegu 1 - 3999999 " << endl;
		cout << "\t(3) Konverzija Rimski - Arapski u opsegu 1 - 3999999 " << endl;
		cout << "\t(0) IZLAZ" << endl;
		cout << Crta;
		cin >> Izbor;
		ProvjeraIntUnos(Izbor);
		if (Izbor == 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			KonverzijaAraRim();
			system("pause");
			system("cls");
		}
		else if (Izbor == 2) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			KonverzijaAraRim(2);
			system("pause");
			system("cls");
		}
		if (Izbor == 3) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			KonverzijaRimAra();
			system("pause");
			system("cls");
		}
		else if (Izbor > 3) {
			system("cls");
			cout << "Pogresan izbor !!!" << endl;
			system("pause");
			system("cls");
		}
	}
}
int main(){
	Menu();
}

 