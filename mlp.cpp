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
        int numLayer = 0;
        int nbNeuron;
        int prevNbNeuron;
        Layer* prevLayer = NULL;

        while (getline (myfile,line)) {
            nbNeuron = std::stoi(line);
            cout << nbNeuron << endl;

            Layer* curLayer = new Layer(nbNeuron, prevLayer);
            layers.push_back(curLayer);
            prevLayer = curLayer;

            numLayer++;
            prevNbNeuron = nbNeuron;

        }
        nbLayer=numLayer;

        myfile.close();
    }
    else
    {
        cerr << "could not open the file: "<<fileName.c_str() << endl;
    }
    return;
}


string MLP::strToString() {

    string str_struct = "coucou\n";
    for (int i=0; i<layers.size();i++) {
        str_struct+=layers[i]->toString();
    }

    return str_struct;


}


MLP::MLP() {
    cout << "create new mlp" << endl;
    readStructure();

}

void MLP::propagate(vector< double> input) {
    layers[0]->setVal(input);
    for (int i=1; i<layers.size(); i++) {
        layers[i]->propagate();
    }
}

// return the number of the output neuron with the highest value
int MLP::resMax(){
    vector<double > val = layers[layers.size()-1]->getVal();
    int indiceMax=0;
    double valMax=val[0];
    for (int i=1; i<val.size(); i++) {
        if (val[i] > valMax) {
            valMax=val[i];
            indiceMax=i;
        }
    }
    return indiceMax;
}

double MLP::eval(vector< vector< double> > example, vector< double> tag) {
    double nbCorrect=0;
    int nbtotal=0;
    for (int i=0; i<example.size(); i++) {
        propagate(example[i]);

        cout << endl << strToString() << endl;
        cout << "tag : " << to_string(tag[i]) <<endl;
        cout << "res : " << to_string(resMax()) << endl;
        if (resMax() == tag[i]) {
            nbCorrect++;
        }
        nbtotal++;
    }

    cout << nbCorrect << endl;
    cout << nbtotal << endl;
    return nbCorrect; 

}


int main(int nbargs, char** args) {
    srand(time(0));
    cout << "coucou" << endl;
    MLP* testmlp = new MLP();
    cout << endl << testmlp->strToString() << endl;

    DataXor* data = new DataXor();

    vector< vector< double>> learnVal = data->getLearnVal();
    cout << to_string(learnVal[0][0]) << endl;

    testmlp->propagate(learnVal[1]);

    cout << endl << testmlp->strToString() << endl;
    cout << endl << to_string(testmlp->resMax()) << endl;

    testmlp->eval(data->getLearnVal(), data->getLearnTag());

}

