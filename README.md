# Assignment 3 Implementation Details

Our program implements a **Kanban board** using **linked lists**. It consists of two structures:

- **Lists**: Each list has a `next` pointer, linking it to the next list.
- **Items**: Items are linked to lists through `itemPtr`, ensuring correct item-list association.

## Functionality Overview

### Finding Items for Editing/Deleting
We use `while` loops to compare input strings with board data, locating target items for modifications.

### Loading a Board
- Implemented similarly to saving a board.
- Uses a `while` loop and `fscanf` to iterate through stored strings.
- Identifies list names by checking for `:` using `strchr`.

### Editing Lists and Items
- The user inputs the name of a list to edit.
- A `while` loop compares the input with existing lists.
- If a match is found, the user enters a new name, stored in `current->name`.
- If no match is found, "List not Found" is displayed.

### Saving a Board
- Begins at the head to traverse the entire list.
- A `while` loop (`while(current != NULL)`) iterates through lists, printing `current->name`.
- A pointer accesses each list's items, which are printed using another `while(ptr != NULL)` loop.
- This ensures items are correctly associated with their respective lists.

## Authors
- **Joey**
- **Pranav**
