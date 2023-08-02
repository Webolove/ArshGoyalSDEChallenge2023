#include "bits/stdc++.h"
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    // if(beginWord == endWord)
    //     return 1;

    set<string> wordSet;
    for (int i = 0; i < wordList.size(); ++i)
        wordSet.insert(wordList[i]);

    queue<pair<int, string>> pq;
    pq.push({1, beginWord});

    while (!pq.empty())
    {
        int val = pq.front().first;
        string word = pq.front().second;
        pq.pop();

        if (word == endWord)
            return val;

        for (int i = 0; i < word.size(); ++i)
        {
            int currChar = word[i];
            for (char c = 'a'; c <= 'z'; ++c)
            {
                word[i] = c;
                if (wordSet.find(word) != wordSet.end())
                {
                    pq.push({val + 1, word});
                    wordSet.erase(word);
                }
            }
            word[i] = currChar;
        }
    }
    return 0;
}

int main()
{

    return 0;
}