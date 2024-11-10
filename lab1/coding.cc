#include "coding.h"
#include <iostream>
#include <fstream>
#include <string>

unsigned char encode(unsigned char c)
{
    return (c + 5) % 256; // Shift ASCII Value by 5
}

unsigned char decode(unsigned char c)
{
    return (c - 5 + 256) % 256; // Reverse Shift ASCII Value by 5
}

void encode_file(std::istream& input, std::ostream& output)
{
    char c;
    while(input.get(c))
    {
        unsigned char encoded_c = encode(c);
        output.put(encoded_c);
    }
}
void decode_file(std::istream& input, std::ostream& output)
{
    char c;
    while(input.get(c))
    {
        unsigned char decoded_c = decode(c);
        output.put(decoded_c);
    }
}

