#include <iostream>
#include <ctime>

void Intro()
{
	//Intro with some scenario
	std::cout << "It looks like you are having a dream...\n";
	std::cout << "\nBut one can not say it is aither a dream or a nightmare...\n";
	std::cout << "\nBy moving forward step by step you can discern a figure far ahead...\n";
	std::cout << "\nAs it happens in any other dream it turns out that a figure was not such far away.\n";
	std::cout << "\nAfter two more steps you find out that a figure is twice bigger than you. You can notice a lot of branches with green leaves on its woody skin.\n";
	std::cout << "\nYou realize that it is the Sentinel without any word spoken but only with thoughts jauntily popping up within your mind.\n";
	std::cout << "\nWith one of this thougts you also realize that to proceed through the dream you must pass the dream doors - it is the only way to arouse from the dream.\n";
}

void DoorFace(int Difficulty)
{
	std::cout << "\nYou catch a feeling that it is a " << Difficulty << " door you face.\n";
	std::cout << "\nBy the time you caught it the things start to happen...\n";
}

int PlayerInput()
{
	int input{};
	std::cin >> input;
	return input;
}

bool Check(int Check1, int Check2)
{
	if (Check1 == Check2)
	{
		return true;
	} else {
		return false;
	}
}

bool GameStart(int Difficulty)
{
	DoorFace(Difficulty);
	std::cout << "\nYou can hear the sentinel whispering in your head: \"To unseal the door you must think about three numbers...\"\n";

	int const NumberA = rand() % Difficulty + 3;
	int const NumberB = rand() % Difficulty + 2;
	int const NumberC = rand() % Difficulty + 3;

	int const OriginSum  = NumberA + NumberB + NumberC;
	int const OriginProd = NumberA * NumberB * NumberC;

	std::cout << "\n\"This numbers are not just a numbers but a magical being.\"\n";
	std::cout << "\n\"They can sum each others to be as " << OriginSum << "\"\n";
	std::cout << "\n\"They can multiply each others to be as \"" << OriginProd << "\"\n";

	int GuessA = PlayerInput();
	int GuessB = PlayerInput();
	int GuessC = PlayerInput();

	int GuessSum  = GuessA + GuessB + GuessC;
	int GuessProd = GuessA * GuessB * GuessC;

	if (Check(OriginSum, GuessSum) == true && Check(OriginProd, GuessProd) == true)
	{
		std::cout << "\nSentinel waves his hand and so door opens. You may proceed...\n";
		return true;
	} else {
		std::cout << "\nSentinel gives you another try. Concentrate...\n";
		return false;
	}
}

void GameOver()
{
	std::cout << "\nYou passed through the last door. The end, indeed, is it?\n";
	std::cout << "\nYou wake up suddenly trying to the last moments of your dream, but you can not remember any of it. This dream just slipped away like others did...\n";
}

int main()
{
	Intro();
	srand(time(NULL));
	int LevelDifficulty = 1;
	int const MaxDifficulty = 10;

	while (LevelDifficulty <= MaxDifficulty)
	{
		bool bLevelCompleted = GameStart(LevelDifficulty);
		std::cin.clear();
		std::cin.ignore();

		if (bLevelCompleted)
		{
			++LevelDifficulty;
		}
	}

	GameOver();

	return 0;
}
