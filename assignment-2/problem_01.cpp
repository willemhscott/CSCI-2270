#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct wordItem {
    string word;
    int count;
};

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]) {
    ifstream ignoreFile;
    ignoreFile.open(ignoreWordFileName);

    if (!ignoreFile.is_open()) {
        cout << "Failed to open " << ignoreWordFileName << endl;
        exit(0);
    }

    int iCount = 0;
    string ignoreWord;

    while (getline(ignoreFile, ignoreWord)) {
        ignoreWords[iCount] = ignoreWord;
        iCount++;
    }
}

bool isStopWord(string w, string ignoredWords[]) {
    for (int i = 0; i < 50; i++) {
        if (w == ignoredWords[i]) {
            return true;
        }
    }
    return false;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        count += uniqueWords[i].count;
    }

    return count;
}

void arraySort(wordItem uniqueWords[], int length) {
    for (int i = 1; i < length; i++) {
        for (int j = i-1; j >= 0; j--) {
            if (uniqueWords[j].count < uniqueWords[j+1].count) {
                wordItem temp = uniqueWords[j];
                uniqueWords[j] = uniqueWords[j+1];
                uniqueWords[j+1] = temp;
            }
        }
    }

    //sort(uniqueWords, uniqueWords + length, cmp);
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(4);

    for (int i = N; i < N + 10; i++) {
        //cout << uniqueWords[i].count << uniqueWords[i].word << endl;

        cout << ((float) uniqueWords[i].count / (float) totalNumWords) << " - " << uniqueWords[i].word << endl;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
        return 0;
    }
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(4);

    int n = stoi(argv[1]);
    string textName = argv[2];

    ifstream textFile;
    textFile.open(textName);

    string ignoreWords[50];
    getStopWords(argv[3], ignoreWords);

    int uCount = 0;
    int uSize = 100;
    int dCount = 0;
    wordItem *uniqueWords = new wordItem[100];
    string newLine;

    while (getline(textFile, newLine)) {
        //cout << "no looping here!" << endl;
        string newWord;
        stringstream ssLine (newLine);
        while (getline(ssLine, newWord, ' ')) {
            //cout << newWord << endl;
            if (isStopWord(newWord, ignoreWords)) {
                continue;
            }
            bool found = false;
            int uC = 0;
            for (; uC < uCount; uC++) {
                if (newWord == uniqueWords[uC].word) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                uniqueWords[uCount].word = newWord;
                uniqueWords[uCount].count = 1;
                uCount++;
            } else {
                uniqueWords[uC].count = uniqueWords[uC].count + 1;
            }

            if (uCount > uSize - 1) {
                uSize = uSize * 2;
                dCount++;
                wordItem *nUniqueWords = new wordItem[uSize];
                for (int i = 0; i < uCount; i++) {
                    nUniqueWords[i] = uniqueWords[i];
                }

                delete[] uniqueWords;
                uniqueWords = nUniqueWords;
            }
        }
    }

    arraySort(uniqueWords, uCount);

    int tCount = getTotalNumberNonStopWords(uniqueWords, uCount);
    cout << "Array doubled: " << dCount << "\n#\n";
    cout << "Unique non-common words: " << uCount << "\n#\n";
    cout << "Total non-common words: " << tCount << "\n#\n";
    cout << "Probability of next 10 words from rank " << n << "\n---------------------------------------\n";

    printNext10(uniqueWords, n, tCount);

    return 0;
}
