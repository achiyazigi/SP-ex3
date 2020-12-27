#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
int getAline(char s[]){
    bzero(s,LINE);
    char c = getchar();
    int i = 0;
    while(c != '\n' && c != EOF && i <LINE){
        s[i++] = c;
        c = getchar();
    }
    return i;
}

int getword(char w[]){
    memset(w,'\0',WORD);
    char c = getchar();
    int i = 0;
    while(c != '\n' && c != '\t' && c != ' ' && c!= EOF && i <WORD){
        w[i] = c;
        i++;
        c = getchar();
    }
    if(c == '\n' && i>0){
        w[i-1] = '\0';
        return i-1;
    }
    return i;
}

int isEqualString(char s1[], char s2[]){
    for (int i = 0; i < strlen(s2) && i < strlen(s1); ++i) {
        if(s1[i] != s2[i]){
            return 0;
        }
    }
    return 1;
}

int substring(char *str1, char *str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i = 0; i <= len1 - len2; ++i) {
        if(isEqualString(str1 + i, str2))
            return 1;
    }
    return 0;
}

//convert it to dp
int similar(char s[], char t[], int n){
    if(n < 0 || strlen(s) < strlen(t)){
        return 0;
    }
    if(s[0] == '\0'){
        return 1;
    }
    if(s[0] != t[0]){
        n--;
        return similar(s+1, t, n);
    }

    return similar(s+1, t+1, n);
}

void print_lines(char str[]){
    char line[LINE];
    while(getAline(line) > 0){
        if(substring(line,str)){
            printf("%s\n",line);
        }
    }
}

void print_similar_words(char str[]){
    char w[WORD];
    while(getword(w)){
        if(similar(w,str,1)){
            printf("%s\n", w);
        }
    }
}

int main(){
    char firstword[WORD];
    char garbage[WORD];
    getword(firstword);
    char option = getchar();
    getword(garbage);
    getword(garbage);
    if(option == 'a'){
        print_lines(firstword);
        return  0;
    }
    else if(option == 'b'){
        print_similar_words(firstword);
        return 0;
    }
    printf("ilegal input");
    return -1;
}
