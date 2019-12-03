## Coconut: A Scalable Bottom-Up Approach for Building Data Series Indexes.

**Original Paper:** https://www.vldb.org/pvldb/vol11/p677-kondylakis.pdf
<br>
**Project:** This is the database project for the COP5725 course taught by [Dr.PhD.Peixiang Zhao](http://www.cs.fsu.edu/~zhao/) for Fall '19 @Florida State University.

## Index:

1. **Project Description.**
   - Disclaimer.
   - What is it about?
   - Content.
2. **File Architecture**
3. **How to run the code.**
4. **Dataset.**
5. **Collaborators.**

## 1. Project Description

- **Disclaimer:** As a disclaimer, the source code found in this project is a personal intepretation of the original implementation. The original implementation can be found in the authors' code repositories.
- **What is it about?** C++ implementation of the Coconut technique. The source code implementation generates the following:
  - sortable summarization of data series entries.
  - bulk-loads the sorted entries into the B+ Tree for querying.
- **Content:** The project consists of 5 files:
  - Input:
    - **main.cpp:** Main executable;
    - **functions:** Utility functions separated into an individual module;
    - **class:** Main classes for DataSeries, Indexing, and Query (OOP approach);
    - **input.txt:** Raw data series
    - **README.md** (Documentation);
  - Output:
    - summarization.txt: SAX dataseries summarization;
    - timelog\_\*.txt: Timelog outputs from Indexing and Query execution time;

## 2. File Architecture

```js
  - /class
    - Dataseries.h: Main Dataseries class. Coordinates between Indexing and Querying operations.
    - Indexing.h: Encapsulates methods related to Indexing operations (e.g.: SAX Summarization, BTree build).
    - Query.h: Encapsulates methods related to Query operations (e.g.: Exact Search, Similarity Search).
    - Sax.h: Encapsulates methods related to iSAX summarization (e.g.: zvaluecal, paacal, saxcal, and invertsax);
  - /external_lib
    - stdc++.h:
    - tree_m.h: `BTree` builder
  - /functions
    - menu.h: Display menu for Summarization and Query
    - utility.h: Conversion functions
  - /output
    - (Generated) summarization.txt: SAX representations of Raw Data Series
    - (Generated) timelog_*.txt: Query execution time log
  - input.txt (Raw dataseries input)
  - main.cpp (Main source code)
  - README.md (Code Documentation)
  - (Generated) a.out: Binary executable
```

![Demo__ArchitectureDiagram](https://user-images.githubusercontent.com/16644017/70005785-c3781480-1538-11ea-9d2b-c7b2a6adcfd8.jpeg)

## 3. How to Run the code

```bash
1. Compile the main source code:
$ g++ -std=c++11 main.cpp
```

```bash
2. Run the program with the new compiled executable
$ ./a.out
```

```bash
3. The program consists of two main operations. Indexing and Querying.
Main Menu:
==================================
========== Coconut Menu ==========
==================================
== [0]: Indexing =================
== [1]: Query ====================
== [2]: Exit =====================
==================================
Enter choice:
```

```bash
4. Indexing:
  ==============================================================================
  Raw dataseries input filepath [input.txt]: input.txt
  opening input.txt...

  Performing SAX Summarization...
  =========================================
  ===== Coconut Summarization Output: =====
  =========================================
  [Output filename]: output/summarization.txt
  [Output log filename]: output/timelog_sax_summarization.txt

  Building BTree...
  =========================================
  ====== Coconut BTree Build Output: ======
  =========================================
  [Total execution time]: 7.3e-05s
  [Output log filename]: output/timelog_btree.txt
  Enter [anykey] to continue...
  ==============================================================================

  - Input:
    - Raw dataseries input file (e.g.: input.txt)
  - Output:
    - summarization.txt
    - timelog_btree.txt: Output of the Execution time to build the BTree.
    - timelog_sax_summarization.txt: Output of the Execution time to build the SAX Summarization.
```

```bash
4. Querying:
  ==============================================================================
  =================================
  ========= Coconut Query =========
  =================================
  [e or E]: Exact Search
  [s or S]: Simiilarity Search
  [r or R]: Return to Main Menu
  Enter choice : e

  ================================
  ========= Search Query =========
  ================================
  == Description: Sequence ending with a #(pound) symbol
  == Example: 2 4 20 6 3 1 #
  ================================
  Enter query: 10 20 30 40 50 5 4 26 #
  find the node!
  70368748371968
  36

  ==================================
  ===== Coconut Query Output: =====
  =================================
  [Total execution time]: 0.000116s
  =================================

  Enter [anykey] to continue...
  ==============================================================================
  - Input:
    - Raw dataseries input file (e.g.: input.txt)
    - Summarization of the raw dataseries (e.g.: summarization.txt)
  - Output:
    - summarization.txt
    - timelog_btree.txt: Output of the Execution time to build the BTree.
    - timelog_sax_summarization.txt: Output of the Execution time to build the SAX Summarization.
```

## 4. Dataset

There are two test datasets for this program:

```
[10KB test dataset]
Index construction (BTree build):
  - [Total execution time]: 0.000298s

Query Exact Search
  - [Total execution time]: 0.000118s
```

```
[3.6MB small dataset]
Index construction (BTree build):
  - [Total execution time]: 0.004538s

Query Exact Search
  - [Total execution time]: 0.000199s
```

```
[450MB test dataset - For Scalability test]
You need to download this generated dataset to perform tests.
I've uploaded a copy of the dataset into a public-url in my Google Drive.
https://drive.google.com/open?id=1EHA5QvDUGZ8Uz0E4X0qoZKlOk-GeUTis

Obs.: Make sure to increase your application array memory size.
      This dataset contains 202.000+ dataseries.
      Otherwise, the application will trigger Exceptions.
```

## 5. Collaborators

- **Giwoo G Lee.** PhD student in Computer Science @Florida State University
  - Research
  - Development
  - Presentation
