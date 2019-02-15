/*
 * source.cpp
 *
 *  Created on: Feb 8, 2019
 *      Author: hhazl
 */
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

enum direction{LEFT_RIGHT, RIGHT_LEFT, DOWN, UP, RIGHT_DOWN, RIGHT_UP, LEFT_DOWN, LEFT_UP};

const int MAX = 50;

struct wordGame{
	int version;
	int numberRows;
	int numberColumns;
	char puzzle[MAX][MAX];
};

struct wordFind{
	string word;
	bool found;
	int row;
	int column;
	direction where;
	int foundCount;
};

bool readPuzzle(wordGame &game, string inputFileName){
	game.version = 2;
	ifstream inFS;
	//open file and check if it opened successfully
	inFS.open(inputFileName);
	if(!inFS){
		inFS.close();
		return false;
	}

	vector<string> charList;
	string charString;

	//get puzzle dimensions from file
	inFS >> game.numberRows;
	inFS >> game.numberColumns;

	//check that puzzle dimensions are valid
	if (game.numberRows < 1 || game.numberRows > MAX || game.numberColumns < 1 || game.numberColumns > MAX){
		inFS.close();
		return false;
	}

	//read puzzle from file
	for (int i = 0; i < game.numberRows; i++){
		inFS >> charString;
		charList.push_back(charString);
	}
	inFS.close();

	//assign puzzle values to array in game struct
	for (int i = 0; i < game.numberRows; i++){
		for (int j = 0; j < game.numberColumns; j++){
			game.puzzle[i][j] = toupper(charList.at(i).at(j));
		}
	}

	return true;
}

void displayPuzzle(wordGame &game){
	//print contents of puzzle
	for (int i = 0; i < game.numberRows; i++){
		for (int j = 0; j < game.numberColumns; j++){
			cout << game.puzzle[i][j];
		}
		cout << endl;
	}
	return;
}


void findWord(wordGame &game, wordFind &theFind){
	int wordLength;
	theFind.foundCount = 0;
	theFind.found = false;

	wordLength = theFind.word.length();

	//check if word exists in puzzle in any of 8 directions
	if (game.numberColumns >= wordLength){
		for (int i = 0; i < game.numberRows; i++){
			for (int j = 0; j <= game.numberColumns - wordLength; j++){
				for (int k = 0; k < wordLength; k++){
					if (game.puzzle[i][j + k] != theFind.word.at(k)){
						break;
					}
					else if (k == wordLength - 1){
						theFind.found = true;
						theFind.foundCount += 1;
						theFind.row = i + 1;
						theFind.column = j + 1;
						theFind.where = LEFT_RIGHT;
					}
				}
			}
			for (int j = game.numberColumns - 1; j + 1 >= wordLength; j--){
				for (int k = 0; k < wordLength; k++){
					if (game.puzzle[i][j - k] != theFind.word.at(k)){
						break;
					}
					else if (k == wordLength - 1){
						theFind.found = true;
						theFind.foundCount += 1;
						theFind.row = i + 1;
						theFind.column = j + 1;
						theFind.where = RIGHT_LEFT;
					}
				}
			}
		}
	}
	if (game.numberRows >= wordLength){
		for (int i = 0; i < game.numberColumns; i++){
			for (int j = 0; j <= game.numberRows - wordLength; j++){
				for (int k = 0; k < wordLength; k++){
					if (game.puzzle[j + k][i] != theFind.word.at(k)){
						break;
					}
					else if(k == wordLength - 1){
						theFind.found = true;
						theFind.foundCount += 1;
						theFind.row = j + 1;
						theFind.column = i + 1;
						theFind.where = DOWN;
					}
				}
			}
			for (int j = game.numberRows - 1; j + 1 >= wordLength; j--){
				for (int k = 0; k < wordLength; k++){
					if (game.puzzle[j - k][i] != theFind.word.at(k)){
						break;
					}
					else if (k == wordLength - 1){
						theFind.found = true;
						theFind.foundCount += 1;
						theFind.row = j + 1;
						theFind.column = i + 1;
						theFind.where = UP;
					}
				}
			}
		}
	}
	if (game.numberColumns >= wordLength && game.numberRows >= wordLength){
		for (int i = 0; i <= game.numberRows - wordLength; i++){
			for (int j = 0; j <= game.numberColumns - wordLength; j++){
				for (int k = 0; k < wordLength; k++){
					if (game.puzzle[i + k][j + k] != theFind.word.at(k)){
						break;
					}
					else if (k == wordLength - 1){
						theFind.found = true;
						theFind.foundCount += 1;
						theFind.row = i + 1;
						theFind.column = j + 1;
						theFind.where = RIGHT_DOWN;
					}
				}
			}
			for (int j = game.numberColumns - 1; j + 1 >= wordLength; j--){
				for (int k = 0; k < wordLength; k++){
					if (game.puzzle[i + k][j - k] != theFind.word.at(k)){
						break;
					}
					else if(k == wordLength - 1){
						theFind.found = true;
						theFind.foundCount += 1;
						theFind.row = i + 1;
						theFind.column = j + 1;
						theFind.where = LEFT_DOWN;
					}
				}
			}
		}
		for (int i = game.numberRows - 1; i + 1 >= wordLength; i--){
			for (int j = 0; j <= game.numberColumns - wordLength; j++){
				for (int k = 0; k < wordLength; k++){
					if (game.puzzle[i - k][j + k] != theFind.word.at(k)){
						break;
					}
					else if (k == wordLength - 1){
						theFind.found = true;
						theFind.foundCount += 1;
						theFind.row = i + 1;
						theFind.column = j + 1;
						theFind.where = RIGHT_UP;
					}
				}
			}
			for (int j = game.numberColumns - 1; j + 1 >= wordLength; j--){
				for (int k = 0; k < wordLength; k++){
					if (game.puzzle[i - k][j - k] != theFind.word.at(k)){
						break;
					}
					else if (k == wordLength - 1){
						theFind.found = true;
						theFind.foundCount += 1;
						theFind.row = i + 1;
						theFind.column = j + 1;
						theFind.where = LEFT_UP;
					}
				}
			}
		}
	}

	return;
}

int main(){
	ifstream inFS;
	string firstInput;
	string secondInput;
	wordGame game;
	wordFind wordToFind;

	//get name of puzzle file
	cin >> firstInput;

	if (readPuzzle(game, firstInput)){
		//display puzzle file
		cout << "The puzzle from file \"" << firstInput << "\"" << endl;
		displayPuzzle(game);

		//get name of words file and check if it opened successfully
		cin >> secondInput;
		inFS.open(secondInput);
		if (!inFS){
			cout << "The puzzle file \"" << secondInput << "\" could not be opened or is invalid" << endl;
			inFS.close();
		}
		else{
			//take each word from the words file and search for it in the puzzle
			while (inFS >> wordToFind.word){
				for (int i = 0; i < (int)wordToFind.word.length(); i++){
					wordToFind.word.at(i) = toupper(wordToFind.word.at(i));
				}
				findWord(game, wordToFind);
				//display the results of the word search
				if (wordToFind.found){
					if (wordToFind.foundCount == 1){
						cout << "The word " << wordToFind.word << " was found at (" << wordToFind.row << ", " << wordToFind.column << ") - ";
						switch (wordToFind.where){
							case LEFT_RIGHT:
								cout << "right" << endl;
								break;
							case RIGHT_LEFT:
								cout << "left" << endl;
								break;
							case UP:
								cout << "up" << endl;
								break;
							case DOWN:
								cout << "down" << endl;
								break;
							case RIGHT_DOWN:
								cout << "right/down" << endl;
								break;
							case RIGHT_UP:
								cout << "right/up" << endl;
								break;
							case LEFT_DOWN:
								cout << "left/down" << endl;
								break;
							case LEFT_UP:
								cout << "left/up" << endl;
								break;
						}
					}
					else{
						cout << "The word " << wordToFind.word << " was found " << wordToFind.foundCount << " times" << endl;
					}
				}
				else{
					cout << "The word " << wordToFind.word << " was not found" << endl;
				}
			}
			inFS.close();
		}
	}
	else{
		cout << "The puzzle file \"" << firstInput << "\" could not be opened or is invalid" << endl;
	}

	return 0;
}
