#include <stdio.h>
#include <stdlib.h>
#include "devoir.h"
#include <string.h>

void error()
{
	printf("error error");
	exit(1);
}
int try(FILE** A, char* C)
{
	*A=fopen(C, "r+");
	return(*A==NULL)? false : true;
}


int getlen(FILE* fd)
{
	int c, len=0;
	while((c = fgetc(fd)) != EOF){
		if (c == '\n')
			++len;
	}
	rewind(fd);
	return len;
}

int cgetlen(FILE* fichier)
{
	int c, len=0;
	while((c = fgetc(fichier)) != EOF){
			++len;
	}
	rewind(fichier);
	return len;
}

void tail(FILE* fd,int n)
{
	int c,len=0, a=0;
	len=getlen(fd);
	while((c = fgetc(fd)) != EOF){
		if (c == '\n')
			++a;
		if(a>=len-n)
			putchar(c);
	}
}

void ctail(FILE* fichier, int n)
{
	int c,len=0, a=0;
	len=cgetlen(fichier);
	while((c = fgetc(fichier)) != EOF){
		++a;
		if(a>=len-n)
			putchar(c);
	}
}

void just_tail(FILE* fichier, char** argv , int argc)
{
	for(int i=1 ; i<argc ; i++)
	{
		printf("==> %s <==\n" , argv[i]);
		if(try(&fichier,argv[i]))
			tail(fichier, 10);
		else
			printf("\n%s not found \n" , argv[i]);
	}
}
void finish(FILE* A)
{

	fclose(A);
	printf("\t\tfermeture reussi");
}

void option_courte(FILE* A, char** arg,int argc)
{
	switch (arg[1][1])
	{
		case 'n':
			if(strlen(arg[1])==2)
			{
				if(is_in(0,arg[2],"0123456789"))
				{
					for(int i=3 ; i<argc ; i++)
					{
						
						printf("%d" , argc);
						try(&A , arg[i]);
						if(!cis_in('q', arg[1]))
							printf("==> %s <==\n" , arg[i]);
						tail(A,atoi(arg[2]));
						fclose(A);				
					}
				}
			}
			
			else
			{
				
				for(int i=3 ; i<argc ; i++)
					{
						try(&A , arg[i]);
						if(argc=4)
						{
							if(cis_in('v' , arg[1]))
								printf("==> %s <==\n" , arg[i]);
							tail(A,atoi(arg[2]));
							fclose(A);
						}
						else
						{
							if(!cis_in('q', arg[1]))
								printf("==> %s <==\n" , arg[i]);
							tail(A,atoi(arg[2]));
							fclose(A);
						}	
				}
		}
			
			break;
		case'c':
		if(strlen(arg[1])==2)
			{
				if(is_in(0,arg[2],"0123456789"))
				{
					for(int i=3 ; i<argc ; i++)
					{
						try(&A , arg[i]);
						if(!cis_in('q', arg[1]))
							printf("==> %s <==" , arg[i]);
						ctail(A,atoi(arg[2]));
						fclose(A);
					}
				}
			}
			else
			{
				if(is_in(2,arg[1], "cvfqsz"))
				{
					
						printf("autre option detectee");
				}
			}
			break;
		case 'f':
			printf("option f choisis");
			break;
		case 'q':
			printf("option q choisis");
			break;
		case 's':
			printf("option s choisis");
			break;
		case 'v':
		
			break;
		case 'z':
			printf("option z choisis");
			break;
		default:
			printf("option non reconnu");
			break;
	}
	
}

void option_longue(FILE* A, char** arg)
{
	if(strcmp(arg[1], "--version")==0)
	{
		char a[]="version";
		try(&A, a);
		int c;
		while((c=fgetc(A))!=EOF)
			putchar(c);
	}
	else if(strcmp(arg[1], "--help")==0)
	{
		char a[]="help";
		try(&A, a);
		int c;
		while((c=fgetc(A))!=EOF)
			putchar(c);
	}
	
}

bool is_in(int a,char* A, char* B)
{
	
	int conf=0;
	for(int i=a ; i<strlen(A) ; i++)
	for(int j=0 ; j<strlen(B) ; j++)
		if(A[i]==B[j])
			conf++;
	//printf("%d" , conf);
	return (conf==strlen(A))?true : false;
}


bool cis_in(char A, char* B)
{	
	for(int j=0 ; j<strlen(B) ; j++)
		if(A==B[j])
			return true;
	return false;
}
