class Query {
 public:
  Query() {
    outputPath = "output/";
    timelogSearchExactFilename = "timelog_searchexact.txt";
    timelogSearchSimilarityFilename = "timelog_searchsimilarity.txt";
    saxSummarizationInputFilename = "summarization.txt";
  };
  void openTimelogSearchExactFile() {
    timelogSearchExactFile.open(outputPath + timelogSearchExactFilename);

    if (timelogSearchExactFile.fail()) {
      cout << "\n============================================" << endl;
      cout << "======= Error opening file: " << timelogSearchExactFilename
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
  void openTimelogSearchSimilarityFile() {
    timelogSearchSimilarityFile.open(outputPath +
                                     timelogSearchSimilarityFilename);

    if (timelogSearchSimilarityFile.fail()) {
      cout << "\n============================================" << endl;
      cout << "======= Error opening file: " << timelogSearchSimilarityFilename
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
  void closeTimelogSearchExactFile() { timelogSearchExactFile.close(); }
  void closeTimelogSearchSimilarityFile() {
    timelogSearchSimilarityFile.close();
  }
  string get_search_query() {
    cout << "\n================================" << endl;
    cout << "========= Search Query =========" << endl;
    cout << "================================" << endl;
    cout << "== Description: Sequence ending with a #(pound) symbol" << endl;
    cout << "== Example: 2 4 20 6 3 1 #" << endl;
    cout << "================================" << endl;
    cout << "Enter query: ";

    string input;
    getline(cin, input, '#');
    return input;
  }
  void search_exact(BTree &bt) {
    string queryStr = get_search_query();

    // START TIME TRACKING
    startTime = clock();

    // SAX Summarization
    Sax s;
    uint64_t f2D_32_encode = s.summarization(queryStr);
    BTreeNode *node = bt.search(f2D_32_encode);

    // END TIME TRACKING
    endTime = clock();

    // SAVE EXECUTION TIME
    double delta = (double)(endTime - startTime);
    openTimelogSearchExactFile();
    timelogSearchExactFile << delta << endl;

    // OUTPUT
    cout << "\n==================================" << endl;
    cout << "===== Coconut Query Output: =====" << endl;
    cout << "=================================" << endl;
    cout << "[Total execution time]: " << delta / CLOCKS_PER_SEC << "s" << endl;
    cout << "=================================\n" << endl;
  }

  void search_similarity(BTree &bt) {}

 private:
  clock_t startTime, endTime;

  ofstream timelogSearchExactFile;
  ofstream timelogSearchSimilarityFile;
  ifstream saxSummarizationInputFile;

  string saxSummarizationInputFilename;
  string timelogSearchExactFilename;
  string timelogSearchSimilarityFilename;
  string outputPath;
};