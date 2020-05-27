#include <bits/stdc++.h>
using namespace std;
#define MOD 101
#define alphaKey 256
void RabinKarp(string text, string pattern)
{
    int textLength = text.length();
    int patternLength = pattern.length();
    int textHashValue = 0, patterHashValue = 0;
    int h = 1;
    for (int i = 0; i < patternLength - 1; i++)
        h = (h * alphaKey) % MOD;
    for (int i = 0; i < patternLength; i++)
    {
        textHashValue = (alphaKey * textHashValue + text[i]) % MOD;
        patterHashValue = (alphaKey * patterHashValue + pattern[i]) % MOD;
    }
    for (int i = 0; i < textLength - patternLength; i++)
    {
        int j = 0;
        if (patterHashValue == textHashValue)
        {
            for (j = 0; j < patternLength; j++)
            {
                if (pattern[j] != text[i + j])
                    break;
            }
            if (j == patternLength)
                cout << "Pattern found at index : " << i << '\n';
        }
        if (i < textLength - patternLength)
        {
            textHashValue = (alphaKey * (textHashValue - text[i] * h) + text[i + patternLength]) % MOD;
            if (textHashValue < 0)
                textHashValue = textHashValue + MOD;
        }
    }
}
int main()
{
    string text = "GEEKS FOR GEEKS";
    string pattern = "GEEK";
    RabinKarp(text, pattern);
    return 0;
}