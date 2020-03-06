#include "FileHandler.h"

char * readAllTextFromFile(char path[])
{
	char buffer[128];

	FILE *fp;
	int err = fopen_s(&fp, path, "r");

	if (err != 0) {
		printf("'%s' file open error!\n", path);
		return NULL;
	}

	size_t len = sizeof(buffer);
	char *context = malloc(len);
	context[0] = '\0';

	while (fgets(buffer, sizeof(buffer), fp) != NULL) {
		size_t len_used = strlen(context);
		size_t chunk_used = strlen(buffer);

		//realloc memory size if file too large
		if (len - len_used < chunk_used) {
			len *= 2;
			if ((context = realloc(context, len)) == NULL) {
				perror("Unable to reallocate memory for the line buffer.");
				free(context);
				exit(1);
			}
		}
		// Copy the chunk to the end of the line buffer
		strncpy(context + len_used, buffer, len - len_used);
		len_used += chunk_used;
	}
	fclose(fp);
	
	return context;
}

int writeAllTextToFile(char path[], char ctx[]) {

	FILE *fptr;

	// use appropriate location if you are using MacOS or Linux
	fopen_s(&fptr, path, "w");
	if (fptr == NULL)
	{
		printf("File Open Error!");
		return -1;
	}

	fputs(ctx, fptr);
	fclose(fptr);

	return 0;
}
