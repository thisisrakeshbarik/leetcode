class Spreadsheet {
    unordered_map<string, int> cells;

    bool isNumber(const string &s) {
        return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
    }

public:
    Spreadsheet(int rows) {
        
    }

    void setCell(string cell, int value) {
        cells[cell] = value;
    }

    void resetCell(string cell) {
        cells[cell] = 0;
    }

    int getValue(string formula) {
        int sum = 0;
        int i = 1; // Skip '='
        while (i < formula.size()) {
            int j = i;
            while (j < formula.size() && formula[j] != '+') j++;
            string token = formula.substr(i, j - i);
            sum += isNumber(token) ? stoi(token) : cells[token];
            i = j + 1;
        }
        return sum;
    }
};