#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString
{

private:
	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue)) string Value;

	static short Length(string S1)
	{
		return S1.length();
	}

	short Length()
	{
		return Length(_Value);
	}

	static short CountWords(string S1)
	{
		string Delim = " ";
		short Pos = 0, Cnt = 0;
		string Sword;
		while ((Pos = S1.find(Delim)) != std::string::npos)
		{
			Sword = S1.substr(0, Pos);
			if (Sword != "")
				Cnt++;
			S1.erase(0, Pos + Delim.length());
		}
		if (S1 != "")
			Cnt++;
		return Cnt;
	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static string UpperFirstLetter(string S)
	{
		bool FirstLetter = true;
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ' && FirstLetter)
				S[i] = toupper(S[i]);

			FirstLetter = (S[i] == ' ' ? true : false);
		}
		return S;
	}

	void UpperFirstLetter()
	{
		// no need to return value , this function will directly update the object value
		_Value = UpperFirstLetter(_Value);
	}

	static string LowerFirstLetter(string S)
	{
		bool FirstLetter = true;
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ' && FirstLetter)
				S[i] = tolower(S[i]);

			FirstLetter = (S[i] == ' ' ? true : false);
		}
		return S;
	}

	void LowerFirstLetter()
	{
		_Value = LowerFirstLetter(_Value);
	}

	static string UpperAllString(string S)
	{
		for (int i = 0; i < S.size(); i++)
		{
			S[i] = toupper(S[i]);
		}
		return S;
	}

	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string S)
	{
		for (int i = 0; i < S.size(); i++)
		{
			S[i] = tolower(S[i]);
		}
		return S;
	}

	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}

	static char InvertingChar(char C)
	{
		return isupper(C) ? tolower(C) : toupper(C);
	}

	static string InvertAllLetter(string S)
	{
		for (int i = 0; i < S.size(); i++)
		{
			S[i] = InvertingChar(S[i]);
		}
		return S;
	}

	void InvertAllLetter()
	{
		_Value = InvertAllLetter(_Value);
	}

	enum enWhatToCount { Small = 0, Capital = 1, All = 2 };
	static int CountLetters(string S, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		if (WhatToCount == enWhatToCount::All)
			return S.length();

		short Counter = 0;
		for (int i = 0; i < S.length(); i++)
		{
			if (WhatToCount == enWhatToCount::Capital && isupper(S[i]))
				Counter++;

			if (WhatToCount == enWhatToCount::Small && islower(S[i]))
				Counter++;
		}

		return Counter;
	}

	static int CountCapitalLetter(string S)
	{
		int Count = 0;
		for (int i = 0; i < S.size(); i++)
		{
			Count += isupper(S[i]);
		}
		return Count;
	}

	int CountCapitalLetter()
	{
		return CountCapitalLetter(_Value);
	}

	static int CountSmallLetter(string S)
	{
		int Count = 0;
		for (int i = 0; i < S.size(); i++)
		{
			Count += islower(S[i]);
		}
		return Count;
	}

	int CountSmallLetter()
	{
		return  CountSmallLetter(_Value);
	}

	static int CountSpecifiersLetter(string S, char Letter, bool MatchCase = true)
	{
		int Counter = 0;
		if (MatchCase)
		{
			for (int i = 0; i < S.length(); i++)
			{
				if (S[i] == Letter)
					Counter++;
			}
		}
		else
		{
			for (int i = 0; i < S.length(); i++)
			{
				if (tolower(S[i]) == tolower(Letter))
					Counter++;
			}
		}

		return Counter;
	}

	int CountSpecifiersLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecifiersLetter(_Value, Letter, MatchCase);
	}

	static bool Is_Vowel(char Ch)
	{
		Ch = tolower(Ch);
		return (Ch == 'a' || Ch == 'e' || Ch == 'i' || Ch == 'o' || Ch == 'u');
	}

	static short CountVowels(string S)
	{
		int Count = 0;
		for (int i = 0; i < S.size(); i++)
		{
			Count += Is_Vowel(S[i]);
		}
		return Count;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static vector<string> SplitString(string S, string Delim)
	{
		vector<string>VString;
		short Pos = 0;
		string Sword;
		while ((Pos = S.find(Delim)) != S.npos)
		{
			Sword = S.substr(0, Pos);
			if (Sword != "")
				VString.push_back(Sword);
			S.erase(0, Pos + Delim.length());
		}

		if (S != "")
			VString.push_back(S);
		return VString;
	}


	vector<string> SplitString(string Delim)
	{
		return  SplitString(_Value, Delim);
	}

	static string TrimLeft(string S)
	{
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] != ' ')
				return S.substr(i);
		}
		return "";
	}

	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S)
	{
		for (int i = S.size() - 1; i >= 0; i--)
		{
			if (S[i] != ' ')
				return S.substr(0, i + 1);
		}
		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}


	static string Trim(string S)
	{
		return TrimRight(TrimLeft(S));
	}

	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string>VString, string Delim)
	{
		string S = "";
		for (string& S1 : VString)
		{
			S += S1 + Delim;
		}
		return S.substr(0, S.length() - Delim.length());
	}

	static string JoinString(string arrstring[], short Length, string Delim)
	{
		string S = "";
		for (int i = 0; i < Length; i++)
		{
			S += arrstring[i] + Delim;
		}
		return S.substr(0, S.length() - Delim.length());
	}

	static string ReverseWords(string S1)
	{
		string S2 = "";
		vector<string>vString;
		vString = SplitString(S1, " ");

		// declare iterator
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}

		S2 = S2.substr(0, S2.length() - 1); // remove last space 

		return S2;
	}

	void ReverseWords()
	{
		_Value = ReverseWords(_Value);
	}

	static string ReplaceWords(string S, string StringToReplace, string SReplaceto, bool MatchCase = true)
	{
		vector<string>Vstring = SplitString(S, " ");
		for (string& s : Vstring)
		{
			if (MatchCase)
			{
				if (s == StringToReplace)
					s = SReplaceto;
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(StringToReplace))
					s = SReplaceto;
			}
		}
		return JoinString(Vstring, " ");
	}

	string ReplaceWords(string StringToReplace, string SReplaceto)
	{
		return ReplaceWords(_Value, StringToReplace, SReplaceto);
	}

	static string RemovePunctuation(string S)
	{
		string S2 = "";
		for (int i = 0; i < S.size(); i++)
		{
			if (!ispunct(S[i]))
				S2 += S[i];
		}
		return S2;
	}

	void RemovePunctuation()
	{
		_Value = RemovePunctuation(_Value);
	}
};

