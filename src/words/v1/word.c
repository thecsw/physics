
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 400000
#define WORD_SIZE 32

typedef struct {
	char *string;
	size_t length;
} entry;

typedef struct {
	entry *words;
	size_t size;
} content;

typedef struct {
	char *word;
	int frequency;
	size_t size;
} ranking;

content *read_file(char *file_name);
short find_ranking(char *string, ranking *array, size_t size);
ranking *rank_words(content *text);

int main(int argc, char **argv)
{
	assert(argc == 3);
	char filename[WORD_SIZE];
	strcpy(filename, argv[1]);

	content *text = read_file(filename);

	ranking *words = rank_words(text);

	for (size_t i = 0; i < words->size - 1; i++) {
		for (size_t j = 0; j < words->size - i - 1; j++) {
			if (words[j].frequency < words[j + 1].frequency) {
				int temp = words[j].frequency;
				words[j].frequency = words[j + 1].frequency;
				words[j + 1].frequency = temp;

				char ctemp[32];
				strcpy(ctemp, words[j].word);
				strcpy(words[j].word, words[j + 1].word);
				strcpy(words[j + 1].word, ctemp);
			}
		}
	}

	size_t n = atol(argv[2]);
	assert(n <= words->size);
	printf("\t--------------------------------\n");
	printf("\t|N\t|Word\t|Frequency\t|\n");
	printf("\t--------------------------------\n");
	for (size_t i = 0; i < n; i++) {
		printf("\t|%lu\t|%s\t|%d\t\t|\n", i, words[i].word,
		       words[i].frequency);
	}
	printf("\t--------------------------------");
	puts("\n");
}

/*
 * The function below returns an content struct instance 
 * that includes all the words from the file in correct order
 * and also contains each word's length. Same thing can be done
 * with the strlen() but in this way we just access a variable
 * instead of calling a separate function from string.h
 */
content *read_file(char *file_name)
{
	char *mode = "r";
	FILE *fp;
	fp = fopen(file_name, mode);
	assert(fp);

	int tot_word = 0;
	char **buffer = (char **)malloc(BUFFER_SIZE * sizeof(char *));
	content *text_file = (content *)malloc(sizeof(content));
	while (!feof(fp)) {
		char *word = (char *)malloc(sizeof(char) * WORD_SIZE);
		fscanf(fp, "%s", word);
		size_t length = strlen(word);
		buffer[tot_word] = (char *)malloc(length * sizeof(char));
		strcpy(buffer[tot_word], word);
		tot_word++;
		free(word);
	}

	text_file->size = tot_word;
	text_file->words = (entry *)malloc(text_file->size * sizeof(entry));

	for (size_t i = 0; i < text_file->size; i++) {
		char *single_word = buffer[i];
		size_t len = strlen(single_word);
		text_file->words[i].string = (char *)malloc(len * sizeof(char));
		strcpy(text_file->words[i].string, single_word);
		text_file->words[i].length = len;
	}

	//	printf("%lu\n", text_file->size);
	fclose(fp);

	free(buffer);
	return text_file;
}

ranking *rank_words(content *text)
{
	ranking *checked = (ranking *)malloc(text->size * sizeof(ranking));
	checked->size = 0;

	for (size_t i = 0; i < text->size; i++) {
		if (!find_ranking(text->words[i].string, checked,
				  checked->size)) {
			checked[checked->size].word = (char *)malloc(
				sizeof(char) * text->words[i].length);
			strcpy(checked[checked->size].word,
			       text->words[i].string);
			checked->size++;
		}
	}

	for (size_t i = 0; i < checked->size; i++) {
		checked[i].frequency = 0;
		for (size_t j = 0; j < text->size; j++) {
			if (!strcmp(checked[i].word, text->words[j].string))
				checked[i].frequency++;
		}
	}
//	printf("SIZE -> %lu\n", checked->size);
	return checked;
}

short find_ranking(char *string, ranking *array, size_t size)
{
	for (size_t i = 0; i < size; i++) {
		if (!strcmp(string, array[i].word))
			return 1;
	}
	return 0;
}
