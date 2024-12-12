#include <iostream>
#include <fstream>
#include <sstream>
#include "TagRemover.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <html-file>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cerr << "Error: Could not open file " << argv[1] << std::endl;
        return 1;
    }

    TagRemover tr(inputFile);  // Create TagRemover object from input file
    tr.print(std::cout);       // Print the processed output (tags removed and entities decoded)

    return 0;
}

