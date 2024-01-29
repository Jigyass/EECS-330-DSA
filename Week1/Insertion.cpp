#include<iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
int i,j,key;
for(int i=1; i<n; i++)
{
	key=arr[i]; //set key to which element needs to be sorted
	j=i-1; //set j to just before i
	while(j>=0 && arr[j]>key)
	{
		arr[j+1] = arr[j];
		j--;
	}
	arr[j+1]=key;//since j is the correct position of the element,insert element
}
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}
