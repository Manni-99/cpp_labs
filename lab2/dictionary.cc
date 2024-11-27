#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>  
#include "word.h"
#include "dictionary.h"
#include "spell_checker.h"
using std::string;
using std::vector;

std::vector<std::string> generate_trigrams(const std::string &word)
{
    std::vector<std::string> trigrams;
    if(word.size() < 3)
    {
        return trigrams;
    }
    // Convert word to lowercase
    std::string lowercase_word = word;
    std::transform(lowercase_word.begin(), lowercase_word.end(), lowercase_word.begin(), ::tolower);

    // Generate trigrams
    for (size_t i = 0; i <= lowercase_word.length() - 3; ++i)
    {

        trigrams.push_back(lowercase_word.substr(i, 3));
    }

    return trigrams;
}

std::vector<std::string> split(const std::string& line) {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string word;
    while (ss >> word) {
        result.push_back(word);
    }
    return result;
}

Dictionary::Dictionary() {
	std::ifstream input_file("trigram_dict_words.txt");
	
	if (!input_file.is_open()){
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

	std::string line;
    while (std::getline(input_file, line)){
		std::vector<std::string> parts = split(line);
        
        // The first element is the word, the second element is the number of trigrams
        std::string word = parts[0];
        
        // Ignore words longer than maxlen
        if (word.length() > maxlen) continue;

        // The rest are the trigrams
        std::vector<std::string> trigrams(parts.begin() + 2, parts.end());

        // Create a Word object and store it in the appropriate vector based on word length
        Word word_obj(word, trigrams);
        words[word.length() - 1].push_back(word_obj);  
        
        // Add word to the set for quick lookup
        words_set.insert(word);
	}
	input_file.close();
}

bool Dictionary::contains(const string& word) const {
	return words_set.find(word) != words_set.end();
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	// Add trigram-based suggestions to the vector
    add_trigram_suggestions(word, suggestions);
    
    // Rank the suggestions based on their edit distance to the input word
    rank_suggestions(word, suggestions);
    
    // Trim the suggestions to ensure no more than 5 suggestions
    trim_suggestions(suggestions);
    
	return suggestions;
}

void Dictionary::add_trigram_suggestions(const std::string& word, std::vector<std::string>& suggestions) const {
    // Generate trigrams for the input word
    std::vector<std::string> word_trigrams = generate_trigrams(word);

    // Loop through words with the same length and compare trigrams
    for (const auto& w : words[word.length() - 1]) {
        unsigned int match_count = w.get_matches(word_trigrams);
        
        // If a word has more than 0 matching trigrams, add it to suggestions
        if (match_count > 0) {
            suggestions.push_back(w.get_word());
        }
    }
}

void Dictionary::rank_suggestions(const std::string& word, std::vector<std::string>& suggestions)
{
    // Sort suggestions based on their edit distance to the input word
    std::sort(suggestions.begin(), suggestions.end(),
        [&word](const std::string& a, const std::string& b) {
            return SpellChecker::edit_distance(word, a) < SpellChecker::edit_distance(word, b);
        });
}
void Dictionary::trim_suggestions(std::vector<std::string>& suggestions) const
{
    if (suggestions.size() <= 5) {
        return;
    }
    
    suggestions.resize(5);
}