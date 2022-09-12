//Zachary Hart
//Isaiah Haliotis
//Austin Morgan

#define ROWS 16
#define COLS 57
void collide(int, int);
char beginKeyReading();
void clearScreen();
void printTower();
char wreckage;
void printArray(char lines[ROWS][COLS]);
int loop;
int spd;
int points;
int ID;
extern int c;
extern int pos;
extern int playerPosition;
/*char tower[ROWS][COLS]={
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

*/
