#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct emp
{
      char name[15];
      int age;
      int salary;
      char address[30];
}empDetails[5];

int main(void)
{
    char const fileName[] = "employees.csv";
    FILE* file = fopen(fileName, "r"); // Read Employees
    char line[256];

    /*
    Notes: difference between fscanf and fgets is that fgets reads to upto the newline character and stores it while fscanf only reads upto a whitespace and doesn't store it
    */
    int lineCount = 1;
    while (fgets(line, sizeof(line), file)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        // Stripping the \n
        int lineLen = strlen(line);
        if (line[lineLen -1] == '\n'){
            line[lineLen - 1] = 0;
        }
        printf("%s\n", line);
        sscanf(line, "%s, %i, %i, %s", empDetails[lineCount].name, &empDetails[lineCount].age, &empDetails[lineCount].salary, empDetails[lineCount].address);
        lineCount += 1;

        printf("%d", empDetails[lineCount].age);
    }
    /* may check feof here to make a difference between eof and io failure -- network
       timeout for instance */

    fclose(file);

    return 0;
}
