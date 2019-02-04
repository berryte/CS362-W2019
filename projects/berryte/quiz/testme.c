/*
 * Author: Terence Berry
 * Date: 2/4/19
 * File: testme.c
 * Description: Random Test Quiz - Implement a random tester for the function
 * testme() in testme.c. Your random tester will print the output of any 
 * error messages. You should implement inputChar() and inputString() to 
 * produce random values.
 *
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    int ranNum; //random number to generate a char
    int lowBound = 32; //on ascii table this is the lowest printable char ' '
    int upBound = 126; //on ascii table - highest printable char '~'
    ranNum = (rand() % (upBound - lowBound + 1)) + lowBound; //generate random num
    char randomChar = ranNum; //convert to char
    return randomChar;
}

char *inputString()
{
    static char str[6]; //string to return (needs to be a static/constant size)
    int lengthMax = sizeof(str); //string length
    memset(str, '\0', lengthMax); //initialize with null

    /*Fill string with random characters*/
    int i;
    for(i = 0; i < lengthMax -1; i++){
        str[i] = inputChar();
    }
    return str;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
