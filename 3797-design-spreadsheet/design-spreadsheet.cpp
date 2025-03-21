class Spreadsheet {
public:
    vector<vector<int>> v;
    Spreadsheet(int rows) { v.resize(rows + 1, vector<int>(26, 0)); }

    void setCell(string cell, int value) {
        int col = cell[0] - 65;
        int i = 1;
        string g = "";
        while (i < cell.size()) {
            g += cell[i];
            i++;
        }
        int row = stoi(g);
        cout<<row;
        v[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 65;
        int i = 1;
        string g = "";
        while (i < cell.size()) {
            g += cell[i];
            i++;
        }
        int row = stoi(g);
        v[row][col] = 0;
    }

    int getValue(string formula) {
        int i = 1;
        string x = "";
        string y = "";
        while (formula[i] != '+') {
            x += formula[i];
            i++;
        }
        int a = 0;
        if (x[0] >= 65 && x[0] <= 90) {
            int col = x[0] - 65;
            int j = 1;
            string g = "";
            while (j < x.size()) {
                g += x[j];
                j++;
            }
            cout<<g;
            int row = stoi(g);
            a = v[row][col];
            
        } else {
            a = stoi(x);
            cout<<a;
        }
        i++;
        while (i < formula.size()) {
            y += formula[i];
            i++;
        }
        int b = 0;
        if (y[0] >= 65 && y[0] <= 90) {
            int col = y[0] - 65;
            int j=1;
            string g = "";
            while (j < y.size()) {
                g += y[j];
                j++;
            }
            int row = stoi(g);
            b = v[row][col];
        } else {
            b = stoi(y);
            cout<<b;
        }
        return a + b;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */