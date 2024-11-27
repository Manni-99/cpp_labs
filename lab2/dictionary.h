#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
#include "word.h"

using std::string;
using std::unordered_set;
using std::vector;

class Dictionary
{
public:
	Dictionary();
	bool contains(const std::string &word) const;
	std::vector<std::string> get_suggestions(const std::string &word) const;
    void add_trigram_suggestions(const std::string& word, std::vector<std::string>& suggestions) const; 
	static void rank_suggestions(const std::string& word, std::vector<std::string>& suggestions) ;
    void trim_suggestions(std::vector<std::string>& suggestions) const;  

private:
	static constexpr int maxlen = 25;
	unordered_set<string> words_set;
	vector<Word> words[maxlen];
};

#endif
