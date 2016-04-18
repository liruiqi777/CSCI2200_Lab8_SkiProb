/*
 * main.cpp
 *
 *  Created on: Apr 17, 2016
 *      Author: RLi
 */


#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <random>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#define MIN 40
#define MAX 80

using namespace std;

int *skis;
int totalSkis;
int *skiers;
int totalSkiers;

void bucketSort(int *A, int sizeA, int max, int min){
	int range = max - min + 1;
	int *sortedA = new int[range];
	for (int i = 0; i < range+1; i++){
		sortedA[i] = 0;
	}
	for (int i = 0; i < sizeA; i++){
		sortedA[A[i] - 40]++;
	}
	for (int i = 1; i < range+1; i++){
		sortedA[i] = sortedA[i] + sortedA[i-1];
	}
	int index = 0;
	for (int i = 0; i < sizeA; i++){
		while (!(i < sortedA[index])){
			index++;
		}
		A[i] = index + 40;
	}
}

int OPT_recursive(int i, int j){



	return 0;
}


//
//
//int OPT_dynprogr(int i, int j){
//
//}


int main(int argc, char *argv[]){

	// REMEMBER TO FIX
	argc = 10;
	*argv = "20";

	// store command line argument in global variables
	// the amount of skiers is given as argc
	// the amount of pairs of skis is given as argv
	totalSkiers = argc;
	totalSkis = atoi(*argv);

	// initiate the skiers and skis array
	skiers = new int[totalSkiers];
	skis = new int[totalSkis];

	cout << "You entered " << totalSkiers << " " << totalSkis << endl;

	// randomizing height and length array elements
	srand(time(NULL));

	// creating and sorting the skiers height array
	for (int i = 0; i < totalSkiers; i++){
		skiers[i] = rand() % (MAX-MIN+1) + MIN;
		cout << skiers[i] << " ";
	}
	bucketSort(skiers, totalSkiers, MAX, MIN);
	cout << endl;
	for (int i = 0; i < totalSkiers; i++){
		cout << skiers[i] << " ";
	}

	// creating and sorting the skis length array
	for (int i = 0; i < totalSkis; i++){
		skis[i] = rand() % (MAX-MIN+1) + MIN;
	}
	bucketSort(skis, totalSkis, MAX, MIN);

	// calculating the min sum of disparity
	int min = 0;
	min = OPT_recursive(totalSkiers-1, totalSkis-1);

}

