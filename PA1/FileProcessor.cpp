/*
Joshua Vaysman
2449656
vaysman@chapman.edu
CPSC 350-02
PA1
*/

// Takes a file with English words and outputs them to an html in Robber. I put the html within the proccessString function.
// There may have been a better way to set that up, but I've never worked with HTML before and once I got it to work I 
// decided to not mess with it further.

#include "FileProcessor.h"

/*
Default Constructor
*/
FileProcessor::FileProcessor()
{
}

/*
Default Destructor
*/
FileProcessor::~FileProcessor()
{
}

/*
a. processString
b. Returns nothing. Writes to an html file
c. c. Parameters:
   - 'input': A string representing the name of the input file to read
   - 'output': A string representing the name of the output file to write
*/
void FileProcessor::processString(std::string input, std::string output) {
    std::ifstream inputFile(input);
    std::ofstream outputFile(output);

    outputFile << "<!DOCTYPE html>\n";
    outputFile << "<html>\n";
    outputFile << "<head>\n";
    outputFile << "<title>Translation Output</title>\n";
    outputFile << "</head>\n";
    outputFile << "<body>\n";

    std::string line;
    while (std::getline(inputFile, line)) { 
        outputFile << "<p><b>" << line << "<b><p>\n\n";
        std::string translatedLine = translator.translateEnglishSentence(line);
        outputFile << "<p><i>" << translatedLine << "<i></p>\n\n";
    }

    inputFile.close(); 

}
