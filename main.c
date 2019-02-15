#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIFECOUNT 10

int ball = 0;
int strike = 0;

int CheckDuplicate(int *Answer, int LEVEL){
    int i, j;
    for (i = 0; i < LEVEL; i++)
        for(j = i + 1; j < LEVEL; j++)
              if(Answer[i] == Answer[j]) return 1;
    return 0;
}

void ConstructGameAnswer(int *gAnswer, int LEVEL){
    int i;
    srand((unsigned)time(NULL));    // Construct randomize.
    do{ for (i = 0; i < LEVEL; i++) gAnswer[i] = rand() % 10;    // Construct random.
    }while(CheckDuplicate(gAnswer, LEVEL));  // To prevent duplication.
}

int CheckMatch(int *gAnswer, int *uAnswer, int LEVEL){
     int i, j;
     for (i = 0; i < LEVEL; i++){
         for (j = 0; j < LEVEL; j++){
             if( i == j ){
                 if (gAnswer[i] == uAnswer[j]) strike++;
             }else{
                 if (gAnswer[i] == uAnswer[j]) ball++;
             }
         }
     }
     if (strike == LEVEL) return 1;
     
     return 0;
}

void SetUsersAnswer(int *uAnswer,int life, int LEVEL){
    int i;
    char c[1];
    printf("\nLife %d) Input your Number: ", life);
    for (i = 0; i < LEVEL; i++){
        c[0] = getchar();
        if (c[0] == '\n' || c[0] == '\t' || c[0] == ' ') {i--; continue;}
        uAnswer[i] = atoi(c);
    }
    while(getchar() != '\n');    // Empty the buffer.
}

int main(){
    
    //// Setting ////
    int l, life;
    int Level;
    int *gAnswer;
    int *uAnswer;
    do{
       printf("> The number of digits in the game(0~10): ");
       scanf("%d", &Level);       
    }while(Level <= 0 || Level > 10);
    printf("> Opportunities in the game: ");
    scanf("%d", &life);
    
    gAnswer = (int*)malloc(sizeof(int) * Level);
    uAnswer = (int*)malloc(sizeof(int) * Level);
    ConstructGameAnswer(gAnswer, Level);
    system("cls");
    
    // for(life = 0; life < Level; life++) printf("%d",gAnswer[life]); puts("");     // To confirm game's answer.
    
    //// Running ////
    printf("Game Start!! (Level: %d)\n", Level);
    
    for(l = life; l > 0; l--){
        SetUsersAnswer(uAnswer, l, Level);
        if (CheckDuplicate(uAnswer, Level)){
            puts("> Please do not duplicate..");
        }else{
            if(CheckMatch(gAnswer, uAnswer, Level)){
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
    printf("\n:::: You are Loser ::::\nGame answer: ");
    for(life = 0; life < Level; life++) printf("%d",gAnswer[life]);
    free(uAnswer);
    free(gAnswer);
    system("PAUSE");   
    return 0;
}
