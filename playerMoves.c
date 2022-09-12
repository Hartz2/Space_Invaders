//Zachary Hart
#include <stdio.h>
#include <unistd.h>
#include "functionList.h"

int ID=1;

void printMove(char c){        
   if (c=='s'||c=='w'||c=='f'){
   FILE * f1=fopen("moves.txt", "w");
   fprintf(f1, "%c%d", c, ID);
   ID+=1;
   fclose(f1);
   printf("In Printmove: %c%d\n", c, ID);
   }
}



int main(){
   char v; 
   //scanf("%c", &v);
   while (v!='o'){      
   scanf("%c", &v);
   printf("V= %c\n", v);   
   if (v=='o'){
   return 0;
   }
   printMove(v);
   }
   return 0;
}
