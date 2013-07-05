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
        cout<< thisisanumber <<" is greater then 12\n";
        cin.get();
        }
    else
        {
        cout<< thisisanumber <<" is less then 12\n";
        cin.get();
        }
}
