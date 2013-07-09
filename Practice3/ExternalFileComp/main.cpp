#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    //Create variables for conversion and storage
    long InputConv = 0;
    long TempConv = 0;
    long Deductor = 1;
    long Comparitor = 9;
    int DigitTotal = 1;
    int DigitTrack = 0;
    int DigitLoop = 0;

    //Chars for storing english conversion
    char Millions[17];
    char HundThous[13];
    char TenThous[8];
    char Thousands[14];
    char Hundreds[12];
    char Tens[7];
    char Singles[5];

    int SingledDigits[7];

    //Request number to be convereted
    cout << "Please enter number to be converted\n";

    //Take manual input number
    cin >> InputConv;

    //Store input in major increment variable
    TempConv = InputConv;

    //Calculate how many digits there are in the
    //number being converted to english
    while(TempConv>9)
    {
        DigitTotal++;
        TempConv = TempConv/10;
    }

    //Calculate the value of each digit in the number
    //being converted
    Deductor = 10;
    Comparitor = 9;

    //****************** 1st Sub Loop **********************//
    for(DigitLoop=0; DigitLoop < (DigitTotal-2); DigitLoop++)
    {
        Deductor = Deductor * 10;
        Comparitor = Comparitor * 10;
    }

    //****************** Main Loop **********************//
    //Loop through all digits and calculate individual values
    for(DigitLoop=0; DigitLoop < DigitTotal; DigitLoop++)
    {

    //Store input in major increment variable
    TempConv = InputConv;

    //Rest DigitTrack in order it can be used again
    //to calculate the individual digit value
    DigitTrack = 0;

        //Cycle through each TempConv Digit untill it is
        //less then the highest possible value of the
        //digit afterwards
        while(TempConv>Comparitor)
        {
            //Deduct a tenth of the total highest possible value
            //of the initial input untill that value is less then
            //the highest possible value of the next digit down.
            TempConv=TempConv-Deductor;
            DigitTrack++;
        }

    //Deduct value just calculated
    InputConv = InputConv - (Deductor*DigitTrack);

    Deductor = Deductor / 10;
    Comparitor = Comparitor / 10;

    //Assign value of digit to relevant position in array
    SingledDigits[DigitLoop] = DigitTrack;
    }

    //Re-assemble digits in english form
    for(DigitLoop=0; DigitLoop < DigitTotal; DigitLoop++)
    {
        cout << "\nSingledDigits = "<< SingledDigits[DigitLoop];
    }
}

