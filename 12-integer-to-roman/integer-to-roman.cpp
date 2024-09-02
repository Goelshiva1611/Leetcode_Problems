class Solution {
public:
    void thirdfunction(int num, string& s) {
        if (num == 0) {
            return;
        }
        int a = num / 100;
        if (a == 4) {
            s = s + "CD";
            num = num % 100;
            secondfunction(num, s);
            return;
        }
        if (a == 9) {
            s = s + "CM";
            num = num % 100;
            secondfunction(num, s);
            return;
        }
        if (a == 5) {
            s = s + 'D';
            num = num % 100;
            secondfunction(num, s);
            return;
        }
        if (a < 5 && a != 4) {
            for (int i = 0; i < a; i++) {
                s = s + 'C';
            }
            num = num % 100;
            secondfunction(num, s);
            return;

        } else {
            num = num - 500;
            s = s + 'D';
            for (int i = 0; i < a-5; i++) {
                s = s + 'C';
            }
        }
        num = num % 100;
        
        secondfunction(num, s);
        
        cout<<"fx";
        return;
    }
    void secondfunction(int num, string& s) {
        if (num == 0) {
            return;
        }
        int a = num / 10;
        if (a == 4) {
            s = s + "XL";
            num = num % 10;
            firstfunction(num, s);
            return;
        }
        if (a == 9) {
            s = s + "XC";
            num = num % 10;
            firstfunction(num, s);
            return;
        }
        if (a == 5) {
            s = s + 'L';
            num = num % 10;
            firstfunction(num, s);
            return;
        }
        if (a < 5 && a != 4) {
            for (int i = 0; i < a; i++) {
                s = s + 'X';
            }
            num = num % 10;
            firstfunction(num, s);
            return;
        } else {
            num = num - 50;
            s = s + 'L';
            for (int i = 0; i < a-5; i++) {
                s = s + 'X';
            }
        }
        num = num % 10;
        firstfunction(num, s);
        return;
    }
    void firstfunction(int num, string& s) {
        if (num == 0) {
            return;
        }
        if (num == 4) {
            s = s + "IV";
             return;
        }
        if (num == 9) {
            s = s + "IX";
             return;
        }
        if (num == 5) {
            s = s + 'V';
             return;
        }
        if (num < 5 && num != 4) {
            for (int i = 0; i < num; i++) {
                s = s + 'I';
            }
             return;
        } else {
            num = num - 5;
            s = s + 'V';
            for (int i = 0; i < num; i++) {
                s = s + 'I';
            }
        }
        return;
    }
    string intToRoman(int num) {
        string s = "";
        if (num < 10) {
            
            firstfunction(num, s);
        }
        if (num >= 10 && num <= 99) {
          
            secondfunction(num, s);
        }
        if (num >= 100 && num < 1000) {
            thirdfunction(num, s);
        }
        if (num >= 1000 && num <= 3999) {
            int a = num / 1000;
            for (int i = 0; i < a; i++) {
                s = s + 'M';
            }
            num = num % 1000;
            thirdfunction(num, s);
        }
        return s;
    }
};