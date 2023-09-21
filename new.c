#include <stdio.h>
#include <string.h>

int startDay, modifier, startMonth, startYear, endDay, endMonth, endYear,
    deadline, sort, sortByDeadline, desc = 2;
int i, j, k, e, l, d,deleteByIdCount=0;
int chose = 0, count = 0, s = 0, fait = 1;
char check[100],checkIdToDelete[100];
char array[5][100][50] = {{"id", "title", "description", "status", "deadline"}};
char temp[5][50];
int main() {
  do {
    printf("Choose from the list:\n");
    printf("1- Add a new task\n");
    printf("2- show sort by days\n");
    printf("3- modifie description\n");
    printf("4- delete by id\n");
    scanf("%d", &chose);

    if (chose == 1) {
      s = s + 1;
      count = 0;
      sprintf(array[s][count], "%d", s);
      count = count + 1;

      printf("Enter the title: ");
      scanf(" %[^\n]", array[s][count]);
      count = count + 1;

      printf("Enter the description: ");
      scanf(" %[^\n]", array[s][count]);
      count = count + 1;

      printf("Enter the status: ");
      scanf(" %[^\n]", array[s][count]);
      count = count + 1;

      printf("starting day: ");
      scanf("%d", &startDay);

      printf("starting month: ");
      scanf("%d", &startMonth);

      printf("starting year: ");
      scanf("%d", &startYear);

      printf("endging day: ");
      scanf("%d", &endDay);

      printf("ending month: ");
      scanf("%d", &endMonth);

      printf("ending year: ");
      scanf("%d", &endYear);

      deadline = (endYear * 365 + endMonth * 30 + endDay) -
                 (startYear * 365 + startMonth * 30 + startDay);
      sprintf(array[s][count], "%d jour", deadline);
      for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
          printf("%s\t", array[i][j]);
        }
        printf("\n");
      }
    } else if (chose == 2) {
      printf("Chose from list:\n2-Afficher les tâches avec ordre "
             "alphabétique.\n1-Afficher les tâches par deadline\n3-Afficher "
             "les tâches dont le deadline est dans 3 jours ou moins");
      scanf("%d", &sort);
      if (sort == 1) {
      //this loop to sort by deadline
        for (i = 1; i <= s; i++) {
          for (e = i + 1; e <= s; e++) {
            sortByDeadline = atoi(array[i][4]) - atoi(array[e][4]);
            if (sortByDeadline < 0) {
              for (k = 0; k < 5; k++) {
                strcpy(temp[k], array[i][k]);
                strcpy(array[i][k], array[e][k]);
                strcpy(array[e][k], temp[k]);
              }
            }
          }
        }
        for (i = 0; i <= s; i++) {
          for (j = 0; j < 5; j++) {
            printf("%s\t", array[i][j]);
          }
          printf("\n");
        }
      }

    } else if (chose == 3) {
          printf("Choisi le un numero que tu veus "
                "changer\n1-Description.\n2-Status\n3-Deadline\nEntre le numero "
                "ici:");
          scanf("%d", &modifier);
          printf("entre le Description que vous voulez changer:");
          scanf(" %[^\n]", &check);
            if (modifier == 1) {
                desc = 2;
                for (l = 1; l <= s; l++) {
                  if (strcmp(check, array[l][desc]) == 0) {
                    printf("Entre que vous voulez modifier:");
                    scanf(" %[^\n]", &array[l][desc]);
                    fait = 1;
                    break;
                  } else
                    fait = 0;
                }
        }
      if (fait) {
        printf("Le description est modifier\n");
      } else
        printf("Le description n'pas modifier\n");
    } else if (chose == 4) {
        printf("Enter the identifier number you want to delete: ");
        scanf("%s", &checkIdToDelete);
        
        if (s>0)
        {
          for (d = 0; d <= s; d++)
            if (strcmp(checkIdToDelete,array[1][d]) == 0) {
              for (deleteByIdCount=1; deleteByIdCount <=s; deleteByIdCount++) {
                for (j = 0; j < 5; j++) {
                  strcpy(array[deleteByIdCount][j], array[deleteByIdCount+1][j]);
                }
              }
              printf("element suprimer\n");
            } else {
              printf("element est pas ici\n");
            }
        }
    }
  } while (1);
  return 0;
}