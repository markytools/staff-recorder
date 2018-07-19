#ifndef BOOLQUERY_H
#define BOOLQUERY_H

#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Bool
{
public:
    Bool(bool value, string message);

    bool isValid() const;
    string getMessage() const;

private:
    bool value;
    string message;
};

class BoolQuery
{
public:
    BoolQuery();
    void addQuery(bool boolValue, string message);
    string earliestQuery();
    void clearQuery();

private:
    vector<Bool> queryList;

};

#endif // BOOLQUERY_H
