#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIFE 10

int strike = 0;
int ball = 0;

typedef struct tagAnswer{
        int a;
        int b;
        int c;
        int d;
}Answer;

void CheckMatch(Answer gA, Answer uA){
  if(gA.a == uA.a) strike++;  // Check match about gA.a
  if(gA.a == uA.b) ball++;
  if(gA.a == uA.c) ball++;
  if(gA.a == uA.d) ball++;
  
  if(gA.b == uA.a) ball++;    // Check match about gA.b
  if(gA.b == uA.b) strike++;
  if(gA.b == uA.c) ball++;
  if(gA.b == uA.d) ball++;
  
  if(gA.c == uA.a) ball++;    // Check match about gA.c
  if(gA.c == uA.b) ball++;
  if(gA.c == uA.c) strike++;
  if(gA.c == uA.d) ball++;
  
  if(gA.d == uA.a) ball++;    // Check match about gA.d
  if(gA.d == uA.b) ball++;
  if(gA.d == uA.c) ball++;
  if(gA.d == uA.d) strike++;
}

int main(){
    
  //// Setting ////
  int life;
  int life_count = LIFE;
  Answer gAnswer;       // Game's answer.
  Answer uAnswer;       // User's answer.
  
  srand(time(NULL));    // Construct randomize.
  
  do{
    gAnswer.a = rand() % 10;    // Construct random.
    gAnswer.b = rand() % 10;
    gAnswer.c = rand() % 10;
    gAnswer.d = rand() % 10;
  }while(gAnswer.a == gAnswer.b || gAnswer.a == gAnswer.c || gAnswer.a == gAnswer.d
          || gAnswer.b == gAnswer.c || gAnswer.b == gAnswer.d || gAnswer.c == gAnswer.d);  // To prevent duplication.
  
  // printf("Game answer: %d%d%d%d\n\n", gAnswer.a, gAnswer.b, gAnswer.c, gAnswer.d);    // To Check the answer
  
  //// Running ////
  pust("This game is simple Number_Baseball game."
  for(life = life_count; life > 0; life--){

    printf("Life %d::Input your Number: ", life);
    scanf("%1d%1d%1d%1d", &uAnswer.a, &uAnswer.b, &uAnswer.c, &uAnswer.d);  // Input user data.
    while(getchar() != '\n');    // Empty the buffer.
    
    if(uAnswer.a == uAnswer.b || uAnswer.a == uAnswer.c || uAnswer.a == uAnswer.d
          || uAnswer.b == uAnswer.c || uAnswer.b == uAnswer.d || uAnswer.c == uAnswer.d)  // To prevent duplication.
        puts("> Please do not duplicate..");
    else{
        CheckMatch(gAnswer, uAnswer);
        if(strike == 4){
             printf("> %d Strike, %d Ball!\n", strike, ball);
             puts("\n:::: You are Winner!!! ::::\n");
             system("PAUSE");
             return 0;
        }
    
        printf("> %d Strike, %d Ball!\n", strike, ball);
        strike = 0;
        ball = 0;
    }
    puts("");
  }
  puts("\n:::: You are Loser ::::");
  
  system("PAUSE");   
  return 0;
}
