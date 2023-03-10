#include <bits/stdc++.h>
#include <future>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
struct Node {
    double cost;
    int nelements = 1;
    int id;
    std::vector<int> component;
    int father = 0;
    std::unordered_set<int> children;
    //bool operator < (const Node & n) {
    //    return cost < n.cost;
    //}
};

int main() {
    int n, r;
    std::cin >> n >> r;
    std::unordered_map<int, Node> id_node_map;
    int ans = 0;
    for (int i = 1 ; i <= n; ++i) {
        Node a;
        std::cin >>  a.cost;
        a.id = i;
        a.component.push_back(i);
        id_node_map[i] = a;
    }
    for (int i = 1; i <= n - 1; ++i) {
        int f, s;
        std::cin >> f >> s;
        id_node_map[f].children.insert(s);
        id_node_map[s].father = f;
    }
    auto comp = [](const Node* n1, const Node * n2) { return n1->cost < n2->cost;};
    std::priority_queue<Node*, std::vector<Node*>, decltype(comp)> cost_queue(comp);
    for (auto & id_node : id_node_map) {
        if (id_node.first != r)
            cost_queue.push(&(id_node.second));
    }
    int next_node_id = n + 1;
    std::unordered_set<Node*> processed_node_ids;
    while(cost_queue.size() > 0) {
        Node* top = cost_queue.top();
        cost_queue.pop();
        if (processed_node_ids.count(top) > 0) {
            continue;
        }
        processed_node_ids.insert(top);
        if (top->father == r) {
            for (auto id : top->component) {
                id_node_map[r].component.push_back(id);
            }
            for (auto child : top->children) {
                id_node_map[child].father = r;
                id_node_map[r].children.insert(child);
            }
            
        } else {
            Node& p = id_node_map[top->father];
            processed_node_ids.insert(&p);
            id_node_map[next_node_id] = Node{};
            Node& new_node = id_node_map[next_node_id];
            new_node.nelements = top->nelements + p.nelements;
            new_node.id = next_node_id;
            new_node.cost = (top->cost * top->nelements + p.cost*p.nelements) / (top->nelements + p.nelements);
            new_node.father = p.father;
            Node& grand_father = id_node_map[p.father];
            grand_father.children.insert(next_node_id);
            for (auto child : p.children) {
                if (child != top->id) {
                    new_node.children.insert(child);
                    id_node_map[child].father = new_node.id;
                }
            }
            for (auto child : top->children) {
                new_node.children.insert(child);
                id_node_map[child].father = new_node.id;
            }
            for (auto id : p.component) {
                new_node.component.push_back(id);
            }
            for (auto id : top->component) {
                new_node.component.push_back(id);
            }
            cost_queue.push(&new_node);
            ++next_node_id;
        }

    }
    Node&root = id_node_map[r];
    bool changed = true; 
    std::vector<int> component = root.component;
    int size = component.size();
    int k = 1;
    for (int c : component) {
        ans += k * id_node_map[c].cost;
        ++k;
    }
    std::cout << ans << std::endl;
    return 0;
}