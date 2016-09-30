/*#include <stdio.h>
int strend(char *s,char *t, int i)
{
    while(*s!='\0')
        s++;
    s--;
    while(*t!='\0')
        t++;
    t--;
    while(i>0)
    {
        if(*t==*s)
        {
            t--;
            s--;
            i--;
        }
        else
            return 0;
    }
    return 1;
}
void main()
{
   char s[] = "lapicero", t[] = "cero";
   int a;
   a = strend(s,t,4);
   printf("%d",a);
}*/
