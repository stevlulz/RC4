#include <iostream>
#include <fstream>
#include <cstring>
#include "rc4/RC4.h"

int main(int argc,char**argv){
    std::string help = "--help";
    std::string fileName;
    std::string key = "45A01F645FC35B383552544B9BF5";
    std::string resultFile = "res.txt";
    if(argc == 1){
        std::cout<<"you must enter a valid arguments"<<std::endl;
        std::cout<<"Try ./programName --help"<<std::endl;
        exit(-1);
    }
    if(argc != 4 && argc !=5){
        if(help == argv[1]){
            std::cout<<"File Encryption && Decryption using RC4"<<std::endl;
            std::cout<<"./program -f [fileName] (-e OR -d) (-de OR -k [key])"<<std::endl;
            std::cout<<"\t\t"<<"-f [FileName]"<<std::endl;
            std::cout<<"\t\t"<<"-de | use default seed"<<std::endl;
            std::cout<<"\t\t"<<"-k [key]"<<std::endl;
        }
        else{
            std::cout<<"you must enter a valid arguments"<<std::endl;
            std::cout<<"Try ./programName --help"<<std::endl;
            exit(-1);
        }
    }

    if(argv[1][0] == '-'&&argv[1][1]=='f'){
        fileName = argv[2];
    }


    if(argv[3][1] == 'k'){//default
        if(argv[4]){
          key = argv[4];
        }
        else
            std::cout<<"You must enter a valid key or use default argument"<<std::endl,exit(-1);
    }


    RC4 rc4(key);
    rc4.KSA();

    std::ifstream inFile;
    size_t size = 0; // here

    inFile.open(fileName.c_str(), std::ios::in|std::ios::binary|std::ios::ate );
    char* oData = 0;


    inFile.seekg(0, std::ios::end); // set the pointer to the end
    size = inFile.tellg() ; // get the length of the file
    std::cout << "Size of file: " << size;
    inFile.seekg(0, std::ios::beg); // set the pointer to the beginning

    oData = new char[ size+1 ]; //  for the '\0'
    inFile.read( oData, size );
    oData[size] = '\0' ; // set '\0'

    std::string res = "";
    for ( size_t i = 0; i < strlen(oData); i++ )
    {
            oData[i] = rc4.encrypt_decrypt((unsigned char)oData[i]);

    }


    std::ofstream myfile;
    myfile.open (resultFile.c_str());
    myfile <<oData;
    myfile.close();




    return 0;
}