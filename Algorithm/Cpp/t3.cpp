#include <Windows.h>

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int nfa_state_num, nfa_chars_num, dfa_state_num, dfa_chars_num;
string nfa_state, nfa_chars, dfa_state, dfa_chars;
string **nfa_form, **dfa_form;

string add(string a, string b) {
    for (int i = 0; i < b.length(); i++) {
        int flag = 1;
        for (int j = 0; j < a.length(); j++)
            if (b[i] == a[j]) flag = 0;
        if (flag) a += b[i];
    }
    for (int i = 0; i < a.length(); i++)
        for (int j = 0; j < a.length() - 1; j++)
            if (a[j] > a[j + 1]) {
                char temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }

    return a;
}

void solve() {
    int write_num = 1, read_num = 1;
    string *dfa_head = new string[dfa_state_num];
    dfa_head[0] = nfa_state[0];

    for (int i = 0; i < nfa_chars_num; i++)
        dfa_form[0][i] = nfa_form[0][i];  //表的第一行必定相同

    for (int i = 0; i < nfa_chars_num; i++) {  //进行第零行的读入表头操作
        int flag2 = 1;
        for (int j = 0;; j++) {
            if (!dfa_head[j].compare(nfa_form[0][i])) flag2 = 0;
            if (dfa_head[j].empty()) {
                if (flag2 && nfa_form[0][i].compare("#"))
                    dfa_head[j] = nfa_form[0][i];
                flag2 = 1;
                break;
            }
        }
    }
    //接下来我们讨论一般的情况，先从表头获取写入的字符串，写完后再读取进表头
    for (; dfa_head[write_num] != "" && nfa_state_num != 1;
         write_num++) {  //如果当前要写表头的不为空
        int len = dfa_head[write_num].length();
        //写每一行的过程
        for (int i = 0; i < len; i++)
            for (int j = 0; j < nfa_state_num; j++)
                if (dfa_head[write_num][i] == nfa_state[j])
                    for (int k = 0; k < nfa_chars_num; k++)
                        if (dfa_form[write_num][k] == "" ||
                            dfa_form[write_num][k] == "#")
                            dfa_form[write_num][k] = nfa_form[j][k];
                        else if (nfa_form[j][k] != "#")
                            dfa_form[write_num][k] =
                                add(dfa_form[write_num][k], nfa_form[j][k]);

        //将这行的新元素塞到表头作为新状态
        for (int i = 0; i < nfa_chars_num; i++) {
            int flag3 = 1;
            for (int j = 0;; j++) {
                if (!dfa_head[j].compare(dfa_form[write_num][i])) flag3 = 0;
                if (dfa_head[j].empty() && flag3 &&
                    dfa_form[write_num][i].compare("#")) {
                    dfa_head[j] = dfa_form[write_num][i];
                    flag3 = 1;
                    break;
                }
                if (dfa_head[j].empty()) {
                    flag3 = 1;
                    break;
                }
            }
        }
    }
    //最后我们输出结果格式为先输出表
    cout << "DFA状态转移表" << endl;
    cout << '\t';
    for (auto c : nfa_chars) cout << c << '\t';
    cout << endl;
    for (int i = 0; i < write_num; i++) {
        cout << dfa_head[i] << '\t';
        for (int j = 0; j < nfa_chars_num; j++) cout << dfa_form[i][j] << '\t';

        cout << endl;
    }
    delete[] dfa_head;
}

int main() {
    cout << "请输入NFA状态集 (如ABCD)" << endl;
    cin >> nfa_state;
    nfa_state_num = nfa_state.length();
    cout << "请输入DFA字符集(如abcd)" << endl;
    cin >> nfa_chars;

    nfa_chars_num = nfa_chars.length();
    dfa_state_num = pow(2, nfa_state_num);
    dfa_chars_num = nfa_chars_num;

    nfa_form = new string *[nfa_state_num];
    for (int i = 0; i < nfa_state_num; i++)
        nfa_form[i] = new string[nfa_chars_num];

    dfa_form = new string *[dfa_state_num];
    for (int i = 0; i < dfa_state_num; i++)
        dfa_form[i] = new string[dfa_chars_num];

    cout << "请输入NFA转移表,空集请用'#'表示" << endl;
    for (int i = 0; i < nfa_state_num; ++i)
        for (int j = 0; j < nfa_chars_num; ++j) cin >> nfa_form[i][j];

    solve();

    for (int i = 0; i < dfa_state_num; i++) delete[] dfa_form[i];
    delete[] dfa_form;
    for (int i = 0; i < nfa_state_num; i++) delete[] nfa_form[i];
    delete[] nfa_form;

    system("pause");

    return 0;
}
