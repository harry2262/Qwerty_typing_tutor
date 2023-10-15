#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <random>

using namespace std;
vector<string> generate_words()
{
    fstream text;
    vector<string> words;
    text.open("200en", ios::in);
    if (text.is_open())
    {
        string word;

        while (getline(text, word))
        {
            words.push_back(word);
        }
    }

    text.close();
    return words;
}
string generate_passage(vector<string>&words){
int words_len = 0;
    cout << "enter length of words" << endl;
    cin >> words_len;
    fflush(stdin);

    // default_random_engine generator;
    random_device rd;
    uniform_int_distribution<int> distribution(0, words.size() - 1);
    int index;
    string passage;
    for (int i = 0; i < words_len; i++)
    {
        index = distribution(rd);
        for (const auto &character : words[index])
        {
            passage.push_back(character);
        }
        passage.push_back(' ');
    }
    return passage;
}
