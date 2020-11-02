#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
using namespace std;

int gameon() { //Spelet i sig, slumpningnen h�nder h�r.
	int x = 0, y = 0, vf = 0;
	int game[3][3]{};
	cout << " ___________ " << endl; //Lite "cout" f�r att bygga ett fint rutn�t mot slutet.
	cout << "|";
	for (x = 0; x < 3; x++) {
		Sleep(1500);
		for (y = 0; y < 3; y++) {
			Sleep(1500);
			srand(time(0));

			game[x][y] = rand() % 3;

			if (game[x][y] == 0) { // X med boxv�ggarna
				cout << "_X_|";
			}
			if (game[x][y] == 1) { // Y med boxv�ggarna
				cout << "_Y_|";
			}
			if (game[x][y] == 2) { // Z med boxv�ggarna
				cout << "_Z_|";
			}
			if (x == 0 && y == 2) {
				cout << endl;
				cout << "|";
			}
			if (x == 1 && y == 2) { //De tre olika avsluten
				cout << endl;
				cout << "|";
			}
			if (x == 2 && y == 2) {
				cout << endl;
			}
		}
	}
	// Kontrollen av hur m�nga rader som ger vinst.
	if (game[0][0] == game[0][1] && game[0][0] == game[0][2]) {
		vf++;
	}
	if (game[1][0] == game[1][1] && game[1][0] == game[1][2]) {
		vf++;
	}
	if (game[2][0] == game[2][1] && game[2][0] == game[2][2]) {
		vf++;
	}
	if (game[0][0] == game[1][0] && game[0][0] == game[2][0]) {
		vf++;
	}
	if (game[0][1] == game[1][1] && game[0][1] == game[2][1]) {
		vf++;
	}
	if (game[0][2] == game[1][2] && game[0][2] == game[2][2]) {
		vf++;
	}
	if (game[0][0] == game[1][1] && game[0][0] == game[2][2]) {
		vf++;
	}
	if (game[0][2] == game[1][1] && game[0][2] == game[2][0]) {
		vf++;
	}
	//returen av antal vinstrader
	return vf;
}

void name() { //Bara en v�nlig h�lsning till spelaren
	string name;
	cout << "Vad heter du?" << endl;
	cin >> name;
	cout << "Hejsan " << name << "! L�t oss b�rja spelet." << endl;
}

int ins�ttning(int x, int y) { //funktion f�r att s�tta in pengar och sedan addera p� det p� ditt aktuella saldo
	int i = 0, nyin, tal1 = 100, tal2 = 300, tal3 = 500;
	cout << "Vill du s�tt in pengar? Ja[1] / Nej[2]" << endl;
	cin >> nyin;
	if (nyin == 1) { //Loop f�r att man bara kan s�tta in 100, 300 eller 500kr
		cout << "Hur mycket vill du s�tta in?" << endl;
		cin >> x;
		while (i != 1) {
			if ((x != tal1) && (x != tal2) && (x != tal3)) {
				cout << "Du kan bara s�tta in 100, 300 eller 500kr." << endl;
				cout << "Hur mycket vill du s�tta in?" << endl;
				cin >> x;
			}
			else {
				i = 1;
			}
		}
		cout << "Du har valt att s�tta in " << x << "kr." << endl;
		y = y + x; //Addering av ins�ttningen och gamla saldot
		return y;
	}
	else {
		return y;
	}
}

int satsning() { //Funktion f�r satsa pengar som returerar satsningen och h�ller kvar det inf�r Vinst/F�rlust ber�kningen
	int i = 0, s, satsa[6]{ 50, 100, 200, 300, 400, 500 };
	cout << "Hur mycket vill du satsa?" << endl;
	cin >> s;
	while (i != 1) {
		if ((s != satsa[0]) && (s != satsa[1]) && (s != satsa[2]) && (s != satsa[3]) && (s != satsa[4]) && (s != satsa[5])) {
			cout << "Du kan bara satsa 50, 100, 200, 300, 400 eller 500kr." << endl;
			cout << "Hur mycket vill du satsa?" << endl;
			cin >> s;
		}
		else {
			i = 1;
		}
	}
	cout << "Du har valt att satsa " << s << "kr." << endl;
	return s;
}

int main() {
	/*M�ste inkludera � � �*/
	setlocale(LC_ALL, "swedish");
	int age = 0, saldo = 0, spelaom = 1, vf = 0, satsa = 0, pms = 0; //T�nkte anv�nda ett Array, men crashade spelet tyv�rr
	cout << "V�lkommen till Zi'Bandit!" << endl;
	name(); //Tillkallar "Void Name"-funktionen
	/*M�ste ju enligt lag kontrollera spelarens �lder p� casinospel :P*/
	cout << "Man m�ste vara �ver 18 �r f�r att spela, hur gammal �r du?" << endl;
	cin >> age;
	if (age <= 17) {
		cout << "Du �r f�r ung f�r att spela detta spelet." << endl;
		return 0;
	}
	else {
		cout << "Let's Rock this place!" << endl;
	}
	/*Lite l�tt info om hur spelet funkar*/
	cout << "Lite information om hur spelet funkar." << endl;
	cout << "Du kan alltid avsluta spelet genom att trycka (ctrl + c)." << endl;
	cout << "Enarmad Bandit �r ett spel d�r man v�ljer att spela p� 1-8 rader." << endl;
	cout << "F�r att vinna m�ste man f� 3 tecken i rad, antingen lodr�tt, v�gr�tt eller p� diagonalen." << endl;
	cout << "  ___________  " << "  ___________  " << "  ___________" << endl;
	cout << " |_>_|___|___| " << " |___|___|___| " << " |___|___|_/_|" << endl;
	cout << " |_>_|___|___| " << " |___|___|___| " << " |___|_/_|___|" << endl;
	cout << " |_>_|___|___| " << " |_^_|_^_|_^_| " << " |_/_|___|___|" << endl;
	cout << "Sedan vinner man mer om man har gissat r�tt p� mer �n en rad." << endl;
	cout << "L�t oss b�rja med att s�tta in pengar att spela f�r." << endl;
	while (spelaom == 1) { //Spelets Main While-Loop s� att man kan spela mer �n en g�ng
		saldo = ins�ttning(0, saldo); //Tillkallar Ins�ttningensfunktionen
		cout << "Nu har du " << saldo << " att spela f�r." << endl;
		satsa = satsning(); //Satsnings funktionen
		vf = gameon(); //Main spel Funktionen returnerar "vf" som inneh�ller hur m�nga rader som var vinst
		if (vf == 1) { //Kontroll av hur stor vinsten blev med hj�lp av "vf"
			cout << "Du vann!" << endl;
			satsa = satsa * 2;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo �r just nu " << saldo << "kr." << endl;
		}
		else if (vf == 2) {
			cout << "Du vann!" << endl;
			satsa = satsa * 3;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo �r just nu " << saldo << "kr." << endl;
		}
		else if (vf == 3) {
			cout << "Du vann!" << endl;
			satsa = satsa * 4;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo �r just nu " << saldo << "kr." << endl;
		}
		else if (vf == 4) {
			cout << "Du vann!" << endl;
			satsa = satsa * 5;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo �r just nu " << saldo << "kr." << endl;
		}
		else if (vf == 5) {
			cout << "Du vann!" << endl;
			satsa = satsa * 7;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo �r just nu " << saldo << "kr." << endl;
		}
		else if (vf == 6) {
			cout << "Du vann!" << endl;
			satsa = satsa * 10;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo �r just nu " << saldo << "kr." << endl;
		}
		else if (vf == 7) {
			cout << "Du vann!" << endl;
			satsa = satsa * 10;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo �r just nu " << saldo << "kr." << endl;
		}
		else if (vf == 8) {
			cout << "Du vann!" << endl;
			satsa = satsa * 10;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo �r just nu " << saldo << "kr." << endl;
		}
		else {
			cout << "Du f�rlorade!" << endl;
			saldo = saldo - satsa;
			cout << "Ditt saldo �r just nu " << saldo << "kr." << endl;
		}
		cout << "Vill du forts�tta spela? Ja[1] / Nej[2]" << endl; //V�g val f�r om man vill spela igen eller inte
		cin >> pms;
		if (pms == 2) {
			cout << "Tack f�r att du spelade Zi'Bandit" << endl; //V�nligt avslut, med avslutsh�lsning.
			cout << "V�lkommen �ter!" << endl;
			spelaom = 0;
		}
		else {

		}
	}
	return 0; //The End :D
}