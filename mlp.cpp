#include "mlp.h"



void MLP::readStructure(string fileName="") {

    if (fileName == "") {
        fileName = fileStructure;
    }
    ifstream myfile;
    myfile.open(fileName.c_str());
    if (myfile.is_open())
    {
        string line;
        nbLayer = 0;
        while (getline (myfile,line)) {
            cout << line << endl;
            nbLayer++;
        }
        myfile.close();
    }
    else
    {
        cerr << "could not open the file: "<<fileName.c_str() << endl;
    }
    return;
}


MLP::MLP() {
    cout << "create new mlp" << endl;
    readStructure();
}



int main(int nbargs, char** args) {
    cout << "coucou" << endl;
    MLP* testmlp = new MLP();
}

