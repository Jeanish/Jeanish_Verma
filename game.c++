#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

void rules();

int main()
{
    int number, guess, balance, update_balance;
    int betting_amount;
    string name;
    char choices;

    srand(time(0));
    number = rand() % 10 + 1;

    cout << "\n\n";
    cout << "\t\t\t                 ===-----WELCOME TO GUESSING THE NUMBER GAME-----===\n\n"
         << endl;

    cout << " Enter the player name : ";
    getline(cin, name);

    cout << "\n Enter your balance  : $";
    cin >> balance;

    do
    {
        rules();

        do
        {
            cout << "\n\n Hey, " << name << " your current balance is : $" << balance << endl;
            cout << "\n Enter the betting amount : $";
            cin >> betting_amount;

            if (betting_amount > balance)
            {
                cout << " Betting amount can't be more than your balance "
                     << ", Re-enter the betting amount ";
            }

        } while (betting_amount > balance);

        do
        {
            cout << "\n Enter the guessing number from 1 to 10 : ";
            cin >> guess;

            if (guess <= 0 || guess > 10)
            {
                cout << "\n Number should between 1 to 10 "
                     << ", Re-enter the guess\n";
            }

        } while (guess <= 0 || guess > 10);

        if (guess == number)
        {
            cout << " \n Congratulation you won the game of $" << betting_amount << "\n Your winning amount $" << betting_amount * 10
                 << " is credited in your account's balance !!!";
            balance = balance + betting_amount * 10;
        }
        else
        {
            cout << "\n You lose the game of $" << betting_amount << ", So $" << betting_amount <<" is going to be debited from your account's balance .";
            balance = balance - betting_amount;
        }

        cout << "\n The winning number is " << number << endl;
        cout << "\n " << name << " your current balance is $" << balance << endl;

        if (balance == 0)
        {
            cout << " \n sorry you cant play the game \n\n"
                 << endl;
            break;
        }

        cout << "\n Do you want to play again(y/n) ?";
        cin >> choices;

    } while (choices == 'y' || choices == 'Y');

    cout << " \n Thanks for playing\n Your balance is $" << balance << endl;
    cout << endl;

    return 0;
}

void rules()
{
    cout << "\n                                            ~~~ INSTRUCTIONS ~~~                                                     " << endl;

    cout << "\n                    ##=--  Number will guess in between from 1 to 10  --=##\n                          " << endl;
    cout << "                    ##=--  If you will win the game then you get 10x more amount than your betting amount  --=##                     \n"
         << endl;
    cout << "                    ##=--  If you will loss the game then your betting amount will be gone  --=##                  \n"
         << endl;
    cout << "                                          ---  KEEP PLAYING   ---     \n                                             " << endl;
}