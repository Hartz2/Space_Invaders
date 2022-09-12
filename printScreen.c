//Zachary Hart
//Isaiah Haliotis
//Austin Morgan

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "functionList.h"
//int position=3;
int playerPosition=8;
int projectileY=8;
int projectileX=COLS-5;
int spd=200000;
int points=0;
char fire='t';
char chart[5];
char str[5];
int bk=0;


void print_array(char lines[ROWS][COLS]){
srand(time(NULL));
int x;
 for (x=0; x< ROWS; x++){
    printf("%s\n", lines[x]);
 }
}

int b=0;
int findPlayerPos()
{   
   int a;
   char move;
   FILE * f1=fopen("moves.txt", "r");
   fscanf(f1, "%c%d", &move, &a);
   if (b!=a)
   {
	if ((move=='w')&&(playerPosition>0))
	{
		playerPosition=playerPosition-1;
	}
	else if ((move=='s')&&(playerPosition<ROWS)){
		playerPosition=playerPosition+1;
	}
        else if (move=='f')
	{
		fire='f';		
		projectileY=playerPosition;
		projectileX=52;
	}
	b=a;
   }
   fclose(f1);
   return playerPosition;
}

void clearScreen(){
//    sleep(3);
    if ((points>=2)&&(points<4)){
	spd=100000;
    }
    if ((points>=4)&&(points<6)){
	spd=75000;
    }
    if ((points>=6)&&(points<8)){
	spd=50000;
    }        
    if ((points>=8)&&(points<15)){
	spd=40000;
    }
    if ((points==15)){	
	bk=1;
    }
    usleep(1*spd);
    printf("\e[2J\e[H");
}

void printTower(){
    chart[1]='t';
    fire='t';
    srand(time(NULL));
    int position=rand()%10+2;
    int loop;
    projectileX=COLS-5;
    int shooting;
    char tower[ROWS][COLS]={
     "          ____________________________________________ ",
     "                                                     | ",
     "                                                     | ",
     "                                                     | ",
     "                                                     | ",
     "                                                     | ",
     "                                                     | ",
     "                                                     | ",
     "                                                     | ",
     "                                                     | ",
     "                                                     | ",
     "                                                     | ",
     "                                                     | ",
     "                                                     | ",
     "          ___________________________________________| "};
    
    int enemyX;    
/*    clearScreen();        
    tower[playerPosition][COLS-5]='@';
    print_array(tower); */
    char read;
    
    for(enemyX=1; enemyX<(COLS-2); enemyX+=1){		
    if (bk==0){
	if (enemyX==56){
	   bk=1;	   
 	   break;	   
	}	
	if (bk==1){
	   break;
	}
        clearScreen();		
	playerPosition=findPlayerPos();        
	tower[playerPosition][COLS-5]='@';		
        tower[position][enemyX]='*';	        
	if (fire=='f'){
	   shooting=1;
	}
	if ((fire=='f')&&(shooting==1)){           	   
	   tower[projectileY][projectileX]=':';	   	   
	}
        print_array(tower);
///////////////////[NEXT ITERATION]//////////////////////		
	if ((fire=='f')&&(shooting==1)){
	tower[projectileY][projectileX]=' ';	
	}
	tower[playerPosition][COLS-5]=' ';
        tower[position][enemyX]=' ';	
	if ((fire=='f')&&(shooting==1)){
	   projectileX=projectileX-1;
	}
	shooting=0;
	if (((projectileX==enemyX)||(projectileX==enemyX-1))&&(projectileY==position)){	   
	   points+=1;
	   sprintf(str, "%d", ID+1);
	   fire=strcpy(str, chart);
	   projectileX=52;
	   if (bk==1){
		break;
	   }
	   if (wreckage=='y'){
	      tower[position-1][enemyX]='`';
	      tower[position+1][enemyX]='.';
	   }
	   enemyX=1;
	   position=rand()%10+2;
	}	
    }
    }
    
    if (bk==1){
	printf("\033[0;32m");
	printf("You Win!\n");
	printf("\033[0;37m");
	printf("Enemy ships destroyed: %d\n", points);
    } else{
	printf("\033[0;31m");
	printf("You Failed!\n");
	printf("\033[0;37m");
	printf("Enemy ships destroyed: %d\n", points);
    } 
        
    
    for(loop=0; loop<15; loop++){
        printf("%s\n", tower[loop]);
    
    }
    fire='t';
     printf("\n");     
}
