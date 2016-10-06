#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#define NB_INPUT 10
#define NB_OUTPUT 10


#define F_ACT_LINEAR  0
#define F_ACT_SIGMOID 1
#define F_ACT_ARCTAN  2
#define F_ACT_RELU    3

const string fileStructure = "default.st";

class MLP {
    private:
        int nbLayer;
        vector<int* > curValue;
        vector<int** > wheight;




    public: 
        void readStructure(string fileName);
        MLP();
};

