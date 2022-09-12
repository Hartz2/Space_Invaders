//Zachary Hart

#include <stdio.h>
#include "functionList.h"
int playerPosition;
char fireProj='t';

void main()
{
	char a;
	printf("\n//////////// Welcome to Space Defense ///////////// \n\n");
	printf("Would you like to turn on wreckage graphics? [y/n]   ");
	scanf("%c", &a);
	wreckage=a;
	printTower();	
}
