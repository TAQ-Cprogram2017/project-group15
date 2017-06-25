#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
typedef struct element
{ 
	int order;
	char symbol[2];
	double AR;
	char structure[20]; 
}ele; 

void gotoxy(int x, int y);
void show1(ele* a,ele* b); 
void eledetails(int x,int y,ele* a,ele* b);
void details(int x,int y,ele*a,ele* b);
void move(int x,int y,ele* a,ele*b);
void show2(ele* a,ele*b,int x,int y);

