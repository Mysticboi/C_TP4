#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int nbLines(FILE* stream){
    char c;
    int i=0;
    int a=ftell(stream);
    while((c=fgetc(stream))!=EOF){
        if(c=='\n'){
            i++;
        }
    }
    int f=ftell(stream)-a;
    //rewind(stream);
    fseek(stream,-f,SEEK_CUR);
    return i;
}

int main(int argc, char const *argv[])
{
    srandom(time(NULL));
    FILE* colonne1=fopen("colonne1.txt","r");
    FILE* colonne2=fopen("colonne2.txt","r");
    FILE* colonne3=fopen("colonne3.txt","r");
    FILE* colonne4=fopen("colonne4.txt","r");
    FILE* discours=fopen("discours.txt","w");
    int j;
    for(j=0; j<5; j++){
        char s1[100];
        char s2[100];
        char s3[100];
        char s33[100];
        char s4[100];
        int c1=(random() % (nbLines(colonne1)))+1 ;
        int c2=(random() % (nbLines(colonne2)))+1;
        int c3=(random() % (nbLines(colonne3)))+1;
        int c33=(random() % (nbLines(colonne3)))+1;
        int c4=(random() % (nbLines(colonne4)))+1;
        int i;
        for(i=0; i<c1; i++){
            fgets(s1,1000,colonne1);
        }
        rewind(colonne1);
        for(i=0; i<c2; i++){
            fgets(s2,1000,colonne2);
        }
        rewind(colonne2);
        for(i=0; i<c3; i++){
            fgets(s3,1000,colonne3);
        }
        rewind(colonne3);
        for(i=0; i<c4; i++){
            fgets(s4,1000,colonne4);
        }
        rewind(colonne4);
        fputs(s1,discours);
        fputs(s2,discours);
        fputs(s3,discours);
        fputs(s4,discours);
        /*printf("%s",s1);
        printf("%s",s2);
        printf("%s",s3);
        printf("%s",s4);
        */
        fputc('\n',discours);
    }
    fclose(colonne1);
    fclose(colonne2);
    fclose(colonne3);
    fclose(colonne4);
    fclose(discours);
    return 0;
}
