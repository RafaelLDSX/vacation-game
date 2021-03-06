#include <stdio.h>

static int counter;

static int difficulty;

static int gameMode; //It stores the game mode being played (0 to player set sequence, 1 to random)

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

void initializeDifficulty()
{
	difficulty = 3;
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

void increaseDifficulty()
{
	difficulty += 1;
}

void decreaseDifficulty()
{
	difficulty -= 1;
}


int getDifficulty()
{
	return difficulty;
}

void addToSequence(int* sequence, int value)
{
	if(sequenceSize(sequence, getDifficulty()) > 0){
		sequence[getCounter()] = value;
		printf("Added %d\n", value);
		increaseCounter();
	}
}

void printSequence(int* sequence)
{
	int i;
	for( i = 0; i < getDifficulty(); i++ ){
		printf("%d: %d\n", i, sequence[i]);
	}
}

int getSequenceValue(int* sequence, int position){
	return sequence[position];
}

int checkAndPop(int* sequence, int value){
	int i;

	//finding index of the input to be checked 
	for( i = 0; sequence[i] == 0 && i < getDifficulty(); i++ ){
	}

	//if there is input to be checked (aka 'i' not out of bounds)
	if(sequence[i] == value){
		printf("MATCH!\n");
		sequence[i] = 0;
		decreaseCounter();
		if(getCounter() == 0){
			increaseDifficulty();
		}
		return 1;
	}
	else{
		printf("Ops, Game Over!\nReturning to main screen...\n");
		return 0;
	}
}

void setGameMode(int i){
	if(i == 0 || i == 1)
		gameMode = i;
	else
		printf("invalid game mode selected\n");
}