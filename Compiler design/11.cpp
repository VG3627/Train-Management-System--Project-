#include <iostream>
#include <string>

// Define the structure for the abstract syntax tree
struct ASTNode {
    std::string operation;
    ASTNode* left;
    ASTNode* right;

    ASTNode(const std::string& op, ASTNode* l, ASTNode* r) : operation(op), left(l), right(r) {}
};

// Function to generate machine code recursively from the AST
void generate_code(ASTNode* node) {
    if (node == nullptr)
        return;

    // Traverse the left subtree
    generate_code(node->left);

    // Generate machine code based on the operation
    if (node->operation == "+") {
        std::cout << "ADD\n";
    } else if (node->operation == "-") {
        std::cout << "SUB\n";
    } else if (node->operation == "*") {
        std::cout << "MUL\n";
    } else if (node->operation == "/") {
        std::cout << "DIV\n";
    } else {
        // Handle other operations if needed
        // For simplicity, assuming only arithmetic operations
        std::cerr << "Error: Unsupported operation '" << node->operation << "'\n";
        exit(EXIT_FAILURE);
    }

    // Traverse the right subtree
    generate_code(node->right);
}

// Function to build the AST based on user input
ASTNode* build_ast() {
    std::string operation;
    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> operation;

    if (operation != "+" && operation != "-" && operation != "*" && operation != "/") {
        std::cerr << "Invalid operation\n";
        exit(EXIT_FAILURE);
    }

    if (operation == "+" || operation == "-" || operation == "*" || operation == "/") {
        std::cout << "Enter left operand: ";
        ASTNode* left = build_ast();

        std::cout << "Enter right operand: ";
        ASTNode* right = build_ast();

        return new ASTNode(operation, left, right);
    } else {
        return new ASTNode(operation, nullptr, nullptr);
    }
}

// Main function
int main() {
    // Build the AST based on user input
    ASTNode* root = build_ast();

    // Generate machine code from the AST
    generate_code(root);

    // Clean up
    // Note: Proper deallocation of memory is essential in a real application
    delete root;

    return 0;
}
