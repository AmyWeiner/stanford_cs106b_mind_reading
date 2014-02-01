/* 
 * File: MindReading.cpp
 * ---------------------
 * [TODO: extend the documentation]
 */
#include <iostream>
#include <string>
#include "console.h"
#include "lexicon.h"
#include "simpio.h"

using namespace std;

const string alphabet = "abcdefghijklmnopqrstuvwxyz";

/* Function prototypes */
void ListCompletions(string digits, Lexicon & lex); 
void initializeKeypad(Map<string, Vector<string> > & keypad);
Vector<string> getPrefixes(string str, string digits, Lexicon & lex, Map<string, Vector<string> > & keypad);
void ListCompletionsRec(Vector<string>prefixes, Lexicon & lex);

/* Main program */
int main() {
    Lexicon english("EnglishWords.dat");
    string digits = getLine("Please enter a string of digits 2 through 9: ");
    ListCompletions(digits, english);
	return 0;
}


/* Function: void ListCompletions(string digits, Lexicon & lex);
 * Usage: ListCompletions("72547", english);
 * ==================================================================
 * prints all words from the lexicon that can be formed by extending
 * the given digit sequence.
 */
void ListCompletions(string digits, Lexicon & lex) {
	Map<string, Vector <string> >keypad;
    initializeKeypad(keypad);
    Vector <string> letters;
    Vector<string> prefixes = getPrefixes("", digits, lex, keypad);
    for (int i = 0; i < prefixes.size(); i++) {
        cout << prefixes[i] << endl;
    }
   // ListCompletionsRec(prefixes, lex);
}

void initializeKeypad(Map<string, Vector<string> > & keypad) {
    Vector<string> abc;
    Vector<string> def;
    Vector<string> ghi;
    Vector<string> jkl;
    Vector<string> mno;
    Vector<string> pqrs;
    Vector<string> tuv;
    Vector<string> wxyz;
    abc += "a", "b", "c";
    def += "d", "e", "f";
    ghi += "g", "h", "i";
    jkl += "j", "k", "l";
    mno += "m", "n", "o";
    pqrs += "p", "q", "r", "s";
    tuv += "t", "u", "v";
    wxyz += "w", "x", "y", "z";
    keypad.put("2", abc);
    keypad.put("3", def);
    keypad.put("4", ghi);
    keypad.put("5", jkl);
    keypad.put("6", mno);
    keypad.put("7", pqrs);
    keypad.put("8", tuv);
    keypad.put("9", wxyz);
}


Vector<string> getPrefixes(string str, string digits, Lexicon & lex, Map<string, Vector<string> > & keypad) {
    Vector<string> digitsToLetters;
    if (digits == "") {
        digitsToLetters += str;
    } else {
        string firstDigit = digits.substr(0,1);
        Vector<string> letters = keypad[firstDigit];
        for (int i = 0; i < letters.size(); i ++) {
            str += letters[i];
            digitsToLetters += getPrefixes(str, digits.substr(1), lex, keypad);
            str = str.substr(0, str.size() - 1);
        }
    }
    return digitsToLetters;
}

void ListCompletionsRec(Vector<string>prefixes, Lexicon & lex) {
    for (int i = 0; i < prefixes.size(); i ++) {
        string current = prefixes[i];
        if (lex.contains(current) || lex.containsPrefix(current)) {
            for (int i = 0; i < alphabet.length(); i ++) {
                current += alphabet[i];
                ListCompletionsRec(prefixes, lex);
            }
            
        }
    }
}







