#include "game_of_life.h"
#include <ctime>
bool game_of_life::slucajna_vrijednost()
{
	
	if (((rand() % 100) + 1) <= 25) { return true; }
	return false;
}



void game_of_life::iscrtaj()
{
	
	if (_generacija[0][0] == 204) { //error
	
		srand(time(nullptr));
		for (int i = 0; i < REDAKA; i++)
		{
			for (int j = 0; j < STUPACA; j++)
			{
				if (slucajna_vrijednost()) {
					cout << "*";
					_generacija[i][j] = true;
				}
				else {
					cout << "-";
					_generacija[i][j] = false;
				}
			}
			cout << endl;

		}
	}
	else {

		for (int i = 0; i < REDAKA; i++)
		{
			for (int j = 0; j < STUPACA; j++)
			{
				if (_generacija[i][j]) cout << "*";
				else cout << "-";

			}
			cout << endl;

		}

	}
}


void game_of_life::sljedeca_generacija()
{

	
	
	for (int i = 0; i < REDAKA; i++)
	{ 
		


		for (int j = 0; j < STUPACA; j++)
		{




			int brojac = 0;
			if (_generacija[i - 1][j - 1]) {
				if (!((i - 1) < 0 || ((j - 1) < 0)))brojac++;

			}

			if (_generacija[i - 1][j]) {
				if (!((i - 1) < 0))brojac++;
			}

			if (_generacija[i - 1][j + 1]) {
				if (!((i - 1) < 0 || ((j + 1) > 39)))brojac++;
			}
			if (_generacija[i][j + 1]) {
				if (!((j + 1) > 39))brojac++;
			}

			if (_generacija[i][j - 1]) {
				if (!((j - 1) < 0))brojac++;
			}
			if (_generacija[i + 1][j - 1]) {
				if (!((i + 1) > 19 || ((j - 1) < 0)))brojac++;
			}

			if (_generacija[i + 1][j]) {
				if (!((i + 1) > 19))brojac++;
			}


			if (_generacija[i + 1][j + 1]) {
				if (!((i + 1) > 19 || ((j + 1) > 39)))brojac++;
			}

			//cout << brojac;


			if (_generacija[i][j]) {
				if (!(brojac == 2 || brojac == 3)) {
					_sljedeca_generacija[i][j] = false;
				}

			}
			else if (brojac == 3) {
				_sljedeca_generacija[i][j] = true;



			}
			
			if (!(brojac == 2 || brojac == 3)) {
				_sljedeca_generacija[i][j] = false;
			}


		}
			

		
		//cout << endl;


	}





	int cb = sizeof(bool) * 20 * 40;
	
	memcpy(_generacija, _sljedeca_generacija, cb);






}

