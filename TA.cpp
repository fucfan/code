#include <bits/stdc++.h>
// #include <fstream>
// #include <string>
#include <io.h>
#include <fcntl.h>
// #include <stdio.h>
// #include <codecvt>
// #include <locale>
#pragma warning (disable:4996)
using namespace std;

int main() {
	FILE* fd;
	fd = fopen("VN.txt", "a");
	int ngu, dumb;
	ngu = _setmode(_fileno(stdin), _O_U8TEXT);
	dumb =_setmode(_fileno(fd), _O_U8TEXT);
	locale loc(locale(), new codecvt_utf8<wchar_t>);
	wifstream out(L"VN.txt");
	fstream ENi("EN.txt", ios::in);
	fstream ENo("EN.txt", ios::app);
	fstream ENi2("EN2.txt", ios::in);
	fstream ENo2("EN2.txt", ios::app);
	fstream so("Num.txt", ios::in);
	int num;
	so >> num;
	// cout << num << '\n';
	int quit = 1;
	char EN[100];
	wchar_t VN[100];
	while (quit != 5) {
		cout << "Pick a number:" << endl;
		cout << "1. Add a word" << endl;
		cout << "2. Translate a word using data from this program" << endl;
		cout << "3. Add the missing meaning for a word" << endl;
		cout << "4. Test your memory with random words from this dictionary" << endl;
		cout << "5. Exit" << endl;
		cin >> quit;
		// cout << quit << '\n';
		// break;
		switch (quit) {
		case 1: {
			cout << "Please type the word you want to add:" << endl;
			cin.getline(EN, 100);
			num++;
			cout << "Please type its meaning, if you have no idea, please type 'idk'" << endl;
			wcin.getline(VN, 100);
			if (VN != L"idk") {
				ENo << EN << endl;
				fprintf(fd, "%ws \n", VN);
			}
			else {
				ENo2 << EN << endl;
			}
			ENi.seekp(ios::beg);
			ENi2.seekp(ios::beg);
			ENo.seekp(ios::beg);
			ENo2.seekp(ios::beg);
		}
		case 2: {
			cout << "What word would you like to translate?" << endl;
			cin.getline(EN, 100);
			string EN2;
			wstring VN2;
			int check = 0;
			while (!ENi.eof()) {
				ENi >> EN2;
				out.imbue(loc);	//đọc TV
				getline(out, VN2);
				if (EN2 == EN) {
					check = 1;
					break;
				}
			}
			if (check == 1)
				wcout << "According to this dictionary, the meaning of this word is: " << VN2 << endl;
			if (check == 0) {
				int mode;
				cout << "This word haven't been added to your dictionary yet" << endl;
				cout << "Add it now?" << endl;
				cout << "1. Yes" << endl << "2. No" << endl;
				cin >> mode;
				switch (mode) {
					case 1: {
						ENo << EN;
						cout << "Please type its meaning, if you have no idea, please type 'idk'" << endl;
						wcin.getline(VN, 100);
						if (VN != L"idk") {
							ENo << EN << endl;
							fprintf(fd, "%ws \n", VN);
						}
						else {
							ENo2 << EN << endl;
						}
					}
					case 2: {
						break;
					}
				}
			}
			ENi.seekp(ios::beg);
			ENi2.seekp(ios::beg);
			ENo.seekp(ios::beg);
			ENo2.seekp(ios::beg);
		}
		case 3: {
			cout << "Preparing..." << endl << "Please wait..." << endl;
			string EN2;
			wstring VN2;
			int check = 0;
			int dem = 0;
			while (!ENi2.eof()) {
				ENi2 >> EN2;
				dem++;
			}
			if (dem == 0) {
				cout << "There's no words without meanings in your dictionary" << endl;
				break;
			}
			string** idk = new string * [dem];
			for (int i = 0; i < dem; i++) {
				idk[i] = new string;
			}
			if (dem !=0) {
				ENi2.seekp(ios::beg);
				dem = 0;
				while (!ENi2.eof()) {
					ENi2 >> idk[dem][0];
					dem++;
				}
			}
			cout << "Please add the meaning of these below words, if you still have no idea, please type 'idk'" << endl;
			for (int i = 0; i < dem; i++) {
				cout << idk[i][0];
				wcin.getline(VN, 100);
				if (VN != L"idk") {
					fprintf(fd, "%ws", VN);
					ENo << idk[i][0];
					delete idk[i];
				}
			}
			fstream ENo3("EN2.txt", ios::out);
			for (int i = 0; i < dem; i++) {
				ENo3 << idk[i][0];
			}
			ENi.seekp(ios::beg);
			ENi2.seekp(ios::beg);
			ENo.seekp(ios::beg);
			ENo2.seekp(ios::beg);
		}
		case 4: {

		}
		default: {
			break;
		}
		}
	}
	return 0;
}