#include "FileProcessor.h"

FileProcessor::FileProcessor()
{
}

FileProcessor::~FileProcessor()
{
}

Translator translator;

void FileProcessor::processString(std::string file, std::string output) {
    std::ifstream inputFile(file);
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
        outputFile << "<p><i>" << translatedLine << "<i></p>\n";
    }

    inputFile.close(); 

}
