#include <iostream>
#include <stdlib.h>

using namespace std;

int mult(int x, int y);
void Array();
void Product();
void Guess();

int main()
{
    bool ValidSelect = 0;
    while(ValidSelect == 0)
    {
        int ProgX = 3;
        cout<<"Select which program you wish to execute:\n (0)Prod\n (1)Array\n (2)Guess\n (9)Exit\n";
        cin>> ProgX;
        cin.ignore();
        if(ProgX == 0)
            {
            //Check if variable is greater then 12
            cout<< "\nExecuting Product program\n";
            ValidSelect = 1;
            Product();
            }
        else if(ProgX == 1)
            {
            //Check if variable is greater then 12
            cout<< "\nExecuting Array program\n";
            ValidSelect = 1;
            Array();
            }
        else if(ProgX == 2)
            {
            //Check if variable is greater then 12
            cout<< "\nExecuting Guessing program\n";
            ValidSelect = 1;
            Guess();
            }
        else if(ProgX == 9)
            {
            //Check if variable is greater then 12
            cout<< "\nExiting program\n";
            return 0;
            }
        else
            {
            cout<< "\nInvalid selection\n";
            ValidSelect = 0;
            }
    }
}

void Product()
{
    int thisisanumber;
    int NumX;
    int NumY;

    // Enter the first number to be mulitplied
    // and display it to the user
    cout<<"\nPlease enter the first of two numbers: ";
    cin>> NumX;
    cin.ignore();
    cout<< NumX <<" is your first number\n";

    // Enter the second number to be multiplied
    // and display it to the user
    cout<<"Please enter second number: ";
    cin>> NumY;
    cin.ignore();
    cout<< NumY <<" is your second number\n";

    // Assign product of two number to variable
    thisisanumber = mult(NumX, NumY);

    // Display variable to user
    cout << "The product of your two numbers is " << thisisanumber << "\n";

    // Compare to see if greater than 12
    if(thisisanumber > 12)
        {
        //Check if variable is greater then 12
        cout<< thisisanumber <<" is greater than 12\n";
        cin.get();
        }
    else if(thisisanumber == 12)
        {
        //Check if variable is equal to 12
        cout<< thisisanumber <<" is equal to 12\n";
        cin.get();}
    else
        {
        //Check if variable is less than 12
        cout<< thisisanumber <<" is less than 12\n";
        cin.get();
        }
    return;
}

// Function to multiply two values together
int mult(int x, int y)
{
    return (x * y);
}


void Array()
{
    // Take inputs to find out hwo many values to be entered into array
    int NumX;
    cout << "\nPlease enter the number of values you wish to store: ";
    cin >> NumX;
    cin.ignore();

    // Declare array to store values
    int UserArray[NumX];

    // Loop for entering values into array
    for(int x=0; x<NumX ; x++)
        {
        cout << "\nPlease enter the " << x+1;

        if(x+1 == 1)
            cout << "st value: ";

        else if(x+1 == 2)
            cout << "nd value: ";

        else if(x+1 == 3)
            cout << "rd value: ";

        else
            cout << "th value: ";

        cin >> UserArray[x];
        }
    // Loop for displaying all values in array
    for(int x=0; x<NumX ; x++)
        {
        cout << "\nValue entered: " << UserArray[x];
        }
    return;
}

void Guess()
{
    int Number = rand() %10;
    int AttemptNum = 0;
    int Attempt = -1;
    int NumberOfAttempts = 0;

    for(AttemptNum = 0; AttemptNum < 8; AttemptNum++)
    {
        cout << "Please enter your guess: ";
        cin >> Attempt;

        if(Attempt != Number)
        {
            if(Attempt > Number)
            {
                cout << "\nYour guess was too high\n";
            }
            else
            {
                cout << "\nYour guess was too low\n";
            }
            NumberOfAttempts = 7 - AttemptNum;
            cout << "You have " << NumberOfAttempts << " attempts left\n";
        }

        else
        {
            cout << "Correct!!!";
            AttemptNum = 8;
        }
    }


    return;
}
