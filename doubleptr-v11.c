#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char **p = NULL; //Double Pointer
	char input[30]; 
	int rows, len, i, j;
	//ask user for number of rows
	printf("Enter no of rows\n");
	scanf("%d", &rows);

	//Allocate memory for rows dynamically
	p = (char **) malloc(rows * sizeof(char *));
	if(p == NULL) {
		printf("Malloc for rows failed\n");
		return -1;
	}
	printf("Memory for %d rows allocated\n", rows);
	
	//Take input for all rows and allocate memory based on the input dynamically	
	for(i=0; i<rows; ++i) {
		printf("enter the input\n");
		scanf("%s", input);
		len = strlen(input) + 1;
		p[i] = (char *)malloc(len * sizeof(char));
		if(p[i] == NULL) {
			printf("malloc failed for p[%d]\n", i);
			//free previous rows memory 
			for(j = i-1; j>=0; --j) {
				free(p[j]);
			}
			free(p);
			return -1;
		}
		printf("memory allocatted for p[%d]\n", i);
		strcpy(p[i], input);
		printf("Data copied to p[%d]\n", i);
	}
	//printing all rows
	for(i=0; i<rows; ++i) {
		printf("Data in p[%d] = %s\n", i, p[i]);
	}

	//free all dynamic memory allocations
	//Free all rows in reverse manner of allocation p[i]
	//Free memory for double ptr p

	for(i=rows-1; i>=0; --i) {
		printf("Memory for p[%d] is freed\n", i);
		free(p[i]);
	}

	free(p);
	printf("Memory for dble ptr is freed\n");
	return 0;
}
