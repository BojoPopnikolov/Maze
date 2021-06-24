#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int i,j;
    node *p;
}node;

typedef struct {
    node *last;
}stack;

void push(int i, int j, stack *p){
    node *newnode = malloc(sizeof(node));
    if(p->last == NULL){
        p->last = newnode;
        newnode->p = NULL;
        newnode->i=i;
        newnode->j=j;

        return;
    }
    
    newnode->i=i;
    newnode->j=j;
    newnode->p=p->last;
    p->last = newnode;
}

void pop(stack *p){
    node *buff = p->last;
    p->last = buff->p;
    free(buff);
}

void ClearMatrix(char matrix[40][30], int n, int m) {
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            matrix[i][j] = '.';
        }
    }
}

void saveMatrix(char matrix[40][30]){
    char name[50];
    printf("Enter file name: ");
    fgets(name, 50, stdin);

    FILE* file = fopen(name, "wb");
    fwrite(matrix, sizeof(char), 40 * 30, file);
    fclose(file);

}

char** loadMatrix(){
    char name[50];
    printf("Select file: ");
    fgets(name, 50, stdin);

    FILE* file = fopen(name, "rb");

    if(file == NULL){
        printf("No such file!");
        return NULL;
    }

    char* values = calloc(40 * 30, sizeof(char));
    char** rows = malloc(40 * sizeof(char*));

    fread(rows, sizeof(char), 40 * 30, file);
    fclose(file);

    return rows;
}

void printMatrix(char matrix[40][30], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", matrix[i][j]);
        }

        printf("\n");
    }
}

void generatePath(char matrix[40][30], int n, int m) {

    ClearMatrix(matrix, n, m);

    printf("Enter height: ");
    scanf_s("%d", &n);
    printf("Enter width: ");
    scanf_s("%d", &m);

    if (n > 40 || m > 30 || n < 3 || m < 3) {
        printf("Invalid values (max 40x30) (min 3x3)");
        return;
    }

    int i = 0;
    int j = 0;
    time_t t;

    matrix[0][0] = ' ';
    srand((unsigned)time(&t));
    while (1) {
        int gen;
        int gen2;
        int newi = i;
        int newj = j;
        
        do {
            newi = i;
            newj = j;
            gen = rand() % 2;
            gen2 = rand() % 2;
            
            if (gen == 0) {
                if (gen2 == 0) {
                    newi--;
                }
                else {
                    newi++;
                }
            }
            else {
                if (gen2 == 0) {
                    newj--;
                }
                else {
                    newj++;
                }
            }
        } while (newi < 0 || newj < 0 || newi >= n || newj >= m);

        i = newi;
        j = newj;
        matrix[i][j] = ' ';
        if (i == n - 1 && j == m - 1) {
            break;
        }
    }

    for  (i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            if (matrix[i][j] == ' ') {
                continue;
            }

            int gen = rand() % 8;

            if (gen == 0) {
                matrix[i][j] = ' ';
            }
            else {
                matrix[i][j] = '#';
            }
        }
    }
    printMatrix(matrix, n, m);
}



int Menu()
{
    int n = 0;
menu:
    printf("+-------------------------------------------------------------------------+\n");
    printf("+-----------------------------------Maze----------------------------------+\n");
    printf("+-------------------------------------------------------------------------+\n");
    printf("|0.Generate     |1.Read     |2.Save     |3.User     |4.Computer     |5.Exit\n\n");
    printf("Enter your choice : ");
    scanf_s("%d", &n);

    switch (n)
    {
    case 0:
    {
        char matrix[40][30];
        int n = 0;
        int m = 0;
        generatePath(matrix, n, m);
    }
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        return 0;
    }
    printf("\n\n");
    goto menu;
    return 0;
}

int main()
{
    Menu();
    return 0;
}