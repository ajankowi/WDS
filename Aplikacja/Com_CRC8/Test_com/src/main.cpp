#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <cctype>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <errno.h>
#include <cstring>
#include "transparam.hh"
#include "nadawanie.hh"
#include "odbieranie.hh"

#define ROZMIAR_LINII   100
#define SIG_1 4


using namespace std;


int main(){


	int a = 0;
	int b = 0;
	int sig1 = 0;


	cout << "Uruchomiono odbieranie" << endl;

	while(1){

		while(!a){
			a = Nadaj(b);
			b++;
		}
		a = 0;
		usleep(100000);

		Odbierz(sig1);

		cout << "Sig:  " << sig1 << endl;

		usleep(1000000);
		//usleep(2000000);
	}

	return 0;
}







