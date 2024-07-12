#ifndef __DEVOIR___
#define __DEVOIR
#include <stdio.h>
typedef enum bool{
	false,
	true
}bool;

void error();
int try(FILE** A, char* C);
int getlen(FILE* fichier);
int cgetlenc(FILE* fichier);
void tail(FILE* fichier, int n);
void ctail(FILE* fichier, int n);
void just_tail(FILE* fichier, char** argv , int argc);
bool is_in(int a,char* A, char* B);
bool cis_in(char A, char* B);
void finish(FILE* A);
void option_longue(FILE* A, char** arg);
void option_courte(FILE* A, char** arg,int argc);
#endif
