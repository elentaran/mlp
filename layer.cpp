#include "layer.h"


Layer::Layer(int nbN, Layer* pL=NULL) {
    prevLayer = pL;
    nbNeuron = nbN;
    for (int i=0;i<nbNeuron;i++) {
        value.push_back(0);
        error.push_back(0);
        if (pL != NULL) {
            vector< double> line;
            weight.push_back(line);
            for (int j=0;j<prevLayer->getNbN();j++) {
                weight[i].push_back(0);
            }
        }
    }
    initiateW(1);
}

int Layer::getNbN() {
    return nbNeuron;
}

void Layer::initiateW(double max=1) {
    double val;
    for (int i=0; i<weight.size(); i++) {
        for (int j=0; j<weight[i].size(); j++) {
            val = ((rand()%2000/1000.)-1)*max;
            weight[i][j]=val;
        }
    }
}

string Layer::toString() {
    string text = "value: ";
    for (int i=0; i<value.size(); i++) {
        text+=to_string(value[i])+" ";
    }
    text+="\n";
    
    text += "error: ";
    for (int i=0; i<value.size(); i++) {
        text+=to_string(error[i])+" ";
    }
    text+="\n";
    
    text += "weight: \n";
    for (int i=0; i<weight.size(); i++) {
        for (int j=0; j<weight[i].size(); j++) {
            text+=to_string(weight[i][j])+" ";
        }
        text+="\n";
    }
    text+="\n";
    

    return text;
}

double Layer::sigmoid(double val) {
    return 1.0/(1.0+exp(-val));
}

void Layer::propagate() {

    value = multiply(prevLayer->getVal(),weight);
    for (int i=0; i<value.size(); i++) {
        value[i] = sigmoid(value[i]);
    }
    return ;
}

void Layer::backPropagate(vector< double> error) {

}

vector< double> Layer::multiply(vector<double> vec, vector< vector< double> > mat) {
    vector< double> res;
    double resVal;
    for (int i=0; i<mat.size(); i++) {
        resVal=0;
        for (int j=0; j<vec.size(); j++) {
            resVal+=vec[j]*mat[i][j];
        }
        res.push_back(resVal);
    }
    return res;
}
