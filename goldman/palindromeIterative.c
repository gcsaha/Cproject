/**
 * @defgroup   PALINDROMEITERATIVE palindrome Iterative
 *
 * @brief      This file checks whether a string is palindrome or not in iterative method.
 *
 * @author     Gour Chandra Saha
 * @date       20-Dec-2019
 */
#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define MAX_SIZE 1000

bool isPalindrome(char *src)
{
	int len;
	len = strlen(src)-1;
	for(int i=0;i<len/2;i++)
		if(src[i]!=src[len-i-1])
			return false;
	return true;
}

void main()
{
	char src[MAX_SIZE];
	printf("Provide your input string\n");
	fgets(src,MAX_SIZE,stdin);
	if(isPalindrome(src))
	{
		printf("%s is palindrome\n",src);
	}
	else
	{
		printf("%s is not palindrome\n",src);
	}
	// Added comment from VS terminal
}