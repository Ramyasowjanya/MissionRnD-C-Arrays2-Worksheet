/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int indexa=0,indexb=0,count=0,index,equal=0;
	struct transaction *result;
	if(A!=NULL&&B!=NULL)
	{	
		if(ALen>BLen)
		result=(struct transaction *)malloc(BLen*sizeof(struct transaction));
		else
		result=(struct transaction *)malloc(ALen*sizeof(struct transaction));
		while(indexa!=ALen||indexb!=BLen)		
		{
		equal=0;
			for(index=0;index<10;index++)		
			{
				if(A[indexa].date[index]==B[indexb].date[index])
					equal=1;
				else
				{
					equal=0;break;		
				}	
			}
			if(equal==1){
			result[count]=A[indexa];
			count++;
			indexa++;++indexb;
			}
			else{
			++indexb;			
			}	
			if(indexb==BLen&&indexa!=ALen){
			indexb=0;indexa++;
			}		
		}
		if(count==0)
		return NULL;
		return result;
	}
	return NULL;
}