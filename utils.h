#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <QJsonObject>
#include <vector>
#include <QJsonDocument>
#include <QStringList>
#include <QTime>
#include <vector>
using namespace std;

void clearScreen();
void enterToContinue();
string getCurrentTime();
string substringAtPos(string str, int pos, char delim); //returned string does not include the delim char
string convertCharToString(char c);
void removeSubstring(string &str, string substr);
bool isContactNumFormat(string str);
bool isLettersOnly(string str);
bool isLettersAndNumbersOnly(string str);
bool isDecNumOnly(string str);
bool ifStringHasSubstring(string str, string substr);
bool checkEmailHasCorrectFormat(string email);
bool fileExists(string &name);
void genRandomID(char *s, const int len);
string toLowerString(string str);
bool isFileEmpty(ifstream& pFile);
string limitStringSize(string str, int size);
string numberToString(float number, int prec);
void createFileIfNotExist(string filename);
bool deleteFileOnly(string fileName);
void copyFileToDest(string sourceStr, string destStr);
bool checkIfVectorHasItem(vector<string> items, string item);

string arrayToString(vector<string> &strArray);
bool hasStringInArray(string strV, string str);
vector<string> arrayToVector(string strV);
string url_encode(const string &value);
QString jsonObjectToQString(QJsonObject &obj);
QJsonObject qstringToJSONObject(QString str);
void removeItemFromVec(vector<QString> &vec, QString itemToRemove);
void shuffleList(QStringList &list);
short _get_max_day(short month, int year);
void generateRandStr(char *s, const int len);
string getCurrentFileDirector();
string removeLastOccurrenceStr(string s, char c);
string getStringBetweenStrings(string original, string first, string last); //returns original when no first and last
void launchFileWIthDefaultProg(string filename);

#endif // UTILS_H
