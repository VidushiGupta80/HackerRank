#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the printShortestPath function below.
void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    queue<pair<pair<int, int>, pair<int, vector<string> > >> bfs;
    vector<string> temp;
    bfs.push({{i_start, j_start}, {0, temp}});
    int level = 0;
    bool status = false;
    vector<vector<int> > visited(n, vector<int> (n ,-1));
    while(!bfs.empty())
    {
        int i = bfs.front().first.first;
        int j = bfs.front().first.second;
        int currLevel = bfs.front().second.first;
        temp = bfs.front().second.second;
        bfs.pop();
        if(i < 0 || i >= n || j < 0 || j >= n)
            continue;
        if(visited[i][j] == 1)
            continue;
        visited[i][j] = 1;
        if(currLevel != level)
            level = currLevel;
        if(i == i_end && j == j_end)
        {
            status = true;
            break;
        }
        temp.push_back("UL");
        bfs.push({{i - 2, j - 1}, {level + 1, temp}});
        temp.pop_back();
        temp.push_back("UR");
        bfs.push({{i - 2, j + 1}, {level + 1, temp}});
        temp.pop_back();
        temp.push_back("R");
        bfs.push({{i, j + 2}, {level + 1, temp}});
        temp.pop_back();
        temp.push_back("LR");
        bfs.push({{i + 2, j + 1}, {level + 1, temp}});
        temp.pop_back();
        temp.push_back("LL");
        bfs.push({{i + 2, j - 1}, {level + 1, temp}});
        temp.pop_back();
        temp.push_back("L");
        bfs.push({{i, j - 2}, {level + 1, temp}});
        temp.pop_back();
    }
    if(!status)
    {
        cout << "Impossible" << endl;
        return;
    }
    cout << level << endl;
    for(int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string i_startJ_start_temp;
    getline(cin, i_startJ_start_temp);

    vector<string> i_startJ_start = split_string(i_startJ_start_temp);

    int i_start = stoi(i_startJ_start[0]);

    int j_start = stoi(i_startJ_start[1]);

    int i_end = stoi(i_startJ_start[2]);

    int j_end = stoi(i_startJ_start[3]);

    printShortestPath(n, i_start, j_start, i_end, j_end);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
