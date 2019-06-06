#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char **argv) {
    std::string fileName;
    std::string s1, s2;
    std::fstream inFile;
    std::string buffer;

    if (argc == 4 && argv[1][0] != '\0' && argv[2][0] != '\0' && argv[3][0] != '\0') {
        s1 = argv[2];
        s2 = argv[3];
        fileName = argv[1];
        inFile.open(fileName);
        if (inFile.fail()) {
            std::cout << "file does not exist" << std::endl;
            return (0);
        }
        std::string outFileName = fileName + ".replace";
        std::ofstream outFile(outFileName);
        if (!outFile) {
            std::cout << "error creating file" << std::endl;
            return (0);
        }
        while (getline(inFile, buffer)) {
            unsigned long i = 0;
            while (i < buffer.length() && buffer.find(s1) != std::string::npos) {
                unsigned long location = buffer.find(s1, i);
                buffer.replace(location, s1.length(), s2);
                i = location + s2.length();
            }
            outFile << buffer << std::endl;
        }
        inFile.close();
        outFile.close();
    } else {
        std::cout << "Bad input: replace [filename] [target] [source]" << std::endl;
    }
    return (0);
}