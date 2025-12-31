#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP

#include "node.hpp"
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class HuffmanCompressor {
public:
  HuffmanCompressor(int k = 2);
  ~HuffmanCompressor();

  void compress(const std::string &inputFile, const std::string &outputFile);
  void decompress(const std::string &inputFile, const std::string &outputFile);

private:
  int k; // Arity of the tree (2 for Binary, 3 for Ternary)
  Node *root;
  std::unordered_map<char, std::string> codes;
  std::unordered_map<char, int> freqMap;

  void buildTree(std::unordered_map<char, int> &freq);
  void generateCodes(Node *node, std::string str);
  void deleteTree(Node *node);
  void writeHeader(std::ofstream &out);
  void readHeader(std::ifstream &in);
  void writeBit(char bit, std::ofstream &out, unsigned char &buffer,
                int &bitCount);

  // Helper to pad with dummy nodes for k-ary tree
  void addDummyNodes(
      std::priority_queue<Node *, std::vector<Node *>, CompareNode> &pq);
};

#endif // HUFFMAN_HPP
