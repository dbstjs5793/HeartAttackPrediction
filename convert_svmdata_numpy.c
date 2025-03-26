#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline(char*, int*, FILE*);
int count_max_idx(char*);

int main(int argc, char*argv[])
{
	FILE* input, * output, * labelfile;
	char inputfile[100];// = "libsvm_sample";
	char outputfile[100];// = "dataset.csv";
	int max_line_len = 1024;
	int max_idx = 0;
	char* str = (char*)malloc(max_line_len * sizeof(char));

	if (argc < 3) {
		printf("argc error\n");
		printf("put argument : .exe [inputfilename] [outputfilename.csv]\n");
		return -1;
	}

	strcpy(inputfile, argv[1]);
	strcpy(outputfile, argv[2]);

	//if you know max idx(or dimention) of dataset, don't use count_max_idx : just put value to max_idx  ex) max_idx = 10;
	max_idx = count_max_idx(inputfile);

	input = fopen(inputfile, "rt");
	output = fopen(outputfile, "wt");

	//read each one line(one data)
	while ((readline(str, &max_line_len, input) != NULL)) {
		int i;
		int idx = 0, prev_idx, sig = 1;
		char* tmp;

		// label input
		tmp = strtok(str, " :\t\n");
		fputs(tmp, output);
		while (1) {
			if ((tmp = strtok(NULL, " :\t\n")) == NULL)
				break;
			prev_idx = idx;
			idx = atoi(tmp);	//	index remember
			for (i = 1; i < idx - prev_idx; i++) {	//	if there empty space between prev_idx and idx, filling value 0
				fputs(",0", output);
			}
			if ((tmp = strtok(NULL, " :\t\n")) == NULL)
				break;
			fputc(',', output);
			fputs(tmp, output);	//	save only value, not index. change space to ','
		}
		for (i = 0; i < max_idx - idx; i++) {	//	if last idx is not max idx, fill value 0
			fputs(",0", output);
		}
		fputc('\n', output);
	}
	fclose(input);
	fclose(output);

	return 0;
}


char* readline(char* str, int* max_line_len, FILE* input)
{
	int len;

	if (fgets(str, *max_line_len, input) == NULL)
		return NULL;

	while (strrchr(str, '\n') == NULL) {
		*max_line_len *= 2;
		str = (char*)realloc(str, *max_line_len * sizeof(char));
		len = (int)strlen(str);
		if (fgets(str + len, *max_line_len - len, input) == NULL)
			break;
	}
	return str;
}

int count_max_idx(char* inputfile)
{
	int max_line_len = 1024;
	int max_idx = 0;
	char* str = (char*)malloc(max_line_len * sizeof(char));

	FILE* input;

	input = fopen(inputfile, "rt");

	while (readline(str, &max_line_len, input) != NULL) {
		int i;
		int idx = 0, prev_idx;
		char* tmp;

		tmp = strtok(str, " :\t\n");
		while (1) {
			if ((tmp = strtok(NULL, " :\t\n")) == NULL)
				break;
			idx = atoi(tmp);
			if ((tmp = strtok(NULL, " :\t\n")) == NULL)
				break;
		}
		if (max_idx < idx)
			max_idx = idx;
	}
	fclose(input);
	free(str);

	return max_idx;
}