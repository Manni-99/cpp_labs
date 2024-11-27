#ifndef SPELL_CHECKER_H
#define SPELL_CHECKER_H

#include <string>
#include <vector>
class SpellChecker {
public:
    // Static function to calculate the edit distance between two strings
    static int edit_distance(const std::string& p, const std::string& q);

};
#endif