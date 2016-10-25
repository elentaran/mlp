#include "layer.h"
#include "dataXor.h"


#include <fstream>

const string fileStructure = "default.st";

class MLP {
    private:
        int nbLayer;
        vector< Layer*> layers;




    public: 
        void readStructure(string fileName);
        void propagate(vector< double> input);
        int resMax();
        double eval(vector< vector< double> > example, vector< double> tag);
        string strToString(); 
        MLP();
};

