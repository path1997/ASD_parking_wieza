#include<iostream>

class Wieza {
public:
	int przypadki, **tablica, *temp,wymiar1,wymiar2,liczba,wsp1,wsp2,max,czas,licznik;

	Wieza() {
		przypadki = 0;
		wymiar1 = 0;
		wymiar2 = 0;
		liczba = 0;
		wsp1 = 0;
		wsp2 = 0;
		max = 0;
		czas = 0;
		licznik = 0;
	}

	void start() {
		std::cin >> przypadki;
		for (int i = 0; i < przypadki; i++) {
			std::cin >> wymiar1;
			std::cin >> wymiar2;
			czas = 0;
			tablica = new int *[wymiar1];
			for (int j = 0; j < wymiar1; j++) {
				tablica[j] = new int[wymiar2];
			}
			temp = new int[wymiar2];

			for (int j = 0; j < wymiar1; j++) {
				for (int k = 0; k < wymiar2; k++) {
					std::cin >> liczba;
					tablica[j][k] = liczba;
				}
			}

			for (int j = 0; j < znajdz_max(); j++) {
				wyszukaj(j + 1);
				if (wsp2 > (wymiar2 - wsp2)) {
					przesun_prawo(wsp1,(wymiar2 - wsp2));
					czas += ((wymiar2 - wsp2) * 5);
					czas += wsp1 * 2 * 10;
				}
				else {
					przesun_lewo(wsp1, (wsp2));
					czas += (wsp2 * 5);
					czas += wsp1 * 2 * 10;
				}
			}
			std::cout<< czas << std::endl;

			for (int i = 0; i < wymiar1; i++) {
				delete[] tablica[i];
			}
			delete[] tablica;
			delete[] temp;


		}
	}

	void wyszukaj(int liczba) {
		for (int q = 0; q < wymiar1; q++) {
			for (int w = 0; w < wymiar2; w++) {
				if (tablica[q][w] == liczba) {
					wsp1 = q;
					wsp2 = w;
				}
			}
		}
	}

	int znajdz_max() {
		for (int z = 0; z < wymiar1; z++) {
			for (int x = 0; x < wymiar2; x++) {
				if (tablica[z][x] > max) {
					max = tablica[z][x];
				}
			}
		}
		return max;
	}

	void przesun_lewo(int pietro,int ile) {
		licznik = ile;
		for (int r = 0; r < wymiar2; r++) {
			if (licznik == wymiar2) {
				licznik = 0;
				temp[r] = tablica[pietro][licznik];
				licznik++;
			}
			else {
				temp[r] = tablica[pietro][licznik];
				licznik++;
			}
		}
		wrzuc_do_tablica(pietro);
	}

	void przesun_prawo(int pietro,int ile) {
		licznik = wymiar2 - ile;
		for (int r = 0; r < wymiar2; r++) {
			if (licznik == wymiar2) {
				licznik = 0;
				temp[r] = tablica[pietro][licznik];
				licznik++;
			}
			else {
				temp[r] = tablica[pietro][licznik];
				licznik++;
			}
		}
		wrzuc_do_tablica(pietro);
	}

	void wrzuc_do_tablica(int pietro) {
		for (int e = 0; e < wymiar2; e++) {
			tablica[pietro][e] = temp[e];
		}
	}
};

int main() {
	Wieza w;
	w.start();

}