// PE- FileIO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    
   //output for the text file
    ofstream outputFile;

    outputFile.open("text.txt");

    if (outputFile.is_open()) {
        //print this text to the file, and close the file
        outputFile << "some text for the PE \n";
        outputFile << "Here's a second line of text \n";
        outputFile.close();

    }

    //read from the text file
    ifstream inputFile;

    inputFile.open("text.txt", ios::binary);


    if (inputFile.is_open()) {
        //read all the content fromt the file and return the length
        inputFile.seekg(0, ios::end);
        int fileLength = (int)inputFile.tellg();
        inputFile.seekg(0, ios::beg);

        char* text = new char[fileLength + 1];

        //read the file, and input all content of the file to an array
        inputFile.read(text, fileLength);
        text[fileLength] = 0;

        //print the text in the array to the console
        printf(text);
        //close the file
        inputFile.close();
    }


    
}


