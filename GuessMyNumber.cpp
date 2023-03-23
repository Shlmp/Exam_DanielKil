#include <iostream>
#include <string>
#include<cstdlib> //Trabaja con números random
using namespace std;


int askNumber(string question, int max, int min = 1);
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    //srand(time(NULL));
    int randomNumber = rand();
    int secretNumber = (randomNumber % 100) + 1;
    int tries = 0;
    int veryClose;
    int guess;

    cout << "GUESS MY NUMBER" << endl;
    cout << "Adivina el número en el menor número de intentos posible." << endl;

    //Depurar
    cout << secretNumber;
    do
    {
        guess = askNumber("\nAdivina un numero ", 300);

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
            cout << "Excelente lo hiciste en -- " << tries << " -- intentos";

        }
    } while (guess != secretNumber);
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