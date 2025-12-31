#include "huffman.hpp"
#include <cstring>
#include <iostream>
#include <string>

void printUsage(const char *progName) {
  std::cout << "Usage: " << progName << " [options]\n"
            << "Options:\n"
            << "  -c <file>       Compress file\n"
            << "  -d <file>       Decompress file\n"
            << "  -o <file>       Output file name\n"
            << "  -k <2|3>        Tree arity (default: 2)\n"
            << "  --help          Show this help\n";
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printUsage(argv[0]);
    return 1;
  }

  std::string inputFile;
  std::string outputFile;
  bool compress = true;
  int k = 2;

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "-c") == 0) {
      if (i + 1 < argc) {
        inputFile = argv[++i];
        compress = true;
      } else {
        std::cerr << "Missing argument for -c\n";
        return 1;
      }
    } else if (strcmp(argv[i], "-d") == 0) {
      if (i + 1 < argc) {
        inputFile = argv[++i];
        compress = false;
      } else {
        std::cerr << "Missing argument for -d\n";
        return 1;
      }
    } else if (strcmp(argv[i], "-o") == 0) {
      if (i + 1 < argc) {
        outputFile = argv[++i];
      } else {
        std::cerr << "Missing argument for -o\n";
        return 1;
      }
    } else if (strcmp(argv[i], "-k") == 0) {
      if (i + 1 < argc) {
        k = std::stoi(argv[++i]);
        if (k != 2 && k != 3) {
          std::cerr << "Invalid k. Must be 2 or 3.\n";
          return 1;
        }
      }
    } else if (strcmp(argv[i], "--help") == 0) {
      printUsage(argv[0]);
      return 0;
    }
  }

  if (inputFile.empty()) {
    std::cerr << "No input file specified.\n";
    return 1;
  }

  if (outputFile.empty()) {
    outputFile = inputFile + (compress ? ".huff" : ".out");
  }

  HuffmanCompressor huff(k);
  if (compress) {
    std::cout << "Compressing " << inputFile << " to " << outputFile
              << " with k=" << k << "...\n";
    huff.compress(inputFile, outputFile);
  } else {
    std::cout << "Decompressing " << inputFile << " to " << outputFile
              << "...\n";
    huff.decompress(inputFile, outputFile);
  }

  std::cout << "Done.\n";
  return 0;
}
