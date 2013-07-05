#include <iostream>

using namespace std;

int main()
{
    int thisisanumber;

    cout<<"Please enter a number: ";
    cin>> thisisanumber;
    cin.ignore();
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
