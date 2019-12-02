#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../external_lib/stdc++.h"
#include "../external_lib/tree_m.h"

#include "Sax.h"

using namespace std;
using namespace tree_m;

#include "Indexing.h"
#include "Query.h"

#include "../functions/menu.h"

/**
 * @title: Dataseries Class
 * @author: Giwoo G Lee
 * @project: COP5725 - @FSU Fall '19
 * @since 2019-11-24
 */
class DataSeries {
 public:
  void program_main_routing() {
    int entry = program_main_menu();

    while (entry != '\t') {
      switch (entry) {
        case 0: {
          try {
            summarization();
          } catch (const exception &e) {
            cout << "Summarization Exception: " << e.what() << endl;
          }
          break;
        }
        case 1: {
          try {
            query();
          } catch (const exception &e) {
            cout << "Query Exception: " << e.what() << endl;
          }
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
    Indexing in;
    in.construct(bt);

    program_main_routing();
  }

  void query() {
    // ARGUMENT ERROR HANDLING
    char entry = program_query_menu();

    while (entry != 's' || entry != 'S' || entry != 'e' || entry != 'E' ||
           entry != 'r' || entry != 'R') {
      Query q;
      switch (entry) {
        case 's':
        case 'S':
          q.search_similarity(bt);
          break;
        case 'e':
        case 'E':
          q.search_exact(bt);
          break;
        case 'r':
        case 'R':
          program_main_routing();
          break;
        default: {
          cout << "\nInvalid key" << endl;
          break;
        }
      }
    }
  }

 private:
  BTree bt = BTree(3);
};