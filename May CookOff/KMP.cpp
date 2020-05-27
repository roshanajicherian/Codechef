#include <bits/stdc++.h>
using namespace std;
void preComputeLPS(int LPS[], int patternLength, string pattern)
{
    int LPSLength = 0;
    LPS[0] = 0;
    int i = 1;
    while (i < patternLength)
    {
        if (pattern[i] == pattern[LPSLength])
        {
            LPSLength++;
            LPS[i] = LPSLength;
            i++;
        }
        else
        {
            if (LPSLength != 0)
                LPSLength = LPS[LPSLength - 1];
            else
            {
                LPS[i] = 0;
                i++;
            }
        }
    }
}
void KMP(string text, string pattern)
{
    int patternLength = pattern.length();
    int textLength = text.length();
    int LPS[patternLength];
    preComputeLPS(LPS, patternLength, pattern);
    int textIterator = 0, patternIterator = 0;
    while (textIterator < textLength)
    {
        if (pattern[patternIterator] == text[textIterator])
        {
            patternIterator++;
            textIterator++;
        }
        if (patternIterator == patternLength)
        {
            cout << "Pattern found at index : " << textIterator - patternIterator << '\n';
            patternIterator = LPS[patternIterator - 1];
        }
        else if (textIterator < textLength && pattern[patternIterator] != text[textIterator])
        {
            if (patternIterator != 0)
                patternIterator = LPS[patternIterator - 1];
            else
                textIterator++;
        }
    }
}
int main()
{
    string text, pattern;
    cin >> text >> pattern;
    KMP(text, pattern);
    return 0;
}