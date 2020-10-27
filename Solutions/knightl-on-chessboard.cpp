#include <bits/stdc++.h>

using namespace std;
int findMoves(int i, int j, int n)
{
    queue<pair<int, pair<int, int> > > bfs;
    bfs.push({0, {0, 0}});
    int level = 0;
    bool status = false;
    vector<vector<int> > visited(n, vector<int> (n, -1));
    while(!bfs.empty())
    {
        int row = bfs.front().first;
        int column = bfs.front().second.first;
        int currLevel = bfs.front().second.second;
        bfs.pop();
        if(row < 0 || row >= n || column < 0 || column >= n)
            continue;
        if(visited[row][column] == 1)
            continue;
        visited[row][column] = 1;
        if(currLevel != level)
            level = currLevel;
        if(row == n - 1 && column == n - 1)
        {
            status = true;
            break;
        }
        bfs.push({row + i, {column + j, currLevel + 1}});
        bfs.push({row - i, {column + j, currLevel + 1}});
        bfs.push({row + i, {column - j, currLevel + 1}});
        bfs.push({row - i, {column - j, currLevel + 1}});
        bfs.push({row + j, {column + i, currLevel + 1}});
        bfs.push({row - j, {column + i, currLevel + 1}});
        bfs.push({row + j, {column - i, currLevel + 1}});
        bfs.push({row - j, {column - i, currLevel + 1}});
    }
    if(!status)
        return - 1;
    return level;
}

// Complete the knightlOnAChessboard function below.
vector<vector<int>> knightlOnAChessboard(int n) {
    vector<vector<int> > ans(n - 1, vector<int> (n - 1, 0));
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(ans[i - 1][j - 1] != 0)
                continue;
            int res = findMoves(i, j, n);
            ans[i - 1][j - 1] = res;
            ans[j - 1][i - 1] = res;
        }
    }
   return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
