#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIFECOUNT 10
#define LEVEL 3    // 3 ~ 5

int ball = 0;
int strike = 0;

int CheckDuplicate(int *Answer){
    int i, j;
    for (i = 0; i < LEVEL; i++)
        for(j = i + 1; j < LEVEL; j++)
              if(Answer[i] == Answer[j]) return 1;
              
    return 0;
}

void ConstructGameAnswer(int *gAnswer){
    int i;
    srand((unsigned)time(NULL));    // Construct randomize.
    do{
        for (i = 0; i < LEVEL; i++) gAnswer[i] = rand() % 10;    // Construct random.
    }while(CheckDuplicate(gAnswer));  // To prevent duplication.
}

int CheckMatch(int *gAnswer, int *uAnswer){
     int i, j;
     for (i = 0; i < 4; i++){
         for (j = 0; j < 4; j++){
             if( i == j ){
                 if (gAnswer[i] == uAnswer[j]) strike++;
             }else{
                 if (gAnswer[i] == uAnswer[j]) ball++;
             }
         }
     }
     if (strike == 4) return 1;
     
     return 0;
}

void SetUsersAnswer(int *uAnswer,int life){
    printf("\nLife %d::Input your Number: ", life);
    switch(LEVEL){
        case 3:
             scanf("%1d%1d%1d", &uAnswer[0], &uAnswer[1], &uAnswer[2]);
             break;
        case 4:
             scanf("%1d%1d%1d%1d", &uAnswer[0], &uAnswer[1], &uAnswer[2], &uAnswer[3]);
             break;
        case 5:
             scanf("%1d%1d%1d%1d%1d", &uAnswer[0], &uAnswer[1], &uAnswer[2], &uAnswer[3], &uAnswer[4]);
             break;
    }
    while(getchar() != '\n');    // Empty the buffer.

}

int main(){
    
    //// Setting ////
    if(LEVEL < 3 || LEVEL > 5){
        puts("\nFatal Error:: Must be adjust LEVEL value to 3 ~ 5.\n");
        system("PAUSE");
        return 0;
    }
    int life;
    int gAnswer[LEVEL];
    int uAnswer[LEVEL];
    ConstructGameAnswer(gAnswer);
    
    // for(life = 0; life < LEVEL; life++) printf("%d",gAnswer[life]); puts("");     // To confirm game's answer.
    
    //// Running ////
    puts("Game Start!!");
    
    for(life = LIFECOUNT; life > 0; life--){
        SetUsersAnswer(uAnswer, life);
        if (CheckDuplicate(uAnswer)){
            puts("> Please do not duplicate..");
        }else{
            if(CheckMatch(gAnswer, uAnswer)){
                printf("> %d Strike, %d Ball!\n", strike, ball);
                puts("\n:::: You are Winner!!! ::::\n");
                system("PAUSE");
                return 0;
            }
    
            printf("> %d Strike, %d Ball!\n", strike, ball);
            strike = 0;
            ball = 0;
    
            puts("");
        }
    }
    puts("\n:::: You are Loser ::::");
  
    system("PAUSE");   
    return 0;
}
