#ifndef NADAWANIE_HH
#define NADAWANIE_HH


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <cstdlib>


bool RS232_Nadaj( int DeskPortu, const char*  wNapis);

int Nadaj(const int sig);


#endif
