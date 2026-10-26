#include <iostream>
#include<cstdlib>
using namespace std;

enum enPlayChoises { Slave = 1, Citizen = 2, Emperor = 3 };

enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    unsigned short gameRound = 0;
    enPlayChoises player1Choise;
    enPlayChoises computerChoise;
    enWinner Winner;
    string WinnerName = "";

};

struct stGameResults
{
    unsigned short gameRounds = 0;
    unsigned short player1WonsTimes = 0;
    unsigned short computerWonsTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";


};

string Taps(unsigned short);

int ValidNumberinRange(int from, int to, string message)
{
    int number;
    do {
        cout << message;
        cin >> number;
    } while (number < from || number > to);

    return number;
}

unsigned short HowManyRounds()
{
    short NumOfRounds = 0;
    
        cout<< Taps(3) << "How many rounds do you want to play 6 or 12 ? ";
        cin >> NumOfRounds;
        cout << endl;
    return NumOfRounds;
}

int RandomNumber(int From, int To)
{
    int RandomNum = 0;
    RandomNum = rand() % (To - From + 1) + From;

    return RandomNum;
}

enPlayChoises ReadPlayer1Choise(bool EmperorSide)
{
    unsigned short choise = 0;
    if (EmperorSide)
    {
        do
        {
            cout << Taps(3) << "Your Choice : [1] : Slave, [2] : Citizen ?";
            cin >> choise;
        } while (choise < 1 || choise>2);

    }
    else
    {
        do
        {
            cout << Taps(3) << "Your Choice :  [2] : Citizen, [3] : Emperor ?";
            cin >> choise;
        } while (choise < 2 || choise>3);
    }
   
    return (enPlayChoises)choise;
}

enPlayChoises GetComputerChoise(bool EmperorSide)
{
    cout<< Taps(3) << "Computer choise is ******\n";
    if (EmperorSide)
        return (enPlayChoises)RandomNumber(2, 3);

    else
        return (enPlayChoises)RandomNumber(1, 2);
}

string NameOfChoise(enPlayChoises choise)
{
    string arr[3] = { "Slave" , "Citizen" , "Emperor" };
    return arr[choise - 1];

}

enWinner RoundWinner(stRoundInfo roundInfo)
{
    switch (roundInfo.player1Choise)
    {
    case enPlayChoises::Slave:
        if (roundInfo.computerChoise == enPlayChoises::Emperor)
        {
            return enWinner::Player1;
        }
        else return enWinner::Computer;
       

    case enPlayChoises::Emperor:
        if (roundInfo.computerChoise ==enPlayChoises::Citizen)
        {
            return enWinner::Player1;
        }
        else return enWinner::Computer;
    case enPlayChoises::Citizen:
        if (roundInfo.computerChoise == enPlayChoises::Slave)
        {
            return enWinner::Player1;
        }
        else return enWinner::Computer;
    
    
    }

   // return enWinner::Computer;
}

string GetWinnerName(enWinner Winner)
{
    string arr[3] = { "Player1","Computer","No Winner "};
    return arr[Winner - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
    if (Winner == enWinner::Player1)
    {
        system("color 2F");
    }
    else if (Winner == enWinner::Computer)
    {
        system("color 4F");
        cout << "\a";
    }
}

void PrintRoundResult(stRoundInfo RoundInfo)
{
    cout << endl;
    cout<<Taps(3) << "____________________ Round [" << RoundInfo.gameRound << "] ____________________\n\n";
    cout<<Taps(3) << "Player1  Choise: " << NameOfChoise(RoundInfo.player1Choise) << endl;
    cout<<Taps(3) << "Computer Choise: " << NameOfChoise(RoundInfo.computerChoise) << endl;
    cout<<Taps(3) << "Round Winner   : " << RoundInfo.WinnerName << endl;
    cout<<Taps(3) << "______________________________________________________\n";
    SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner FinalWinner(short player1WonsTimes, short computerWonsTimes)
{
    if (player1WonsTimes > computerWonsTimes)
        return enWinner::Player1;
    else if (computerWonsTimes > player1WonsTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

stGameResults FillGameResults(short GameRounds, short player1WonsTimes, short computerWonsTimes)
{
    stGameResults GameResult;
    GameResult.gameRounds = GameRounds;
    GameResult.computerWonsTimes = computerWonsTimes;
    GameResult.player1WonsTimes = player1WonsTimes;
    GameResult.GameWinner = FinalWinner(player1WonsTimes, computerWonsTimes);
    GameResult.WinnerName = GetWinnerName(GameResult.GameWinner);

    return GameResult;

}

bool IsComputerHasEmperor()
{
    return (bool)RandomNumber(0, 1);
}

void ReadAndGetCardsInEachPlay( bool EmperorSide, stRoundInfo& RoundInfo)
{
    short play = 0;
    do 
    {
        play++;
        if (EmperorSide)
        {
            if (play % 2 != 0)
            {
                RoundInfo.computerChoise = GetComputerChoise(EmperorSide);
                RoundInfo.player1Choise = ReadPlayer1Choise(EmperorSide);
                //must get winner and break loop;
            }
            else
            {
                RoundInfo.player1Choise = ReadPlayer1Choise(EmperorSide);
                RoundInfo.computerChoise = GetComputerChoise(EmperorSide);

            }
        }
        else
        {
            if (play % 2 != 0)
            {
                RoundInfo.player1Choise = ReadPlayer1Choise(EmperorSide);
                RoundInfo.computerChoise = GetComputerChoise(EmperorSide);

            }
            else
            {
                RoundInfo.computerChoise = GetComputerChoise(EmperorSide);
                RoundInfo.player1Choise = ReadPlayer1Choise(EmperorSide);
            }
        }
        cout<< Taps(3) << "_______________________________________________________";
        cout << endl;
    } while (play <4 && RoundInfo.computerChoise == enPlayChoises::Citizen && RoundInfo.player1Choise == enPlayChoises::Citizen);
}

void StartRound(bool EmperorSide, short& player1WonsTimes, short& computerWonsTimes)
{
    stRoundInfo RoundInfo;

    short GameRound = 0;

   // GameRound can be static

    GameRound = computerWonsTimes + player1WonsTimes + 1;

    cout<< Taps(3) << "Round [" << GameRound << "] begins:\n";
    RoundInfo.gameRound = GameRound;

    cout << "Your Score : " << player1WonsTimes << Taps(9) << "Computer Score : " << computerWonsTimes<<endl;

        ReadAndGetCardsInEachPlay( EmperorSide, RoundInfo);

        RoundInfo.Winner = RoundWinner(RoundInfo);
        RoundInfo.WinnerName = GetWinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Computer)
        {
            computerWonsTimes++;
            PrintRoundResult(RoundInfo);
           
        }
        else
        {
            player1WonsTimes++;
            PrintRoundResult(RoundInfo);
            
        }

    }

void StartGroup(bool EmperorSide, short& player1WonsTimes, short& computerWonsTimes)
{

    for (short Round = 1;Round <= 3;Round++)
    {
        StartRound(EmperorSide, player1WonsTimes, computerWonsTimes);
    }
}

stGameResults StartGroups(short NumberOfRounds, short& player1WonsTimes, short& computerWonsTimes)
{

    bool EmperorSide = IsComputerHasEmperor();
    bool InvertEmperorSide = !EmperorSide;

    for (short Group = 1;Group <= NumberOfRounds / 3;Group++)
    {
        cout<< Taps(3) << "Group [" << Group << "] begins:\n\n";

        if (Group % 2 == 0)

            EmperorSide = InvertEmperorSide;
        else
            EmperorSide = !(InvertEmperorSide);


        StartGroup(EmperorSide, player1WonsTimes, computerWonsTimes);
    }

  return FillGameResults(NumberOfRounds, player1WonsTimes, computerWonsTimes);
}

string Taps(unsigned short number)
{
    string tap = "";
    for (unsigned int i = 1;i <= number;i++)
    {
        tap += "\t";
    }
    return tap;
}

void ShowGameOverScreen()
{
    cout << Taps(3) << "____________________________________________\n\n";
    cout << Taps(3) << "          +++ G a m e O v e r +++ \n\n";
    cout << Taps(3) << "____________________________________________\n\n";

}

void PrintGameResults(stGameResults GameResults)
{
    cout << Taps(3) << "_______________ [Game Results] _______________\n\n";
    cout << Taps(3) << "Player1 won Times  :" << GameResults.player1WonsTimes << endl;
    cout << Taps(3) << "Computer won Times :" << GameResults.computerWonsTimes << endl;
    cout << Taps(3) << "Final Winner       :" << GameResults.WinnerName << endl;
    cout << Taps(3) << "______________________________________________\n\n";
}

void PlayGame(short NumberOfRounds)
{

    stGameResults GameResults;

    short computerWonsTimes = 0, player1WonsTimes = 0;


    GameResults = StartGroups(NumberOfRounds, player1WonsTimes, computerWonsTimes);

    ShowGameOverScreen();
    PrintGameResults(GameResults);
}

void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char playAgain = 'Y';
    do
    {

        ResetScreen();
        PlayGame(HowManyRounds());

        cout << Taps(3) << "Do You Want to paly again? Y/N ? : ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();


}
