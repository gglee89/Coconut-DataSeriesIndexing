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
    - **main.css:** Main executable generator;
    - **utility.h:** Utility functions separated into an individual file;
    - **input/:** Data series entries
    - **README.md** (Documentation);
  - Output:
    - djwaioda
    - dhwuiahduwai

## 2. File Architecture

```js
  - /external_lib
  - /functions
  - /output
    - (Generated) summarization.txt: SAX representations of Raw Data Series
    - (Generated) execution_timelog.txt: Query execution time log
  - input.txt (Raw dataseries input)
  - main.cpp (Main source code)
  - README.md (Code Documentation)
  - (Generated) a.out: Binary executable
```

## 3. How to Run the code

```bash
1. Compile the main source code:
$ g++ -std=c++11 main.cpp
```

```bash
2. Run the program with the new compiled executable
$ ./a.out
```

## 4. Dataset

There are two test datasets for this program:

```
[1MB test dataset]
input.txt
```

```
[450MB test dataset - For Scalability test]
You need to download this generated dataset to perform tests.
I've uploaded a copy of the dataset into a public-url in my Google Drive.

```

## 5. Collaborators

- **Giwoo G Lee.** PhD student in Computer Science @Florida State University
  - Research
  - Development
  - Presentation
