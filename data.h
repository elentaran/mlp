#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Data {
    protected:
        vector<vector< double> > learnValue;
        vector< double> learnTag;
        vector<vector< double> > testValue;
        vector< double> testTag;

    public: 
        Data() {};
        vector<vector< double> > getLearnVal() {return learnValue;};
        vector< double> getLearnTag() {return learnTag;};
        vector<vector< double> > getTestVal() {return testValue;};
        vector< double> getTestTag() {return testTag;};

};

