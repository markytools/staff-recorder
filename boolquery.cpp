#include "boolquery.h"

BoolQuery::BoolQuery()
{

}

void BoolQuery::addQuery(bool boolValue, string message)
{
    Bool boolClass(boolValue, message);
    queryList.push_back(boolClass);
}

string BoolQuery::earliestQuery()
{
    for(auto const& value : queryList) {
        Bool boolClass = value;
        if (!boolClass.isValid()) return boolClass.getMessage();
    }
    return "";
}

void BoolQuery::clearQuery()
{
    queryList.clear();
}


Bool::Bool(bool value, string message)
{
    this->value = value;
    this->message = message;
}

bool Bool::isValid() const
{
    return value;
}

string Bool::getMessage() const
{
    return message;
}


