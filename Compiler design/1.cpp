// // #include <iostream>
// // #include <string>
// // #include <vector>

// // using namespace std;

// // enum TokenType {
// //     IDENTIFIER,
// //     INTEGER,
// //     FLOAT,
// //     OPERATOR,
// //     COMMENT
// // };

// // struct Token {
// //     TokenType type;
// //     string value;
// // };

// // class Lexer {
// // private:
// //     string input;
// //     size_t position;

// // public:
// //     Lexer(string input) : input(input), position(0) {}

// //     // Helper function to check if a character is a valid identifier character
// //     bool isValidIdentifierChar(char c) {
// //         return isalnum(c) || c == '_';
// //     }

// //     // Helper function to skip whitespace and comments
// //     void skipWhitespaceAndComments() {
// //         while (position < input.size()) {
// //             if (input[position] == ' ' || input[position] == '\t' || input[position] == '\n') {
// //                 position++;
// //             }
// //             else if (input[position] == '/' && input[position + 1] == '/') {
// //                 position += 2;
// //                 while (position < input.size() && input[position] != '\n') {
// //                     position++;
// //                 }
// //             }
// //             else if (input[position] == '/' && input[position + 1] == '*') {
// //                 position += 2;
// //                 while (position < input.size() && !(input[position] == '*' && input[position + 1] == '/')) {
// //                     position++;
// //                 }
// //                 if (position < input.size()) {
// //                     position += 2;
// //                 }
// //             }
// //             else {
// //                 break;
// //             }
// //         }
// //     }

// //     // Get the next token from the input
// //     Token getNextToken() {
// //         skipWhitespaceAndComments();

// //         if (position >= input.size()) {
// //             return {COMMENT, ""}; // No more tokens
// //         }

// //         char currentChar = input[position];
// //         if (isalpha(currentChar) || currentChar == '_') {
// //             string identifier;
// //             while (position < input.size() && isValidIdentifierChar(input[position])) {
// //                 identifier += input[position];
// //                 position++;
// //             }
// //             return {IDENTIFIER, identifier};
// //         }
// //         else if (isdigit(currentChar)) {
// //             string number;
// //             while (position < input.size() && (isdigit(input[position]) || input[position] == '.')) {
// //                 number += input[position];
// //                 position++;
// //             }
// //             return {INTEGER, number}; // For simplicity, treating all numbers as integers
// //         }
// //         else {
// //             string op(1, currentChar);
// //             position++;
// //             return {OPERATOR, op};
// //         }
// //     }

// //     // Tokenize the entire input string
// //     vector<Token> tokenize() {
// //         vector<Token> tokens;
// //         Token token = getNextToken();
// //         while (token.type != COMMENT) {
// //             tokens.push_back(token);
// //             token = getNextToken();
// //         }
// //         return tokens;
// //     }
// // };

// // int main() {
// //     string input = "int main() { // This is a comment\n return 0; }";
// //     Lexer lexer(input);
// //     vector<Token> tokens = lexer.tokenize();

// //     cout << "Tokens:\n";
// //     for (const Token& token : tokens) {
// //         cout << "Type: " << token.type << ", Value: " << token.value << endl;
// //     }

// //     return 0;
// // }

// #include <string.h>
// #include <ctype.h>
// #include <stdio.h>
// void keyword(char str[10])
// {
//     if (strcmp("for", str) == 0 || strcmp("while", str) == 0 || strcmp("do", str) == 0 || strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 || strcmp("double", str) == 0 || strcmp("static", str) == 0 || strcmp("switch", str) == 0 || strcmp("case", str) == 0)
//         printf("\n%s is a keyword", str);
//     else
//         printf("\n%s is an identifier", str);
// }
// main()
// {
//     FILE *f1, *f2, *f3;
//     char c, str[10], st1[10];
//     int num[100], lineno = 0, tokenvalue = 0, i = 0, j = 0, k = 0;
//     printf("\n Enter the c program : "); /*gets(st1);*/
//     f1 = fopen("input", "w");
//     while ((c = getchar()) != EOF)
//         putc(c, f1);
//     fclose(f1);
//     f1 = fopen("input", "r");
//     f2 = fopen("identifier", "w");
//     f3 = fopen("specialchar", "w");
//     while ((c = getc(f1)) != EOF)
//     {
//         if (isdigit(c))
//         {
//             tokenvalue = c - '0';
//             c = getc(f1);
//             while (isdigit(c))
//             {
//                 tokenvalue *= 10 + c - '0';
//                 c = getc(f1);
//             }
//             num[i++] = tokenvalue;
//             ungetc(c, f1);
//         }
//         else if (isalpha(c))
//         {
//             putc(c, f2);
//             c = getc(f1);
//             while (isdigit(c) || isalpha(c) || c == '_' || c == '$')
//             {
//                 putc(c, f2);
//                 c = getc(f1);
//             }
//             putc(' ', f2);
//             ungetc(c, f1);
//         }
//         else if (c == ' ' || c == '\t')
//             printf(" ");
//         else if (c == '\n')
//                  lineno++;
//         else putc(c, f3);
//     }
//     fclose(f2);
//     fclose(f3);
//     fclose(f1);
//     printf("\n The no's in the program are :");
//     for (j = 0; j < i; j++)
//         printf("%d ", num[j]);
//     printf("\n");
//     f2 = fopen("identifier", "r");
//     k = 0;
//     printf("The keywords and identifiers are:");
//     while ((c = getc(f2)) != EOF)
//     {
//         if (c != ' ')
//             str[k++] = c;
//         else
//         {
//             str[k] = '\0';
//             keyword(str);
//             k = 0;
//         }
//     }
//     fclose(f2);
//     f3 = fopen("specialchar", "r");
//     printf("\n Special characters are : ");
//     while ((c = getc(f3)) != EOF)
//         printf("%c", c);
//     printf("\n");
//     fclose(f3);
//     printf("Total no. of lines are:%d", lineno);
// }

#include <string.h>
#include <ctype.h>
#include <stdio.h>

void keyword(char str[10]) {
    if (strcmp("for", str) == 0 || strcmp("while", str) == 0 || strcmp("do", str) == 0 || strcmp("int", str) == 0 || strcmp("float", str) == 0 || strcmp("char", str) == 0 || strcmp("double", str) == 0 || strcmp("static", str) == 0 || strcmp("switch", str) == 0 || strcmp("case", str) == 0)
        printf("\n%s is a keyword", str);
    else
        printf("\n%s is an identifier", str);
}

int main() {
    FILE *f1, *f2, *f3;
    char c, str[10], st1[10];
    int num[100], lineno = 0, tokenvalue = 0, i = 0, j = 0, k = 0;
    printf("\n Enter the C program : "); /*gets(st1);*/
    f1 = fopen("input", "w");
    while ((c = getchar()) != EOF)
        putc(c, f1);
    fclose(f1);
    f1 = fopen("input", "r");
    f2 = fopen("identifier", "w");
    f3 = fopen("specialchar", "w");
    while ((c = getc(f1)) != EOF) {
        if (c == '/') {
            c = getc(f1);
            if (c == '/') {
                // Single-line comment
                while ((c = getc(f1)) != '\n' && c != EOF)
                    ;
            } else if (c == '*') {
                // Multi-line comment
                int prev_char = 0; // To track if previous character was '*'
                while ((c = getc(f1)) != EOF) {
                    if (c == '/' && prev_char == '*')
                        break;
                    prev_char = c;
                }
            } else {
                // Not a comment, put '/' back and process as normal
                putc('/', f2);
                if (c != EOF)
                    putc(c, f2);
            }
        } else if (isdigit(c)) {
            tokenvalue = c - '0';
            c = getc(f1);
            while (isdigit(c)) {
                tokenvalue = tokenvalue * 10 + (c - '0');
                c = getc(f1);
            }
            num[i++] = tokenvalue;
            ungetc(c, f1);
        } else if (isalpha(c)) {
            putc(c, f2);
            c = getc(f1);
            while (isdigit(c) || isalpha(c) || c == '_' || c == '$') {
                putc(c, f2);
                c = getc(f1);
            }
            putc(' ', f2);
            ungetc(c, f1);
        } else if (c == ' ' || c == '\t') {
            // Do nothing, skip whitespace
        } else if (c == '\n') {
            lineno++;
        } else {
            putc(c, f3);
        }
    }
    fclose(f2);
    fclose(f3);
    fclose(f1);
    printf("\n The numbers in the program are :");
    for (j = 0; j < i; j++)
        printf("%d ", num[j]);
    printf("\n");
    f2 = fopen("identifier", "r");
    k = 0;
    printf("The keywords and identifiers are:");
    while ((c = getc(f2)) != EOF) {
        if (c != ' ')
            str[k++] = c;
        else {
            str[k] = '\0';
            keyword(str);
            k = 0;
        }
    }
    fclose(f2);
    f3 = fopen("specialchar", "r");
    printf("\n Special characters are : ");
    while ((c = getc(f3)) != EOF)
        printf("%c", c);
    printf("\n");
    fclose(f3);
    printf("Total number of lines: %d", lineno);
    return 0;
}

