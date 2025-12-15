/*
  @pintia psid=1988824816654635008 pid=1988825531288539137 compiler=GXX
  ProblemSet: 计软24级数据结构上机实验（第5次）
  Title: 哈夫曼树
  https://pintia.cn/problem-sets/1988824816654635008/exam/problems/type/7?problemSetProblemId=1988825531288539137
*/
// @pintia code=start
#include <bits/stdc++.h>
using namespace std;
const int maxN = 5000 + 10;

struct huffNode{
    char data;
    int weight;
    int order;
    huffNode *left, *right;
    huffNode() : data(' '), weight(0), order(0), left(NULL), right(NULL) {}
};

struct huffCode{
    char c;
    string code;
    int freq;
    int firstPos;
};

bool isLeafNode(huffNode *node)
{
    return node->left == NULL && node->right == NULL;
}

bool compareRules(huffNode *a, huffNode *b)
{
    if (a->weight != b->weight){
        return a->weight < b->weight;
    }
    bool aLeaf = isLeafNode(a);
    bool bLeaf = isLeafNode(b);
    if (aLeaf != bLeaf){
        return aLeaf;
    }
    return a->order < b->order;
}

vector<huffNode *> buildLeafNodes(int freq[], int firstPos[]){
    vector<huffNode *> nodes;
    for (int i = 0; i < 26; i++){
        if (freq[i] > 0){
            huffNode *node = new huffNode();
            node->data = 'a' + i;
            node->weight = freq[i];
            node->order = firstPos[i];
            nodes.push_back(node);
        }
    }
    return nodes;
}

huffNode *buildHuffmanTree(vector<huffNode *> nodes) {
    int nextOrder = maxN;
    while (nodes.size() > 1) {
        int n = nodes.size();
        bool swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; ++j) {
                if (!compareRules(nodes[j], nodes[j + 1])) {
                    swap(nodes[j], nodes[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break;
        }

        huffNode *left = nodes[0];
        huffNode *right = nodes[1];
        huffNode *parent = new huffNode();
        parent->left = left;
        parent->right = right;
        parent->weight = left->weight + right->weight;
        parent->order = nextOrder++;

        nodes.erase(nodes.begin(), nodes.begin() + 2);
        nodes.push_back(parent);
    }
    return nodes[0];
}

void encoding(huffNode *node, string cur, vector<string> &codes){
    if (node == NULL)
        return;
    if (isLeafNode(node)){
        codes[node->data - 'a'] = cur;
        return;
    }
    encoding(node->left, cur + "0", codes);
    encoding(node->right, cur + "1", codes);
}

bool decoding(const string &code, huffNode *root, string &out){
    if (root == NULL)
        return false;
    huffNode *p = root;
    for (int i = 0; i < code.size(); i++){
        char ch = code[i];
        if (ch == '0'){
            p = p->left;
        }
        else if (ch == '1'){
            p = p->right;
        }
        if (p == NULL)
            return false;
        if (isLeafNode(p)){
            out.push_back(p->data);
            p = root;
        }
    }
    return p == root;
}

void calculateSizes(const string &text, int freq[], const vector<string> &codes, int &originalSize, int &compressedSize){
    originalSize = text.size();
    int Total = 0;
    for (int i = 0; i < 26; i++){
        if (freq[i] > 0)
            Total += freq[i] * codes[i].size();
    }
    compressedSize = (Total + 7) / 8;
}

void outputCodes(int freq[], int firstPos[], const vector<string> &codes){
    vector<huffCode> codeList;
    for (int i = 0; i < 26; i++){
        if (freq[i] > 0){
            codeList.push_back({
                (char)('a' + i),
                codes[i],
                freq[i],
                firstPos[i]
            });
        }
    }

    int n = codeList.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++){
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j){
            bool needSwap = false;
            if (codeList[j].freq != codeList[j+1].freq){
                needSwap = codeList[j].freq > codeList[j+1].freq;
            }
            else{
                needSwap = codeList[j].firstPos > codeList[j+1].firstPos;
            }

            if (needSwap){
                swap(codeList[j], codeList[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
    for (int i = 0; i < codeList.size(); i++){
        cout << codeList[i].c << ":" << codeList[i].code << endl;
    }
}

int main()
{
    string text, code1, code2;
    getline(cin, text);
    getline(cin, code1);
    getline(cin, code2);

    int freq[26] = {0};
    int firstPos[26];
    for (int i = 0; i < 26; i++){
        firstPos[i] = -1;
    }
    for (int i = 0; i < text.size(); i++){
        char ch = text[i];
        int index = ch - 'a';
        freq[index]++;
        if (firstPos[index] == -1){
            firstPos[index] = i;
        }
    }

    vector<huffNode *> nodes = buildLeafNodes(freq, firstPos);

    huffNode *root = buildHuffmanTree(nodes);

    vector<string> codes(26);
    encoding(root, "", codes);

    int originalSize, compressedSize;
    calculateSizes(text, freq, codes, originalSize, compressedSize);
    cout << originalSize << " " << compressedSize << endl;

    outputCodes(freq, firstPos, codes);

    string res1, res2;
    bool valid1 = decoding(code1, root, res1);
    bool valid2 = decoding(code2, root, res2);
    cout << (valid1 ? res1 : "INVALID") << endl;
    cout << (valid2 ? res2 : "INVALID") << endl;
    return 0;
}
// @pintia code=end