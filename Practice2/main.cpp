#include <iostream>

using namespace std;

int mult(int x, int y);
int Array();

int main()
{

    Array();

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
}

// Function to multiply two values together
int mult(int x, int y)
{
    return (x * y);
}


int Array()
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
}
