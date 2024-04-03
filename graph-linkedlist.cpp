
#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <string>
#include <set>

class Graph {
    std::unordered_map<std::string, std::list<std::string>> adjList;
    std::set<std::string> provinces;
    std::set<std::string> states;

public:
    // Add edge to the graph
    void addEdge(const std::string& src, const std::string& dest, bool isProvince = false) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
        if (isProvince) {
            provinces.insert(src);
            provinces.insert(dest);
        } else {
            states.insert(src);
            states.insert(dest);
        }
    }

    // Display only provinces
    void displayProvinces() {
        std::cout << "Provinces:\n";
        for (const auto& province : provinces) {
            std::cout << province << "\n";
        }
    }

    // Display only states
    void displayStates() {
        std::cout << "States:\n";
        for (const auto& state : states) {
            std::cout << state << "\n";
        }
    }

    // BFS implementation using linked list (queue)
    void bfs(const std::string& start) {
        std::queue<std::string> queue;
        std::unordered_map<std::string, bool> visited;

        visited[start] = true;
        queue.push(start);

        while (!queue.empty()) {
            std::string current = queue.front();
            queue.pop();
            std::cout << current << " ";

            for (auto& adj : adjList[current]) {
                if (!visited[adj]) {
                    visited[adj] = true;
                    queue.push(adj);
                }
            }
        }
        std::cout << "\n";
    }
};

int main() {
    Graph g;

    // Add provinces and states (example)
    g.addEdge("Alberta", "British Columbia", true);
    g.addEdge("Alabama", "Georgia");

    // Display only provinces
    g.displayProvinces();

    // Display only states
    g.displayStates();

    // BFS Search
    std::cout << "BFS Search for 'USA': ";
    g.bfs("USA");
    std::cout << "BFS Search for 'Puerto Rico': ";
    g.bfs("Puerto Rico");
    std::cout << "BFS Search for 'Quebec': ";
    g.bfs("Quebec");

    return 0;
}
