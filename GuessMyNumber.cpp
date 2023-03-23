#include <iostream>
#include<cstdlib> //Trabaja con números random
using namespace std;


int Limits(int min, int max);
int main()
{
    srand(static_cast<unsigned int>(time(0)));
    //srand(time(NULL));
    int randomNumber = rand();
    int secretNumber = (randomNumber % 200) + 50;
    int tries = 0;
    int veryClose;
    int guess;

    cout << "GUESS MY NUMBER" << endl;
    cout << "Adivina el número en el menor número de intentos posible." << endl;

    //Depurar
    cout << secretNumber;
    do
    {
        guess = Limits(50, 200);

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
            cout << "Excelente lo hiciste en -- " << tries << "-- intentos";

        }
    } while (guess != secretNumber);
}

int Limits(int min, int max)
{
    int guess;
    do
    {
        cout << "\nEnter a guess (50-200):" << endl;

        cin >> guess;
    } while (guess > max || guess < min);

    return guess;
}