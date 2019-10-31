#include <iostream>
#include <fstream>
using namespace std;

void readEntry(ifstream& in, int& entry);

int main() {

    ifstream inFile; //cin
    ofstream outFile; //cout

    inFile.open("input.txt");
    outFile.open("output.txt");

    if (!inFile.is_open()){
        outFile<<"Could not open the input.txt file"<<endl;
        return 1;
    }


    // read table dimensions and allocate 2D array
    cout<< "test 1"<<endl;
    int nRows, nCols;
    char c;
    inFile >> nRows >> nCols;
    int** table = new int*[nRows];
    for(int i = 0; i < nRows; i++) {
        table[i] = new int[nCols];
    }

    // read table data
    outFile<<"Enter your numbers: ";
    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < nCols; j++) {
            try {
              readEntry(inFile,table[i][j]);
            }
            catch (int x) {
                    outFile << "Entry " << i << "," << j << " not an integer, was set to " << x << ", now setting it to 0" << endl;
                    table[i][j] = 0;
                    inFile.clear();
                    string tmp;
                    inFile >> tmp;
            }
        }
    }


    // write table data to the screen in transposed order
    outFile << nCols << " " << nRows << endl;
    for(int i = 0; i < nCols; i++) {
        for(int j = 0; j < nRows; j++) {
            outFile << table[j][i] << " ";
        }
        outFile << endl;
    }


    // free memory
    for(int i = 0; i < nRows; i++) {
        delete [] table[i];
    }
    delete [] table;

    inFile.close();
    outFile.close();

}

void readEntry(ifstream& in, int& entry) {

    in >> entry;
    if(in.fail()) {
        throw entry;
    }
}