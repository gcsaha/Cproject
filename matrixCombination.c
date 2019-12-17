/**
 * @defgroup   MATRIXCOMBINATION matrix Combination
 *
 * @brief      This file implements matrix Combination.
 *
 * Source : https://www.careercup.com/question?id=5651887483781120
 * Given a matrix, find all its combinations by row. For example,
 * [a, b, c]
 * [d, e, f]
 * [x, y, z]
 * 
 * its combinations are adx, ady, adz, bdx, …. cfy, cfz
 * 
 * @author     Gour Chandra Saha
 * @date       17-Dec-2019
 */
#include<stdio.h> 
char a[3][3] = {{'a','b','c'},
				{'d','e','f'},
				{'x','y','z'}};

void main()
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				printf("%c%c%c\n",a[0][i],a[1][j],a[2][k]);
			}
		}
	}
}