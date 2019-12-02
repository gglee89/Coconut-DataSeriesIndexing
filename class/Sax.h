#include <math.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#include "../functions/utility.h"

/**
 * @title: SAX Class
 * @author: Giwoo G Lee
 * @project: COP5725 - @FSU Fall '19
 * @since 2019-11-24
 */
class Sax {
 public:
  uint64_t summarization(string line) {
    // CREATE A VECTOR FROM THE INPUT.TXT FILE
    vector<float> numlist;
    vector<string> list = split(line, " ");

    // ITERATES OVER EACH ITEM IN THE VECTOR
    for (int i = 0; i < list.size(); i++) {
      // CHECK FOR EMPTY ENTRIES
      if (list[i].compare("") != 0) {
        try {
          numlist.push_back(stof(list[i]));
        } catch (const exception &e) {
          cout << "Exception: " << e.what();
        }
      }
    }

    // INPUT SUMMARIZATION PROCEDURE
    vector<float> zNormOutput = zvaluecal(numlist);
    vector<float> paaOutput = paacal(zNormOutput);
    string saxOutput = saxcal(paaOutput);
    return invertsax(saxOutput);
  }

  /**
   * @title: Calculate Z-Value
   * @description Pass vector integers into z-value function
   * @author: Giwoo G Lee
   * @project: COP5725 - @FSU Fall '19
   * @since 2019-11-24
   */
  vector<float> zvaluecal(vector<float> list) {
    float sum = 0, ssum = 0, ave = 0, newvalue;
    vector<float> result;
    for (int i = 0; i < list.size(); i++) {
      sum = sum + list[i];
    }
    ave = sum / list.size();
    for (int i = 0; i < list.size(); i++) {
      ssum = ssum + pow((abs(list[i] - ave)), 2);
    }
    ssum = sqrt(ssum);
    for (int i = 0; i < list.size(); i++) {
      newvalue = (list[i] - ave) / ssum;
      result.push_back(newvalue);
    }
    return result;
  }

  /**
   * @title: Calculate PAA-Value
   * @description Pass vector of integers into PAA function
   * @author: Giwoo G Lee
   * @project: COP5725 - @FSU Fall '19
   * @since 2019-11-24
   */
  vector<float> paacal(vector<float> list) {
    // DIVIDES BY 4 BECAUSE THERE'S FOUR GROUPS
    int M = list.size() / 4;  // 7 / 4 = 1
    int newsize = M;

    // SIZE OF THE ORIGINAL SET
    int n = list.size();

    vector<float> result;
    // ITERATE OVER AVAILABLE GROUPS
    for (int i = 1; i <= newsize; i++) {
      float sum = 0;
      for (int k = (n / newsize * (i - 1) + 1); k <= ((n / newsize) * i); k++) {
        sum = list[k - 1] + sum;
      }
      float x = sum * newsize / n;
      result.push_back(x);
    }
    return result;
  }

  /**
   * @title: Calculate SAX-Representation
   * @description Pass vector of integers into SAX function
   * @author: Giwoo G Lee
   * @project: COP5725 - @FSU Fall '19
   * @since 2019-11-24
   */
  string saxcal(vector<float> list) {
    int size = list.size();
    string result;
    for (int i = 0; i < size; i++) {
      int a = ceil(list[i] * 10) + 107;
      result.push_back(char(a));
    }
    return result;
  }

  /**
   * @title: Calculate InvertSAX-Representation
   * @description Pass vector of SAX-representation into
   * invertSAX-representation
   * @author: Giwoo G Lee
   * @project: COP5725 - @FSU Fall '19
   * @since 2019-11-24
   */
  uint64_t invertsax(string list) {
    uint64_t answer = 0;
    for (int i = 3; i > 0; i--) {
      for (int j = 0; j < sizeof(list); j++) {
        int binaryFormat = (list[j] >> (i - 1)) & 0x1;  // 0 or 1
        uint64_t powerFormat = pow(2, (i * sizeof(list) - j - 1));
        answer += binaryFormat * powerFormat;
      }
    }
    return answer;
  }
};