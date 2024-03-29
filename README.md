## HUFFMAN_CODING_PROJECT

This project is a C++ implementation of the Huffman coding algorithm, which is a lossless data compression technique. The program can be used to compress and decompress files of various types, achieving significant reductions in file size compared to the original.



## Author

- [@akshcode (Akshit Kaushal)](https://www.github.com/akshcode)


## Dependencies

This program does not have any dependencies on external libraries. It uses only the standard C++ libraries.




## How to use?

For file compression, run these commands on your terminal.

```bash
  g++ encode.cpp huffman.cpp -o main
```
```bash
  ./main inputFile.txt compressedFile.huf
```
where inputFile is the file you want to compress, and compressedFile is your compressed File.

For file decompression, run these commands on your terminal.

```bash
  g++ decode.cpp huffman.cpp -o main
```
```bash
  ./main compressedFile.huf outputFile.txt
```
where compressedFile is the compressed file, and outputFile is the file where you want to save the decompressed file.





## Implementation details

The program uses a binary tree to construct the Huffman code for the given input file. The tree is built by first constructing a min-heap of all the characters in the file based on their frequency of occurrence. The two characters with the lowest frequency are then combined to form a new node, which is inserted back into the heap. This process is repeated until the heap contains only one node, which represents the root of the Huffman tree.

Once the Huffman tree is constructed, the program generates a code for each character by traversing the tree from the root to the leaf node corresponding to the character. The code is generated by assigning a '0' to each left traversal and a '1' to each right traversal. The codes are then written to an output file along with the encoded data.

During the decompression process, the program reads the Huffman tree from the input file, constructs the tree, and then traverses the tree to decode the data.
