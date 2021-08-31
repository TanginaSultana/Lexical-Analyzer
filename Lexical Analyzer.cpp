#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
bool isValidOperator(char ch){
   if (ch == '+' || ch == '-' || ch == '*' ||
   ch == '/' || ch == '>' || ch == '<' ||
   ch == '=')
   return (true);
   return (false);
}

bool isValidKeyword(char* str) {
   if (!strcmp(str, "if") || !strcmp(str, "else") || !strcmp(str, "while") || !strcmp(str, "do") ||    !strcmp(str, "break") || !strcmp(str, "continue") || !strcmp(str, "int")
   || !strcmp(str, "double") || !strcmp(str, "float") || !strcmp(str, "return") || !strcmp(str,    "char") || !strcmp(str, "case") || !strcmp(str, "char")
   || !strcmp(str, "sizeof") || !strcmp(str, "long") || !strcmp(str, "short") || !strcmp(str, "typedef") || !strcmp(str, "switch") || !strcmp(str, "unsigned")
   || !strcmp(str, "void") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "goto"))
   return (true);
   return (false);
}


int main(){
   char str[100] = "int a = b * 1c + 10 ; ";
   char str1[15];
   char str2[15];
   printf("The Program is : '%s' \n", str);
   int x=strlen(str);

   for(int i=0;i<x;i++)
   {
       if(str[i]>=97 && str[i]<=122){
        int p=0;
        while(str[i]!= ' '){
            str1[p]=str[i];
            p++;
            i++;
        }
        if(isValidKeyword(str1) == true)
            printf("Keyword : '%s'\n", str1);
        else
        {
            printf("Valid Identifier : '");
            for(int t=0;t<p;t++)
            {
                printf("%c",str1[t]);
            }
            printf("'\n");
        }

       }
       if (isValidOperator(str[i]) == true)
         printf("Operator : '%c'\n", str[i]);

       if(str[i] >= 48 && str[i] <= 57)
       {
           int p=0,q=0,r=0;
           while(str[i]!= ' '){
             // check for alphabets
             if (isalpha(str[i]) != 0)
                p++;

            // check for decimal digits
             else if (isdigit(str[i]) != 0)
                q++;
            str2[r]=str[i];
            r++;
            i++;
           }
        if(q==r){
            printf("Constant : '");
            for(int t=0;t<q;t++)
            {
                printf("%c",str2[t]);
            }
            printf("'\n");
        }
        else
        {
            printf("InValid Identifier : '");
            for(int t=0;t<r;t++)
            {
                printf("%c",str2[t]);
            }
            printf("'\n");
        }

       }

       if(str[i]==' ')
        continue;

       if(str[i]==';')
          printf("Punctuation : '%c'\n", str[i]);
   }
   return (0);
}

