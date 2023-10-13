/*
Solution:

- sort all the skill levels
- for each skill in order
  - find all possible teams for the skill
  - if it cannot join any existing teams
    - put it in a new teams
  - otherwise put it in the smallest team

Hackerrank result:
  passed: rest
  timed-out: 3, 11, 12
  failed: none

Possible improvements:
- if there is a team of size 1 stop

How to build:
Linux: g++ --std=c++11 <file>.cpp
Windows (vcvarsall.bat): cl /EHsc <file>.cpp
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// returns:
const int ADDED_TO_TEAM=1;  // id added to an existing team
const int FORM_NEW_TEAM=2;  // if student level cannot be added to any team
const int TEAM_SIZE_ONE_EXIST=3;  // signal to stop execition because there is a team of size 1
int add_student_level_to_team(
        int student,
        vector<vector<int>>& open_teams,
        vector<vector<int>>& closed_teams) {

    int result = FORM_NEW_TEAM;
    int last_team_index = open_teams.size() - 1;

    if (open_teams.size() > 0) {
        cout << "check open teams for student " << student << endl;
        for (int i=last_team_index; i>=0; i--) {
            if ((student - open_teams[i].back()) == 1) {
                cout << "goes to team " << i << endl;
                open_teams[i].push_back(student);
                result = ADDED_TO_TEAM;

                if (i > 0) {
                    cout << "check if we can close some teams" << endl;
                    for (int j=i-1; j>=0; j--) {
                        cout << "check team " << j << endl;
                        if (student - open_teams[j].back() > 1) {
                            cout << "close " << j << " and older" << endl;
                            for (int k=j; k>=0; k--) {
                                cout << "add to closed " << k << endl;
                                if (open_teams[k].size() == 1) {
                                    return TEAM_SIZE_ONE_EXIST;
                                }
                                closed_teams.push_back(open_teams[k]);
                                cout << "remove from open " << k << endl;
                                open_teams.erase(open_teams.begin()+k);
                            }

                            break;
                        }
                    }
                }

                break;
            }
        }
    }

    return result;
}

int team_formation(vector<int>& students) {
    sort(students.begin(), students.end());

    vector<vector<int>> closed_teams;
    vector<vector<int>> open_teams;

    int students_size = students.size();
    for (int i=0; i<students_size; i++) {
        cout << "check student " << students[i] << endl;
        int result = add_student_level_to_team(students[i], open_teams, closed_teams);

        if (result == FORM_NEW_TEAM) {
            cout << "no valid team - create new" << endl;
            vector<int>* new_team = new vector<int>;
            new_team->push_back(students[i]);
            open_teams.push_back(*new_team);
        }

        if (result == TEAM_SIZE_ONE_EXIST) {
            return 1;
        }
    }

    int smallest_team = students_size + 1;
    for (const auto& team: open_teams) {
        if (team.size() < smallest_team) {
            smallest_team = team.size();
        }
    }

    for (const auto& team: closed_teams) {
        if (team.size() < smallest_team) {
            smallest_team = team.size();
        }
    }

    return smallest_team;
}

void perform_test(vector<int>& students, int expected) {
    cout << "=== begin test case ===" << endl;
    int smallest_team = team_formation(students);
    cout << "smallest_team " << smallest_team << " expected " << expected << endl << endl;

}

void test_001() {
    vector<int> students = {1,2,3,4,4,5,6};
    perform_test(students, 3);
}

void test_002() {
    vector<int> students = {1,1,2,2,3,3,4,4};
    perform_test(students, 4);
}

void hr_testcase() {
    int n;
    cin >> n;

    if (n==0) {
        cout << "0" << endl;
        return;
    }

    vector<int> students(n);
    for (int i=0; i<n; i++) {
        cin >> students[i];
    }

    int smallest_team = team_formation(students);

    cout << smallest_team << endl;
}

void hackerrank() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {
        hr_testcase();
    }
}

int main() {
    //hackerrank();
    test_001();
    test_002();
    return 0;
}
