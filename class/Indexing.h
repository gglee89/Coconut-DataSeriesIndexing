class Indexing {
 public:
  Indexing() {
    outputPath = "output/";
    saxSummarizationFilename = "summarization.txt";
    timelogSaxSummarizationFilename = "timelog_sax_summarization.txt";
    timelogBTreeFileName = "timelog_btree.txt";
  };
  void openDataseriesFile() {
    try {
      cout << "Raw dataseries input filepath [input.txt]: ";

      string file_name = "input.txt";
      cin >> file_name;

      rawDataSeriesFileName = file_name;
      rawDataseriesFile.open(file_name);
      if (rawDataseriesFile.fail()) {
        cout << "\n============================================" << endl;
        cout << "======= Error opening file: " << file_name << endl;
        cout << "======= Check if file_path exists" << endl;
        cout << "============================================" << endl;
        char input = '\t';
        while (input == '\t') {
          cout << "Enter [anykey] to continue..." << endl;
          cin >> input;
        };
      } else {
        cout << "opening " << file_name << "..." << endl;
      }
    } catch (const exception &e) {
      cout << "Exception: " << e.what() << endl;
    }
  }
  void openTimelogSaxSummarizationInputFile() {
    timelogSaxSummarizationInputFile.open(outputPath +
                                          timelogSaxSummarizationFilename);

    if (timelogSaxSummarizationInputFile.fail()) {
      cout << "\n============================================" << endl;
      cout << "======= Error opening file: " << timelogSaxSummarizationFilename
           << endl;
      cout << "======= Check if file_path exists" << endl;
      cout << "============================================" << endl;
      char input = '\t';
      while (input == '\t') {
        cout << "Enter [anykey] to continue..." << endl;
        cin >> input;
      };
    }
  }
  void openTimelogSaxSummarizationOutputFile() {
    timelogSaxSummarizationOutputFile.open(outputPath +
                                           timelogSaxSummarizationFilename);

    if (timelogSaxSummarizationOutputFile.fail()) {
      cout << "\n============================================" << endl;
      cout << "======= Error opening file: " << timelogSaxSummarizationFilename
           << endl;
      cout << "======= Check if file_path exists" << endl;
      cout << "============================================" << endl;
      char input = '\t';
      while (input == '\t') {
        cout << "Enter [anykey] to continue..." << endl;
        cin >> input;
      };
    }
  }
  void openTimelogBTreeFile() {
    timelogBTreeFile.open(outputPath + timelogBTreeFileName);

    if (timelogBTreeFile.fail()) {
      cout << "\n============================================" << endl;
      cout << "======= Error opening file: " << timelogBTreeFileName << endl;
      cout << "======= Check if file_path exists" << endl;
      cout << "============================================" << endl;
      char input = '\t';
      while (input == '\t') {
        cout << "Enter [anykey] to continue..." << endl;
        cin >> input;
      };
    }
  }
  void openSaxSummarizationInputFile() {
    saxSummarizationInputFile.open(outputPath + saxSummarizationFilename);

    if (saxSummarizationInputFile.fail()) {
      cout << "\n============================================" << endl;
      cout << "======= Error opening file: " << saxSummarizationFilename
           << endl;
      cout << "======= Check if file_path exists" << endl;
      cout << "============================================" << endl;
      char input = '\t';
      while (input == '\t') {
        cout << "Enter [anykey] to continue..." << endl;
        cin >> input;
      };
    }
  }
  void openSaxSummarizationOutputFile() {
    saxSummarizationOutputFile.open(outputPath + saxSummarizationFilename);

    if (saxSummarizationOutputFile.fail()) {
      cout << "\n============================================" << endl;
      cout << "======= Error opening file: " << saxSummarizationFilename
           << endl;
      cout << "======= Check if file_path exists" << endl;
      cout << "============================================" << endl;
      char input = '\t';
      while (input == '\t') {
        cout << "Enter [anykey] to continue..." << endl;
        cin >> input;
      };
    }
  }
  void closeDataseriesFile() { rawDataseriesFile.close(); }
  void closeTimelogSaxSummarizationInputFile() {
    timelogSaxSummarizationInputFile.close();
  }
  void closeTimelogSaxSummarizationOutputFile() {
    timelogSaxSummarizationOutputFile.close();
  }
  void closeTimelogBTreeFile() { timelogBTreeFile.close(); }
  void closeSaxSummarizationInputFile() { saxSummarizationInputFile.close(); }
  void closeSaxSummarizationOutputFile() { saxSummarizationOutputFile.close(); }
  void buildBTree(BTree &bt) {
    cout << "\nBuilding BTree...";

    // FILE PROCESSING STARTS HERE
    openSaxSummarizationInputFile();
    openTimelogSaxSummarizationInputFile();

    string lineSaxSummarizationTimelog, lineSaxSummarization;

    // START TIME TRACKING
    startTime = clock();

    /*******************
    ** BTree Creation **
    ********************/
    while (getline(saxSummarizationInputFile, lineSaxSummarization) &&
           getline(timelogSaxSummarizationInputFile,
                   lineSaxSummarizationTimelog)) {
      bt.insert(stoull(lineSaxSummarization), lineSaxSummarizationTimelog);
    }

    // END TIME TRACKING
    endTime = clock();
    double delta = (double)(endTime - startTime);

    // SAVE EXECUTION TIME
    openTimelogBTreeFile();
    timelogBTreeFile << delta << "\n";

    // CLOSE FILES
    closeSaxSummarizationInputFile();
    closeTimelogSaxSummarizationInputFile();
    closeTimelogBTreeFile();

    // OUTPUT
    cout << "\n=========================================" << endl;
    cout << "====== Coconut BTree Build Output: ======" << endl;
    cout << "=========================================" << endl;
    cout << "[Total execution time]: " << delta / CLOCKS_PER_SEC << "s" << endl;
    cout << "[Output log filename]: " << outputPath + timelogBTreeFileName
         << endl;
  }
  void saxSummarization() {
    try {
      // OPEN FILES
      openDataseriesFile();
      openSaxSummarizationOutputFile();
      openTimelogSaxSummarizationOutputFile();

      cout << "\nPerforming SAX Summarization...";
      string line;

      // BUILD SAX SUMMARIZATION
      Sax s;
      while (getline(rawDataseriesFile, line)) {
        // PROCESS DATASET
        startTime = clock();

        uint64_t f2D_32_encode = s.summarization(line);

        // SAVE SAX SUMMARIZATION
        saxSummarizationOutputFile << f2D_32_encode << "\n";

        // END EXECUTION TIME
        endTime = clock();
        double delta = (double)(endTime - startTime);

        // SAVE EXECUTION TIME
        timelogSaxSummarizationOutputFile << delta << "\n";
      }

      // CLOSE All FILES
      closeDataseriesFile();
      closeTimelogSaxSummarizationOutputFile();
      closeSaxSummarizationOutputFile();

      // OUTPUT
      cout << "\n=========================================" << endl;
      cout << "===== Coconut Summarization Output: =====" << endl;
      cout << "=========================================" << endl;
      cout << "[Output filename]: " << outputPath + saxSummarizationFilename
           << endl;
      cout << "[Output log filename]: "
           << outputPath + timelogSaxSummarizationFilename << endl;

    } catch (const exception &e) {
      cout << "Exception in Indexing.Summarization: " << e.what() << endl;
    }
  }
  void construct(BTree &bt) {
    saxSummarization();
    buildBTree(bt);

    char input = '\t';
    while (input == '\t') {
      cout << "Enter [anykey] to continue..." << endl;
      cin >> input;
    };
  }

 private:
  clock_t startTime, endTime;

  ifstream rawDataseriesFile;
  ifstream saxSummarizationInputFile;
  ifstream timelogSaxSummarizationInputFile;
  ofstream timelogSaxSummarizationOutputFile;
  ofstream saxSummarizationOutputFile;
  ofstream timelogBTreeFile;

  string outputPath;
  string timelogBTreeFileName;
  string timelogSaxSummarizationFilename;
  string saxSummarizationFilename;
  string rawDataSeriesFileName;
};