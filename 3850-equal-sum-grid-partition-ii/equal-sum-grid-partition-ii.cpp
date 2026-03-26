class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {

        long long totalSum = 0;
        long long rowSum1 = 0;
        long long colSum1 = 0;

        vector<long long> rowSum;
        vector<long long> colSum;

        // map for each element it will occur any one side so we just have to
        // see if it is on the border or not

        // eg  2 -> [ { 1 , { row , col } } , { 1 , { row , col } } ... ]

        unordered_map<int, vector<pair<int, pair<int, int>>>> mapping;

        int row = grid.size();
        int col = grid[0].size();

        int element;
        int flag;

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {

                element = grid[i][j];

                rowSum1 += element;
                flag = 0;

                if ((i == 0 || i == row - 1) && j != 0 && j != col - 1) {
                    flag = 1;
                } else if ((j == 0 || j == col - 1) && i != 0 && i != row - 1) {
                    flag = 1;
                }

                if (mapping.find(element) == mapping.end()) {
                    mapping[element] = {{flag, {i, j}}};
                } else {
                    mapping[element].push_back({flag, {i, j}});
                }
            }
            rowSum.push_back(rowSum1);
        }

        int rowNumber, colNumber;
        for (int j = 0; j < col; j++) {
            for (int i = 0; i < row; i++) {
                colSum1 += grid[i][j];
            }
            colSum.push_back(colSum1);
        }

        totalSum = max(colSum1, rowSum1);

        if (row == 1) {
            // only vertical cuts possible; sections are 1-row strips
            for (int i = 0; i < col - 1; i++) {
                if (2 * colSum[i] == totalSum)
                    return true;
                int diff = abs(2 * colSum[i] - totalSum);
                bool leftH = 2 * colSum[i] > totalSum;
                if (mapping.count(diff)) {
                    for (auto& [f, pos] : mapping[diff]) {
                        int c = pos.second;
                        bool inHeavier = leftH ? (c <= i) : (c > i);
                        if (!inHeavier)
                            continue;
                        // 1-row strip: only endpoints of that strip are
                        // removable
                        if (leftH ? (c == 0 || c == i)
                                  : (c == i + 1 || c == col - 1))
                            return true;
                    }
                }
            }
            return false;
        }

        if (col == 1) {
            // only horizontal cuts possible; sections are 1-col strips
            for (int i = 0; i < row - 1; i++) {
                if (2 * rowSum[i] == totalSum)
                    return true;
                int diff = abs(2 * rowSum[i] - totalSum);
                bool topH = 2 * rowSum[i] > totalSum;
                if (mapping.count(diff)) {
                    for (auto& [f, pos] : mapping[diff]) {
                        int r = pos.first;
                        bool inHeavier = topH ? (r <= i) : (r > i);
                        if (!inHeavier)
                            continue;
                        // 1-col strip: only endpoints of that strip are
                        // removable
                        if (topH ? (r == 0 || r == i)
                                 : (r == i + 1 || r == row - 1))
                            return true;
                    }
                }
            }
            return false;
        }

        for (int i = 0; i < row-1; i++) {
            if (2 * rowSum[i] == totalSum) {
                return true;
            }

            long long diff = abs(2LL * rowSum[i] - totalSum);
            int width;
            if (2 * rowSum[i] > totalSum) {
                width = i + 1;
            } else {
                width = row - 1 - i;
            }
            // heavier width

            if (diff <= INT_MAX && mapping.find(diff) != mapping.end()) {
                vector<pair<int, pair<int, int>>> vec = mapping[diff];

                for (int k = 0; k < vec.size(); k++) {
                    flag = vec[k].first;

                    rowNumber = vec[k].second.first;
                    colNumber = vec[k].second.second;

                    bool topHeavier = 2 * rowSum[i] > totalSum;

                    // inside the cell loop, add section membership check:
                    // 3. Cell must be in heavier section
                    bool inHeavier =
                        topHeavier ? (rowNumber <= i) : (rowNumber > i);
                    if (!inHeavier)
                        continue;

                    if (flag == 1) {
                        if (width != 1) {
                            return true;
                        }
                    } else {
                        return true;
                    }
                }
            }
        }

        for (int i = 0; i < col-1; i++) {
            if (2 * colSum[i] == totalSum) {
                return true;
            }

            long long diff = abs(2LL * colSum[i] - totalSum);
            int width;
            if (2 * colSum[i] > totalSum) {
                width = i + 1;
            } else {
                width = col - 1 - i;
            }
            if (diff <= INT_MAX && mapping.find(diff) != mapping.end()) {
                vector<pair<int, pair<int, int>>> vec = mapping[diff];

                for (int k = 0; k < vec.size(); k++) {
                    flag = vec[k].first;

                    rowNumber = vec[k].second.first;
                    colNumber = vec[k].second.second;

                    bool topHeavier = 2 * colSum[i] > totalSum;

                    // inside the cell loop, add section membership check:
                    // 3. Cell must be in heavier section
                    bool inHeavier =
                        topHeavier ? (colNumber <= i) : (colNumber > i);
                    if (!inHeavier)
                        continue;
                    if (flag == 1) {
                        if (width != 1) {
                            return true;
                        }
                    } else {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};