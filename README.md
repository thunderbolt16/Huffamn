# Huffman Encoding and Decoding Tool

This project implements a lossless file compression tool in C++ using the Huffman Coding algorithm. It supports both Binary (k=2) and Ternary (k=3) Huffman trees to benchmark compression efficiency.

## Features
- **Lossless Compression**: Achieves significant size reduction on text files.
- **Dual-Mode Encoder**: Supports Binary and Ternary Huffman trees.
- **Optimized Data Structures**: Uses Min-Heaps (Priority Queue) and Unordered Maps for O(N log N) time complexity.
- **Validation**: Calculates Shannon Entropy and Average Code Length to validate algorithm efficiency.

## Build Instructions

### Prerequisites
- C++17 compiler
- CMake 3.10+

### Build
```bash
mkdir build
cd build
cmake ..
make
```

## Usage

### Compression
```bash
./huffman_tool -c input.txt -o output.huff -k 2
```
- `-c`: Input file to compress.
- `-o`: Output file name (optional, defaults to input.txt.huff).
- `-k`: Tree arity (2 for Binary, 3 for Ternary). Default is 2.

### Decompression
```bash
./huffman_tool -d output.huff -o restored.txt
```
- `-d`: Input file to decompress.
- `-o`: Output file name (optional, defaults to output.huff.out).

## Project Structure
- `src/`: Source code.
- `src/huffman.cpp`: Core Huffman logic.
- `src/metrics.hpp`: Entropy and code length calculations.
- `src/node.hpp`: Tree node structure.

## Benchmarking
The tool automatically outputs the Original Size, Shannon Entropy, and Average Code Length during compression.
