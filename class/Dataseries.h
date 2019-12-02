#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

#include "../external_lib/stdc++.h"
#include "../external_lib/tree_m.h"

#include "Sax.h"

using namespace std;
using namespace tree_m;

#include "../functions/menu.h"

/**
 * @title: Dataseries Class
 * @author: Giwoo G Lee
 * @project: COP5725 - @FSU Fall '19
 * @since 2019-11-24
 */
class DataSeries {
 public:
  DataSeries() {
    outputPath = "output/";
    saxFilename = "summarization.txt";
  };

  void openDataseriesFile() {
    cout << "Enter raw dataseries filepath: ";

    string file_name;
    cin >> file_name;

    rawDataseriesFile.open(file_name);
    if (rawDataseriesFile.fail()) {
      throw("cannot open input file.");
    } else {
      cout << "opening " << file_name << "..." << endl;
    }
  }

  void closeDataseriesFile() { rawDataseriesFile.close(); }

  void programMainRouting() {
    int entry = program_main_menu();

    while (entry != 3) {
      switch (entry) {
        case 0: {
          try {
            openDataseriesFile();
            summarization();
          } catch (const exception &e) {
            cout << "Summarization Exception: " << e.what() << endl;
          }
          closeDataseriesFile();
          break;
        }
        case 1: {
          try {
            openDataseriesFile();
            query();
          } catch (const exception &e) {
            cout << "Query Exception: " << e.what() << endl;
          }
          closeDataseriesFile();
          break;
        }
        case 2: {
          cout << "\n" << endl;
          cout << "Thank you for trying Coconut." << endl;
          cout << "All rights are reserved to the original authors." << endl;
          cout << "========= Authors =========" << endl;
          cout << "== Haridimos Kondylakis ==" << endl;
          cout << "== FORTH-ICS ==" << endl;
          cout << "== kondylak@ics.forth.gr ==\n" << endl;
          cout << "== Niv Dayan ==" << endl;
          cout << "== Harvard University ==" << endl;
          cout << "== dayan@seas.harvard.edu ==\n" << endl;
          cout << "== Kostas Zoumpatianos ==" << endl;
          cout << "== Harvard University ==" << endl;
          cout << "== kostas@seas.harvard.edu ==\n" << endl;
          cout << "== Themis Palpanas ==" << endl;
          cout << "== Paris Descartes University ==" << endl;
          cout << "== themis@mi.parisdescartes.fr ==" << endl;
          cout << "===========================" << endl;
          exit(EXIT_FAILURE);
          break;
        }
        default: {
          cout << "\nInvalid key." << endl;
          break;
        }
      }

      entry = program_main_menu();
    }
  }

  void summarization() {
    string line, str;
    clock_t startTime, endTime;

    if (rawDataseriesFile.fail()) {
      throw("no file has been loaded.");
    }

    try {
      // PROCESS DATASET
      startTime = clock();
      while (getline(rawDataseriesFile, line)) {
        // BUILD SAX SUMMARIZATION
        Sax s;
        uint64_t f2D_32_encode = s.summarization(line);

        // END EXECUTION TIME
        endTime = clock();

        // SUMMARIZATION FILE
        saxSummarizationFile.open(outputPath + saxFilename, ios::app);
        saxSummarizationFile << f2D_32_encode << "\n";

        // OUTPUT
        cout << "\n=========================================" << endl;
        cout << "===== Coconut Summarization Output: =====" << endl;
        cout << "=========================================" << endl;
        cout << "[Total execution time]: "
             << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
        cout << "[Output filename]: " << outputPath + saxFilename << endl;
      }
      saxSummarizationFile.close();
    } catch (const exception &e) {
      throw(e.what());
    }
  }

  void query() {
    // ARGUMENT ERROR HANDLING
    char entry = program_query_menu();

    while (entry != 'q' || entry != 'Q') {
      switch (entry) {
        case 's':
        case 'S':
          cout << "Options S selected" << endl;
          break;
        case 'e':
        case 'E':
          cout << "Options E selected" << endl;
          break;
        case 'r':
        case 'R':
          programMainRouting();
          break;
        default:
          cout << "\nInvalid key" << endl;
          break;
      }
    }
  }

 private:
  ifstream rawDataseriesFile;
  ofstream saxSummarizationFile;
  string outputPath;
  string saxFilename;
  string executionTimelogFilename;
};