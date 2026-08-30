#include <iostream>
#include <vector>
#include "RichString.h"

using namespace std;

int main()
{
    // 1. Instantiation and Getter/Setter Checks
    RichString string1;
    RichString string2("Cairo");

    string1.SetValue("Software Engineering");

    cout << "string1 = " << string1.Value() << endl;
    cout << "string2 = " << string2.Value() << endl;

    // 2. Word Counting (Instance vs Static)
    cout << "string1 words count: " << string1.CountWords() << endl;
    cout << "Static words count: " << RichString::CountWords("High performance C++ string utility", " ") << endl;

    // 3. Case Formatting
    RichString string3("backend architecture and design");
    cout << "\nOriginal String 3: " << string3.Value() << endl;

    string3.StartWordsWithUppercase();
    cout << "Start Words Uppercase: " << string3.Value() << endl;

    string3.StartWordsWithLowerCase();
    cout << "Start Words Lowercase: " << string3.Value() << endl;

    string3.CapitalizeString();
    cout << "All Uppercase: " << string3.Value() << endl;

    string3.DecapitalizeString();
    cout << "All Lowercase: " << string3.Value() << endl;

    // 4. Character & Case Inversion
    cout << "\nInverting 'z': " << RichString::InvertCharacter('z') << endl;
    cout << "Inverting 'B': " << RichString::InvertCharacter('B') << endl;

    string3.SetValue("DataStructures");
    cout << "Before inverting string: " << string3.Value() << endl;
    string3.InvertString();
    cout << "After inverting string: " << string3.Value() << endl;

    // 5. Counting Conditions (Alpha, Numeric, Vowels, etc.)
    RichString analyzer("Compiler 2026: Build v2.1!");
    cout << "\nAnalyzing: " << analyzer.Value() << endl;
    cout << "Total Length: " << analyzer.Length() << endl;
    cout << "Letters: " << analyzer.CountAllLetters() << endl;
    cout << "Uppercase: " << analyzer.CountUppercaseLetters() << endl;
    cout << "Lowercase: " << analyzer.CountLowercaseLetters() << endl;
    cout << "Digits: " << analyzer.CountDigits() << endl;
    cout << "Punctuation: " << analyzer.CountPunctuation() << endl;
    cout << "Spaces: " << analyzer.CountSpaces() << endl;
    cout << "Vowels: " << analyzer.CountVowels() << endl;
    cout << "Specific Letter 'e' (case-insensitive): " << analyzer.CountSpecificLetter('e', false) << endl;

    // 6. Sliding Window Splitting & Printing
    RichString sentence("Optimizing   memory   allocations   in   loops");
    cout << "\nSplitting text by delimiter: \n";
    vector<string> tokens = sentence.Split(" ");

    for (const string& token : tokens)
    {
        cout << "[" << token << "]\n";
    }

    cout << "\nPrint first letters directly: ";
    RichString::PrintFirstLetters("Object Oriented Programming Paradigm", " ", false);
    cout << endl;

    // 7. Trimming Operations
    RichString untrimmed("   Zero Overhead Systems   ");
    cout << "\nUntrimmed: '" << untrimmed.Value() << "'" << endl;

    untrimmed.TrimLeft();
    cout << "Trim Left: '" << untrimmed.Value() << "'" << endl;

    untrimmed.SetValue("   Zero Overhead Systems   ");
    untrimmed.TrimRight();
    cout << "Trim Right: '" << untrimmed.Value() << "'" << endl;

    untrimmed.SetValue("   Zero Overhead Systems   ");
    untrimmed.Trim();
    cout << "Full Trim: '" << untrimmed.Value() << "'" << endl;

    // 8. Transformations (Join, Reverse, Replace, Punctuation)
    vector<string> pipeline = { "Database", "Cache", "Server", "Client" };
    cout << "\nJoined Pipeline: " << RichString::JoinString(pipeline, " -> ") << endl;

    RichString phrase("First In Last Out");
    phrase.ReverseWords();
    cout << "Reversed Words: " << phrase.Value() << endl;

    RichString config("host: localhost, port: 8080");
    config.Replace("8080", "5432");
    cout << "Replaced Config: " << config.Value() << endl;

    RichString dirtyInput("SELECT * FROM users WHERE id = 10; -- clean!");
    dirtyInput.RemovePunctuations();
    cout << "Removed Punctuation: " << dirtyInput.Value() << endl;

    return 0;
}