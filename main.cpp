#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);  //alokuje obszar pamieci na tablice dwuwymiarowa
void drawCharSquare(char **square, int n); //wypisuje kwadrat na ekranie
void freeCharSquare(char **square);  //zwalnia zaalokowana pamiec

void fErr1();  //gdy nie znaleziono argumentow programu

int main(int argc, char **argv)
{
	int n, seed;

	if (argc==1) fErr1();

	if (argc==2) {n=atoi(argv[1]);}

	drawCharSquare(charSquare(n), n);	
}

char **charSquare(int n)
{
	char **square;
	int i, j;  //na razie do petli

	square=new char* [n];
	**square='a';	
//	for (i=0; i<n; i++) {for (j=0; j<n; j++) square[j][i]='a';};
	return square;
}

void drawCharSquare(char **square, int n)
{
freeCharSquare(square);
}

void freeCharSquare(char **square)
{
	delete[] square;
}

void fErr1()
{
	printf("ERROR: Nie podano argumentow do programu...\n");
}