// Code for Huffman Encoding

#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// A tree node
struct Node {
    char data; 
    int freq; 
    Node *left, *right;

    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

struct Compare { e
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq; 
    }
};

Node* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (const auto& pair : freqMap) {
        minHeap.push(new Node(pair.first, pair.second));
    }

    while (minHeap.size() > 1) {
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();
        Node *internal = new Node('\0', left->freq + right->freq);
        internal->left = left;
        internal->right = right;
        minHeap.push(internal);
    }

    return minHeap.top();
}

void generateCodes(Node* root, const string& str, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->data] = str; // Store the code for the character
    }

    generateCodes(root->left, str + "0", huffmanCode);
    generateCodes(root->right, str + "1", huffmanCode);
}

string encode(const string& text, const unordered_map<char, string>& huffmanCode) {
    string encodedStr;
    for (char ch : text) {
        encodedStr += huffmanCode.at(ch);
    }
    return encodedStr;
}

string decode(Node* root, const string& encodedStr) {
    string decodedStr;
    Node* current = root;
    for (char bit : encodedStr) {
        current = (bit == '0') ? current->left : current->right; 
        if (!current->left && !current->right) { 
            decodedStr += current->data; 
            current = root; 
        }
    }
    return decodedStr;
}

int main() {
    string text; 
    cout << "Enter your name: "; 
    cin >> text;
    unordered_map<char, int> freqMap;

    for (char ch : text) {
        freqMap[ch]++; // for every char, +1 freq
    }

    Node* root = buildHuffmanTree(freqMap);

    // Generate Huffman codes
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);

    // Encode the input text
    string encodedStr = encode(text, huffmanCode);
    cout << "Encoded: " << encodedStr << endl;

    // Decode the encoded string
    string decodedStr = decode(root, encodedStr);
    cout << "Decoded: " << decodedStr << endl;

    return 0;
}
