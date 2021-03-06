/*
###############################################
            Casino game using C++

@author: Tapati
Student at GCETTB
###############################################
*/

#include <iostream>
#include <string>

#include "game.h"

using namespace std;

void Game::setbetAmount(int bamount)
{
    this->betAmount = bamount;
}

void Game::setdice(int dice)
{
    this->dice = dice;
}

void Game::setguessNumber(int gnumber)
{
    this->guessNumber = gnumber;
}

void Game::setplayerName(string pname)
{
    this->playerName = pname;
}

void Game::settotalAmount(int tamount)
{
    this->totalAmount = tamount;
}

void Game::rules()
{
    cout << "\n\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
    cout << "\t\t#################                                             ######################" << endl;
    cout << "\t\t=================β¨ β¨ CASINO NUMBER GUESSING GAME RULES β¨ β¨======================" << endl;
    cout << "\t\t#################                                             ######################" << endl;
    cout << "\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n" << endl;
    cout << "\t--------------------------------------------------------------------\n" << endl;
    cout << "\t π1. Choose a number between 1 to 10 \t" << endl;
    cout << "\t π2. Winner gets 5 times of the money he/she bet \t" << endl;
    cout << "\t π3. Wrong bet, and you will loose the money you bet\n" << endl;
    cout << "\t--------------------------------------------------------------------" << endl;
}

void Game::getBettingAmount()
{
    do
    {
        cout << "Hey, " << this->playerName << " please enter your betting amount:π° Rs.";
        cin >> this->betAmount;

        if(this->betAmount > this->totalAmount)
        {
            cout << "\nπ«π«π«π«" << endl;
            cout << "\nBetting balance can't be more than your current balance!ππ\n" << endl;
            cout << "πRe-enter your betting amount \n" << endl;
        }
    }while(this->betAmount > this->totalAmount);
}

void Game::getGuessingNumber()
{
    do
    {
        cout << "πGuess any number between 1 to 10: ";
        cin >> this->guessNumber;

        if(this->guessNumber <= 0 || this->guessNumber > 10)
        {
            cout << "\nπ«π«π«π«" << endl;
            cout << "\nYour guessing number should be between 1 to 10 π\n" << endl;
            cout << "πPlease re-enter your guessing number \n" << endl;
        }
    }while(this->guessNumber <= 0 || this->guessNumber > 10);
}

void Game::play()
{
    char choice;
    srand(time(0));

    cout << "\t\t###################################################################################" << endl;
    cout << "\t\t#############                                                      ################" << endl;
    cout << "\t\t############################ ππ    WELCOME    ππ ##############################" << endl;
    cout << "\t\t#############                           TO                         ################" << endl;
    cout << "\t\t#############                 π²  CASINO   WORLD  π²               ################" << endl;
    cout << "\t\t#############                                                      ################" << endl;
    cout << "\t\t###################################################################################\n\n" << endl;

    cout << "Please tell what's your name?π : " << endl;
    getline(cin, this->playerName);
    cout << "\n" << "Helloβ " << this->playerName << "\n" << "Enter the starting amountπ° to start the game : Rs.";
    cin >> this->totalAmount;

    cout << "\n\tπππ€Let's start................\n" << endl;
    cout << "\tRead all the rules carefully-------------" << endl;

    rules();
    do
    {
        cout << "\n\nYour current balance isπ°: Rs." << this->totalAmount << "\n" << endl;

        getBettingAmount();
        getGuessingNumber();

        this->dice = rand()%10 + 1;
        if(this->dice == this->guessNumber)
        {
            cout << "\n\t\tπππππ\t\t" << endl;
            cout << "\t ***π€π CONGRADULATIONS ππ€*** \t\n" << "You are in luck!!π" << endl;
            cout << "\nππYou have won π°Rs. " << this->betAmount * 5 << endl;
            this->totalAmount = this->totalAmount + this->betAmount * 5;
        }
        else
        {
            cout << "\n\tOpps!  ππBetter luck, next time!!!\n" << endl;
            cout << "πYou have lost Rs." << this->betAmount << endl;
            this->totalAmount = this->totalAmount - this->betAmount;
        }

        cout << "\nThe winning number is: " << dice << "\n" << endl;
        cout << this->playerName << " your current balance is: " << this->totalAmount << endl;

        if(this->totalAmount == 0)
        {
            cout << "\n\tYou have no sufficient balanceπ° to play furtherπ\t\n" << endl;
            break;
        }
        cout << "\n\n\t*** >> Do you want to play again(Y/N)???π\t" << endl;
        cin >> choice;

    }while(choice == 'Y' || choice == 'y');
    cout << "\n\tπThanks for playing the game. Your balance is π°: Rs." << this->totalAmount << endl;

}