# AGENTS.md creation and codebase guidelines

**Session ID:** ses_2cbfd201dffeECM6jnuBNQ1g7P
**Created:** 3/28/2026, 6:34:56 PM
**Updated:** 3/28/2026, 6:41:55 PM

---

## User

Please analyze this codebase and create an AGENTS.md file containing:
1. Build/lint/test commands - especially for running a single test
2. Code style guidelines including imports, formatting, types, naming conventions, error handling, etc.

The file you create will be given to agentic coding agents (such as yourself) that operate in this repository. Make it about 150 lines long.
If there are Cursor rules (in .cursor/rules/ or .cursorrules) or Copilot rules (in .github/copilot-instructions.md), make sure to include them.

If there's already an AGENTS.md, improve it if it's located in /

---

## Assistant (Build · claude-haiku-4.5 · 3.6s)

I'll analyze the codebase and create a comprehensive AGENTS.md file for you. Let me start by exploring the repository structure and understanding the project setup.

**Tool: bash**

**Input:**
```json
{
  "command": "find /home/jiashuo/code/projects/opencode-demo -type f -name \"package.json\" -o -name \"tsconfig.json\" -o -name \".cursorrules\" -o -name \".cursor\" -type d | head -20",
  "description": "Find project config files and cursor rules"
}
```

---

## Assistant (Build · claude-haiku-4.5 · 2.4s)

Let me check the directory structure more carefully:

**Tool: read**

**Input:**
```json
{
  "filePath": "/home/jiashuo/code/projects/opencode-demo"
}
```

**Output:**
```
<path>/home/jiashuo/code/projects/opencode-demo</path>
<type>directory</type>
<entries>
linked_list
linked_list.c

(2 entries)
</entries>
```

---

## Assistant (Build · claude-haiku-4.5 · 3.5s)

Let me explore the actual content of these files:

**Tool: read**

**Input:**
```json
{
  "filePath": "/home/jiashuo/code/projects/opencode-demo/linked_list.c"
}
```

**Output:**
```
<path>/home/jiashuo/code/projects/opencode-demo/linked_list.c</path>
<type>file</type>
<content>1: #include <stdio.h>
2: #include <stdlib.h>
3: 
4: // Define the structure for a node
5: struct Node {
6:     int data;
7:     struct Node* next;
8: };
9: 
10: // Function to create a new node
11: struct Node* createNode(int data) {
12:     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
13:     if (newNode == NULL) {
14:         printf("Memory allocation failed!\n");
15:         exit(1);
16:     }
17:     newNode->data = data;
18:     newNode->next = NULL;
19:     return newNode;
20: }
21: 
22: // Function to insert a node at the beginning of the list
23: struct Node* insertAtBeginning(struct Node* head, int data) {
24:     struct Node* newNode = createNode(data);
25:     newNode->next = head;
26:     return newNode;
27: }
28: 
29: // Function to insert a node at the end of the list
30: struct Node* insertAtEnd(struct Node* head, int data) {
31:     struct Node* newNode = createNode(data);
32:     if (head == NULL) {
33:         return newNode;
34:     }
35:     struct Node* current = head;
36:     while (current->next != NULL) {
37:         current = current->next;
38:     }
39:     current->next = newNode;
40:     return head;
41: }
42: 
43: // Function to delete a node with a specific value
44: struct Node* deleteNode(struct Node* head, int data) {
45:     if (head == NULL) {
46:         printf("List is empty. Cannot delete.\n");
47:         return NULL;
48:     }
49: 
50:     // If head node itself holds the data to be deleted
51:     if (head->data == data) {
52:         struct Node* temp = head;
53:         head = head->next;
54:         free(temp);
55:         return head;
56:     }
57: 
58:     struct Node* current = head;
59:     struct Node* prev = NULL;
60:     while (current != NULL && current->data != data) {
61:         prev = current;
62:         current = current->next;
63:     }
64: 
65:     // If data was not present in the list
66:     if (current == NULL) {
67:         printf("Node with data %d not found.\n", data);
68:         return head;
69:     }
70: 
71:     // Unlink the node from the list and free memory
72:     prev->next = current->next;
73:     free(current);
74:     return head;
75: }
76: 
77: // Function to display the linked list
78: void displayList(struct Node* head) {
79:     struct Node* current = head;
80:     if (current == NULL) {
81:         printf("Linked List is empty.\n");
82:         return;
83:     }
84:     printf("Linked List: ");
85:     while (current != NULL) {
86:         printf("%d -> ", current->data);
87:         current = current->next;
88:     }
89:     printf("NULL\n");
90: }
91: 
92: // Main function to demonstrate linked list operations
93: int main() {
94:     struct Node* head = NULL; // Initialize an empty linked list
95: 
96:     printf("--- Inserting elements ---\n");
97:     head = insertAtBeginning(head, 10);
98:     displayList(head); // Expected: 10 -> NULL
99: 
100:     head = insertAtEnd(head, 20);
101:     displayList(head); // Expected: 10 -> 20 -> NULL
102: 
103:     head = insertAtBeginning(head, 5);
104:     displayList(head); // Expected: 5 -> 10 -> 20 -> NULL
105: 
106:     head = insertAtEnd(head, 30);
107:     displayList(head); // Expected: 5 -> 10 -> 20 -> 30 -> NULL
108: 
109:     printf("\n--- Deleting elements ---\n");
110:     head = deleteNode(head, 20);
111:     displayList(head); // Expected: 5 -> 10 -> 30 -> NULL
112: 
113:     head = deleteNode(head, 5);
114:     displayList(head); // Expected: 10 -> 30 -> NULL
115: 
116:     head = deleteNode(head, 100); // Node not found
117:     displayList(head); // Expected: 10 -> 30 -> NULL (and "Node not found" message)
118: 
119:     head = deleteNode(head, 30);
120:     displayList(head); // Expected: 10 -> NULL
121: 
122:     head = deleteNode(head, 10);
123:     displayList(head); // Expected: Linked List is empty.
124: 
125:     // Free all remaining nodes to prevent memory leaks (though in this example, it's empty after deletes)
126:     struct Node* current = head;
127:     while (current != NULL) {
128:         struct Node* next = current->next;
129:         free(current);
130:         current = next;
131:     }
132:     // head = NULL; // No need to set head to NULL again as it's already handled by deleteNode for the last node
133: 
134:     return 0;
135: }

(End of file - total 135 lines)
</content>
```

---

## Assistant (Build · claude-haiku-4.5 · 3.5s)

Let me check for the linked_list directory and any config files:

**Tool: bash**

**Input:**
```json
{
  "command": "ls -la /home/jiashuo/code/projects/opencode-demo/ && find /home/jiashuo/code/projects/opencode-demo -type f \\( -name \"Makefile\" -o -name \"CMakeLists.txt\" -o -name \"*.md\" -o -name \".cursorrules\" -o -name \"copilot-instructions.md\" \\) 2>/dev/null",
  "description": "List directory contents and find config/rules files"
}
```

**Output:**
```
total 28
drwxr-xr-x  2 jiashuo jiashuo  4096 Mar 28 02:31 .
drwxr-xr-x 24 jiashuo jiashuo  4096 Mar 28 01:01 ..
-rwxr-xr-x  1 jiashuo jiashuo 16320 Mar 28 02:31 linked_list
-rw-r--r--  1 jiashuo jiashuo  3729 Mar 28 02:27 linked_list.c

```

---

## Assistant (Build · claude-haiku-4.5 · 3.9s)

Now let me check if there's a parent directory with configuration files:

**Tool: bash**

**Input:**
```json
{
  "command": "find /home/jiashuo/code/projects -maxdepth 2 -type f \\( -name \"*.cursorrules\" -o -name \".cursorrules\" -o -name \"copilot-instructions.md\" \\) 2>/dev/null",
  "description": "Search for cursor and copilot rules in projects directory"
}
```

---

## Assistant (Build · claude-haiku-4.5 · 1.0s)

Let me check the repo root more thoroughly:

**Tool: bash**

**Input:**
```json
{
  "command": "find / -maxdepth 3 -type d -name \".cursor\" 2>/dev/null | head -5",
  "description": "Find any .cursor directories"
}
```

---

## Assistant (Build · claude-haiku-4.5 · 16.4s)

Now I have a clear understanding of the repository. Let me create the AGENTS.md file with guidelines for this C project:

**Tool: write**

**Input:**
```json
{
  "filePath": "/home/jiashuo/code/projects/opencode-demo/AGENTS.md",
  "content": "# AGENTS.md - Development Guidelines for Agentic Coding\n\nThis document provides guidelines for agents working on the opencode-demo repository.\n\n## Build, Test, and Lint Commands\n\n### Compilation\n```bash\n# Compile the linked list implementation\ngcc -Wall -Wextra -std=c99 -o linked_list linked_list.c\n\n# Compile with debug symbols for debugging\ngcc -Wall -Wextra -std=c99 -g -o linked_list linked_list.c\n\n# Compile with all warnings and treat warnings as errors\ngcc -Wall -Wextra -Werror -std=c99 -o linked_list linked_list.c\n```\n\n### Running\n```bash\n# Run the compiled executable\n./linked_list\n\n# Run with memory leak detection (using valgrind)\nvalgrind --leak-check=full --show-leak-kinds=all ./linked_list\n```\n\n### Linting & Static Analysis\n```bash\n# Check for common issues with cppcheck\ncppcheck --enable=all linked_list.c\n\n# Use clang static analyzer\nclang --analyze linked_list.c\n```\n\n### Testing\nCurrently, there are no automated tests. The main() function contains manual test cases that verify:\n- Insertion at beginning\n- Insertion at end\n- Deletion of nodes\n- Deletion from empty list\n- Handling of non-existent nodes\n\nWhen adding tests, follow this structure:\n```bash\n# Compile and run with test output\ngcc -Wall -Wextra -std=c99 -o linked_list_test linked_list.c\n./linked_list_test\n```\n\n## Code Style Guidelines\n\n### Includes\n- System headers (stdio.h, stdlib.h) before any local includes\n- Group includes with blank line between system and local headers\n- Always include guards with #ifndef, #define, #endif for header files\n\n### Formatting\n- Use 4-space indentation (consistent with file)\n- Maximum line length: 100 characters\n- Opening braces on same line (K&R style):\n  ```c\n  if (condition) {\n      // code\n  }\n  ```\n- One blank line between function definitions\n- No trailing whitespace\n\n### Types and Variables\n- Use standard C types: int, char, float, double, struct\n- Use typedef for struct names to avoid \"struct\" keyword repetition\n- Explicitly cast malloc() results:\n  ```c\n  struct Node* node = (struct Node*)malloc(sizeof(struct Node));\n  ```\n- Initialize pointers to NULL when appropriate\n- Use meaningful variable names (head, current, next, prev, data)\n\n### Naming Conventions\n- **Functions**: camelCase, descriptive action verb prefix (create, insert, delete, display)\n- **Variables**: camelCase for local/global, UPPER_CASE for constants\n- **Structs**: PascalCase (Node, LinkedList, Queue)\n- **File scope statics**: prefix with underscore or static keyword\n- Example: `struct Node* createNode(int data)`\n\n### Function Design\n- Keep functions focused on a single responsibility\n- Add comment header for each function explaining purpose, parameters, return value\n- Return NULL pointers on error conditions\n- Free allocated memory in complementary functions\n- Use early returns to reduce nesting\n\n### Error Handling\n- Check malloc() return value immediately after allocation\n- Return NULL or head unchanged on invalid input\n- Print descriptive error messages to stdout (current pattern)\n- Example:\n  ```c\n  if (newNode == NULL) {\n      printf(\"Memory allocation failed!\\n\");\n      exit(1);\n  }\n  ```\n- For delete operations, verify node exists before accessing next pointer\n- Use exit(1) for fatal unrecoverable errors\n- Use printf messages for non-fatal errors (missing nodes, empty lists)\n\n### Memory Management\n- Always free() allocated memory when no longer needed\n- Avoid memory leaks: pair malloc() with free()\n- For linked lists, provide cleanup functions\n- Example memory leak check: `valgrind --leak-check=full ./linked_list`\n- Set freed pointers to NULL in function returns\n- In list operations (deleteNode), free node before returning\n\n### Comments and Documentation\n- Comment non-obvious logic and algorithm steps\n- Keep comments concise and above the code they describe\n- Document function purpose before implementation:\n  ```c\n  // Function to insert a node at the beginning of the list\n  struct Node* insertAtBeginning(struct Node* head, int data)\n  ```\n- Inline comments for complex conditions\n- No excessive comments for obvious code\n\n### Common Patterns\n- **List traversal**: Use current pointer, check for NULL termination\n- **Insertion**: Create node, link it, return new head if needed\n- **Deletion**: Handle head case separately, use prev/current pattern\n- **Display**: Check for NULL/empty case first, use loop with NULL check\n\n### Specific to This Project\n- Focus on linked list operations: create, insert (beginning/end), delete, display\n- Maintain singly-linked list structure (Node with data and next pointer)\n- Support integer data type for nodes\n- Ensure no memory leaks in all operations\n- Include comprehensive main() with test cases demonstrating all operations\n\n## Additional Guidelines\n\n### Before Committing Changes\n1. Compile with `-Wall -Wextra -std=c99` flags\n2. Run memory leak check with valgrind\n3. Verify main() test cases pass and output is correct\n4. Ensure no compiler warnings or errors\n5. Add comments for any new functions or complex logic\n\n### When Adding New Features\n- Update comments and documentation\n- Add test cases to main() demonstrating the feature\n- Follow existing naming and formatting conventions\n- Consider edge cases (empty list, single node, NULL pointers)\n- Test with valgrind to catch memory issues early\n"
}
```

**Output:**
```
Wrote file successfully.
```

---

## Assistant (Build · claude-haiku-4.5 · 5.8s)

Perfect! I've created a comprehensive **AGENTS.md** file for your opencode-demo repository. Here's what I included:

## Summary

The file contains approximately 160 lines with:

1. **Build/Lint/Test Commands**
   - Compilation options (standard, debug, strict error checking)
   - Running with memory leak detection (valgrind)
   - Static analysis tools (cppcheck, clang analyzer)
   - Testing structure and how to run tests

2. **Code Style Guidelines** covering:
   - **Includes**: System headers first, organized with blank lines
   - **Formatting**: 4-space indentation, K&R style braces, 100-char line limit
   - **Types & Variables**: Standard C types, explicit malloc casts, meaningful names
   - **Naming Conventions**: camelCase for functions/variables, PascalCase for structs
   - **Function Design**: Single responsibility, early returns, proper error handling
   - **Error Handling**: malloc checks, NULL returns, exit(1) for fatal errors
   - **Memory Management**: malloc/free pairing, valgrind checks, cleanup functions
   - **Comments**: Clear function headers, concise inline comments
   - **Common Patterns**: Traversal, insertion, deletion, display operations

3. **Project-Specific Guidelines**
   - Linked list focus (singly-linked, integer nodes)
   - Comprehensive pre-commit checks
   - Feature addition best practices

The file is tailored to your C linked list project and provides agents with clear, actionable guidelines for maintaining code quality and consistency.

---

