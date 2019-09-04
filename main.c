#include <stdio.h>
#include <stdlib.h>
#define TABLESIZE 100

typedef struct time{
    short hour, minute, second;
}time;

typedef struct t_time {
    char* key;
    time hour;
}t_time;

t_time t_timeTable[TABLESIZE];

int compareTime(time h1, time h2);
void printTimeTable();
void putTimeTable(char* key, time time);
int containsTime(time time);
char* getTimeKey(time time);
int getTime (time time);
int sizeTimeTable();

int main(){
    t_time t;
    t.key = "WASHINGTON";
    time tk;
    tk.hour = 4;
    tk.minute = 30;
    tk.second = 0;
    t.hour = tk;
    putTimeTable(t.key, tk);
    t.key = "PAQUISTAO";
    time tk2;
    tk2.hour = 0;
    tk2.minute = 30;
    tk2.second = 25;
    putTimeTable(t.key, tk2);
    t.key = "LUA";
    time tk3;
    tk3.hour = 6;
    tk3.minute = 30;
    tk3.second = 25;
    putTimeTable(t.key, tk3);
    printf("Tabela contem elementos %d\n000\n",sizeTimeTable());
    printf("TK3 encontrado na posicao %d\n000\n", getTime(tk3));
    printTimeTable();
    printf("000\n");
    deleteTime(tk);
    printf("Contem %s TK: %d\n", getTimeKey(tk), containsTime(tk));

    printf("Contem %s TK2: %d\n000\n", getTimeKey(tk2), containsTime(tk2));
    printf("Tabela contem elementos %d\n000\n",sizeTimeTable());
    printTimeTable();
    return 0;
}

void putTimeTable(char* key, time time){
//biggest to smaller
    for(int i = 0; i < TABLESIZE; i++){
            if((compareTime(time,t_timeTable[i].hour) == 1)){
                for(int j = TABLESIZE-1; j > i ; j--){
                    t_timeTable[j] = t_timeTable[j-1];
                }
                t_timeTable[i].key = key;
                t_timeTable[i].hour = time;
                return;
            }
    }
}

//for debugging use
void printTimeTable(){
    for(int i = 0; i < TABLESIZE; i++){
        if(t_timeTable[i].key){
            printf("Position %5d Key %10s Hour: %2dh%2dm%2ds\n", i, t_timeTable[i].key, t_timeTable[i].hour.hour, t_timeTable[i].hour.minute, t_timeTable[i].hour.second);
        }
    }

}

int compareTime(time h1, time h2){
    double h1Fator = h1.hour + ((double)h1.minute / 60) + ((double) h1.second / 3600);
    double h2Fator = h2.hour + ((double)h2.minute / 60) + ((double) h2.second / 3600);
    if(h1Fator > h2Fator){return 1;}
    if(h1Fator < h2Fator){return -1;}
    else{return 0;}
}

//Implementation of Binary Search
int getTime (time time){
     int inf = 0;     // botton limit          )
     int sup = TABLESIZE-1; // top limit
     int meio;
     while (inf <= sup)
     {
          meio = (inf + sup)/2;
          if (compareTime(time,t_timeTable[meio].hour) == 0)
               return meio;
          if (compareTime(time,t_timeTable[meio].hour) == 1)
               sup = meio-1;
          else
               inf = meio+1;
     }
     return -1;   // not found
}

char* getTimeKey(time time){
    if (containsTime(time) != -1){
        return t_timeTable[getTime(time)].key;
    }
    return "";
}

void deleteTime(time time){

    int pos = getTime(time);
    for(int j = pos; j < TABLESIZE; j++){
        t_timeTable[j] = t_timeTable[j+1];
    }
}

int containsTime(time time){
    if(getTime(time) == -1){
        return 0;
    }
    return 1;
}

int sizeTimeTable(){
    int count = 0;
    for(int i = 0; i < TABLESIZE; i++){
        if(t_timeTable[i].key){
            count++;
        }
    }
    return count;
}

