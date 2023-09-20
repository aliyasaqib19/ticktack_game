#include <iostream>
#include <fstream>
#include <ctime>
//#include <cstdlib>

using namespace std;
class Dice 
{
public:
    int roll()
	{
        return rand() % 6 + 1;
    }
};
class Player 
{
protected:
    string name;
    int score;

public:
    Player(const string& playerName)  
	{
		name=playerName;
		score=0;
	}
    virtual void playTurn(Dice& dice) = 0;

    string getName() const 
	{
        return name;
    }

    int getScore() const 
	{
        return score;
    }

    void updateScore(int points) 
	{
        score += points;
    }
};

class HumanPlayer : public Player 
{
public:
    HumanPlayer(const string& playerName) : Player(playerName) {}
    void playTurn(Dice& dice)  
	{
        cout << name << ", it's your turn.\n";
        cout << "               Press enter to roll the dice...";
        cin.ignore();
        int roll = dice.roll();
        cout << "You rolled a " << roll << ".\n";
        //inheritance/////////
        updateScore(roll);
        cout << "Your score is now " << score << ".\n";
        cout << endl;
    }
};

class ComputerPlayer : public Player 
{
public:
    ComputerPlayer(const string& playerName) : Player(playerName) {}
    void playTurn(Dice& dice) 
	{
        cout << name << " is playing...\n";
        int roll = dice.roll();
        cout << name << " rolled a " << roll << ".\n";
        updateScore(roll);
        cout << name << "'s score is now " << score << ".\n";
        cout << endl;
    }
};

void saveScores(const Player& player) 
{
    ofstream file("scores.txt", ios::app);
    if (file.is_open()) 
	{
        file << player.getName() << " " << player.getScore() << endl;
        file.close();
    }
}

void displayScores() 
{
    ifstream file("scores.txt");
    if (file.is_open()) 
	{
        string line;
        cout << "Scores:\n";
        while (getline(file, line)) 
		{
            cout << line << endl;
        }
        file.close();
    }
}


int main() 
{
    //srand(time(0));

    cout << "..............................Welcome to the game of 21!..............................\n\n";

    string playerName;
    cout << "      Enter your name: ";
    getline(cin, playerName);

    HumanPlayer humanPlayer(playerName);
    ComputerPlayer computerPlayer("Computer");

    Dice dice;

    char choice;
    do {
        humanPlayer.playTurn(dice);
        if (humanPlayer.getScore() <= 21) 
		{
            computerPlayer.playTurn(dice);
        }

        if (humanPlayer.getScore() > 21) 
		{
            cout << "..............................You lost! Your score exceeded 21..............................\n";
            break;
        } else if (computerPlayer.getScore() > 21) {
            cout << "..............................You won! The computer's score exceeded 21.....................\n";
            break;
        } else
		 
		{
            int humanDiff = 21 - humanPlayer.getScore();
            int computerDiff = 21 - computerPlayer.getScore();

            if (humanDiff < computerDiff) 
			{
                cout << "..............................Congratulations! You won!\n..............................";
            } else if (humanDiff > computerDiff) 
			{
                cout << "..............................You lost! The computer won...............................\n";
            } else 
			{
                cout << "..............................It's a tie!..............................\n";
            }
        }

        saveScores(humanPlayer);
        saveScores(computerPlayer);

        cout << "             Do you want to play again? (y/n): ";
        cin >> choice;
        cin.ignore();

        cout << endl;
    } while (choice == 'y' || choice == 'Y');
    char n;
    cout << "if you want to diplay the records then press (y) :) "<<endl;
    cin>>n;
    if(n=='y'||n=='y')
	{
		displayScores();
	}

    

    return 0;
}