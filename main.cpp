#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char **charSquare(int n);  //alokuje obszar pamieci na tablice dwuwymiarowa
void drawCharSquare(char **square, int n); //wypisuje kwadrat na ekranie
void freeCharSquare(char **square, int n);  //zwalnia zaalokowana pamiec

void fErr1();  //gdy nie znaleziono argumentow programu
void fInfo(int n, int seed); //funkcja informacyjna

int main(int argc, char **argv)
{
	int n, seed;

	if (argc==1) {fErr1(); return 1;}

	if (argc==2) {n=atoi(argv[1]); seed=0;}

	if (argc>=3) {n=atoi(argv[1]); seed=atoi(argv[2]);}



	srand(seed);

	drawCharSquare(charSquare(n), n);
	fInfo(n, seed);
	return 0;
}

char **charSquare(int n)
{
	char **square;

	square=new char* [n];
	for(int a=0; a<n; a++) {square[a]=new char[n];}

	for(int i=0; i<n*n; i++) {square[i/n][i%n]='a'+rand()%('z'-'a'+1);}
	return square;
}

void drawCharSquare(char **square, int n)
{
	for(int i=0; i<n*n; i++) {(i%n)==(n-1)?printf("%c\n", square[i/n][i%n]):printf("%c ", square[i/n][i%n]);}
	freeCharSquare(square, n);
}

void freeCharSquare(char **square, int n)
{
	for (int i=0; i<n; i++) {delete[] square[i];}
	delete[] square;
}

void fErr1()
{
	printf("ERROR: Nie podano argumentow do programu...\n");
}

void fInfo(int n, int seed)
{
	printf("Ilosc znakow w boku kwadratu: %d\nZiarno generatora: %d\n", n, seed);
}

// Aleksy Bernat 226023