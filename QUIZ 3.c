/*
NAME:KEITH BARRACK OJUANG
REG:PA106/G/29044/25
DESCRIP:DIPLAY OF INPUT OUTPUT AVERAGE
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputFile, *outputFile;
    int numbers[10];
    int sum = 0, count = 0;
    float average;
    int i;        
    int num;      
    char ch;     

    // 1. Prompt user to input 10 integer
    inputFile = fopen("input.txt", "w");
    if (inputFile == NULL) {
        printf("Error  in opening input.txt for writing.\n");
        return 1;
    }

    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
        fprintf(inputFile, "%d\n", numbers[i]);
    }
    fclose(inputFile);
    printf("\nData successfully saved to input.txt\n");

    
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input.txt for reading.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output.txt for writing.\n");
        fclose(inputFile);
        return 1;
    }

    while (fscanf(inputFile, "%d", &num) != EOF) {
        sum += num;
        count++;
    }

    if (count == 0) {
        printf("No numbers found in input.txt\n");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    average = (float)sum / count;
    fprintf(outputFile, "Sum = %d\nAverage = %.2f\n", sum, average);
    fclose(inputFile);
    fclose(outputFile);
    printf("The Sum and average successfully written to output.txt\n");

    // 3. Display contents of both files
    printf("\nContents of input.txt:\n");
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error reading input.txt.\n");
        return 1;
    }
    while ((ch = fgetc(inputFile)) != EOF) {
        putchar(ch);
    }
    fclose(inputFile);

    printf("\nContents of output.txt:\n");
    outputFile = fopen("output.txt", "r");
    if (outputFile == NULL) {
        printf("Error reading output.txt.\n");
        return 1;
    }
    while ((ch = fgetc(outputFile)) != EOF) {
        putchar(ch);
    }
    fclose(outputFile);

    return 0;

}
