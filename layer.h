#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define F_ACT_LINEAR  0
#define F_ACT_SIGMOID 1
#define F_ACT_ARCTAN  2
#define F_ACT_RELU    3

class Layer {
    private:
        Layer* prevLayer;
        Layer* nextLayer;
        int nbNeuron;
        vector<double > value;
        vector<double > error;
        vector<int > function;
        vector<vector< double> > weight;


    public: 
        string toString(); 
        Layer(int nbN, Layer* pL);
        void setNextLayer(Layer* nL) {nextLayer=nL;};
        int getNbN();
        void initiateW(double max);
        vector< double> getError() { return error; };
        void setError( vector< double> newError) { error = newError; };
        vector< double> getVal() { return value; };
        void setVal( vector< double> newVal) { value = newVal; };
        void propagate();
        void backPropagate(vector< double> error);
        vector< double> multiply(vector<double> vec, vector< vector< double> > mat);
        double sigmoid(double val);

};

