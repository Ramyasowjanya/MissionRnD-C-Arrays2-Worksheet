/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

int findSingleOccurenceNumber(int *A, int len) {
	int start=0,end=len-1,repeat=0;
	if(A)
	{
		while(start!=end)
		{
			if(A[start]==A[end]){
			A[end]=0;repeat=1;}
			if((start==end-1&&repeat==1)||A[start]==0)	
			{
			repeat=0;
			start++;end=len;
			}
		end--;	
		}
	return A[end];
	}
	return -1;
}