#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

//A left rotation operation on an array of size n shifts each of the array's elements 1 unit to the left. For example, if 2 left rotations are performed on array [1, 2, 3, 4, 5], then the array would become [3, 4, 5, 1, 2].
//
//Given an array of n integers and a number, d, perform d left rotations on the array. Then print the updated array as a single line of space-separated integers.
//
//Input Format
	//
	//The first line contains two space-separated integers denoting the respective values of n (the number of integers) and d (the number of left rotations you must perform).
	//The second line contains n space-separated integers describing the respective elements of the array's initial state.
	//
//Constraints
	////
	//1 <= n <= 100000
	//1 <= d <= n
	//1<= a_i <= 1000000
	//
////Output Format
	//
	//Print a single line of  space-separated integers denoting the final state of the array after performing left rotations.
	//
//Sample Input
	//
	//5 4
	//1 2 3 4 5
	//
//Sample Output
	//
	//5 1 2 3 4
	//


void leftRotate(int array[], int arrayLength, int shift);
void printArray(int array[], int arrayLength);

int main(){
    int n;
    int k;
    scanf("%d %d",&n,&k);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    leftRotate(a, n, k);
    printArray(a, n);
    return 0;
}

void leftRotate(int array[], int arrayLength, int shift){
    if (shift >= 1 && shift <= arrayLength && arrayLength >= 1 && arrayLength <= 100000){
        int temp[shift];
        int index = 0;
        for (index = 0; index < shift; index++){
            temp[index] = array[index];
        }
        while (index < arrayLength){
            array[index - shift] = array[index];
            index++;
        }
        while (index-shift < arrayLength){
            array[index-shift] = temp[index-arrayLength];
            index++;
        }
    } else {
        printf("Wrong input... could not process\n");
    }
}

void printArray(int array[], int arrayLength){
    for(int a_i = 0; a_i < arrayLength; a_i++){
        printf("%d ", array[a_i]);
    }
}
