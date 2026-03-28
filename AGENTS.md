# AGENTS.md - Development Guidelines for Agentic Coding

This document provides guidelines for agents working on the opencode-demo repository.

## Build, Test, and Lint Commands

### Compilation
```bash
# Compile the linked list implementation
gcc -Wall -Wextra -std=c99 -o linked_list linked_list.c

# Compile with debug symbols for debugging
gcc -Wall -Wextra -std=c99 -g -o linked_list linked_list.c

# Compile with all warnings and treat warnings as errors
gcc -Wall -Wextra -Werror -std=c99 -o linked_list linked_list.c
```

### Running
```bash
# Run the compiled executable
./linked_list

# Run with memory leak detection (using valgrind)
valgrind --leak-check=full --show-leak-kinds=all ./linked_list
```

### Linting & Static Analysis
```bash
# Check for common issues with cppcheck
cppcheck --enable=all linked_list.c

# Use clang static analyzer
clang --analyze linked_list.c
```

### Testing
Currently, there are no automated tests. The main() function contains manual test cases that verify:
- Insertion at beginning
- Insertion at end
- Deletion of nodes
- Deletion from empty list
- Handling of non-existent nodes

When adding tests, follow this structure:
```bash
# Compile and run with test output
gcc -Wall -Wextra -std=c99 -o linked_list_test linked_list.c
./linked_list_test
```

## Code Style Guidelines

### Includes
- System headers (stdio.h, stdlib.h) before any local includes
- Group includes with blank line between system and local headers
- Always include guards with #ifndef, #define, #endif for header files

### Formatting
- Use 4-space indentation (consistent with file)
- Maximum line length: 100 characters
- Opening braces on same line (K&R style):
  ```c
  if (condition) {
      // code
  }
  ```
- One blank line between function definitions
- No trailing whitespace

### Types and Variables
- Use standard C types: int, char, float, double, struct
- Use typedef for struct names to avoid "struct" keyword repetition
- Explicitly cast malloc() results:
  ```c
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  ```
- Initialize pointers to NULL when appropriate
- Use meaningful variable names (head, current, next, prev, data)

### Naming Conventions
- **Functions**: camelCase, descriptive action verb prefix (create, insert, delete, display)
- **Variables**: camelCase for local/global, UPPER_CASE for constants
- **Structs**: PascalCase (Node, LinkedList, Queue)
- **File scope statics**: prefix with underscore or static keyword
- Example: `struct Node* createNode(int data)`

### Function Design
- Keep functions focused on a single responsibility
- Add comment header for each function explaining purpose, parameters, return value
- Return NULL pointers on error conditions
- Free allocated memory in complementary functions
- Use early returns to reduce nesting

### Error Handling
- Check malloc() return value immediately after allocation
- Return NULL or head unchanged on invalid input
- Print descriptive error messages to stdout (current pattern)
- Example:
  ```c
  if (newNode == NULL) {
      printf("Memory allocation failed!\n");
      exit(1);
  }
  ```
- For delete operations, verify node exists before accessing next pointer
- Use exit(1) for fatal unrecoverable errors
- Use printf messages for non-fatal errors (missing nodes, empty lists)

### Memory Management
- Always free() allocated memory when no longer needed
- Avoid memory leaks: pair malloc() with free()
- For linked lists, provide cleanup functions
- Example memory leak check: `valgrind --leak-check=full ./linked_list`
- Set freed pointers to NULL in function returns
- In list operations (deleteNode), free node before returning

### Comments and Documentation
- Comment non-obvious logic and algorithm steps
- Keep comments concise and above the code they describe
- Document function purpose before implementation:
  ```c
  // Function to insert a node at the beginning of the list
  struct Node* insertAtBeginning(struct Node* head, int data)
  ```
- Inline comments for complex conditions
- No excessive comments for obvious code

### Common Patterns
- **List traversal**: Use current pointer, check for NULL termination
- **Insertion**: Create node, link it, return new head if needed
- **Deletion**: Handle head case separately, use prev/current pattern
- **Display**: Check for NULL/empty case first, use loop with NULL check

### Specific to This Project
- Focus on linked list operations: create, insert (beginning/end), delete, display
- Maintain singly-linked list structure (Node with data and next pointer)
- Support integer data type for nodes
- Ensure no memory leaks in all operations
- Include comprehensive main() with test cases demonstrating all operations

## Additional Guidelines

### Before Committing Changes
1. Compile with `-Wall -Wextra -std=c99` flags
2. Run memory leak check with valgrind
3. Verify main() test cases pass and output is correct
4. Ensure no compiler warnings or errors
5. Add comments for any new functions or complex logic

### When Adding New Features
- Update comments and documentation
- Add test cases to main() demonstrating the feature
- Follow existing naming and formatting conventions
- Consider edge cases (empty list, single node, NULL pointers)
- Test with valgrind to catch memory issues early
