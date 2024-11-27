#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>

// Function to generate trigrams from a word
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

int main()
{
    std::ifstream input_file("dict-words.txt");          // Open input file
    std::ofstream output_file("trigram_dict_words.txt"); // Open output file

    if (!input_file.is_open() || !output_file.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string word;
    while (std::getline(input_file, word))
    { // Read each word from the file
        // Generate trigrams
        std::vector<std::string> trigrams = generate_trigrams(word);

        // Sort trigrams alphabetically
        std::sort(trigrams.begin(), trigrams.end());

        // Write word, number of trigrams, and the sorted trigrams to the output file
        output_file << word << " " << trigrams.size(); // Write word and number of trigrams
        for (const auto &trigram : trigrams)
        {
            output_file << " " << trigram; // Write each trigram
        }
        output_file << "\n"; // New line after each word
    }

    input_file.close();  // Close input file
    output_file.close(); // Close output file

    std::cout << "Processing complete! Check 'words.txt'." << std::endl;

    return 0;
}
