/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare_dates(char *input1,char *input2)
{
	int index1,result1 = 0,result2=0;
	for (index1 = 6; index1 <10; index1++)
	{
		result1 = (result1 * 10) + input1[index1] - '0';
		result2= (result2 * 10) + input2[index1] - '0';
	}
	if(result1>result2)
	return 2;
	else if(result1==result2)
	{
	result1=0;result2=0;
		for (index1 = 3; index1 <5; index1++)
		{
		result1 = (result1 * 10) + input1[index1] - '0';
		result2= (result2 * 10) + input2[index1] - '0';
		}
		if(result1>result2)
		return 2;
		else if(result1==result2)
		{
		result1=0;result2=0;
			for (index1 = 0; index1 <2; index1++)
			{
			result1 = (result1 * 10) + input1[index1] - '0'	;
			result2= (result2 * 10) + input2[index1] - '0';
			}
			if(result1>result2)	
			return 2;
			else if(result1==result2)
			return 0;
			return 1;
		}
		else
		return 1;
	return 0;
	}
	return 1;
}

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int indexa=0,indexb=0,indexr=0,index,equal=0,ret;
	struct transaction *result;
	if(A!=NULL&&B!=NULL)
	{
		result=(struct transaction *)malloc((ALen+BLen)*sizeof(struct transaction));
		while(indexa!=ALen&&indexb!=BLen)		
		{
			ret=compare_dates(A[indexa].date, B[indexb].date);
			if(ret==1)
			{
				result[indexr]=A[indexa];
			indexr++;
			indexa++;
			}
			else if(ret==2)
			{
			result[indexr]=B[indexb];
			indexr++;
			++indexb;
			}
			else
			{
			result[indexr]=A[indexa];
			indexr++;
			result[indexr]=B[indexb];
			indexr++;
			indexa++;++indexb;			
			}	
		}
		if(indexa!=ALen){
			while(indexa!=ALen)
			{
			result[indexr]=A[indexa];
			indexr++;
			indexa++;
			}		
		}
		if(indexb!=BLen){
			while(indexb!=BLen)
			{
			result[indexr]=B[indexb];
			indexr++;
			indexb++;
			}		
		}
		return result;
	}
	return NULL;
}