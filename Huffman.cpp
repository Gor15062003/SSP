#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

struct Node {
    char data;
    unsigned frequency;
    Node* left;
    Node* right;

    Node(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
    
    bool operator>(const Node& other) const {
        return frequency > other.frequency;
    }
};

Node* buildHuffmanTree(const std::unordered_map<char, unsigned>& frequencies) {
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> minHeap;

    for (const auto& pair : frequencies) {
        minHeap.push(Node(pair.first, pair.second));
    }

    while (minHeap.size() > 1) {
        Node* left = new Node(0, 0);
        Node* right = new Node(0, 0);

        *left = minHeap.top();
        minHeap.pop();

        *right = minHeap.top();
        minHeap.pop();

        Node* internalNode = new Node(0, left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(*internalNode);
    }

    return new Node(*minHeap.top().left);
}

void generateCodes(Node* root, const std::string& currentCode, std::unordered_map<char, std::string>& codes) {
    if (root == nullptr) {
        return;
    }

    if (root->data != 0) {
        codes[root->data] = currentCode;
    }

    generateCodes(root->left, currentCode + '0', codes);
    generateCodes(root->right, currentCode + '1', codes);
}

std::string huffmanEncode(const std::string& message) {
    std::unordered_map<char, unsigned> frequencies;

    for (char ch : message) {
        frequencies[ch]++;
    }

    Node* root = buildHuffmanTree(frequencies);

    std::unordered_map<char, std::string> codes;
    generateCodes(root, "", codes);

    std::string encodedMessage;
    for (char ch : message) {
        encodedMessage += codes[ch];
    }

    return encodedMessage;
}

std::string huffmanDecode(const std::string& encodedMessage, Node* root) {
    std::string decodedMessage;
    Node* current = root;

    for (char bit : encodedMessage) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (current->data != 0) {
            decodedMessage += current->data;
            current = root;
        }
    }

    return decodedMessage;
}

int main() {
    std::string message = "hello world";

    std::string encodedMessage = huffmanEncode(message);
    std::cout << "Encoded: " << encodedMessage << std::endl;

    Node* root = buildHuffmanTree({{'h', 1}, {'e', 1}, {'l', 3}, {'o', 2}, {' ', 1}, {'w', 1}, {'r', 1}, {'d', 1}});
    std::string decodedMessage = huffmanDecode(encodedMessage, root);
    std::cout << "Decoded: " << decodedMessage << std::endl;

    return 0;
}
