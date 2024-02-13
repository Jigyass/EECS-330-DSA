#include<iostream.h>
#include<random.h>

int partition(int A[], int low, int high)
{
	int randomindex = random(low, high);
	swap(&A[low], &A[randomindex]);
	int pivot = A[low];
	int i = low;
	int j = high;

	while(i<j)
	{
	do{i++}while(A[i]<=pivot);
	do{j--}while(A[j]>pivot);
	if(i<j)
		swap(&A[i], &A[j]);
	}
	swap(&A[low], &A[j]);
	return j;
}

void QuickSort(int A[], int low, int high)
{
	if(low<high)
	{
	int PartitionIndex = partition[A, low, high];
	QuickSort(A, low, PartitionIndex);
	QuickSort(A, PartitionIndex+1, high);
	}
}
