#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum enChoice {Stone = 1 , Paper = 2 , Scissors = 3};

enum enGameWins {PlayerWins = 1 , ComputerWins = 2 , Draw = 3};

struct stGameResults {

	int PlayerScore = 0;
	int ComputerScore = 0;
	int Draw = 0;
	int NumberOfRounds = 0;
	string FinalResults = " ";
};

int RandomNumber(int From, int To) {

	int randNumber = rand() % (To - From + 1) + From;
	return randNumber;
}

short ReadHowManyRoundes() {

	short Number = 1;

	do {

		cout << "How Many Rounds 1 to 10 ?" << endl;
		cin >> Number;

	} while (Number < 1 || Number > 10);

	return Number;
}

enChoice GameChoice(short number) {

	return (enChoice)number;

}

enChoice PlayerChoice() {

	short number = 0;

	do {

		cout << "Your Choice : [1]:Stone, [2]:Paper, [3]:Scissors ?" << endl;
		cin >> number;


	} while (number < 1 || number > 3);

	return GameChoice(number);
}

enChoice GetComputerChoice() {

	return GameChoice(RandomNumber(1, 3));
}

void SpecialEffectsWinnerScreen(string winner) {

	if (winner == "Player")
	{
		system("color 2F");

		cout << "\a";
	}

	else if (winner == "Computer") {

		system("color 4F");

		cout << "\a";
	}

	else if (winner == "Draw")
	{

		system("color 6F");

		cout << "\a";
	}

	else {

		system("color 7");
	}

}

string GetRoundResults(enChoice  player, enChoice  computer) {


	if (player == computer) {
		enGameWins::Draw;

		SpecialEffectsWinnerScreen("Draw");

		return "[No Winner]";
	}
	if ((player == Stone && computer == Scissors) ||
		(player == Paper && computer == Stone) ||
		(player == Scissors && computer == Paper)) {

		enGameWins::PlayerWins;

		SpecialEffectsWinnerScreen("Player");

		return "[Player]";
	}

	if (enGameWins::ComputerWins) {

		SpecialEffectsWinnerScreen("Computer");

		return "[Computer]";

	}
}

void PlayGameRounds(stGameResults &Results) {

	int rounds = ReadHowManyRoundes();
	Results.NumberOfRounds = rounds;

	for (int i = 1; i <= rounds; i++) {

		cout << "\nRound [" << i << "] begins:\n";

		enChoice playerChoice = PlayerChoice();
		enChoice computerChoice = GetComputerChoice();

		string winner = GetRoundResults(playerChoice, computerChoice);


		if (winner == "[Player]") {

			Results.PlayerScore++;

		}

		else if (winner == "[Computer]") {

			Results.ComputerScore++;
		}
		

		else {

			Results.Draw++;
		}
	
		

		cout << "\n_______________________Round [" << i << "]_______________________\n\n";

		cout << "Player1  Choice : " << playerChoice << endl;
		cout << "Computer Choice : " << computerChoice << endl;
		cout << "Round WinNer    : " << winner << endl;

		cout << "_______________________________________________________\n\n";


	}
}

void DisplayGameOverScreen() {

	cout << "\n\t\t______________________________________________________________________\t\t\n";

	cout <<                        "\n\t\t\t\t\t+++ G a m e  O v e r +++\t\t\t\t\t";

	cout << "\n\t\t______________________________________________________________________\t\t\n";
}

string Tabs(short NumberOfTbas) {

	string t = "";

	for (int i = 1; i < NumberOfTbas; i++) {

		t += "\t";
		cout << t;
	}

	return t;
}

void ResteScreen() {

	system("cls");
	system("color 0F");
}

void ShowFinalGameRounds(stGameResults &GameResults) {

	if (GameResults.PlayerScore > GameResults.ComputerScore) {

		GameResults.FinalResults = "Player";
	}
	else if (GameResults.PlayerScore < GameResults.ComputerScore) {

		GameResults.FinalResults = "Computer";
	}
	else {

		GameResults.FinalResults = "No winner";
	}

		cout << "\n" << Tabs(3) <<"____________________________[ Game Results ]__________________________"<< Tabs(3) <<"\n";
		
		cout << Tabs(2) <<"Game Rounds        : " << GameResults.NumberOfRounds << endl;
		cout << Tabs(2) <<"Player1 won times  : " << GameResults.PlayerScore << endl;
		cout << Tabs(2) <<"Computer won times : " << GameResults.ComputerScore << endl;
		cout << Tabs(2) <<"Draw times         : " << GameResults.Draw << endl;
		cout << Tabs(2) <<"Final Winner       : " << GameResults.FinalResults << endl;

		cout << Tabs(2) << "______________________________________________________________________"<< Tabs(1) << "\n";

}

void StartGame() {

	char PlayAgain = 'Y';

	stGameResults GameStart;

	do {

		ResteScreen();
		PlayGameRounds(GameStart);
		DisplayGameOverScreen();
		ShowFinalGameRounds(GameStart);

		cout << endl << "\t\t\t" << "Do you want to play again? [Y/N] : ";

		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');
	
}

int main() {

	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}