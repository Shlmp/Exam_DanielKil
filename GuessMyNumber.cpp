#include <iostream>
#include <string>
#include<cstdlib> //Trabaja con números random
#include <string>
#include <vector>
#include <algorithm> // Ayudan a identificar si lo que puso el usuario son letras o no
#include <cctype> // Ayudan a identificar si lo que puso el usuario son letras o no

using namespace std;

//Parcial 1
void GuessMyNumber();
int askNumber(string question, int max, int min = 1);

//Parcial 2
void InventorySimulator();
void replay();

int main()
{
    int option = 0;
    cout << "Bienvenido, cual parcial desea ver?" << endl << "1 - Guess My Number       2 - Inventory Simulator" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
        GuessMyNumber();
        break;
    case 2:
        InventorySimulator();
        break;
    default:
        break;
    }
}

void GuessMyNumber()
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

void InventorySimulator()
{
    vector<string> inventory(20);
    vector<string>::iterator myIterator;
    vector<string>::const_iterator iter;
    unsigned int gems = 6;
    int option = 0;
    int replace = 0;
    int i = 0;
    int x = 0;
    string replacement;
    char buy = 0;
    int again = 0;
    int spaces = 10;

    do
    {
        cout << "Your current inventory has - 10 - spaces                     Gems = " << gems << endl;
        inventory.insert(inventory.begin(), "Sword");
        inventory.insert(inventory.begin() + 1, "Shield");
        inventory.insert(inventory.begin() + 2, "Hammer");
        inventory.insert(inventory.begin() + 3, "Gun");
        inventory.insert(inventory.begin() + 4, "Fishing Rod");
        inventory.insert(inventory.begin() + 5, "Bike");
        inventory.insert(inventory.begin() + 6, "Stone");
        inventory.insert(inventory.begin() + 7, "Potion");
        inventory.insert(inventory.begin() + 8, "Map");
        inventory.insert(inventory.begin() + 9, "Food");

        cout << "Your items:\n";
        for (iter = inventory.begin(); iter != inventory.begin() + spaces; iter++)
        {
            cout << "You grabed a " << *iter << "!" << endl;
        }
        cout << "\nWhat is your new object?" << endl;
        cin >> inventory[10];

        system("cls");
        cout << "Oh no!, your inventory is full. What do you weant to do?" << endl << "1 - Replace an object   2 - Leave behind the new object   3 - Buy a new inventory slot" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            system("cls");
            cout << "What object do you want to replace?" << endl;
            cout << "Your items:\n";
            for (iter = inventory.begin(); iter != inventory.begin() + spaces; iter++)
            {
                cout << i << " - " << *iter << endl;
                i++;
            }
            cin >> replace;
            x = replace;
            inventory[x] = replacement;

            system("cls");
            cout << "This is your new inventory" << endl;
            i = 0;
            for (iter = inventory.begin(); iter != inventory.begin() + spaces; iter++)
            {
                cout << i << " - " << *iter << endl;
                i++;
            }
            break;
        case 2:
            system("cls");
            cout << "Your " << inventory[10] << " has been abandoned" << endl;
            inventory.erase(inventory.begin() + 10);
            for (iter = inventory.begin(); iter != inventory.begin() + spaces; iter++)
            {
                cout << i << " - " << *iter << endl;
                i++;
            }
            break;
        case 3:
            system("cls");
            cout << "A new slot costs 5 gems" << endl;
            gems = gems - 5;
            if (gems < 5)
            {
                cout << "Congratulations, you bought a new slot for your inventory" << endl;
                for (iter = inventory.begin(); iter != inventory.begin() + spaces+ 1; iter++)
                {
                    cout << i << " - " << *iter << endl;
                    i++;
                }
            }
            else
            {
                cout << "You do not have enough to buy a new slot";
            }
            break;
        default:
            break;
        }
        replay();
        spaces = spaces + 1;
        gems = 1;
    } while (again != 1);
    return;
}

void replay()
{
    int again = 0;

    cout << "Do you want to play again?" << endl << "0 - yes" << endl << "1 - no" << endl;
    cin >> again;
    if (again == 0)
    {
        return InventorySimulator();
    }
    else if (again == 1)
    {
        cout << "Thank you for playing!" << endl;
        return;
    }
    else
    {
        if (again > 1 || again < 0)
        {
            cout << "Invalid option, the program will close" << endl;

        }
    }
    system("cls");
}