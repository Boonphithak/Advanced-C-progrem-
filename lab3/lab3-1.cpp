#include <iostream>
#include <string>
#include <fstream>

 
 

int main(){
    std::ifstream file("arai.text");
    std::string line;
    while(std::getline(file, line)){
        std::cout << line << std::endl;
        std::string lowerline = line;
        for (char& c : lowerline) {
            c = std::tolower(c);
        }

        size_t pos = line.find("Love");
        
        if (pos >= line.length()) {
            std::cout << "love not found" << std::endl;
        } else {
            std::cout << "love found at position " << pos << std::endl;
        }

        //tokennize the line in to word
        size_t start = 0;
        size_t end = line.find(" ");
        bool found = false;
        while (end != std::string::npos) {
            std::string word = line.substr(start, end - start);
            start = end + 1;
            end = line.find(" ", start);
            std::cout << word << std::endl;

        }
       
        
        
    }
    file.close();
    return 0;

}