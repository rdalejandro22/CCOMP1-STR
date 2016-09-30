#include <stdio.h>
/*void strcpy(char *s, char *t, int n)
{
    int i=0;

    while(i<n){
            *s = *t;
            s++;
            t++;
            i++;
    }
    *s = '\0';
}*/
/*int strncmp(char *s, char *t, int n)
{
    for(;*s==*t && n>0 ;s++,t++,n--)
    {
        if(*s=='\0')
            return 0;
    }
    return *s-*t;
}*/
int strncmp(char *s, char *t, int n);
void strcpy(char s[], char t[], int n);
/*void main()
{
   char s[] = "flumpo", t[] = "cachito";
   int n;
   n=2;
   strcpy(s,t,n);
   printf("%s",s);
}
*//*
void main()
{
   char s[] = "abcdef", t[] = "ABCDEF";
   int n,a;
   n=3;
   a = strncmp(s,t,n);
   printf("%d",a);
}*/
void strcat(char *s, char *t,int i) {
    while(*s != '\0')
        s++;
    while(i>0){
        *s++=*t++;
        i--;}
        ;
}
void strcat(char s[], char t[], int i);
void main()
{
   char s[] = "perro", t[] = "gato";
   strcat(s,t,3);
   printf("%s",s);
}
