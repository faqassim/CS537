#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int read()
{
    return 0;
}

int main(int argc, char const *argv[])
{

    char fileOutput[100];
    int folderNumber = 0;
    char address[100];

    if (argc > 3 || argc < 2)
    {
        printf("usage: ./wman <man page> <command name>\n");
        exit(1);
    }
    else
    {
        const char *commandName = argv[1];
        if (argc > 2)
        {
            folderNumber = atoi(argv[2]);
        }
        else
        {
            folderNumber = 1;
        }

        snprintf(address, sizeof(address), "./man_pages/man%d/%s.%d", folderNumber, commandName, folderNumber);

        FILE *fp = fopen(address, "r");
        if (fp == NULL)
        {
            // perror("Error opening file");
            printf("cannot open file\n");
            exit(1);
        }
        while (fgets(fileOutput, sizeof(fileOutput), fp) != NULL)
        {
            printf("%s", fileOutput);
        }
        fclose(fp);
    }
    return 0;
}
