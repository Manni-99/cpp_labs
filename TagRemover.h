#include <iostream>
#include <string>
#include <regex>
#include <unordered_map>
#include <sstream>

class TagRemover{
    public:
        TagRemover(std::istream& input){
            std::ostringstream buffer;
            buffer << input.rdbuf();
            content = buffer.str();
        }

        void print(std::ostream& output){
            std::string without_tags = removeHTMLTags(content);
            std::string decoded_content = decodeHTMLEntities(without_tags);
            output << decoded_content;
        }

    private:
        std::string content;

        std::string removeHTMLTags(const std::string& input){
            std::regex tagRegex("<[^>]+>");
            return std::regex_replace(input, tagRegex, "");
        }
    
        std::string decodeHTMLEntities(const std::string& input){
            static const std::unordered_map<std::string, char> htmlEntities = {
                {"&amp;", '&'},
                {"&lt;", '<'},
                {"&gt;", '>'},
                {"&quot;", '"'},
                {"&apos;", '\''},
                {"&nbsp;", ' '},
            };
            
            std::string output = input;
            for(const auto& entity : htmlEntities){
                size_t pos = 0;
                while((pos = output.find(entity.first, pos)) != std::string::npos){
                    output.replace(pos, entity.first.length(), std::string(1, entity.second));
                    pos += entity.first.length();;
                }
            }
            return output;
        }
};