#include <iostream>
#include <vector>
#include <string>
#include <algorithm>    
#include "spell_checker.h"

int SpellChecker::edit_distance(const std::string& p, const std::string& q){
    int m = p.size();
    int n = q.size();

	static constexpr int maxlen = 25;
    int d[maxlen +1][maxlen +1];
    // Initialize the matrix (base cases)
    for (int i = 0; i <= m; ++i) {
        d[i][0] = i;  // Deleting all characters from p to match an empty string q
    }
    for (int j = 0; j <= n; ++j) {
        d[0][j] = j;  // Inserting all characters to match an empty string p
    }

    // Fill the matrix with dynamic programming
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            // If characters match, no edit needed
            int cost = (p[i - 1] == q[j - 1]) ? 0 : 1;

            // Take the minimum of the three possible operations
            d[i][j] = std::min({d[i - 1][j] + 1,    // Deletion
                                d[i][j - 1] + 1,    // Insertion
                                d[i - 1][j - 1] + cost});  // Substitution
        }
    }

    return d[m][n];  // Return the edit distance
    

}

