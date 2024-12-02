
# **Get Next Line**

## **Description**

The `get_next_line` project is part of the 42 School curriculum. It involves creating a function that reads a file line by line, allowing precise and efficient handling of text files of varying sizes. This implementation focuses on memory management and modular design.

The function prototype is:
```c
char *get_next_line(int fd);
```

### **Features**
- Reads one line at a time from a file descriptor.
- Handles both `\n`-terminated and non-terminated lines.
- Utilizes a static variable to preserve leftover data between function calls.
- Supports configurable `BUFFER_SIZE` for optimized performance.

---

## **Files**

### **Mandatory Files**
1. **`get_next_line.c`**  
   Contains the core logic for reading and parsing lines.

2. **`get_next_line_utils.c`**  
   Includes helper functions like `ft_strjoin` and `ft_strlen`.

3. **`get_next_line.h`**  
   Header file containing function prototypes and necessary includes.

---

## **Implementation Details**

### **Key Functions**
1. **`get_next_line(int fd)`**  
   - Manages the file descriptor's buffer (`stash`) and retrieves the next line.
   - Uses static variables to retain data across function calls.

2. **`line_read(char *stash, int fd)`**  
   - Reads from the file descriptor and appends new data to the `stash`.
   - Stops reading when a newline character is found or the file ends.

3. **`get_line(char *buf)`**  
   - Extracts a single line (including `\n`, if present) from the buffer.

4. **`left(char *buf)`**  
   - Updates the `stash` to hold leftover data after the current line is extracted.

### **Helper Functions**
- **`ft_strjoin(char *s1, char *s2)`**  
   Concatenates two strings into a new dynamically allocated string.
   
- **`ft_strlen(char *s)`**  
   Calculates the length of a string.

---

## **Memory Management**

1. **Dynamic Allocation**  
   - Memory is dynamically allocated for buffers and returned strings.
   - Ensures no memory leaks by freeing unused variables.

2. **Error Handling**  
   - Returns `NULL` if memory allocation fails or if invalid parameters are passed.

3. **Static Variable**  
   - The `stash` variable retains leftover data between successive calls.

---

## **Edge Cases**

1. **Empty File**  
   - Returns `NULL` immediately.

2. **Large Lines**  
   - Handles lines larger than `BUFFER_SIZE` seamlessly.

3. **Files without Newline**  
   - Reads the entire file as a single line if no newline character is present.

4. **Invalid File Descriptor**  
   - Returns `NULL` if the file descriptor is invalid.

---

## **Challenges**

1. **Buffer Management**  
   - Ensuring that no data is lost between reads.

2. **Memory Leaks**  
   - Freeing dynamically allocated memory at the right time.

3. **Performance**  
   - Reading efficiently without excessive system calls.

---

## **Testing**

### **Example Test Cases**
1. **Basic File**
   - A file with multiple lines.
   - Expected: each call to `get_next_line` returns the next line.

2. **Single Line File**
   - A file with a single, long line.
   - Expected: line returned correctly.

3. **Empty File**
   - Expected: `NULL` returned immediately.

4. **File with Only Newlines**
   - Expected: empty lines are returned for each newline.

5. **Invalid File Descriptor**
   - Expected: `NULL` returned.

---

## **Compilation and Norminette**
- Ensure compliance with the 42 Norm.
- Compile with `-Wall -Wextra -Werror` to catch potential issues.

---

## **Acknowledgments**

This implementation of `get_next_line` was designed as part of the 42 School curriculum. It highlights the importance of efficient file reading and memory management in C.

---
