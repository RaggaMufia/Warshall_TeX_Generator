#include<stdio.h>	// For terminal io
#include<stdlib.h>

int readMatrix(char* inputFileName);	// Creates matrix from file contents, retuns dimensions
void warshall(char** matrix, int dimension);		// Gets transitive closure of matrix
void printMatrix(char** matrix, int dimension, char* outputFileName);	// Output matrix to file

int main() {
	int dimensions;	// Dimension of square matrix
	char **matrix;	// n x n matrix
	char inputFileName[] = "input.txt";	// Name of input file
	char outputFileName[] = "output.tex";	// Name of output file

	dimensions = readMatrix(inputFileName);
//	printMatrix(matrix, dimensions, outputFileName);

/*	
	matrix = malloc(n * sizeof *matrix);
	for (i = 0; i < n; i++)
		matrix[i] = malloc(n * sizeof *matrix[i]);
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			matrix[i][j] = '0';
		}
	}
*/
	return(EXIT_SUCCESS);
}

int readMatrix(char* inputFileName) {
	FILE* file = fopen(inputFileName, "r");	// Opens file in read mode
	int dimension;	// Order of matrix
	int i, j;	// column and row
	char** matrix;	// matrix of order [dimension]
	
	// Check for errors opening file
	if(!file) {
		printf("Error! Could not open input file.\n");
		exit(-1);	// Exit with error code
	}
	
	// Read order of matrix
	fscanf(file, "%i", &dimension);
	
	// Allocate memory for matrx
	matrix = (char**)malloc(dimension * sizeof(char*));
	for(i = 0; i < dimension; i++)
		matrix[i] = (char*)(dimension * sizeof(char));

	// Initialize each element in the array with '0'
	for(i = 0; i < dimension; i++) {
		for(j = 0; j < dimension; j++)
			matrix[i][j] = '0';
	}

//	while(file)  {
		// Reset variables
		i = 0;
		j = 0;
		// Read new coordinates from file
//		fscanf(file, "%i", &i);
//		fscanf(file, "%i", &j);
//		matrix[0][0] = '1';
//	}

	fclose(file);		// Close input file
	return dimension;	// Return order of matrix 
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
	return;	// Return void
}

void printMatrix(char** matrix, int dimension, char* outputFileName) {
	int i, j;
	FILE* file = fopen(outputFileName, "w");	// Open output file in write mode

	// Check for successful open/creation
	if(!file) {
		printf("Error! Could not open outputFile.\n");
		exit(-2);
	}

	fprintf(file, "\\begin{bmatrix}");
	for(i = 0; i < dimension; i++) {
		fprintf(file, "\n");
		for(j = 0; j < dimension; j++) {
			if(j == dimension - 1)	// End of row
				fprintf(file, "%c\\\\", matrix[i][j]);
			else
				fprintf(file, "%c&\t", matrix[i][j]);
		}
	}

	return;	// Return void
}
