#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:

    enum enCharType { CapitalLetter = 1, SmallLetter = 2, Digit = 3, MixChar = 4, SpecialChar = 5 };

    static void Srand()
    {
        //Seeds the random number generator in C++, called only once
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        // function to generate the random number
        int RandNum = rand() % (To - From + 1) + From;

        return RandNum;
    }

    static char GetRandomCharacter(enCharType CharType)
    {

        if (CharType == MixChar)
        {
            CharType = (enCharType)RandomNumber(1, 3);
        }
        switch (CharType)
        {
        case enCharType::SmallLetter:
        {
            return char(RandomNumber(97, 122));
            break;
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
            break;
        }
        case enCharType::SpecialChar:
        {
            return char(RandomNumber(33, 47));
            break;
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
            break;
        }
        }
    }


    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word;

        for (int i = 1; i <= Length; i++)
        {
            Word += GetRandomCharacter(CharType);
        }

        return Word;
    }

    static string GenerateKey(enCharType  CharType = CapitalLetter)
    {
        string Key = "";

        Key = GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4) + "-";
        Key += GenerateWord(CharType, 4);

        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [ " << i << " ] : " << GenerateKey(CharType) << endl;
        }
    }

    static void Swap(int& Num1, int& Num2)
    {
        int Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(double& Num1, double& Num2)
    {
        double Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }

    static void Swap(bool& Num1, bool& Num2)
    {
        bool Temp = Num1;
        Num1 = Num2;
        Num2 = Temp;
    }


    static void Swap(char& C1, char& C2)
    {
        char Temp = C1;
        C1 = C2;
        C2 = Temp;
    }

    static void Swap(string& S1, string& S2)
    {
        string Temp = S1;
        S1 = S2;
        S2 = Temp;
    }

    static void Swap(clsDate& Date1, clsDate& Date2)
    {
        clsDate::SwapDates(Date1, Date2);
    }

    static void ShuffleArray(int Arr[100], int ArrLength)
    {
        for (int i = 0; i < ArrLength; i++)
        {
            Swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
        }
    }

    static  void ShuffleArray(string arr[100], int arrLength)
    {
        for (int i = 0; i < arrLength; i++)
        {
            Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
        }

    }

    static void FillArrayWithRandomNumber(int Arr[100], int Length, int From, int To)
    {
        for (int i = 0; i < Length; i++)
        {
            Arr[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string arr[100], int Length, enCharType CharType, int WordLength)
    {
        for (int i = 0; i < Length; i++)
        {
            arr[i] = GenerateWord(CharType, WordLength);
        }
    }

    static void FillArrayWithRandomKeys(string arr[100], int Length, enCharType CharType)
    {
        for (int i = 0; i < Length; i++)
        {
            arr[i] = GenerateKey(CharType);
        }
    }

    static string  Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;
    }

    static string EncryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);

        }
        return Text;
    }

    static string DecryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }

        return Text;
    }

    static string NumberToText(long long Number)
    {
        if (Number == 0)
            return "";
        else if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One", "Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve",
                "Thirteen","Fourteen","Fiveteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return arr[Number] + " ";
        }
        else if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy",
            "Eighty","Ninety" };

            return arr[Number / 10] + " " + NumberToText(Number % 10);
        }
        else if (Number >= 100 && Number <= 199)
        {
            return "One Hundred " + NumberToText(Number % 100);
        }
        else if (Number >= 200 && Number <= 999)
        {
            return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 100);
        }
        else if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }
        else if (Number >= 2000 && Number <= 999999)
        {
            return NumberToText(Number / 1000) + " Thousand " + NumberToText(Number % 1000);
        }
        else if (Number >= 1000000 && Number <= 1999999)
        {
            return "One Million " + NumberToText(Number % 1000000);
        }
        else if (Number >= 2000000 && Number <= 999999999)
        {
            return NumberToText(Number / 1000000) + " Million " + NumberToText(Number % 1000000);
        }
        else if (Number >= 1000000000 && Number <= 1999999999)
        {
            return "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return NumberToText(Number / 1000000000) + " Billion " + NumberToText(Number % 1000000000);
        }
    }
};

