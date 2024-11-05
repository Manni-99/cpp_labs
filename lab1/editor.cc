#include "editor.h"
#include <iostream>
#include <string>
#include <stack>

using std::string;

using size_type = Editor::size_type;

size_type Editor::get_size() const
{
    return text.size();
}

size_type Editor::find_left_par(size_type pos) const
{
    if (pos >= get_size())
    {
        pos = get_size() - 1;
    }

    // Only proceed if the character at pos is a closing parenthesis
    char closingChar = text[pos];
    if (closingChar != ')' && closingChar != '}' && closingChar != ']')
    {
        return std::string::npos;
    }

    std::stack<char> parStack;
    parStack.push(closingChar);  // Start by pushing the initial closing parenthesis

    // Traverse the string backward from pos - 1
    for (size_type i = pos - 1; i != static_cast<size_type>(-1); --i)
    {
        char curr = text[i];
      //  std::cout << "Current character: " << curr << " at position " << i << std::endl;

        // If we encounter another closing parenthesis, push it onto the stack
        if (curr == ')' || curr == '}' || curr == ']')
        {
            parStack.push(curr);
    //        std::cout << "Pushed to stack: " << curr << std::endl;
        }
        // If we encounter an opening parenthesis, check if it matches the top of the stack
        else if (curr == '(' || curr == '{' || curr == '[')
        {
            // Check if the current opening character matches the top of the stack
            if (!parStack.empty() &&
                ((curr == '(' && parStack.top() == ')') ||
                 (curr == '{' && parStack.top() == '}') ||
                 (curr == '[' && parStack.top() == ']')))
            {
                parStack.pop();
                //std::cout << "Popped from stack, matching: " << curr << std::endl;

                // If the stack is empty, we've found the matching opening parenthesis
                if (parStack.empty())
                {
                  //  std::cout << "Stack is empty, returning position: " << i << std::endl;
                    return i;
                }
            }
        }
    }

    // No match found
  //  std::cout << "No match found, returning -1" << std::endl;
    return std::string::npos;
}
