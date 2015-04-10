#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int guess;
int chance = 10;
int replay;
int goal;
int gameOver();

int runGame()
{
	srand(time(0));
	int goal = 1+(rand()%100);

	cout << "\nGuess a number between 1 and 100... \n";
	cin >> guess;

	while(guess!=goal){

		if(!cin){
			cin.clear();
			cin.ignore();
			cout << "\nThat is not a number. Try again...\n" << endl;
		}else{
		if(guess<0 || guess>100){
			cout << "\nInvalid number.  Try again... \n";
		}
		if(guess>goal && guess<101){
			cout << "\nNope, that's too high.  Guess again. \n";
			chance = chance -1;
			cout << "You have " << chance << "chances left... \n";
		}
		if(guess<goal && guess>=-1){
			cout << "\nNope, that's too low.  Guess again. \n";
			chance = chance -1;
			cout << "You have " << chance << "chances left... \n";
		}
		if(chance==0){
			cout << "\nYOU LOSE!! THE CORRECT NUMBER WAS " << goal << endl << endl;
			gameOver();
			return 0;
		}
		cin >> guess;
		}
	}

	if(guess==goal){
		cout << "\nThat is correct.  You are a ROCK STAR!!\n\n";
		gameOver();
	}
	return 0;
}

int gameOver()
{
	cout << "Would you like to play again? \nEnter 1 for YES \nor 2 for NO:\n";
	cin >> replay;
	while(replay!=0){
		guess = 1+goal;
		chance = 10;
		if(!cin){
			cin.clear();
			cin.ignore();
			cout << "\nInvalid response. Try again... \nEnter 1 for YES \nor2 for NO:\n";
			}else{
			if(replay<1 || replay>2){
				cout << "\nInvalid selection.  Try again... \nEnter 1 for YES \nor2 for NO:\n";
				cin >> replay;
			}else{
			if(replay==1){
				replay = 0;
				cout << "\n\nOK... \n";
				runGame();
			}
			if(replay==2){
				cout << "OK... \nSee you next time!!\n\n";
				return 0;
			}
			}
		}
	}
	return 0;
}

int main()
{
	runGame();
	return 0;
}
