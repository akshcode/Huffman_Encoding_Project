#include <iostream>
#include "huffman.hpp"

using namespace std;

int main(int numarg, char *argv[])
{
    // Check if the number of command-line arguments is not equal to 3
    if (numarg != 3)
    {
        cout << "Failed to detect Files";
        exit(1);
    }

    // Create an object of the huffman class, passing the input and output file paths as arguments
    Huffman f(argv[1], argv[2]);

    // Call the decompress function to decompress the input file and write the decompressed data to the output file
    f.decompress();
    cout << "Decompressed successfully" << endl;

    return 0;
}
