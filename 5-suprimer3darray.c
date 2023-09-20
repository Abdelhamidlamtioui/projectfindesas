#include <stdio.h>

int main() 
{
    int deleteById;
    int i, j, l;
    char array[5][5][20] = {
        {"id", "title", "description", "deadline", "status"},
        {"1", "Project1", "details", "2023", "done"},
        {"2", "Project2", "details", "2023", "started"},
        {"3", "Project3", "details", "2023", "in process"},
        {"4", "Project4", "details", "2023", "in process"}
    };

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%s\t", array[i][j]);
        }
        printf("\n");
    }

    printf("Enter the identifier number you want to delete: ");
    scanf("%d", &deleteById);

    if (deleteById >= 1 && deleteById <= 4) {
        for (deleteById; deleteById < 5; deleteById++) {
            for (j = 0; j < 5; j++) {
                strcpy(array[deleteById][j], array[deleteById + 1][j]);
            }
        }
        printf("element suprimer\n");
    } else {
        printf("element est pas ici\n");
    }

    printf("nouveau tableau:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            printf("%s\t", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}