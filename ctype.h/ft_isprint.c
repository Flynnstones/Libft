#include <stdio.h>

int main(int argc, char *argv[])
{
    char carattere = argv[1][0];

    if(!(carattere >= 32 && carattere <= 126))
        printf("Il carattere inserito non è stampabile");
    else
        printf("Il carattere inserito è stampabile");

    return 0;
}