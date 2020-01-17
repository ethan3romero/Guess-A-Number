// guessanumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// Variables
int minNumber{ 1 };
int maxPrompt{ 10 };
int maxNumber{ 10 };
int minLimit{ 10 };
int maxLimit{ 100 };
char advancedPrompt{};
int promptGuess{ 0 };
int guesses{ 0 };
int addGuess{ 1 };
int randomNumber{ 0 };
int correctNumber{ 0 };
int minGuess{ 0 };
int health{ 3 };
int subHealth{ 1 };
const int healthOut{ 0 };
char restartPrompt{};
const int resetHealth{ 3 };
const int resetGuess{ 0 };

char selection{};

//

void advancedFun() {
	//Advanced Prompt

	do {
		cout << "Would you like to play an advanced version of the game?" << endl;
		cin >> advancedPrompt;
		advancedPrompt = toupper(advancedPrompt);

		if (advancedPrompt == 'Y') {

			do {
				cout << "Please enter a number between " << minLimit << " and " << maxLimit << endl;
				cin >> maxPrompt;

				if (maxPrompt > maxLimit || maxPrompt < minLimit) {
					cout << "Please enter a valid number between " << minLimit << " and " << maxLimit << endl;
				}
				else {
					maxNumber = maxPrompt;
				}
			} while (maxPrompt > maxLimit || maxPrompt < minLimit);
		}
		else if (advancedPrompt != 'Y' && advancedPrompt != 'N') {
			cout << "Please enter a valid response" << endl;
		}
	} while (advancedPrompt != 'Y' && advancedPrompt != 'N');

	//
}

void randomNum() {
	//Randomize Number, set correct Number

	srand((unsigned int)time(NULL));

	randomNumber = rand() % maxNumber + minNumber;

	correctNumber = randomNumber;

	//
}

void startGame() {
	// Start the game
	// All code for the actual game in here

	do {

		if (guesses == minGuess) {
			cout << "Start the game? (y/n)" << endl;
			cin >> selection;
			selection = toupper(selection);
		}
		else if (guesses > minGuess) {
			cout << "Resume the game? (y/n)" << endl;
			cin >> selection;
			selection = toupper(selection);
		}

		if (selection == 'Y') {

			do {


				cout << "Please guess a number between 1 and " << maxNumber << endl;
				cin >> promptGuess;

				if (promptGuess >= minNumber && promptGuess <= maxNumber) {
					if (promptGuess == correctNumber) {
						guesses = guesses + addGuess;
						cout << "You got it right in " << guesses << " guesses." << endl;
						break;
					}
					else if (promptGuess > correctNumber) {
						guesses = guesses + addGuess;
						health = health - subHealth;
						if (health == healthOut) {
							break;
						}
						cout << "You guessed too high, you have " << health << " health left." << endl;
						cout << "Try again? (y/n)" << endl;
						cin >> selection;
						selection = toupper(selection);
					}
					else if (promptGuess < correctNumber) {
						guesses = guesses + addGuess;
						health = health - subHealth;
						if (health == healthOut) {
							break;
						}
						cout << "You guessed too low, you have " << health << " health left." << endl;
						cout << "Try again? (y/n)" << endl;
						cin >> selection;
						selection = toupper(selection);
					}
					else {
						cout << "Invalid" << endl;
					}
				}
				else {
					cout << "Please enter a valid number." << endl;
					cout << "Try again? (y/n)" << endl;
					cin >> selection;
					selection = toupper(selection);
				}

				if (selection != 'Y' && selection != 'N') {
					cout << "Please enter a valid response" << endl;
				}

        } while (selection == 'Y');

		}
		else if (selection != 'Y' && selection != 'N') {
			cout << "Please enter a valid response" << endl;
		}

    } while (selection != 'Y' && selection != 'N');

	//
}

void restart() {

	//restarts entire game and resets key variables
	//resets correct number

	health = resetHealth;

	guesses = resetGuess;

	advancedFun();

	randomNum();

	startGame();
}

void healthOutFun() {

	//happens if health = 0

	do {
		cout << "You ran out of health. Restart? (y/n)" << endl;
		cin >> restartPrompt;
		restartPrompt = toupper(restartPrompt);
		if (restartPrompt == 'Y') {
			restart();
		}
		else if (restartPrompt == 'N') {
			break;
		}
		else {
			cout << "Please enter a valid response" << endl;
			healthOutFun();
		}
	} while (health == 0);
}

int main()
{
	//runs every main function

	advancedFun();

	randomNum();

	startGame();

	//checks if health = 0, then runs function prompting restart

	if (health == healthOut) {
		healthOutFun();
	}
}