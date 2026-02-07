# CSC340 Milestone 1 - Doubly Linked List Operations

## Project Overview
This C++ project implements a doubly linked list and processes JSON-defined test cases to perform operations like insertion, deletion, and movement of nodes. The program reads configuration from `milestone1_config.json` to determine input/output files, executes operations from `milestone1.json`, and logs results to both console and a specified output file.

## Architecture
- **Core Classes**: `DoublyLinkedList` (manages head/tail pointers and operations), `DllNode` (individual nodes with key, prev, next)
- **Data Flow**: JSON config → input JSON with test cases → operations on DLL → logged output to console + file
- **Key Pattern**: Each test case is an array of operation objects (e.g., `{"insertAtHead": 50}`), processed sequentially, followed by forward/reverse list prints and list clearing

## Build & Run
Compile with: `clang++ -std=c++11 milestone1.cpp dll_node.cpp doubly_linked_list.cpp -o milestone1`  
Run: `./milestone1`  
Note: Requires `doubly_linked_list.cpp` (implementation file may be missing from repo)

## Key Files
- `milestone1.cpp`: Main driver, JSON parsing, test case processing
- `doubly_linked_list.h`: DLL class declarations (implementation in .cpp)
- `dll_node.h/.cpp`: Node class with print functionality
- `milestone1_config.json`: Specifies input/output file paths and unused defaults (FIFOListSize, hashTableSize)
- `milestone1.json`: Test cases as JSON arrays of operations

## Conventions
- **Logging**: Use `logToFileAndConsole()` for dual console/file output (global `std::ofstream` managed via `setOutFile()`)
- **JSON Operations**: Each operation is a single-key object (e.g., `{"isEmpty": {}}` or `{"insertAtHead": 50}`)
- **List Management**: After each test case, print forward (`printList()`), reverse (`reversePrintList()`), then `clear()`
- **Includes**: Local `json.hpp` (nlohmann/json), standard I/O streams

## Common Operations
- Insert: `insertAtHead(int)`, `insertAtTail(int)`
- Remove: `remove(int key)`, `removeHeaderNode()`, `removeTailNode()`
- Move: `moveNodeToHead(int)`, `moveNodeToTail(int)`
- Query: `isEmpty()` returns bool
- Print: `printList()` (head→tail), `reversePrintList()` (tail→head)

## Dependencies
- nlohmann/json (included as `json.hpp`)
- C++11 standard (for JSON parsing)</content>
<parameter name="filePath">/Users/excalibur/Projects/CSC340/.github/copilot-instructions.md