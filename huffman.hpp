// to prevent header files from being included multiple times
#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include <fstream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// Defining Huffman Tree Node
class Node
{
public:
    char data;
    unsigned freq;
    string code;
    Node *left;
    Node *right;

    Node()
    {
        left = NULL;
        right = NULL;
    }
};

class Huffman
{
private:
    fstream inFile, outFile;
    string inFileName, outFileName;
    Node *root;
    vector<Node *> arr; // vector of pointers to Node objects

    // for the creation of minHeap on basis of frequency
    class Compare
    {
    public:
        bool operator()(Node *a, Node *b)
        {
            return a->freq > b->freq;
        }
    };

    priority_queue<Node *, vector<Node *>, Compare> minHeap;

    // Initialising vector of tree nodes with character's ASCII values and frequency = 0
    void createTheArr();

    // Traversing the constructed tree to generate huffman codes of each present character
    void traverse(Node *, string);

    // to convert binary string to its equivalent decimal value
    int binToDec(string);

    // to convert a decimal number to its equivalent binary string
    string decToBin(int);

    // Reconstructing the Huffman tree while Decoding the file
    void buildTree(char, string &);

    // Creating Min Heap of Nodes by frequency of characters in the input file
    void createMinHeap();

    // Constructing the Huffman tree
    void createTree();

    // Generating Huffman codes
    void createCodes();

    // Saving Huffman Encoded File
    void saveEncodedFile();

    // Saving Decoded File to obtain the original File
    void saveDecodedFile();

    // Reading the file to reconstruct the Huffman tree
    void getTree();

public:
    // Constructor for the Huffman Class
    Huffman(string inFileName, string outFileName)
    {
        this->inFileName = inFileName;
        this->outFileName = outFileName;
        createTheArr();
    }
    // Compressing input file
    void compress();

    // Decrompressing input file
    void decompress();
};
#endif