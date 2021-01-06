//This program accepts the user input for a string
//then calculates the number of vowels and consonants
//and displays a menu of options for the user to choose from
//SDEV340-81
//Kodi Lein
#include <iostream>
#include <string>
using namespace std;

//** FUNCTION PROTOTYPES**//
void displayMenu();
char getChoice();

//** MAIN **//
int main()
{
    char str[500]; //string array
    char choice;
    
    int vowels, consonants;

    vowels = consonants = 0;

    cout << "Enter a string: ";
    
    do {
        cin.getline(str, 500); //reads line input given by user

        for (int i = 0; str[i] != '\0'; ++i) //counts vowels and consonants for cin.getline
        {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
                str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
                str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
                str[i] == 'U')
            {
                ++vowels;
            }
            else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            {
                ++consonants;
            }
        }

        //call to functions
        displayMenu();
        choice = getChoice();

        //define output for different choices made
        if (choice == 'A' || choice == 'a')
        {
            cout << "Vowels: " << vowels << endl;
        }
        else if (choice == 'B' || choice == 'b')
        {
            cout << "Consonants: " << consonants << endl;
        }
        else if (choice == 'C' || choice == 'c')
        {
            cout << "Vowels and Consonants: " << consonants + vowels << endl;
        }
        else if (choice == 'D' || choice == 'd')
        {
            vowels = consonants = 0; //resets count to 0 so previous entries are not included
            cout << "Enter a string: ";
            cin.getline(str, 150);

            for (int i = 0; str[i] != '\0'; ++i)
            {
                if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
                    str[i] == 'o' || str[i] == 'u' || str[i] == 'A' ||
                    str[i] == 'E' || str[i] == 'I' || str[i] == 'O' ||
                    str[i] == 'U')
                {
                    ++vowels;
                }
                else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
                {
                    ++consonants;
                }
            }
        }
        
    } while (choice != 'E' && choice != 'e'); //loop continues as long as choice isn't the letter "e"
    if (choice == 'E' || choice == 'e') //loop ends, program terminates.
    {
        cout << "The program has ended.";
    }
        return 0;
}

//**FUNCTIONS**//

void displayMenu() //displays menu options
{
    cout << "\nWhat would you like to do? \n\n";
    cout << "\tA. Count the number of vowels\n \tB. Count the number of consonants\n";
    cout << "\tC. Count vowels and Consonants\n \tD. Enter another string\n \tE. Exit program\n";
}
char getChoice() //interprets if option choice is valid or not
{
    char input;

    cin >> input;

    //only accept a-e in caps or undercase. all other input = invalid.
    while (input != 'a' && input != 'A' && input != 'b' && input != 'B' && input != 'c' && input != 'C' 
           && input != 'd' && input != 'D' && input != 'e' && input != 'E')
    {
        cout << "\nInvalid Entry. \nPlease enter valid choice: ";
        cin >> input;
    }
    return input; //valid input accepted, in main function it is called as 'choice'
}