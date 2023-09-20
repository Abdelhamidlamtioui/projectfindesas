#include <stdio.h>
#include <string.h>
int chose = 0, count = 0, s = 0;
int main() 
{
    char check[100];
    char array[5][7][20] = {
        {"id", "title", "description", "deadline", "status"},
        {"1", "Project1", "details", "2023", "done"},
        {"2", "Project2", "whhw", "2023", "started"},
        {"3", "Project3", "dhdh", "2023", "in process"},
        {"4", "Project4", "gdgd", "2023", "in process"}
    };

    printf("Choose from the list:\n");
    printf("1- Add a new task\n");
    scanf("%d", &chose);

    if (chose == 1)
    {
        s = s + 1;
        
        sprintf(array[s][count], "%d", s+1);
        count = count + 1;

        printf("Enter the title: ");
        scanf(" %[^\n]", array[s][count]);
        count = count + 1;

        printf("Enter the description: ");
        scanf(" %[^\n]", array[s][count]);
        count = count + 1;

        printf("Enter the deadline: ");
        scanf(" %[^\n]", array[s][count]);
        count = count + 1;

        printf("Enter the status: ");
        scanf(" %[^\n]", array[s][count]);
    }
    return 0;
}