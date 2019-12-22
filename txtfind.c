#include "txtfind.h"

int getLine(char*s) {

	char ch;
	int countLine = 0;
	int i = 0;
	strcpy(s, " ");

	do {
		scanf("%c", &ch);
		*(s + i) = ch;
		i++;
		countLine++;

		if (ch == '\n') {
			*(s + i) = '\0';
			i = 0;
			break;

		}
		*(s + i) = '\0';
	} while (ch != EOF);

	if (ch == EOF) {
		return 0;
	}

	
		
	return countLine;
}

int getWord(char* w) {
    	char ch;
	int countWord = 0;
	int i = 0;
	
	do {
		scanf("%c", &ch);
		if (ch == EOF) {
			return 0;
		}

		if (ch == '\n'||ch==' '||ch=='\t') {
			break;
		}
		else {
			countWord++;
			*(w + i) = ch;
			i++;
		}
		*(w + i) = '\0';
	} while (ch != EOF);
	
	return countWord;
		
}



int containStringCheak( char* w, char* inputWord) {

	int lenW = strlen(w);
	int lenInputW = strlen(inputWord);
	int found = 0;

	if (lenW >= lenInputW)
	{
		for (int i = 0, j = 0;i < lenW; i++)
		{
			do {

				if (*(w+i) == *(inputWord+j))
				{
					if (++found == lenInputW)
						return 1;
					i++;
					j++;
				}
				else {
					i -= found;
					found = 0;
					j = 0;
				}

			} while (found);
		}
		return 0;
	}
	else return 0;
}

int similarCheck( char* w, char* inputWord,int n) {
	int bil = 0;
	int ct = 0;
	int count = 0;
	char temp[WORD_LEN_MAX];
	int ansCheck;
	
	if (strlen(w) < strlen(inputWord)) {
		return 0;
	}
	if (strlen(w) == strlen(inputWord)) {
		if (containStringCheak(w, inputWord) == 1) {
			return  1;
		}
	}
	strcpy(temp, w);
	for (int i = 0; i < strlen(w); i++) {
		char checkCT = *(w + i);
		for (int x = 0; x < WORD_LEN_MAX; x++) {
			if (*(inputWord + x) == *(w + i)) {
				ct++;
			}
		}

		if (ct != 0) {
			ansCheck = countChar(w, inputWord, checkCT);
			if (ansCheck == 0) {
				memmove((w + i), (w + (i + 1)), strlen(w) - i);
				count++;
			}
		}
			if(ct==0){
				memmove((w + i), (w + (i + 1)), strlen(w) - i);
				count++;
			}
			
		if (strlen(w) == strlen(inputWord)) {
				if (containStringCheak(w, inputWord) == 1) {
					bil = 1;
					break;
				}
			}
		ct = 0;
	}

	strcpy(w, temp);
	
	if (bil == 1 && count <= n){
		return 1;
	}
	return 0;
}

int countChar(char*w, char* inputWord, char checkCT) {
	int ctInputWord = 0;
	for (int i = 0; i < strlen(inputWord); i++) {
		if (*(inputWord + i) == checkCT) {
			ctInputWord++;
		}
	}
	int ctTemp = 0;
	for (int j = 0; j < strlen(w); j++) {
		if (*(w + j) == checkCT) {
			ctTemp++;
		}
	}
	if (ctTemp <= ctInputWord) {
		return 1;
	}
	return 0;
}

void printWordSimilar( char* w) {
	printf("%s\n", w);

}
void printLineSimilar( char* s) {
	printf("%s\n", s);
}
