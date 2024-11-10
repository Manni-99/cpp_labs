#ifndef CODING_H
#define CODING_H
#include <iostream>  // For std::istream and std::ostream

unsigned char encode(unsigned char c);
unsigned char decode(unsigned char c);
void encode_file(std::istream& input, std::ostream& output);
void decode_file(std::istream& input, std::ostream& output);

#endif
