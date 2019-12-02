/**
 * @title: Data Series Query function
 * @description: Output query result:
 *  [1]: Exact Search
 *  [2]: Similarity Search
 * @author: Giwoo G Lee
 * @project: COP5725 - @FSU Fall '19
 * @since 2019-11-24
 */
string OUTPUT_PATH = "output/";
string FILE_NAME_EXECUTION_TIMELOG = "execution_timelog.txt";
string FILE_NAME_SUMMARIZATION = "summarization.txt";

void dataseries_query() {
  // ARGUMENT ERROR HANDLING
  char entry = program_menu_query();

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
      case 'q':
      case 'Q':

        break;
      default:
        cout << "\nInvalid key" << endl;
        break;
    }

    ifstream myfileExecutionTimelog;
    ifstream myfileSummarization;
    clock_t startTimeTreeBuild, endTimeTreeBuild;
    clock_t startTimeQuery, endTimeQuery;

    // FILE OPEN
    myfileExecutionTimelog.open(OUTPUT_PATH + FILE_NAME_EXECUTION_TIMELOG);
    myfileSummarization.open(OUTPUT_PATH + FILE_NAME_SUMMARIZATION);

    // FILE ERROR HANDLING
    if (myfileExecutionTimelog.fail()) {
      cerr << "cannot open input file: output.txt ... terminating." << endl;
      exit(EXIT_FAILURE);
    }
    if (myfileSummarization.fail()) {
      cerr << "cannot open input file: saxoutput.txt ... terminating." << endl;
      exit(EXIT_FAILURE);
    }

    // FILE PROCESSING STARTS HERE
    string lineExecutionTimelog, lineSummarization;
    int numline = 0;

    // START TIME TRACKING
    startTimeTreeBuild = clock();

    // B-TREE CREATION
    BTree bt(3);
    while (getline(myfileSummarization, lineSummarization) &&
           getline(myfileExecutionTimelog, lineExecutionTimelog)) {
      numline++;
      bt.insert(std::stoull(lineSummarization), lineExecutionTimelog);
    }

    // SAVE TIME TRACKING - EXECUTION TIME
    endTimeTreeBuild = clock();

    cout << "==== Query ====" << endl;
    cout << "Description: Sequence ending with a #(pound) symbol" << endl;
    cout << "Example: 2 4 20 6 3 1 #" << endl;
    cout << "Enter query:" << endl;

    getline(selectOption, queryline, "#");

    // START EXECUTION TIME TRACKING
    startTimeQuery = clock();

    // BUILD SAX SUMMARIZATION
    uint64_t f2D_32_encode = process_summarization(queryLine);

    cout << f2D_32_encode << endl;
    cout << "the result is (key and sequence ) " << endl;
    BTreeNode *node = bt.search(f2D_32_encode);
    cout << node << endl;

    // END EXECUTION TIME
    endTimeQuery = clock();

    // OUTPUT
    cout << "\n==================================" << endl;
    cout << "===== Coconut Query Output: =====" << endl;
    cout << "=================================" << endl;
    cout << "[Total execution time]: "
         << (double)(endTimeQuery - startTimeQuery) / CLOCKS_PER_SEC << "s"
         << endl;
  }