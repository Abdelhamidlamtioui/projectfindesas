#include <stdio.h>
#include <string.h>
#include <time.h>


typedef struct{
  int id;
  char title [100];
  char description [100];
  char deadline[100];
  char status[100];
  int r_days;
  char remaningDays[100];
  int daysCalculation;
} toDOList;
toDOList tab[100];


int countAddElement=0;
int searchID,countSearch,searchListChoice;
int id_G=0;


//choix de status
void status(int count_s)
{
  int StatusAdd;
  printf("------------------------------------\n");
  printf("\n|1| - A realiser\n|2| - En cours de realisation\n|3| - Finalisee\nEnter un choix pour status:");
  scanf(" %d", &StatusAdd);
  if (StatusAdd == 1) 
  {
      strcpy(tab[count_s].status, "A realiser");
  } 
  else if (StatusAdd == 2) 
  {
      strcpy(tab[count_s].status, "En cours de realisation");
  } 
  else if (StatusAdd == 3) 
  {
      strcpy(tab[count_s].status, "Finalisee");
  } 
  else 
  {
  printf("Entrez un nouveau nombre valide.\n");
  }
}
//FONCTION de date
void date(int count)
{
  int tempDaysCalculation,day,month,year,currentDaysCalculation,remainingDays;
  time_t currentTime=time(NULL);
  struct tm currentdate=*localtime(&currentTime);
  int currentDay = currentdate.tm_mday;
  int currentMonth = currentdate.tm_mon + 1;
  int currentYear = currentdate.tm_year + 1900;
  currentDaysCalculation=currentDay+(30*currentMonth)+(currentYear*360);
  printf("------------------------------------\n");
  printf("Date d\'aujourd\'hui: %02d-%02d-%04d\n",currentDay ,currentMonth ,currentYear);
  printf("------------------------------------\n\n");
  printf("Entre le jour de deadline:");
  scanf("%d",&day);
  printf("Entre le mois de deadline:");
  scanf("%d",&month);
  printf("Entre le annee de deadline:");
  scanf("%d",&year);
  tempDaysCalculation=(year*360)+(month*30)+day;
  tab[count].daysCalculation=tempDaysCalculation;
  remainingDays=tempDaysCalculation-currentDaysCalculation;
  tab[count].r_days=remainingDays;
  sprintf(tab[count].remaningDays,"%d day",remainingDays);
  sprintf(tab[count].deadline,"%d/%d/%d",day,month,year);
};
//fonction d'ajouter dans le todolist
void addinfo()
{            
  id_G++;
  tab[countAddElement].id=id_G;
  printf("------------------------------------\n");
  printf("Votre id est : %d\n",tab[countAddElement].id);
  printf("------------------------------------\n\n");
  printf("Enter the title: ");
  scanf(" %[^\n]", tab[countAddElement].title);
  printf("Enter the description: ");
  scanf(" %[^\n]", tab[countAddElement].description);
  status(countAddElement);
  date(countAddElement);
  countAddElement++;
};
//fonction d\'echange
void swap(int showListCount,int showListCount1)
{
    int tempSortAlphabetNum;
    char tempSortAlphabet[100];
    // swap id
    tempSortAlphabetNum=tab[showListCount].id;
    tab[showListCount].id=tab[showListCount1].id;
    tab[showListCount1].id=tempSortAlphabetNum;
    //swap title
    strcpy(tempSortAlphabet,tab[showListCount].title);
    strcpy(tab[showListCount].title,tab[showListCount1].title);
    strcpy(tab[showListCount1].title,tempSortAlphabet);
    //swap description
    strcpy(tempSortAlphabet,tab[showListCount].description);
    strcpy(tab[showListCount].description,tab[showListCount1].description);
    strcpy(tab[showListCount1].description,tempSortAlphabet);
    //swap status
    strcpy(tempSortAlphabet,tab[showListCount].status);
    strcpy(tab[showListCount].status,tab[showListCount1].status);
    strcpy(tab[showListCount1].status,tempSortAlphabet);
    //swap deadline
    strcpy(tempSortAlphabet,tab[showListCount].deadline);
    strcpy(tab[showListCount].deadline,tab[showListCount1].deadline);
    strcpy(tab[showListCount1].deadline,tempSortAlphabet);
    //swap daysCalculation
    tempSortAlphabetNum=tab[showListCount].daysCalculation;
    tab[showListCount].daysCalculation=tab[showListCount1].daysCalculation;
    tab[showListCount1].daysCalculation=tempSortAlphabetNum;
    //swap remaningDays
    strcpy(tempSortAlphabet,tab[showListCount].remaningDays);
    strcpy(tab[showListCount].remaningDays,tab[showListCount1].remaningDays);
    strcpy(tab[showListCount1].remaningDays,tempSortAlphabet);
    //swap r_days
    tempSortAlphabetNum=tab[showListCount].r_days;
    tab[showListCount].r_days=tab[showListCount1].r_days;
    tab[showListCount1].r_days=tempSortAlphabetNum;
};

int main()
{
  while(1)
  {
    int choisie;
    printf("+++++++++++++        TODOLIST        +++++++++++++\n\n");
    printf("+++++++++++++Choisie de list suivant:+++++++++++++\n\n");
    printf("|1| - Ajouter une nouvelle tache.\n");
    printf("|2| - Ajouter plusieurs nouvelles taches.\n");
    printf("|3| - Afficher la liste de toutes les taches\n");
    printf("|4| - Modifier une tache\n");
    printf("|5| - Supprimer une tache par identifiant\n");
    printf("|6| - Rechercher les Taches\n");
    printf("|7| - Statistiques\n");
    printf("|0| - Quitter\n\n");
    printf("Entre numero entre 0 et 7:");
    scanf("%d", &choisie);
    switch(choisie)
    {
      case 1:
          addinfo();
        break;
      case 2:
      {
        int numOfTask;
        printf("Entre le nombre de taches que vous voulez ajouter: ");
                scanf("%d", &numOfTask);
          for (int countAdd = 0; countAdd < numOfTask; countAdd++) 
          {
            addinfo();
          }
        break;
      }
      case 3:
      {
        int showListchoice;
        printf("Choisie de ce list que vous voulez:\n1-Trier les taches par ordre alphabetique\n2-Trier les taches par deadline.\n3-Afficher les taches dont le deadline est dans 3 jours ou moins.");
        scanf("%d",&showListchoice);
        //SORTER PAR ALPHABETER
        if(showListchoice==1)
        {
          for (int showListCount=0;showListCount<countAddElement;showListCount++)
          {
            if (tab[showListCount].title[0] != '\0') 
            {
                  strlwr(tab[showListCount].title);
            }
          }
          for (int showListCount = 0; showListCount < countAddElement; showListCount++)
          {
            for (int showListCount1=showListCount+1;showListCount1<countAddElement;showListCount1++)
            {
              if(strcmp(tab[showListCount].title,tab[showListCount1].title)<1)
              {
                swap(showListCount,showListCount1);
              }
            }
          }
          for (int showListCount= 0; showListCount < countAddElement; showListCount++)
          {
            printf("\n------------------------------------\n");
            printf("Id est : %d\n",tab[showListCount].id);
            printf("Le titre de tache est %s\n",tab[showListCount].title);
            printf("Le description de tache est %s\n",tab[showListCount].description);
            printf("Le deadline de tache est %s\t",tab[showListCount].deadline);
            printf("Le statut de tache est %s\n",tab[showListCount].status);
          }
        }
        //SORTER PQR DATE
        else if(showListchoice==2)
        {
          for (int showListCount = 0; showListCount < countAddElement; showListCount++)
          {
            for (int showListCount1=showListCount+1;showListCount1<countAddElement;showListCount1++)
            {
              if (tab[showListCount].daysCalculation<tab[showListCount1].daysCalculation)
              {
                swap(showListCount,showListCount1);
              }
            }
          }
          for (int showListCount= 0; showListCount < countAddElement; showListCount++)
          {
            printf("\n------------------------------------\n");
            printf("Id est : %d\n",tab[showListCount].id);
            printf("Le titre de tache est %s\n",tab[showListCount].title);
            printf("Le description de tache est %s\n",tab[showListCount].description);
            printf("Le deadline de tache est %s\n",tab[showListCount].deadline);
            printf("Le statut de tache est %s\n",tab[showListCount].status);
          }
        }
        //VOIR LES DENIER 3 JOUR
        else if(showListchoice==3)
        {
          for (int showListCount = 0; showListCount < countAddElement; showListCount++)
          {
              if (tab[showListCount].r_days<4)
              {
                printf("\n------------------------------------\n");
                printf("Id est : %d\n",tab[showListCount].id);
                printf("Le titre de tache est %s\n",tab[showListCount].title);
                printf("Le description de tache est %s\n",tab[showListCount].description);
                printf("Le deadline de tache est %s\n",tab[showListCount].deadline);
                printf("Le statut de tache est %s\n",tab[showListCount].status);
              }
          }   
        }
        else printf("this number is not on the list");
        break;
      }
      case 4:
      {
        int modidyId,modidyChoisie;
        char newDescription[100];
        printf("entre le id de tach:");
        scanf("%d",&modidyId);
        printf("\n1-Modifier la description de une tache\n2-Modifier le statut de une tache.\n3-Modifier le deadline de une tache.\nChoisie de ce list que vous voulez:");
        scanf("%d",&modidyChoisie);
        if(modidyChoisie==1)
        {
          printf("Entre la nouvelle description:");
          scanf("%s",&newDescription);
          for (int modidyListCount=0;modidyListCount<countAddElement;modidyListCount++)
          {
            if (modidyId==tab[modidyListCount].id)
            {
              strcpy(tab[modidyListCount].description,newDescription);
              break;
            }
          }
 
        }
        else if(modidyChoisie==2)
        {
          for (int modidyListCount=0;modidyListCount<countAddElement;modidyListCount++)
          {
            if (modidyId==tab[modidyListCount].id)
            {
              printf("Entre la nouveau status:");
              status(modidyListCount);
            }
          }
        }
        else if(modidyChoisie==3)
        {
          for (int modidyListCount=0;modidyListCount<countAddElement;modidyListCount++)
          {
            if (modidyId==tab[modidyListCount].id)
            {
                date(modidyListCount);
            }
          }
        }
        else printf("Votre id est pas dans list\n");
        break;
      }
      case 5:
      {
        int deleteId;
        printf("entre le id de tach:");
        scanf("%d",&deleteId);
        for (int countDelete = 0; countDelete < countAddElement; countDelete++)
        {
          if (tab[countDelete].id==deleteId)
          {
            for (int countDelete1= countDelete; countDelete1 < countAddElement; countDelete1++)
            {
              tab[countDelete1]=tab[countDelete1+1];
            }
            countAddElement--;
          }
        }
      }
        break;
      case 6:
      printf("Choisie de ce list que vous voulez:\n1-Rechercher une tache par son Identifiant.\n2-Rechercher une tache par son Titre.");
      scanf("%d",&searchListChoice);
      if (searchListChoice==1)
      {
        printf("Entre le id de tach:");
        scanf("%d",&searchID);
        for ( countSearch=0 ; countSearch < countAddElement; countSearch++)
        {
          if (tab[countSearch].id==searchID)
          {
            printf("\n------------------------------------\n");
            printf("Id est : %d\n",tab[countSearch].id);
            printf("Le titre de tache est %s\n",tab[countSearch].title);
            printf("Le description de tache est %s\n",tab[countSearch].description);
            printf("Le deadline de tache est %s\n",tab[countSearch].deadline);
            printf("Le statut de tache est %s\n\n",tab[countSearch].status);
          }
        }
      }
      if (searchListChoice==2)
      {
        char searchTitle[100];
        printf("Entre le titre de tach:");
        scanf("%d",&searchTitle);
        for ( countSearch=0 ; countSearch < countAddElement; countSearch++)
        {
          if (strcmp(tab[countSearch].title,searchTitle)==0)
          {
            printf("Id est : %d\n",tab[countSearch].id);
            printf("Le titre de tache est %s\n",tab[countSearch].title);
            printf("Le description de tache est %s\n",tab[countSearch].description);
            printf("Le deadline de tache est %s\n",tab[countSearch].deadline);
            printf("Le statut de tache est %s\n",tab[countSearch].status);
          }
        }
      }
        break;
      case 7:
      { 
        int choiceStatistiques;
        printf("|1|-Afficher le nombre total des taches.\n|2|-Afficher le nombre de taches completes et incompletes.\n|3|-Afficher le nombre de jours restants jusqu'au delai de chaque tache.\n");
        printf("choisir de list que vous voulez:");
        scanf("%d",&choiceStatistiques);
        do
        {
          if (choiceStatistiques==1)
          {
            printf("\nNumero de tach est: %d\n",countAddElement);
            break;
          }
          else if (choiceStatistiques==2)
          {
            int countTaskStart,countTaskEnded;
            countTaskEnded==0;
            countTaskStart=0;
            for (int countChoiceStatistiques= 0; countChoiceStatistiques < countAddElement; countChoiceStatistiques++)
            {
              if (strcmp(tab[countChoiceStatistiques].status,"Finalisee")==0)
              {
                countTaskEnded++;
              }
              else countTaskStart++;
            }
            printf("Number of finalised:%d\n",countTaskEnded);
            printf("Number of not finalised:%d\n",countTaskStart);
            break;
          }
          else if (choiceStatistiques==3)
          {
          for (int showListCount= 0; showListCount < countAddElement; showListCount++)
            {
              printf("Id est : %d\n",tab[showListCount].id);
              printf("Le titre de tache est %s\n",tab[showListCount].title);
              printf("Le description de tache est %s\n",tab[showListCount].description);
              printf("Le deadline de tache est %s\n",tab[showListCount].deadline);
              printf("Le statut de tache est %s\n",tab[showListCount].status);
              printf("Les jour restent de tache est %s\n",tab[showListCount].remaningDays);
            }
            break;
          }
          else printf("Number is not valid");
        } while (1);
        break;
      }
      case 0:
        return 0;
        break;
      }
    }
    return 0;
}