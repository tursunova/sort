#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comparator.h"

int main(int argc, char** argv){

    const int n = atoi(argv[1]);
    char const* const fileName = argv[2];

    FILE* file = fopen(fileName, "r");

    int *len = (int*)malloc(sizeof(int) * n);
    int i;

	for (i = 0; i < n; i++){
		len[i] = 0;
	}
	i = 0;
	char c;
    while (((c = fgetc(file)) != EOF) && (i < n)) {
        if (c != '\n'){
            len[i]++;
        } else {
            i++;
		}
		c = fgetc(file);
	}
	char** s = (char**)malloc(sizeof(char*) * n);
	rewind(file);
	for(i = 0; i < n; i ++)
	{
		s[i] = (char*)malloc(sizeof(char)*(len[i]+1));
		int k = 0;
		while (((c = fgetc(file)) != '\n')&&(c != EOF))
		{
			s[i][k++] = c;
		}
		s[i][k] = '\0';
	}
	free(len);

    qsort(s, n, sizeof(char *), cmp);

    for( i = 0; i < n; i++ ) {
        printf("%s\n", s[i]);
        free(s[i]);
    }
    free(s);

    fclose(file);
    return 0;
}
