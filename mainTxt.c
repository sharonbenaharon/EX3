#include <stdio.h>
#include <string.h>                                                            
#include <stdlib.h>                                                            
#include <ctype.h> 
#include "txtfind.h"



int main() {

	char inputOP;
	char inputWord[WORD_LEN_MAX];
	char w[WORD_LEN_MAX];
	char s[LINE_LEN_MAX];
	int ansLine;
	char fileName[WORD_LEN_MAX];
	int n;
	int lenA = 1;
	int ans;
	int i = 0;


	
		getWord(w);
		strcpy(inputWord, w);
		getWord(w);
		inputOP = *(w + i);
	
		if (inputOP == 'a') {
			printf("some characters you want to check?\n");
			scanf("%d", &n);
			ans = getWord(w);
			while (lenA!=0) {
				ans = getWord(w);
				int ansWord = similarCheck(w, inputWord, n);
				if (ansWord == 1) {
				printWordSimilar(w);
				}
				lenA = ans;
			}
			
		}
		int lenB = 1;
		if (inputOP == 'b') {
			while (lenB != 0) {
				ans = getLine(s);
				ansLine = containStringCheak(s, inputWord);
				if (ansLine == 1) {
					printLineSimilar(s);
				}
				lenB = ans;
			}
			
		}
	

	return 0;
}
