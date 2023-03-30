#include <iostream>
#include <string>
#include<cstdlib> //Trabaja con números random
using namespace std;


int askNumber(string question, int max, int min = 1);
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    int randomNumber = rand();
    int playerMin = 0, playerMax = 0;
    int tries = 0;
    int veryClose = 0;
    int guess = 0;
    int option = 0;
    char exit[1] = "";
    char play[1] = "";
    int leave = 0;


    do
    {
        system("cls");
        cout << "Bienvenido! Que desea hacer?" << endl << "Play (1)" << endl << "Exit (2)" << endl;
        cin >> option;


        switch (option)
        {
        case 1:
            system("cls");
            cout << "GUESS MY NUMBER" << endl;
            cout << "\nAdivina el número en el menor número de intentos posible." << endl;
            cout << "Primero, asigne los valores" << endl << "Low: ";
            cin >> playerMin;
            cout << "\nAhora el otro valor" << endl << "High: ";
            cin >> playerMax;
            do
            {
                int secretNumber = (rand() % (playerMax - playerMin + 1)) + playerMin;
                tries = 0;
                do
                {
                    cout << secretNumber;
                    guess = askNumber("\nAdivina un numero ", playerMax, playerMin);

                    tries++;

                    veryClose = secretNumber - guess;

                    if (veryClose <= 5 && veryClose >= -5 && veryClose != 0)
                    {
                        cout << "Muy cerca!!\n";
                    }

                    if (guess > secretNumber) {
                        cout << "Muy Alto\n\n";
                    }
                    else if (guess < secretNumber) {
                        cout << "Muy Bajo\n\n";
                    }
                    else {
                        cout << "\nExcelente lo hiciste en -- " << tries << " -- intentos";

                    }
                } while (guess != secretNumber);

                cout << "\nDesea volver a jugar? (y/n) ";
                cin >> play;
                system("cls");
            } while (strcmp(play, "n"));
            break;
        case 2:
            cout << "Realmente quiere irse? (y/n) ";
            cin >> exit;
            break;
        default:
            break;
        }
        if (strcmp(exit, "y"))
            leave = 3;

    } while (leave != 3);
}

int askNumber(string question, int max, int min)
{
    int number = 0;
    do
    {
        cout << question << "entre " << min << " y " << max << endl;

        cin >> number;
    } while (number > max || number < min);

    return number;
}