#include <stdio.h>

static int counter;

int* mallocSequence(int size)
{
	int *sequence = malloc( sizeof(int)*size );
	int i;

	//nullifying 
	for( i = 0; i < size; i++ ){
		sequence[i] = 0;
	}

	return sequence;
}

int sequenceSize(int* sequence, int size)
{
	int i;
	for( i = 0; i < size; i++ ){
		if(sequence[i] == 0){
			//if there's space to fill, return the number of empty ones
			return (size - i);
		}
	}
	//return 0 if it's full
	return 0;
}

void initializeCounter()
{
	counter = 0;
}

void increaseCounter()
{
	counter += 1;
}

void decreaseCounter()
{
	counter -= 1;
}


int getCounter()
{
	return counter;
}

void addToSequence(int* sequence, int value)
{
	if(sequenceSize(sequence, 3) > 0){
		sequence[getCounter()] = value;
		increaseCounter();
	}
}

void printSequence(int* sequence)
{
	int i;
	for( i = 0; i < getCounter(); i++ ){
		printf("%d: %d\n", i, sequence[i]);
	}
}

int checkAndPop(int* sequence, int value){
	if(sequence[(getCounter()-1)] == value){
		printf("MATCH!\n");
		sequence[(getCounter()-1)] = 0;
		decreaseCounter();
		if(getCounter() != 0){
			return 1;
		}
		else{
			return 2;
		}
	}
	else{
		printf("Ops, Game Over!\nReturning to main screen...\n");
		return 0;
	}
}