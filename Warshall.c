#include<stdio.h>	// For terminal io
#include<stdlib.h>

int readMatrix(char** matrix, char* inputFileName);	// Creates matrix from file contents, retuns dimensions
void warshall(char** matrix, int dimension);		// Gets transitive closure of matrix
void printMatrix(char** matrix, int dimension, FILE* outputFile);	// Output matrix to file

int main() {
	int dimensions;	// Dimension of square matrix
	char **matrix;	// n x n matrix
	char[] inputFileName = "input.txt";	// Name of input file
	char[] outputFileName = "output.tex";	// Name of output file

	FILE *inputFile = fopen("input.txt", "r");	// Input file
	FILE *outputFile = fopen("output.tex", "w");	// Output file

	/* allocate the array */
	matrix = malloc(n * sizeof *matrix);
	for (i = 0; i < n; i++)
		matrix[i] = malloc(n * sizeof *matrix[i]);
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			matrix[i][j] = '0';
		}
	}

	return(EXIT_SUCCESS);
}

int readMatrix(char** matrix, char* inputFileName) {
	FILE* inputFile = fopen(inputFileName, "r");	// Opens file in read mode
}

void warshall(char** matrix, int dimension) {
	int k, i, j;

	for(k = 0; k < dimension; k++) {
		for(i = 0; i < dimension; i++) {
			for(j = 0; j < dimension; j++) {
				if(matrix[i][j] == '1') {
				}
				else if(matrix[i][k] == '1' && matrix[k][j] == '1')
					matrix[i][j] = '1';
			}
		}
	}
	return;	// End returning void
}

void printMatrix(char** matrix, int dimension, FILE* outputFile) {
	int i, j;

	fprintf(outputFile, "\\begin{bmatrix}");
	for(i = 0; i < dimension; i++) {
		fprintf(outputFile, "\n");
		for(j = 0; j < dimension; j++) {
			if(j == dimension - 1)	// End of row
				fprintf(outputFile, "%c\\\\", matrix[i][j]);
			else
				fprintf(outputFile, "%c&\t", matrix[i][j]);
		}
	}

	return;	// Return void
}
