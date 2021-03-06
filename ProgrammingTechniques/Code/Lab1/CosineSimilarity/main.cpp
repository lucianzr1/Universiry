#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

unordered_map<string, int> getVector(vector<string> document) {
    unordered_map<string, int> vector;
    for (const string &s : document) {
        vector[s] += 1;
    }
    return vector;
}

int dotProduct(unordered_map<string, int> vector1, unordered_map<string, int> vector2) {
    int dotProduct = 0;
    if (vector1.size() < vector2.size()) {
        for (auto p : vector1) {
            dotProduct += vector1[p.first] * vector2[p.first];
        }
    } else {
        for (auto p : vector2) {
            dotProduct += vector1[p.first] * vector2[p.first];
        }
    }
    return dotProduct;
}

float modulo(unordered_map<string, int> vector) {
    float m = 0;
    for (auto p : vector) {
        m += p.second * p.second;
    }
    return sqrt(m);
}

float compute(vector<string> doc1, vector<string> doc2) {
    unordered_map<string, int> vec1 = getVector(doc1);
    unordered_map<string, int> vec2 = getVector(doc2);
    int dp = dotProduct(vec1, vec2);
    float m1 = modulo(vec1);
    float m2 = modulo(vec2);
    return dp / (m1 * m2);
}

vector<string> readDocument(const string &filename) {
    fstream fin;
    fin.open(filename, ios::in);
    vector<string> document;
    string word;
    while (fin >> word) {
        document.push_back(word);
    }
    fin.close();
    return document;
}

int main() {

    vector<string> doc1 = readDocument("F1.txt");
    vector<string> doc2 = readDocument("F2.txt");
    cout<<compute(doc1, doc2);
    return 0;
}   