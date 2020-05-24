/*************************************************************************
    > File Name: urldecode.c
    > Author: tonywang
    > Mail: wtmmac@gmail.com
    > Created Time: 四 11/27 20:38:36 2014
 ************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* Function: url_decode */
char *url_decode(const char *str) {
  int d = 0; /* whether or not the string is decoded */

  char *dStr = malloc(strlen(str) + 1);
  char eStr[] = "00"; /* for a hex code */

  strcpy(dStr, str);

  while(!d) {
    d = 1;
    int i; /* the counter for the string */

    for(i=0; i<strlen(dStr); ++i) {

      if(dStr[i] == '%') {
        if(dStr[i+1] == 0)
          return dStr;

        if(isxdigit(dStr[i+1]) && isxdigit(dStr[i+2])) {

          d = 0;

          /* combine the next to numbers into one */
          eStr[0] = dStr[i+1];
          eStr[1] = dStr[i+2];

          /* convert it to decimal */
          long int x = strtol(eStr, NULL, 16);

          /* remove the hex */
          memmove(&dStr[i+1], &dStr[i+3], strlen(&dStr[i+3])+1);
//        realloc(&dStr[i+1], strlen(&dStr[i+1])+1);

          dStr[i] = x;
        }
      }
      else if(dStr[i] == '+') { dStr[i] = ' '; }
    }
  }
// free(dStr);
  return dStr;
}

int main()
{
  int size = 1024;
  char *buff = (char*)malloc(size);
 
  while(NULL != fgets(buff, size, stdin)){
    printf("%s", url_decode(buff));
  }

  free(buff);

  return 0;
}