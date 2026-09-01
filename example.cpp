#include <iostream>
#include <vector>
#include "RichString.h"

using namespace std;

int main()
{
    cout << "=========================================\n";
    cout << "       RichString Library Showcase       \n";
    cout << "=========================================\n\n";

    // --- 1. INSTANTIATION & BASICS ---
    cout << "--- 1. Instantiation & Basics ---\n";
    RichString textInstance("  hello C++ world  ");
    cout << "Instance Value      : [" << textInstance.Value() << "]\n";
    cout << "Instance Length     : " << textInstance.Length() << "\n";
    cout << "Static Length       : " << RichString::Length("Direct text") << "\n\n";


    // --- 2. TRIMMING (Instance vs Static) ---
    cout << "--- 2. Trimming ---\n";
    RichString trimObj("   spacing   ");

    cout << "[Instance] Before   : [" << trimObj.Value() << "]\n";
    trimObj.TrimLeft();
    cout << "[Instance] TrimLeft : [" << trimObj.Value() << "]\n";

    trimObj.SetValue("   spacing   ");
    trimObj.TrimRight();
    cout << "[Instance] TrimRight: [" << trimObj.Value() << "]\n";

    trimObj.SetValue("   spacing   ");
    trimObj.Trim();
    cout << "[Instance] Full Trim: [" << trimObj.Value() << "]\n\n";

    string rawText = "   static trim   ";
    cout << "[Static] Before     : [" << rawText << "]\n";
    cout << "[Static] Trim       : [" << RichString::Trim(rawText) << "]\n\n";


    // --- 3. CASE FORMATTING ---
    cout << "--- 3. Case Formatting ---\n";
    RichString caseObj("backend architecture and design");

    cout << "[Instance] Before               : " << caseObj.Value() << "\n";
    caseObj.StartWordsWithUppercase();
    cout << "[Instance] StartWordsUppercase  : " << caseObj.Value() << "\n";
    caseObj.StartWordsWithLowerCase();
    cout << "[Instance] StartWordsLowercase  : " << caseObj.Value() << "\n";
    caseObj.CapitalizeString();
    cout << "[Instance] CapitalizeString     : " << caseObj.Value() << "\n";
    caseObj.DecapitalizeString();
    cout << "[Instance] DecapitalizeString   : " << caseObj.Value() << "\n\n";

    string staticCase = "object oriented programming";
    cout << "[Static] Before                 : " << staticCase << "\n";
    cout << "[Static] StartWordsWithUppercase: " << RichString::StartWordsWithUppercase(staticCase, " ") << "\n";
    cout << "[Static] CapitalizeString       : " << RichString::CapitalizeString(staticCase) << "\n\n";


    // --- 4. CHARACTER & STRING INVERSION ---
    cout << "--- 4. Character & String Inversion ---\n";
    RichString invObj("DaTa StrUcTuReS");

    cout << "[Instance] Before String Invert : " << invObj.Value() << "\n";
    invObj.InvertString();
    cout << "[Instance] After String Invert  : " << invObj.Value() << "\n";

    invObj.SetValue("abc");
    cout << "[Instance] Before Char Invert   : " << invObj.Value() << "\n";
    invObj.InvertCharacter(0); // Invert 'a' at index 0
    cout << "[Instance] After Char Invert(0) : " << invObj.Value() << "\n\n";

    cout << "[Static] InvertCharacter('z')   : " << RichString::InvertCharacter('z') << "\n";
    cout << "[Static] InvertString('MaCrO')  : " << RichString::InvertString("MaCrO") << "\n\n";


    // --- 5. STRING ANALYSIS & COUNTING ---
    cout << "--- 5. Analysis & Counting ---\n";
    RichString stats("C++ 20, Build v2.5! (Beta)");
    cout << "Analyzing Text: [" << stats.Value() << "]\n";

    cout << "[Instance] Word Count           : " << stats.CountWords() << "\n";
    cout << "[Instance] Total Letters        : " << stats.CountAllLetters() << "\n";
    cout << "[Instance] Uppercase Letters    : " << stats.CountUppercaseLetters() << "\n";
    cout << "[Instance] Lowercase Letters    : " << stats.CountLowercaseLetters() << "\n";
    cout << "[Instance] Digits               : " << stats.CountDigits() << "\n";
    cout << "[Instance] Punctuation          : " << stats.CountPunctuation() << "\n";
    cout << "[Instance] Spaces               : " << stats.CountSpaces() << "\n";
    cout << "[Instance] Vowels               : " << stats.CountVowels() << "\n";
    cout << "[Instance] Specific Letter ('b'): " << stats.CountSpecificLetter('b', false) << "\n\n";

    cout << "[Static] Word Count             : " << RichString::CountWords("One two three", " ") << "\n";
    cout << "[Static] Hex Digits in '0x1A3F' : " << RichString::CountHexDigits("0x1A3F") << "\n\n";


    // --- 6. TOKENIZATION (Split, Join, Printing) ---
    cout << "--- 6. Tokenization ---\n";
    RichString tokenObj("node1,node2,node3");

    cout << "[Instance] Split by ','         :\n";
    vector<string> tokens = tokenObj.Split(",");
    for (const string& t : tokens) cout << "  -> " << t << "\n";

    cout << "[Static] Join with ' | '        :\n";
    cout << "  -> " << RichString::JoinString(tokens, " | ") << "\n\n";

    cout << "[Instance] PrintEachWordInText  :\n";
    tokenObj.SetValue("Read the docs today");
    tokenObj.PrintEachWordInText(" ");
    cout << "\n\n";

    cout << "[Static] PrintFirstLetters      :\n";
    RichString::PrintFirstLetters("Hyper Text Transfer Protocol", " ", false);
    cout << "\n\n";


    // --- 7. TRANSFORMATIONS (Replace, Reverse, Clean) ---
    cout << "--- 7. Transformations ---\n";
    RichString transObj("user_id=100; SELECT * FROM users; -- clean");

    cout << "[Instance] Before Remove Punct  : " << transObj.Value() << "\n";
    transObj.RemovePunctuations();
    cout << "[Instance] After Remove Punct   : " << transObj.Value() << "\n\n";

    transObj.SetValue("I hate bugs and I hate typos");
    cout << "[Instance] Before ReplaceWord   : " << transObj.Value() << "\n";
    transObj.ReplaceWord("hate", "love");
    cout << "[Instance] After ReplaceWord    : " << transObj.Value() << "\n\n";

    transObj.SetValue("First In Last Out");
    cout << "[Instance] Before ReverseWords  : " << transObj.Value() << "\n";
    transObj.ReverseWords();
    cout << "[Instance] After ReverseWords   : " << transObj.Value() << "\n\n";

    string query = "localhost:8080/api/v1";
    cout << "[Static] Before General Replace : " << query << "\n";
    cout << "[Static] After Replace('8080')  : " << RichString::Replace(query, "8080", "443") << "\n";

    cout << "\n=========================================\n";
    system("pause>0");
    return 0;
}