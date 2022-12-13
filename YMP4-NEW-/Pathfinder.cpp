#pragma once
#include "Pathfinder.h"

void inputPathMatrix(string filename, int** arr, const int m, const int n)
{
    ifstream in(filename);
    if (in.is_open()) {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++) {
                in >> *(*(arr + i) + j);
                cout << *(*(arr + i) + j) << " ";
            }
            cout << endl;
        }
    }
    in.close();
    cout << "=====" << endl;
}

void getNextNodes(vector<pair<int, int>>& nextNodes, pair<int, int> parent, const int m, const int n)
{
    nextNodes.clear();
    if (parent.first != 0)
        nextNodes.push_back({ parent.first - 1, parent.second });
    if (parent.first != n - 1)
        nextNodes.push_back({ parent.first + 1, parent.second });
    if (parent.second != 0)
        nextNodes.push_back({ parent.first, parent.second - 1});
    if (parent.second != m - 1)
        nextNodes.push_back({ parent.first, parent.second + 1});
}

void pathfinder(pair<int, int> start, pair<int, int> goal, int** arr, const int m, const int n)
{
    Queue q;
    q.push(start);
    vector<vector <bool>> visited;
    visited.assign(m, vector<bool>(n, false));
    vector<vector <int>> dst;
    dst.assign(m, vector<int>(n, -1));
    visited[start.first][start.second] = true;
    dst[start.first][start.second] = 0;

    while (!q.isEmpty()) {
        pair<int, int> cur = q.pop();


        vector<pair<int, int>> nextNodes;
        getNextNodes(nextNodes, cur, m, n);
        for (auto node : nextNodes) {
            if (!visited[node.first][node.second] && *(*(arr + node.first) + node.second) != -1) {
                q.push(node);
                visited[node.first][node.second] = true;
                dst[node.first][node.second] = dst[cur.first][cur.second] + 1;
            }
        }
    }

    if (dst[goal.first][goal.second] != -1)
        cout << "Путь существует. Длина пути - " << dst[goal.first][goal.second] << endl;
    else
        cout << "Пути не существует" << endl;
}
