//////////////////////////////////////////
// Aslýhan Altun
// 1306200094
// Date: 2021.22.05
// IDE: Visual Studio 2019
///////////////////////////////////////////
//Structýn adýnýn Node olmasýna raðmen adres bilgisi içermeyen bir struct oluþturdum. 
//Baðlantýlarý adjacency matriste toparladým.
//Bunu benim için yeni bir þey olduðu için bilinçli tercih ettim(Complexity arttýrmasýna raðmen).
//////////////////////////////////////////
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

struct Node {
    string name;
    int index;
    Node() {}
    Node(string _name, int i) {
        name = _name;
        index = i;
    }
};
vector <Node*> nodes;
vector<vector<int>> link;
string delspace(string line) {
    int i = 0;
    string line1 = "";
    while (i < line.length()) {
        if (line[i] != ' ') {
            line1 += line[i];
        }
        i++;
    }
    return line1;
}
void nodenames(string firstline) {
    firstline = delspace(firstline) + ',';
    string str = "";
    int i = 0;
    for (auto a : firstline) {
        if (a == ',') {
            nodes.push_back(new Node(str, i));
            str = "";
            i++;
        }
        else { str += a; }
    }
}
void linking(string line) {
    string l_line = line.substr(0, line.find("->"));
    string r_line = line.substr(line.find("->") + 2);\
        for (auto a : nodes) {
            if (a->name == l_line) {
                for (auto b : nodes) {
                    if (b->name == r_line) {
                        link[a->index][b->index] = 1;
                        break;
                    }
                }
                break;
            }
        }
}
bool path_finder(string path) {
    queue<Node*> q;
    for (auto N : nodes) if (N->name[0] == path[0]) q.push(N);
    path = path.substr(1);
    for (auto a : path) {
        int size = q.size();
        if (size == 0) { return false; }
        for (int i = 0; i < size; i++) {
            for (int x = 0; x < link.size(); x++) {
                if (link[q.front()->index][x] == 1)
                    for (auto N : nodes) if (N->index == x && N->name[0] == path[0]) q.push(nodes[x]);
            }
            q.pop();
        }
        path = path.substr(1);
    }
    return q.size();
}
int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    string line;
    getline(input, line);
    nodenames(line);
    link.resize(nodes.size(), vector<int>(nodes.size(), 0));
    getline(input, line);
    while (getline(input, line) && line != "Paths:") linking(line);
    while (getline(input, line)) {
        if (path_finder(line) == 1) output << line << " [YES]" << endl;
        else output << line << " [NO]" << endl;
    }
    return 0;
}