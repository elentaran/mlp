#include "data.h"

class DataXor: public Data {

    public:
        DataXor() {
            vector<double > val;
            val = {0,0};
            learnValue.push_back(val);
            learnTag.push_back(0);
            testValue.push_back(val);
            testTag.push_back(0);
            val = {0,1};
            learnValue.push_back(val);
            learnTag.push_back(1);
            testValue.push_back(val);
            testTag.push_back(1);
            val = {1,0};
            learnValue.push_back(val);
            learnTag.push_back(1);
            testValue.push_back(val);
            testTag.push_back(1);
            val = {1,1};
            learnValue.push_back(val);
            learnTag.push_back(0);
            testValue.push_back(val);
            testTag.push_back(0);

        }
};

