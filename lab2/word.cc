#include <string>
#include <vector>
#include "word.h"

using std::string;
using std::vector;

Word::Word(const string &w, const vector<string> &t) : word(w), trigrams(t)
{
	std::sort(trigrams.begin(), trigrams.end());
}

string Word::get_word() const
{
	return word;
}

unsigned int Word::get_matches(const vector<string> &t) const
{
	 unsigned int count = 0;
    
    for (const auto& trigram : t) {
        if (std::find(trigrams.begin(), trigrams.end(), trigram) != trigrams.end()) {
            ++count;
        }
    }
    return count;
}
