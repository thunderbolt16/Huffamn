#ifndef NODE_HPP
#define NODE_HPP

#include <string>
#include <vector>

struct Node {
  char ch;
  int freq;
  unsigned char minChar; // For deterministic tie-breaking
  std::vector<Node *> children;
  bool isLeaf;

  Node(char c, int f)
      : ch(c), freq(f), minChar((unsigned char)c), isLeaf(true) {}
  Node(int f, const std::vector<Node *> &c)
      : ch('\0'), freq(f), children(c), isLeaf(false) {
    minChar = 255;
    for (Node *child : c) {
      if (child->minChar < minChar) {
        minChar = child->minChar;
      }
    }
  }

  ~Node() {
    for (Node *child : children) {
      delete child;
    }
  }
};

// Comparator for Min-Heap
struct CompareNode {
  bool operator()(Node *const &n1, Node *const &n2) {
    if (n1->freq != n2->freq) {
      return n1->freq > n2->freq;
    }
    return n1->minChar > n2->minChar;
  }
};

#endif // NODE_HPP
