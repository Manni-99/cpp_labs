// coder.cc
#include "coder.h"   // Include coder.h for utility functions (if needed)
#include "coding.h"   // Include the header file for function declarations
#include <iostream>
#include <fstream>
#include <string>

void handle_encoding_decoding(int argc, const char** argv)
{
    std::ifstream input_file;
    std::ofstream output_file;

    if (argc < 2)  // If no arguments are passed, prompt the user
    {
        std::cerr << "Usage: ./encode [-d] <filename>" << std::endl;
        return;
    }

    std::string mode = "encode";  // Default mode is encoding
    std::string input_filename;
    std::string output_filename;

    if (argc == 3 && std::string(argv[1]) == "-d")
    {
        mode = "decode";
        input_filename = argv[2];
        output_filename = input_filename + ".dec";  // Output file for decoded content
    }
    else if (argc == 2)
    {
        input_filename = argv[1];
        output_filename = input_filename + ".enc";  // Output file for encoded content
    }
    else
    {
        std::cerr << "Usage: ./encode [-d] <filename>" << std::endl;
        return;
    }

    input_file.open(input_filename);
    if (!input_file)
    {
        std::cerr << "Error opening input file: " << input_filename << std::endl;
        return;
    }

    output_file.open(output_filename);
    if (!output_file)
    {
        std::cerr << "Error opening output file: " << output_filename << std::endl;
        return;
    }

    if (mode == "encode")
    {
        encode_file(input_file, output_file);  // Encode the file
    }
    else if (mode == "decode")
    {
        decode_file(input_file, output_file);  // Decode the file
    }
}

int main(int argc, const char** argv)
{
    handle_encoding_decoding(argc, argv);
    return 0;
}
