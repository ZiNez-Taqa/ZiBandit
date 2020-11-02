#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
using namespace std;

int gameon() { //Spelet i sig, slumpningnen händer här.
	int x = 0, y = 0, vf = 0;
	int game[3][3]{};
	cout << " ___________ " << endl; //Lite "cout" för att bygga ett fint rutnät mot slutet.
	cout << "|";
	for (x = 0; x < 3; x++) {
		Sleep(1500);
		for (y = 0; y < 3; y++) {
			Sleep(1500);
			srand(time(0));

			game[x][y] = rand() % 3;

			if (game[x][y] == 0) { // X med boxväggarna
				cout << "_X_|";
			}
			if (game[x][y] == 1) { // Y med boxväggarna
				cout << "_Y_|";
			}
			if (game[x][y] == 2) { // Z med boxväggarna
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
	// Kontrollen av hur många rader som ger vinst.
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

void name() { //Bara en vänlig hälsning till spelaren
	string name;
	cout << "Vad heter du?" << endl;
	cin >> name;
	cout << "Hejsan " << name << "! Låt oss börja spelet." << endl;
}

int insättning(int x, int y) { //funktion för att sätta in pengar och sedan addera på det på ditt aktuella saldo
	int i = 0, nyin, tal1 = 100, tal2 = 300, tal3 = 500;
	cout << "Vill du sätt in pengar? Ja[1] / Nej[2]" << endl;
	cin >> nyin;
	if (nyin == 1) { //Loop för att man bara kan sätta in 100, 300 eller 500kr
		cout << "Hur mycket vill du sätta in?" << endl;
		cin >> x;
		while (i != 1) {
			if ((x != tal1) && (x != tal2) && (x != tal3)) {
				cout << "Du kan bara sätta in 100, 300 eller 500kr." << endl;
				cout << "Hur mycket vill du sätta in?" << endl;
				cin >> x;
			}
			else {
				i = 1;
			}
		}
		cout << "Du har valt att sätta in " << x << "kr." << endl;
		y = y + x; //Addering av insättningen och gamla saldot
		return y;
	}
	else {
		return y;
	}
}

int satsning() { //Funktion för satsa pengar som returerar satsningen och håller kvar det inför Vinst/Förlust beräkningen
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
	/*Måste inkludera Å Ä Ö*/
	setlocale(LC_ALL, "swedish");
	int age = 0, saldo = 0, spelaom = 1, vf = 0, satsa = 0, pms = 0; //Tänkte använda ett Array, men crashade spelet tyvärr
	cout << "Välkommen till Zi'Bandit!" << endl;
	name(); //Tillkallar "Void Name"-funktionen
	/*Måste ju enligt lag kontrollera spelarens ålder på casinospel :P*/
	cout << "Man måste vara över 18 år för att spela, hur gammal är du?" << endl;
	cin >> age;
	if (age <= 17) {
		cout << "Du är för ung för att spela detta spelet." << endl;
		return 0;
	}
	else {
		cout << "Let's Rock this place!" << endl;
	}
	/*Lite lätt info om hur spelet funkar*/
	cout << "Lite information om hur spelet funkar." << endl;
	cout << "Du kan alltid avsluta spelet genom att trycka (ctrl + c)." << endl;
	cout << "Enarmad Bandit är ett spel där man väljer att spela på 1-8 rader." << endl;
	cout << "För att vinna måste man få 3 tecken i rad, antingen lodrätt, vågrätt eller på diagonalen." << endl;
	cout << "  ___________  " << "  ___________  " << "  ___________" << endl;
	cout << " |_>_|___|___| " << " |___|___|___| " << " |___|___|_/_|" << endl;
	cout << " |_>_|___|___| " << " |___|___|___| " << " |___|_/_|___|" << endl;
	cout << " |_>_|___|___| " << " |_^_|_^_|_^_| " << " |_/_|___|___|" << endl;
	cout << "Sedan vinner man mer om man har gissat rätt på mer än en rad." << endl;
	cout << "Låt oss börja med att sätta in pengar att spela för." << endl;
	while (spelaom == 1) { //Spelets Main While-Loop så att man kan spela mer än en gång
		saldo = insättning(0, saldo); //Tillkallar Insättningensfunktionen
		cout << "Nu har du " << saldo << " att spela för." << endl;
		satsa = satsning(); //Satsnings funktionen
		vf = gameon(); //Main spel Funktionen returnerar "vf" som innehåller hur många rader som var vinst
		if (vf == 1) { //Kontroll av hur stor vinsten blev med hjälp av "vf"
			cout << "Du vann!" << endl;
			satsa = satsa * 2;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo är just nu " << saldo << "kr." << endl;
		}
		else if (vf == 2) {
			cout << "Du vann!" << endl;
			satsa = satsa * 3;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo är just nu " << saldo << "kr." << endl;
		}
		else if (vf == 3) {
			cout << "Du vann!" << endl;
			satsa = satsa * 4;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo är just nu " << saldo << "kr." << endl;
		}
		else if (vf == 4) {
			cout << "Du vann!" << endl;
			satsa = satsa * 5;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo är just nu " << saldo << "kr." << endl;
		}
		else if (vf == 5) {
			cout << "Du vann!" << endl;
			satsa = satsa * 7;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo är just nu " << saldo << "kr." << endl;
		}
		else if (vf == 6) {
			cout << "Du vann!" << endl;
			satsa = satsa * 10;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo är just nu " << saldo << "kr." << endl;
		}
		else if (vf == 7) {
			cout << "Du vann!" << endl;
			satsa = satsa * 10;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo är just nu " << saldo << "kr." << endl;
		}
		else if (vf == 8) {
			cout << "Du vann!" << endl;
			satsa = satsa * 10;
			cout << "Din vinst blev " << satsa << "kr!" << endl;
			saldo = saldo + satsa;
			cout << "Ditt saldo är just nu " << saldo << "kr." << endl;
		}
		else {
			cout << "Du förlorade!" << endl;
			saldo = saldo - satsa;
			cout << "Ditt saldo är just nu " << saldo << "kr." << endl;
		}
		cout << "Vill du fortsätta spela? Ja[1] / Nej[2]" << endl; //Väg val för om man vill spela igen eller inte
		cin >> pms;
		if (pms == 2) {
			cout << "Tack för att du spelade Zi'Bandit" << endl; //Vänligt avslut, med avslutshälsning.
			cout << "Välkommen åter!" << endl;
			spelaom = 0;
		}
		else {

		}
	}
	return 0; //The End :D
}