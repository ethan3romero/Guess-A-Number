// guessanumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
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

	char selection{};
	
	//


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


	//Randomize Number, set correct Number
	
	    srand((unsigned int)time(NULL));

		randomNumber = rand() % maxNumber + minNumber;

		correctNumber = randomNumber;

	//


   // Start the game

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
					cout << "You guessed too high, try again? (y/n)" << endl;
					cin >> selection;
					selection = toupper(selection);
				}
				else if (promptGuess < correctNumber) {
					guesses = guesses + addGuess;
					cout << "You guessed too low, try again? (y/n)" << endl;
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
		
		} else if (selection != 'Y' && selection != 'N') {
			cout << "Please enter a valid response" << endl;
		}

	} while (selection != 'Y' && selection != 'N');

	//
}