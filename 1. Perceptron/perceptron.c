#include <stdio.h>
#include <math.h>

// calculating dot product of two vectors
void dotp(double dst[3], double W[3][3], double I[3])
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			dst[i] += (W[i][j] * I[j]);
		}
	}
}

// sigmoid function
void sigmoid(double dst[3], double source[3])
{
	for (int i = 0; i < 3; i++) {
		dst[i] = exp(source[i]) / (1.0 + exp(source[i]));
	}
}

// printing an array (n by 1)
void printarr(double* arr) {
	for (int i = 0; i < 3; i++) {
		printf("%f ", arr[i]);
	}
	printf("\n\n");
}

// printing an array (3 by 3)
void printarr3(double arr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++){
			printf("%f ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

// main Function
void main() {
	// Inputs and Weigts (임의의 값)
	double I[3] = { 0.3, 0.7, 0.2 };
	printf("I = \n");
	printarr(I);
	double W_ith[][3] = { {0.1, 0.5, 0.3}, {0.2, 0.4, 0.9}, {0.7, 0.3, 0.8} };
	printf("W (Input-to-Hidden) = \n");
	printarr3(W_ith);
	double W_hto[][3] = { {0.9, 0.8, 0.4}, {0.5, 0.1, 0.3}, {0.2, 0.6, 0.4} };
	printf("W (Hidden-to-Output) = \n");
	printarr3(W_hto);

	// Inputs and Weights (임의의 값 2)
	/*
	double I[3] = { 0.9, 0.1, 0.8 };
	printf("I = \n");
	printarr(I);
	double W_ith[][3] = { {0.9, 0.3, 0.4}, {0.2, 0.8, 0.2}, {0.1, 0.5, 0.6} };
	printf("W (Input-to-Hidden) = \n");
	printarr3(W_ith);
	double W_hto[][3] = { {0.3, 0.7, 0.5}, {0.6, 0.5, 0.2}, {0.8, 0.1, 0.9} };
	printf("W (Hidden-to-Output) = \n");
	printarr3(W_hto); 
	*/

	//init
	double X_h[3] = { 0.0,0.0,0.0 };
	double X_o[3] = { 0.0,0.0,0.0 };
	double O_h[3] = { 0.0,0.0,0.0 };
	double O_o[3] = { 0.0,0.0,0.0 };

	dotp(X_h, W_ith, I);
	printf("X Hidden: \n");
	printarr(X_h); printf("\n");

	sigmoid(O_h, X_h);
	printf("O Hidden: \n");
	printarr(O_h); printf("\n");

	dotp(X_o, W_hto, O_h);
	printf("X Output: \n");
	printarr(X_o); printf("\n");

	sigmoid(O_o, X_o);
	printf("O Output: \n");
	printarr(O_o);
	
	return;

}
