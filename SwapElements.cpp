#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int StringToInt(string val);
const void PrintSwappedElements(const vector<string>& elements);
void SwapVals(vector<string>& vElements, const char& swapDel, vector<string>& swaps);

int main(int argc, char *argv[])
{
    ifstream inputFile;
    
    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string line;

        while(getline(inputFile,line))
        {
            //cout << "Input: " << line << endl;

            string elements;
            string swapLine;
            string tempStr;
            vector<string> swaps;
            vector<string> vElements;

            stringstream swapStream;
            stringstream elementStream;

            char delimiter = ':';
            char swapDel = '-';

            size_t delLocation = line.find(delimiter); 
    
            elements = line.substr(0,delLocation-1);
            swapLine = line.substr(delLocation+2);

            //cout << "Elements: " << elements << endl;
            //cout << "Swaps: " << swapLine << endl;

            swapStream << swapLine;
            elementStream << elements;
            
            while(getline(elementStream,tempStr,' '))
            {
                vElements.push_back(tempStr);
            }

            while(getline(swapStream, tempStr, ','))
            {
                if(tempStr.compare(0,1," ") == 0)
                {
                    tempStr.erase(0,1);
                }

                swaps.push_back(tempStr);

                //cout << tempStr << endl;
            }

            SwapVals(vElements, swapDel, swaps);

            PrintSwappedElements(vElements);
        }
    }
    else
    {
        cout << "Error with input file" << endl;
    }
    return 0;
}

void SwapVals(vector<string>& vElements,const char& swapDel, vector<string>& swaps)
{
    for(vector<string>::const_iterator it=swaps.begin();
        it!=swaps.end();
        ++it)
    {
        size_t dashLocation = (*it).find(swapDel);

        string swapOne = (*it).substr(0,dashLocation);
        string swapTwo = (*it).substr(dashLocation+1,(*it).size()-dashLocation-1);

        //cout << "First Swap: " << firstLoc << endl;
        //cout << "Second Swap: " << secondLoc << endl;

        int swapIndexOne = StringToInt(swapOne);
        int swapIndexTwo = StringToInt(swapTwo);
       
        //cout << "Swap Index One: " << swapIndexOne << endl;
        //cout << "Swap Index Two: " << swapIndexTwo << endl;

        //tempInt = elements.at(swapIndexOne);
        swap(vElements[swapIndexOne],vElements[swapIndexTwo]);
    }
}

const void PrintSwappedElements(const vector<string>& elements)
{
    for(vector<string>::const_iterator it=elements.begin();
        it!=elements.end();
        ++it)
    {
        cout << *it;
        if(it != elements.end()-1)
        {
            cout << " ";
        }
        else if(it == elements.end()-1)
        {
            cout << endl;
        }
    }
}

int StringToInt(string val)
{
    int i;

    stringstream valStream(val);

    valStream >> i;

    return i;
}
