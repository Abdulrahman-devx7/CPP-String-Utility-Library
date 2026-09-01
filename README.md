# 📦 C++ String Utility Library
A powerful string library that not only serves as an upgraded string object with more methods added to `std::string`, but is also rich with static methods that you can use directly on you data **without needing to instantiate an object**.

## Initialization 
You can initialize an empty `RichString` or use the built-in constructor to instantiate a meaningful object with data
```cpp
RichString example1; // Empty String
RichString example2("Library"); // A RichString object with the value "library"
```
### Setters and getters for the string value
You also use the `SetValue()` and `Value()` methods to set the object's value to something and grab the string's value respectively.
```cpp
RichString st1("Employee Name");
st1.SetValue("Jane Carter Smith");
cout << st1.Value(); 
```

### Use of original `std::string` methods
In order to use the original `std::string` methods, aside from the methods this library offers, you can still access the `std::string` member functions by getting the value of the `RichString` object and then use the dot operator again to view its methods as of the image.
[Image showing how you can access original string object methods whilst using the `RichString`](show_string_methods.png) 

## Static Usage 
You can use the static methods in this library to process data streaming from a source like a file or a database.
```cpp
cout << "Static words count: " << RichString::CountWords("High performance C++ string utility", " ") << endl; 
// Output : 5
cout << "Start Words Uppercase: " << RichString::StartWordsWithUppercase("william johnson smith", " ") << endl;
// Output: William Johnson Smith
```
### The example.cpp File
This is a comprehensive implementation file that utilizes all the library's methods. You can clone the repository locally via `git clone` (click [here](#installation) for details). Compile and run the .exe file and compare the example code with the console output.

To make things easier, here are images showing you the output:

<details>
<summary> Click to view the console output examples! </summary>

[First Part](outputShowcase1.png)

[Second Part](outputShowcase2.png)

</details>

## 💡 Core Features
The library features a variety of methods to serve various purposes:
### 📝 **Modification:** 
The library includes methods like:
- `Trim()` : This trims trailing or leading spaces for a **secure data pipeline** when exporting data from a CSV file, database, etc.. This method uses `TrimRight()` and `TrimLeft()` to run. Both of which can be used individually as well.
- `CapitalizeString()` and `DecapitalizeString()` to invert letter cases of the whole string to either uppercase or lowercase respectively. 
- Inversion functions like `InvertCharacter()` and `InvertString()` to invert all letter cases in a string.
- Functions to capitalize or decapitalize individual words in a string: `StartWordsWithUppercase()` and `StartWordsWithLowerCase()` . One of which can be useful record the full name of user correctly.

### 🪙 **Tokenization:** 
By characterizing the delimiter in your string, you can **split** it into tokens for modification or processing to be ready in the runtime of a certain program.
- `Split()` : This method takes your whole string with a given delimiter to characterize data fields from a line in a file for example.
- `JoinString()` : This is the opposite of the `Split()` method . It takes your tokens from an array and writes them into a file with a certain delimiter. This can be used to save data after updating.

### 🔁 **Transformations:** 
This involves methods that reform the whole string by reversing words or replacing certain words.
- `ReverseWords()` : This method tokenizes the elements or words, characterized by a delimiter, in a string and returns the whole thing reversed
- `ReplaceWords()` : This method follows a similar flow to `ReplaceWords()`, but the mere difference is that it picks the targeted words to replace them with a given word.
- `Replace()` : This method uses a sliding window mechanism to replace occurrences of a certain string with another string. The difference between it and `ReplaceWords()` is that this method **doesn't characterize words in a string via a delimiter. It runs the sliding window across the whole string to replace the instance of a given word regardless of where it exists or what part it forms from another string.** This can be super useful for web usage like in **URLs and API Endpoints.** 
- `RemovePunctuations()` : This method filters a given string from any special characters (i.e., `! " # \$ % & ' ( )` ) and gives you a clean string without any of these.

### 🔎 **Analysis:** 
This involves the **`Count` methods**, which is a set of methods dedicated to count instances of character types in a given string.
#### Word & Token Counting
Quantifies grouped segments of text based on specific delimiters.
* `CountWords(delimiter)`

#### Alphabet & Case Counting
Evaluates standard alphabetic characters and their casing formats.
* `CountAllLetters()`
* `CountUppercaseLetters()`
* `CountLowercaseLetters()`

#### Specific Character & Subset Counting
Targets exact character matches or specific linguistic subsets.
* `CountSpecificLetter(letter, matchCase)`
* `CountVowels()`

#### Numeric & Alphanumeric Counting
Analyzes numerical digits, hex-based systems, and broad alphanumeric combinations.
* `CountDigits()`
* `CountAlphanumeric()`
* `CountHexDigits()`

#### Formatting & Grammar Counting
Identifies whitespace structural elements and grammatical symbols.
* `CountSpaces()`
* `CountPunctuation()`

### Output
In addition to the main 4 above, this part involves some useful output functions that can do different things.

- `PrintFirstLetters()` : Given a certain delimiter to target words, this method picks words and prints the first letters of each word. It includes an optional boolean parameter to print the letters separated by spaces or each on a new line.
- `PrintEachWordInText()` : This method tokenizes the string based on a specified delimiter and prints each individual extracted word directly to the console. It automatically trims excess spaces from each token and also includes the optional toggle for single-line or multi-line console output

## ⚙️ Architecture and Engineering Choices
- The library features a function in the `private` scope of the class: `CountByCondition`, which serves as a **single source of truth (SSOT)** for the `Count` methods. It receives a **function pointer** as a parameter, which is given in the `Count` methods, to determine which function from the `<cctype>` library is going to applied for counting. E.g., `isupper()`, `isalnum()`, `isdigit()`, etc.
- The same pattern is seen with `StartWordsWith` methods, which use the `ModifyFirstLetters` method. This method serves similarly to `CountByCondition` , Meaning it's an SSOT that takes a function pointer to determine the modification type. It also receives a delimiter to characterize.
- An efficient algorithm that involves a **sliding window with two pointers** is used across several methods. It's efficiency lies in the fact that it doesn't involve heavy memory allocation with each use. Memory allocation is merely needed in `Split()` and other transformation methods to deliver the data as tokens for usage. There are lots of methods that involve this algorithm:
	- `PrintEachWordInText()`
	- `PrintFirstLetters()`
	- `CountWords()`
	- `ModifyFirstLetters()`
- An important decision has been taken in favor of **performance and memory efficiency.** A cleaner approach for this library would've involved the use of `Split()` across all the methods mentioned above. Regardless of what these methods do in UI or manipulation, memory allocation is always a **costly operation.** So in a trade-off of clean code for memory efficiency, I decided to keep this **repeated** logic in several methods to avoid memory allocation. The logic remains identical across some methods, but the functionalities differ for sure. So trying to make a something like the methods in the **private** scope of the class might overcomplicate the situation because each function has a different action to do. Thus, trading memory efficiency for repeating myself a little bit was the optimal solution.

## 🔗 Installation
In order to be able to use this library in you project, you just need to drop `RichString.h` into your directory. In addition, you'll need to include this header file by adding `#include "RichString.h"` to your files.

### Cloning the repository locally
#### Standard Clone 
Navigate to the directory where you want the project to live in your terminal, then run:
```bash
git clone https://github.com/Abdulrahman-devx7/CPP-String-Utility-Library.git
```
This automatically creates a new folder matching the remote repository's name.

#### Clone into a specific folder
To download the repository into a directory with a custom name, append the desired folder name to the end of the command:
```bash
git clone https://github.com/Abdulrahman-devx7/CPP-String-Utility-Library.git custom_folder_name
```

## 📎 Contribution Guidelines
- This project is considered an open-source project and is fully open for any contributions. You can apply your changes, whether it's more features, better performance, etc., and then send a detailed pull request with the changes!

- We prefer that you create a dedicated branch for your updates and use atomic commits to keep the version history clear and trackable.