/**
 * @defgroup   PALINDROMERECURSIVE palindrome Recursive
 *
 * @brief      This file checks whether a string is palindrome or not using Recursion.
 *
 * @author     Gour Chandra Saha
 * @date       20-Dec-2019
 */
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#define MAX_SIZE 1000
void prepareReverseString(char *src,char *dest)
{
	if(!src)
		return;
	if(*src == '\0' || *src == '\n')
		return;
	prepareReverseString(src+1,dest-1);
	*dest = *src;
}

bool isPalindrome(char *src)
{
	char dest[MAX_SIZE];
	prepareReverseString(src, &dest[strlen(src) - 2]);
	dest[strlen(src) - 1] = src[strlen(src)-1];

	if(!strcmp(src,dest))
		return true;
	else
		return false;
}

void main()
{
	char src[MAX_SIZE];

	printf("Give input string\n");
	fgets(src,MAX_SIZE,stdin);
	if(isPalindrome(src))
		printf("%s is palindrome\n",src);
	else
		printf("%s is not palindrome\n",src);
}