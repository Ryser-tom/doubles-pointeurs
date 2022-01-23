#include <stdio.h>
const int INT_SIZE = 4;

void print(int* s[], int size){
	int i = 0;
	while(i < size){
		printf("%d\n", *s[i]);
		i++;
	}
}

int main(void) {
  int arr[] = { 18, 2, 34, 21, 7, 4 };
	int n = sizeof(arr)/sizeof(arr[0]);
	int *sorted[n];
  
	int i = 0;
	while(i < n){
		sorted[i] = &arr[i];
		i++;
	}

	int k, j;
  for (k = 0; k < n-1; k++){     
		// Last i elements are already in place   
    for (j = 0; j < n-k-1; j++){
      if (*sorted[j] > *sorted[j+1]){
				int* tmp = sorted[j];
				sorted[j] = sorted[j+1];
				sorted[j+1]= tmp;
			}
		}
	}
	print(sorted, n);
  return 0;
} 