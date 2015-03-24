#include<stdio.h>	// For terminal io
#include<stdlib.h>
#include<stdbool.h>	// For boolean

void warshall(bool matrix[][], int dimensions);	// Gets transitive closure of matrix

int main() {
	int n;
	bool matrix[n][n];	// n x n matrix

	return(EXIT_SUCCESS);
}

void warshall(bool matrix[][], int dimensions) {
	int k, i, j;

	for(k = 0; k <= dimensions; k++) {
		for(i = 0; i <= dimensions; i++) {
			for(j = 0; j <= dimensions; j++) {
				if(matrix[i][j] == true)
					// Element is already true
				else if(matrix[i][k] == true && matrix[k][j] == true)
					matrix[i][j] = true;
			}
		}
	}
}
