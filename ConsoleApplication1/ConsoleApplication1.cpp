// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#define _CRT_SECURE_NO_WARNINGS 

#define SOURCE_FILE	"input.txt"
#define OUTPUT_FILE	"output.txt"

#define MAX_LENGTH	64
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <locale>

void CheckFile(FILE *ft, char *name_file);
void changeWord(char *word, FILE *ft);

int main() {
	system("chcp 1251");
	system("cls");

	FILE *finp, *fout;
	char word[MAX_LENGTH];

	finp = fopen(SOURCE_FILE, "rt");
	CheckFile(finp, SOURCE_FILE);

	fout = fopen(OUTPUT_FILE, "wt");
	CheckFile(fout, OUTPUT_FILE);

	while (!feof(finp)) {
		fscanf(finp, "%s", word);
		changeWord(word, fout);
	}

	fclose(finp);
	fclose(fout);

	return 1;
}

void changeWord(char *word, FILE *ft) {
	int	length = strlen(word);

	word[0] = word[length - 1];
	fprintf(ft, "%s ", word);
}

void CheckFile(FILE *ft, char *name_file) {
	if (ft == NULL) {
		printf("Ошибка открытия файла %s", name_file);
		_getch();
		exit(1);
	}
}