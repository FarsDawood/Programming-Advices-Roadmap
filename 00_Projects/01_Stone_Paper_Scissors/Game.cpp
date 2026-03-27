#include <iostream>
#include <ctime>
using namespace std;

enum enGameChoice
{
    Stone = 1,
    Paper = 2,
    Scissor = 3
};
enum enWinner
{
    Player1 = 1,
    Computer = 2,
    Draw = 3
};

struct stRoundDetails
{
    static short RoundNumber;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
};
short stRoundDetails::RoundNumber = 0;
struct stGameFinalResult
{
    short GameRounds = 0;
    short Player1WinCount = 0;
    short ComputerWinCount = 0;
    short DrawCount = 0;
};

int ReadPositiveNumber(string message)
{
    int number;
    do
    {
        cout << message;
        cin >> number;
    } while (number <= 0);
    return number;
}

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enWinner WhoWonTheRound(stRoundDetails RoundDetails)
{
    if (RoundDetails.Player1Choice == RoundDetails.ComputerChoice)
        return enWinner::Draw;
    else if ((RoundDetails.Player1Choice == enGameChoice::Stone && RoundDetails.ComputerChoice == enGameChoice::Scissor) ||
             (RoundDetails.Player1Choice == enGameChoice::Paper && RoundDetails.ComputerChoice == enGameChoice::Stone) ||
             (RoundDetails.Player1Choice == enGameChoice::Scissor && RoundDetails.ComputerChoice == enGameChoice::Paper))
        return enWinner::Player1;
    else
        return enWinner::Computer;
}

enWinner WhoWonTheGame(stGameFinalResult GameResult)
{
    if (GameResult.ComputerWinCount == GameResult.Player1WinCount)
        return enWinner::Draw;
    else if (GameResult.Player1WinCount > GameResult.ComputerWinCount)
        return enWinner::Player1;
    else
        return enWinner::Computer;
}

enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1, 3);
}
enGameChoice ReadPlayer1Choice()

{
    cout << "\n";
    short player1Choice;
    do
    {
        player1Choice = ReadPositiveNumber("Your Choice: [1]:Stone, [2]:Paper, [3]:Scissor ? ");
    } while (player1Choice > 3 || player1Choice < 1);
    return (enGameChoice)player1Choice;
}
string PrintChoice(enGameChoice Choice)

{
    string arrChoices[3] = {"Stone", "Paper", "Scissors"};
    return arrChoices[Choice - 1];
}
string WinnerName(enWinner Winner)
{
    string arrWinnerNames[3] = {"Player1", "Computer", "No Winner"};
    return arrWinnerNames[Winner - 1];
}

void ChangeScreenColor(enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
        system("color 2F");
        break;
    case enWinner::Computer:
        system("color 4F");
        break;
    case enWinner::Draw:
        system("color 6F");
        break;
    }
}
void ClearScreen()
{
    system("cls");
    system("color 0F");
}

void PrintRoundResult(stRoundDetails Round)
{
    ChangeScreenColor(Round.Winner);
    cout << "\n\n------------- Round [" << Round.RoundNumber << "] -------------\n";
    cout << "\nPlayer1  Choice: " << PrintChoice(Round.Player1Choice);
    cout << "\nComputer Choice: " << PrintChoice(Round.ComputerChoice);
    cout << "\nRound Winner   : [" << WinnerName(Round.Winner) << "]";
    cout << "\n\n-------------------------------------\n\n";
}

stRoundDetails StartNewRound()
{
    stRoundDetails Round;
    Round.RoundNumber++;
    cout << "\nRound [" << Round.RoundNumber << "] begins:\n";
    Round.Player1Choice = ReadPlayer1Choice();
    Round.ComputerChoice = GetComputerChoice();
    Round.Winner = WhoWonTheRound(Round);
    return Round;
}

short GetGameRounds()
{
    short gameRounds;
    do
    {
        gameRounds = ReadPositiveNumber("Enter how many rounds to play 1 to 10 : ");
    } while (gameRounds < 1 || gameRounds > 10);
    return gameRounds;
}

void RoundWinnerCounting(stGameFinalResult &GameDetails, enWinner Winner)
{
    switch (Winner)
    {
    case enWinner::Player1:
        GameDetails.Player1WinCount++;
        break;
    case enWinner::Computer:
        GameDetails.ComputerWinCount++;
        break;
    case enWinner::Draw:
        GameDetails.DrawCount++;
        break;
    }
}

void ShowGameOverScreen()
{
    cout << "\n\n\t\t----------------------------------------------------------------------------------\n\n";
    cout << "\t\t                             +++ G a m e  O v e r +++                             \n\n";
    cout << "\t\t----------------------------------------------------------------------------------\n\n";
}
void ShowWelcomeScreen()
{
    cout << "\n\n\t\t----------------------------------------------------------------------------------\n\n";
    cout << "\t\t                             +++ W e l c o m e  T o +++                             \n";
    cout << "\t\t                         S t o n e  P a p e r  S c i s s o r s                         \n\n";
    cout << "\t\t----------------------------------------------------------------------------------\n\n";
}
void showEndGameScreen()
{
    system("color 0F");
    cout << "\n\n\t\t----------------------------------------------------------------------------------\n\n";
    cout << "\t\t                             +++ E n d  G a m e +++                             \n\n";
    cout << "\t\t----------------------------------------------------------------------------------\n\n";
}

void PrintFinalGameResult(stGameFinalResult GameDetails)
{
    enWinner Winner = WhoWonTheGame(GameDetails);
    ChangeScreenColor(Winner);
    cout << "\n\n\t\t-------------------------------- [ Game Results ] --------------------------------\n\n";
    cout << "\t\tGame Rounds        : " << GameDetails.GameRounds;
    cout << "\n\t\tPlayer1 won times  : " << GameDetails.Player1WinCount;
    cout << "\n\t\tComputer won times : " << GameDetails.ComputerWinCount;
    cout << "\n\t\tDraw times         : " << GameDetails.DrawCount;
    cout << "\n\t\tFinal Winner       : " << WinnerName(Winner);
    cout << "\n\n\t\t----------------------------------------------------------------------------------\n\n";
}

bool CheckPlayNewGameAgain()
{
    char playAgain;
    do
    {
        cout << "\t\tDo you want to play again ? [Y/N] : ";
        cin >> playAgain;
    } while (playAgain != 'Y' && playAgain != 'y' && playAgain != 'n' && playAgain != 'N');
    return (playAgain == 'n' || playAgain == 'N') ? false : true;
}

stGameFinalResult PlayGame(short GameRounds)
{
    stGameFinalResult gameDetails;
    gameDetails.GameRounds = GameRounds;
    stRoundDetails::RoundNumber = 0;

    while (gameDetails.GameRounds > stRoundDetails::RoundNumber)
    {
        stRoundDetails newRound = StartNewRound();
        RoundWinnerCounting(gameDetails, newRound.Winner);
        PrintRoundResult(newRound);
    }
    return gameDetails;
}

void StartGame()
{
    bool playAgain = true;
    do
    {
        ClearScreen();
        ShowWelcomeScreen();
        stGameFinalResult gameDetails = PlayGame(GetGameRounds());
        ShowGameOverScreen();
        PrintFinalGameResult(gameDetails);
        playAgain = CheckPlayNewGameAgain();

    } while (playAgain);
    showEndGameScreen();
}

int main()
{

    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}