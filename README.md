# 📝 Console-Based Notepad with AVL Tree Dictionary

A lightweight **console-based notepad** application with **spell-checking** and **dictionary support**, powered by an **AVL tree** for efficient word lookup and correction.

---

## 📌 Features
✅ **AVL Tree Dictionary** – Stores words for fast lookup and spell-checking.  
✅ **Real-Time Spell Check** – Detects and suggests corrections for misspelled words.  
✅ **Text Editing** – Add, delete, and load text dynamically using a linked list.  
✅ **File Handling** – Save and load text using keyboard shortcuts.  
✅ **Memory Management** – All dynamically allocated memory is released on exit.

---

## 🚀 How It Works
1️⃣ **Type your text** – Each letter is stored in a linked list.  
2️⃣ **Spell Check** – When you enter a space, the last word is checked in the AVL tree.  
3️⃣ **Corrections** – If a word is incorrect, possible corrections are suggested.  
4️⃣ **Edit & Manage Text** – Use keyboard shortcuts for quick text operations.  

---

## ⌨️ Controls & Shortcuts
- **Type Normally** – Adds characters to the notepad.
- **Backspace** – Deletes the last character.
- **Space** – Triggers spell-check for the last word.
- **Ctrl + L** – Load text from a file.
- **Ctrl + S** – Save the text to `save.txt`.
- **Esc** – Quit the application and release memory.

---

## 🔍 Spell-Check Modifications
The application suggests corrections using the following techniques:
- 🔄 **Letter Substitution** – Replaces each character with another to find valid words.
- ➖ **Letter Omission** – Removes one character at a time to form valid words.
- ➕ **Letter Insertion** – Inserts characters at various positions.
- 🔁 **Letter Reversal** – Swaps adjacent letters to form correct words.

---

## 🛠 Installation & Setup
1. **Clone the Repository**:
   ```sh
   git clone https://github.com/hamdashahid/Console-Notepad.git
   ```
2. **Navigate to the Project Folder**:
   ```sh
   cd Console-Notepad
   ```
3. **Compile & Run**:
   ```sh
   g++ -o notepad main.cpp -lncurses
   ./notepad
   ```

---

## 🏆 Future Improvements
- 🔹 Implement auto-suggestions as the user types.
- 🔹 Add a GUI version for better usability.
- 🔹 Support more file formats (e.g., `.doc`, `.pdf`).

---

## 📜 License
This project is open-source. Feel free to contribute and improve!

**Developed by:** *Your Name*  
© 2023 All Rights Reserved. 

---
