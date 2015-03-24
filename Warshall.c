#include<stdio.h>	// For terminal io
#include<stdlib.h>
#include<stdbool.h>	// For boolean

void warshall(bool matrix[][], int dimension);	// Gets transitive closure of matrix

int main() {
	int n;			// Dimension of square matrix
	bool matrix[n][n];	// n x n matrix

	return(EXIT_SUCCESS);
}

void warshall(bool matrix[][], int dimension) {
	int k, i, j;

	for(k = 0; k <= dimension; k++) {
		for(i = 0; i <= dimension; i++) {
			for(j = 0; j <= dimension; j++) {
				if(matrix[i][j] == true)
					// Element is already true
				else if(matrix[i][k] == true && matrix[k][j] == true)
					matrix[i][j] = true;
			}
		}
	}
	return;	// End returning void
}

void printMatrix(bool matrix[][], int dimension) {

	return;	// Return void
}
