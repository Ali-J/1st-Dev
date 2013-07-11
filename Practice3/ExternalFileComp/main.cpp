#include <iostream>
#include <fstream>

using namespace std;

string Convert(int);
string ConvertTens(int);
string ConvertTeens(int);


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
    string Sign = "";
    string Millions = "";
    string HundThous = "";
    string TenThous = "";
    string Thousands = "";
    string Hundreds = "";
    string Tens = "";
    string Singles = "";

    //Temporary storage for plain english equivalent
    //of digit being converted
    string StrOutput = "";

    int SingledDigits[7];

    //Request number to be convereted
    cout << "Please enter number to be converted\n";

    //Take manual input number
    cin >> InputConv;

    //Store input in major increment variable
    TempConv = InputConv;

    //Calculate how many digits there are in the
    //number being converted to english
    while(TempConv>9||TempConv<0)
    {
        DigitTotal++;
        TempConv = TempConv/10;
    }

    //Calculate the value of each digit in the number
    //being converted
    Deductor = 10;
    Comparitor = 9;

    //If number is negative then remove - from start
    //and remember that number is negative
    if(InputConv<0)
    {
        InputConv = InputConv*-1;
        Sign = "Minus ";
    }

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
        //Debug - outputs individual digits for number array
        //cout << "\nSingledDigits = "<< SingledDigits[DigitLoop];

        if ((DigitTotal-DigitLoop-1) == 6 && SingledDigits[DigitLoop]!=0)
        {
            StrOutput = Convert(SingledDigits[DigitLoop]);
            Millions = StrOutput + " million, ";
        }
        else if((DigitTotal-DigitLoop-1) == 5 && SingledDigits[DigitLoop]!=0)
        {
            StrOutput = Convert(SingledDigits[DigitLoop]);
            HundThous = StrOutput + " hundred and ";
        }
        else if((DigitTotal-DigitLoop-1) == 4 && SingledDigits[DigitLoop]!=0)
        {
            StrOutput = ConvertTens(SingledDigits[DigitLoop]);
            TenThous = StrOutput;
        }
        else if((DigitTotal-DigitLoop-1) == 3 && SingledDigits[DigitLoop]!=0)
        {
            if(SingledDigits[DigitLoop-1] == 1)
            {
                StrOutput = ConvertTeens(SingledDigits[DigitLoop]);
                TenThous = StrOutput + " thousand, ";
            }
            else
            {
                StrOutput = Convert(SingledDigits[DigitLoop]);
                Thousands = " " +StrOutput + " thousand, ";
            }
        }
        else if((DigitTotal-DigitLoop-1) == 2 && SingledDigits[DigitLoop]!=0)
        {
            StrOutput = Convert(SingledDigits[DigitLoop]);
            Hundreds = StrOutput + " hundred and ";
        }
        else if((DigitTotal-DigitLoop-1) == 1 && SingledDigits[DigitLoop]!=0)
        {
            StrOutput = ConvertTens(SingledDigits[DigitLoop]);
            Tens = StrOutput + " ";
        }
        else if((DigitTotal-DigitLoop-1) == 0 && SingledDigits[DigitLoop]!=0)
        {
            if(SingledDigits[DigitLoop-1] == 1)
            {
                StrOutput = ConvertTeens(SingledDigits[DigitLoop]);
                Tens = StrOutput;
            }
            else
            {
                StrOutput = Convert(SingledDigits[DigitLoop]);
                Singles = StrOutput;
            }
        }
    }
    // Final output of complete string
    cout << "\n" + Sign + Millions + HundThous + TenThous + Thousands + Hundreds + Tens + Singles;
}

//Convert individual digits from numbers
//to plain english (Singles)
string Convert(int NumbToConvert)
{
    string StrReturn = "";
    if (NumbToConvert == 1)
    {
        StrReturn = "one";
    }
    else if(NumbToConvert == 2)
    {
        StrReturn = "two";
    }
    else if(NumbToConvert == 3)
    {
        StrReturn = "three";
    }
    else if(NumbToConvert == 4)
    {
        StrReturn = "four";
    }
    else if(NumbToConvert == 5)
    {
        StrReturn = "five";
    }
    else if(NumbToConvert == 6)
    {
        StrReturn = "six";
    }
    else if(NumbToConvert == 7)
    {
        StrReturn = "seven";
    }
    else if(NumbToConvert == 8)
    {
        StrReturn = "eight";
    }
    else if(NumbToConvert == 9)
    {
        StrReturn = "nine";
    }
    else
    {
        StrReturn = "";
    }
    return StrReturn;
}

//Convert individual digits from numbers
//to plain english (Tens)
string ConvertTens(int NumbToConvert)
{
    string StrReturn = "";
    if (NumbToConvert == 1)
    {
        StrReturn = "ten";
    }
    else if(NumbToConvert == 2)
    {
        StrReturn = "twenty";
    }
    else if(NumbToConvert == 3)
    {
        StrReturn = "thirty";
    }
    else if(NumbToConvert == 4)
    {
        StrReturn = "fourty";
    }
    else if(NumbToConvert == 5)
    {
        StrReturn = "fifty";
    }
    else if(NumbToConvert == 6)
    {
        StrReturn = "sixty";
    }
    else if(NumbToConvert == 7)
    {
        StrReturn = "seventy";
    }
    else if(NumbToConvert == 8)
    {
        StrReturn = "eighty";
    }
    else if(NumbToConvert == 9)
    {
        StrReturn = "ninety";
    }
    else
    {
        StrReturn = "";
    }
    return StrReturn;
}

//Convert individual digits from numbers
//to plain english (Teens)
string ConvertTeens(int NumbToConvert)
{
    string StrReturn = "";
    if (NumbToConvert == 1)
    {
        StrReturn = "eleven";
    }
    else if(NumbToConvert == 2)
    {
        StrReturn = "twelve";
    }
    else if(NumbToConvert == 3)
    {
        StrReturn = "thirteen";
    }
    else if(NumbToConvert == 4)
    {
        StrReturn = "fourteen";
    }
    else if(NumbToConvert == 5)
    {
        StrReturn = "fifteen";
    }
    else if(NumbToConvert == 6)
    {
        StrReturn = "sixteen";
    }
    else if(NumbToConvert == 7)
    {
        StrReturn = "seventeen";
    }
    else if(NumbToConvert == 8)
    {
        StrReturn = "eighteen";
    }
    else if(NumbToConvert == 9)
    {
        StrReturn = "nineteen";
    }
    else
    {
        StrReturn = "";
    }
    return StrReturn;
}
