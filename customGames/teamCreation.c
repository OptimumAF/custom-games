#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ranking();
int value(char user[], char tier[], int tierSub);
void teams();
void playerInput();



int main(void){
    //playerInput();
    ranking();
    teams();
    return 0;
}


void ranking(){
    
    FILE *players = NULL;
    players = fopen("players.txt","r");
    if (players == NULL) {
      printf("Could not open file players.txt.\n");
    }
    char grab[100];
    char name[50];
    char division[50];
    int divisionNumber = 0;
    int tier;
    char ranking[100];
    for (int i = 26; i > 0; i--){
        while(!feof(players)){
            fgets(grab, 100, players);
            sscanf(grab, "%s %s %d", name, division, &divisionNumber);
            //puts(grab);
            if (i == value(name, division, divisionNumber)){
                sprintf(ranking, "%s%s\n",ranking,name);
            }
        }
        rewind(players);
    }
    fclose(players);
    //printf("%s", ranking);
    FILE *ranked;
    ranked = fopen("ranked.txt", "w");
    fprintf(ranked, ranking);
    fclose(ranked);
}


int value(char user[], char tier[], int tierSub){
    if (strcmp(tier, "iron") == 0 || strcmp(tier, "Iron") == 0){
        return abs(tierSub-4)+1;
    }
    else if (strcmp(tier, "bronze") == 0 || strcmp(tier, "Bronze") == 0){
        return abs(tierSub-4)+1+4*1;
    }
    else if (strcmp(tier, "silver") == 0 || strcmp(tier, "Silver") == 0){
        return abs(tierSub-4)+1+4*2;
    }
    else if (strcmp(tier, "gold") == 0 || strcmp(tier, "Gold") == 0){
        return abs(tierSub-4)+1+4*3;
    }
    else if (strcmp(tier, "platinum") == 0 || strcmp(tier, "Platinum") == 0){
        return abs(tierSub-4)+1+4*4;
    }
    else if (strcmp(tier, "diamond") == 0 || strcmp(tier, "Diamond") == 0){
        return abs(tierSub-4)+1+4*5;
    }
    else if (strcmp(tier, "master") == 0 || strcmp(tier, "Master") == 0){
        return 1+4*6;
    }
    else if (strcmp(tier, "challenger") == 0 || strcmp(tier, "Challenger") == 0){
        return 2+6*4;
    }
}

void teams(){
    char team1[250]="";
    char team2[250]="";
    FILE *ranked;
    ranked = fopen("ranked.txt", "r");
    char player[50];
    fgets(player, 50, ranked);
    player[strlen(player)-1] = '\0';
    sprintf(team1, "%s%s\n",team1,player);
    fgets(player, 50, ranked);
    player[strlen(player)-1] = '\0';
    sprintf(team2, "%s%s\n",team2,player);
    fgets(player, 50, ranked);
    player[strlen(player)-1] = '\0';
    sprintf(team2, "%s%s\n",team2,player);
    fgets(player, 50, ranked);
    player[strlen(player)-1] = '\0';
    sprintf(team1, "%s%s\n",team1,player);
    fgets(player, 50, ranked);
    player[strlen(player)-1] = '\0';
    sprintf(team2, "%s%s\n",team2,player);
    fgets(player, 50, ranked);
    player[strlen(player)-1] = '\0';
    sprintf(team1, "%s%s\n",team1,player);
    fgets(player, 50, ranked);
    player[strlen(player)-1] = '\0';
    sprintf(team1, "%s%s\n",team1,player);
    fgets(player, 50, ranked);
    player[strlen(player)-1] = '\0';
    sprintf(team2, "%s%s\n",team2,player);
    fgets(player, 50, ranked);
    player[strlen(player)-1] = '\0';
    sprintf(team2, "%s%s\n",team2,player);
    fgets(player, 50, ranked);
    player[strlen(player)-1] = '\0';
    sprintf(team1, "%s%s",team1,player);
    printf("Team 1\n---------------\n%s\n\n",team1);
    printf("Team 2\n---------------\n%s\n",team2);
    fclose(ranked);
}

void playerInput(){
    FILE *roster;
    roster = fopen("players.txt", "w");
    char playerRoster[1000]="";
    for (int i = 0; i < 10; i++){
        char input[100];
        char name[50];
        char rank[50];
        int subRank;
        printf("What is the IGN: ");
        fgets(name, 150, stdin);
        name[strlen(name)-1] = '\0';
        for (int j = 0; j < strlen(name); j++){
            if (name[j] == ' '){
                name[j] = '-';
            }
        }
        printf("What is the rank: ");
        fgets(input, 100, stdin);
        sscanf(input, "%s %d", rank, &subRank);
        sprintf(playerRoster, "%s%s %s %d\n",playerRoster, name, rank, subRank);
    }
    fprintf(roster, playerRoster);
    fclose(roster);
}