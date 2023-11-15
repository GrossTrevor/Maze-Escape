/*
    Maze Escape

    Sometimes when dealing with graphs, it is easiest to leave it in its input format 
    rather than creating another structure like an adjacency list/matrix. You are given 
    a graph represented as a vector of strings. Write a function 
    `traverse(vector<string>& graph)` that takes as input a graph and returns the length 
    of the shortest path between vertices `s` and `t`. If no path exists between `s` and 
    `t`, then return `-1`. The details of the graph as a vector of strings are as follows:

    1. The start position is represented by a 's' and will always be the first character of 
       the first string (`graph[0][0]`). 
    2. The end position is represented by a 't' and will always be the last character of the 
       final string (`graph[graph.size()-1][graph[0].length()-1]`).
    3. A '.' character represents a normal vertex in the graph.
    4. A '#' character represents that you cannot visit this vertex in the graph (or there 
       is no vertex at this position).
    5. Adjacent vertices are those immediately horizontal or vertical from the current vertex 
       (diagonal moves are not allowed).
    6. The cost of moving along one edge (from one vertex to an adjacent vertex) is always 1 
       (i.e. this is an unweighted graph).

    Sample Input
        s#.#.   
        .#...  
        ...#t    

    Sample Output: 8
*/

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>

using std::queue;
using std::vector;
using std::string;
using std::map;
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;

int traverse(std::vector<std::string> &graph) {
    int x = 0, y = 0;
    bool pushed = false;
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    map<pair<int, int>, int> m;

    for (int i = 0; i < graph.size(); i++)
        for (int j = 0; j < graph[i].length(); j++) 
            m[make_pair(i, j)] = 10001;

    v.push_back(make_pair(0, 0));
    q.push(make_pair(0, 0));
    m[make_pair(0, 0)] = 0;

    while (!q.empty()) {
        x = q.front().second;
        y = q.front().first;
        q.pop();

        v.push_back(make_pair(y, x));

        if (x - 1 >= 0 && find(v.begin(), v.end(), make_pair(y, x - 1)) == v.end()) {
            if (graph[y][x - 1] == '.') {
                q.push(make_pair(y, x - 1));
                if (m[make_pair(y, x - 1)] > m[make_pair(y, x)]++) {
                    m[make_pair(y, x - 1)] = m[make_pair(y, x)]++;
                }
            }
            else if(graph[y][x - 1] == 't')
                if (m[make_pair(y, x - 1)] > m[make_pair(y, x)]++) {
                    m[make_pair(y, x - 1)] = m[make_pair(y, x)]++;
                }
        }

        if (x + 1 < graph[y].length() && find(v.begin(), v.end(), make_pair(y, x + 1)) == v.end()) {
            if (graph[y][x + 1] == '.') {
                q.push(make_pair(y, x + 1));
                if (m[make_pair(y, x + 1)] > m[make_pair(y, x)]++) {
                    m[make_pair(y, x + 1)] = m[make_pair(y, x)]++;
                }
            }
            else if (graph[y][x + 1] == 't')
                if (m[make_pair(y, x + 1)] > m[make_pair(y, x)]++) {
                    m[make_pair(y, x + 1)] = m[make_pair(y, x)]++;
                }
        }

        if (y - 1 >= 0 && find(v.begin(), v.end(), make_pair(y - 1, x)) == v.end()) {
            if (graph[y - 1][x] == '.') {
                q.push(make_pair(y - 1, x));
                if (m[make_pair(y - 1, x)] > m[make_pair(y, x)]++) {
                    m[make_pair(y - 1, x)] = m[make_pair(y, x)]++;
                }
            }
            else if (graph[y - 1][x] == 't')
                if (m[make_pair(y - 1, x)] > m[make_pair(y, x)]++) {
                    m[make_pair(y - 1, x)] = m[make_pair(y, x)]++;
                }
        }

        if (y + 1 < graph.size() && find(v.begin(), v.end(), make_pair(y + 1, x)) == v.end()) {
            if (graph[y + 1][x] == '.') {
                q.push(make_pair(y + 1, x));
                if (m[make_pair(y + 1, x)] > m[make_pair(y, x)]++) {
                    m[make_pair(y + 1, x)] = m[make_pair(y, x)]++;
                }
			}
            else if (graph[y + 1][x] == 't')
                if (m[make_pair(y + 1, x)] > m[make_pair(y, x)]++) {
                    m[make_pair(y + 1, x)] = m[make_pair(y, x)]++;
                }
        }
    }
    if(m[make_pair(graph.size() - 1, graph[0].length() - 1)] != 10001)
		return m[make_pair(graph.size() - 1, graph[0].length() - 1)];
	return -1;
}
