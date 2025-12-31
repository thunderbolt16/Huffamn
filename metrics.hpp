#ifndef METRICS_HPP
#define METRICS_HPP

#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>

class Metrics {
public:
  static double
  calculateShannonEntropy(const std::unordered_map<char, int> &freqMap,
                          int totalChars) {
    double entropy = 0.0;
    for (auto const &[key, val] : freqMap) {
      double p = (double)val / totalChars;
      entropy -= p * std::log2(p);
    }
    return entropy;
  }

  static double
  calculateAverageCodeLength(const std::unordered_map<char, int> &freqMap,
                             const std::unordered_map<char, std::string> &codes,
                             int totalChars) {
    double avgLength = 0.0;
    for (auto const &[key, val] : freqMap) {
      double p = (double)val / totalChars;
      if (codes.find(key) != codes.end()) {
        avgLength += p * codes.at(key).length();
      }
    }
    return avgLength;
  }
};

#endif // METRICS_HPP
