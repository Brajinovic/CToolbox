#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int *allocateArray(int numberOfElements){
	// allocate an array
	int* array =(int*)malloc(numberOfElements * sizeof(int));
	if(array == NULL){
		printf("Error allocating array!");
		return -1;
	}
	return array;
}


int **allocateMatrix(int rows, int columns){
	// allocate a 2d array
	int **C;
	C = (int**)malloc(rows * sizeof(int*));
	if(C == NULL){
		printf("Error allocating memory 2 dimensional array!");
		return -1;
	}
	for(int i = 0; i < rows; i++){
		C[i] = (int*)malloc(columns * sizeof(int));
		if(C[i] == NULL){
			printf("Error allocating memory 2 dimensional array!");
			return -1;
		}
	}

	return C;
}


void fillArrayRandomInt(int *array, int numberOfElements){
	// fill the array with random numbers
	for(int i = 0; i < numberOfElements; i++){
		array[i] = (rand() % 100) + 1;
	}
}


void fillMatrixRandomInt(int **matrix, int numberOfRows, int numberOfColumns){
	for(int i = 0; i < numberOfRows; i++){
		fillArrayRandomInt(matrix[i], numberOfColumns);
	}
}


void printArray(int *array, int sizeOfArray){
	// tester function for printing an array
	for(int i = 0; i < sizeOfArray; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}


void printMatrix(int **array, int numberOfRows, int numberOfColumns){
	for(int i = 0; i < numberOfRows; i++){
		printArray(array[i], numberOfColumns);
	}
}


int selectionSearch(int *array, int sizeOfArray, int number){
	// selection search algorithm for searching an element in an array
	for(int i = 0; i < sizeOfArray; i++){
		if(array[i] == number){
			return i;
		}
	}

	return -1;
}


int binarySearch(int *array, int sizeOfArray, int number){
	// binary search algorithm for searching an elememnt in an array
	int bottomBorder = 0;
	int topBorder = sizeOfArray - 1;
	int s;

	while(bottomBorder <= topBorder){
		s = (topBorder + bottomBorder) / 2;
		if(array[s] == number){
			return s;
		}else if(array[s] > number){
			topBorder = s - 1;
		}else{
			bottomBorder = s + 1;
		}
	}

	return -1;
}


void swap(int *firstNumber, int *secondNumber){
	// simple swap function, swaps 2 elements -> thier values
	int temp = *firstNumber;
	*firstNumber = *secondNumber;
	*secondNumber = temp;
}


void selectSort(int *array, int sizeOfArray){
	// selection sort sorting algorithm for an array
	for(int i = 0; i < sizeOfArray - 1; i++){
		for(int j = i + 1; j < sizeOfArray; j++){
			if(array[i] > array[j]){
				swap(&array[i], &array[j]);
			}
		}
	}
}




int **multiplyMatrix(int **A, int rowsA, int columnsA, int **B, int columnsB){
	// function for multiplying 2 matrices
	int **C = allocateMatrix(rowsA, columnsB);
	for(int i = 0; i < rowsA; i++){
		for(int j = 0; j < columnsB; j++){
			C[i][j] = 0;
			for(int k = 0; k < columnsA; k++){
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	return C;
}


void testArray(){
	// function to test the array algorithms

	// number of elements
	int numberOfElements = 10;
	// allocate the memory for the field
	int *array = allocateArray(numberOfElements);
	srand(time(NULL));
	// fill the field with random numbers
	fillArrayRandomInt(array, numberOfElements);
	// test the array algorithms
	testArray(array, numberOfElements);
	

	// print the unsorted array
	printArray(array, numberOfElements);
	// sort the array
	selectSort(array, numberOfElements);
	// print the sorted array
	printArray(array, numberOfElements);
	// print the indexes of the elements that we seek
	printf("%d\n", selectionSearch(array, numberOfElements, 72));
	printf("%d\n", binarySearch(array, numberOfElements, 72));
	
}


void testMatrix(){
	// create 2 matrices
	int **A = allocateMatrix(3, 2);
	int **B = allocateMatrix(2, 3);
	// fill them with random int
	fillMatrixRandomInt(A, 3, 2);
	fillMatrixRandomInt(B, 2, 3);
	// print them out
	printMatrix(A, 3, 2);
	printMatrix(B, 2, 3);

	
	

	printMatrix(multiplyMatrix(A, 3, 2, B, 3), 3, 3);
	
}



int main(void){

	//testArray();
	testMatrix();
	
	return 0;
}