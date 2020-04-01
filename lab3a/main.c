#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

char *getstr();
char *getstr2();
char *skipSpace(char *str);
char *copyNumbers(char **from, char *to, int *numflag);
char *copyWords(char **from, char *to,  int *wordflag);
void fun1(char *in, char *outNumbers, char *outWords);
void fun2(char *outNumbers, char *outWords);


int main() {
    char *buf, *outNumbers, *outWords;
    printf("Please, input your string: \n");
    buf = getstr();
    while (buf) {
       printf("Original string: \"%s\"\n", buf);
       //выделяем память под массивы символов - строку со словами и с числами
       outWords = (char *) malloc((strlen(buf)));
       outNumbers = (char *) malloc((strlen(buf)));

       fun1(buf, outNumbers, outWords);
       //вывод строк
       printf("Result string of nums: \"%s\" \n", outNumbers);
       printf("Result string of words: \"%s\" \n", outWords);
       //освобождение памяти
       free(outNumbers);
       free(outWords);
       free(buf);
       fun2(outNumbers,outWords);
       printf("\nPlease, input your next string: \n");
       buf=getstr();}
}


char *getstr() {
    char *ptr = (char *) malloc(1);
    char buf[81];
    int n, len = 0;
    *ptr = '\0';

    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            free(ptr);
            ptr = NULL;
            continue;
        }
        if (n == 0) scanf("%*c");
        else {
            len += strlen(buf);
            ptr = (char *) realloc(ptr, len + 1);
            strncat(ptr, buf, len);
        }
    } while (n > 0);
    return ptr;
}

void fun1(char *in, char *outNumbers, char *outWords){
    int numflag=0, wordflag=0;

    while( *(in = skipSpace(in)) ){
        if(*in >= '0' && *in <= '9'){ //числа
            if(numflag) {
                outNumbers = copyNumbers(&in, outNumbers, &numflag);
                numflag=1;
            }
            if(!numflag)
                outNumbers = copyNumbers(&in, outNumbers, &numflag);

        } else {//слова
            if(wordflag) {
                outWords = copyWords(&in, outWords, &wordflag);
                wordflag=1;
            }
            if(!wordflag)
                outWords = copyWords(&in, outWords, &wordflag);
        }
    }
    *outNumbers = '\0';
    *outWords = '\0';
}

char *skipSpace(char *str)
{
    while(*str && ((*str<'0' || *str>'9') && (*str<'A' || *str>'Z') && (*str<'a' || *str>'z'))){ //пропускаем ненужные символы
        str++;
    }
    return str;
}

char *copyNumbers(char **from, char *to, int *numflag){
    if(*numflag==0) {
        while ((**from >= '0' && **from <= '9')) {
            *to++ = *(*from)++;
        }
        *numflag = 1;
    }else if(*numflag==1){
        *to++ = ' ';
        while ((**from >= '0' && **from <= '9')) {
            *to++ = *(*from)++;
        }
    }
    return to;
}

char *copyWords(char **from, char *to, int *wordflag){
    if(*wordflag == 0) {
        while ((**from >= 'A' && **from <= 'Z') || (**from >= 'a' && **from <= 'z')) {
            *to++ = *(*from)++;
        }
        *wordflag=1;
    } else if(*wordflag == 1){
        *to++ = ' ';
        while ((**from >= 'A' && **from <= 'Z') || (**from >= 'a' && **from <= 'z')) {
            *to++ = *(*from)++;
        }
    }
    return to;
}

//добавить функцию, благодаря которой пользователь задает символ, а программа ищет кол-во повторений его в строке"
void fun2(char *outNumbers, char *outWords) {
    const char *a;
    int p = 0;
    printf("Please, input your symbol: \n");
    a = (getstr());
    //getchar
    if ((*a>= '0') && (*a<= '9')) {
        char *pch;
        pch = strpbrk(outNumbers,a);//first search
        if (pch != NULL)
            p++;
        while (pch != NULL) {
            pch = strpbrk((pch + 1), a);
            p++;
        }
    }
    if((*a>= 'A' && *a <= 'Z') || (*a >= 'a' && *a <= 'z')){
    char *pch2;
    pch2 = strpbrk(outWords, a);//first search
        if (pch2 != NULL)
            p++;
        while (pch2 != NULL) {
            pch2 = strpbrk(pch2 + 1, a);
            p++;
        }
    }
    printf("\nNumber of repetitions: %d\n", p);
}


