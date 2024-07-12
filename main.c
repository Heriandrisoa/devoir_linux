#include "devoir.h"
#include <stdio.h>

int main(int argc , char** arg)
{
	FILE *fd=NULL;
	int n=10;
	if(argc==2)
	{
		if(try(&fd, arg[1]))
			tail(fd,n);
		else
			error();
	}
	else
	{
		if(arg[1][0]=='-')
		{
			if(arg[1][1]=='-')
				option_longue(fd,arg);

			else
				option_courte(fd,arg,argc);
		}
		else
		{
			just_tail(fd, arg , argc );
		}
	}
			
	return 0;
}

