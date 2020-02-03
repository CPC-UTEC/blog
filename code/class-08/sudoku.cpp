#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> sudoku;
vector <vector <int>> sudoku_solved;
vector <vector <pair <int, int>>> quadrant;
int n;
int N;
bool found;

bool validInRow (int r, int d) {
  for (int c = 0; c < N; c++) {
    if (sudoku[r][c] == d) return false;
  }
  return true;
}

bool validInCol (int c, int d) {
  for (int r = 0; r < N; r++) {
    if (sudoku[r][c] == d) return false;
  }
  return true;
}

bool validInQuadrant (int q, int d) {
  for (pair <int, int> pos: quadrant[q]) {
    int r = pos.first;
    int c = pos.second;
    if (sudoku[r][c] == d) return false;
  }
  return true;
}

// run this function for every 0 <= r < N and 0 <= c < N and you will get
// what this function does
int getQuadrant (int r, int c) {
  return (r / n) * n + (c / n);
}

void backtrack (int r, int c) {
  if (r == N) {
    found = true;
    sudoku_solved = sudoku;
    return;
  }
  if (found) {
    return;
  }
  int nc = (c + 1 == N) ? 0 : c + 1; // new column
  int nr = (c + 1 == N) ? r + 1 : r; // new row
  if (sudoku[r][c] != 0) {
    backtrack(nr, nc);
    return;
  } 
  for (int d = 1; d <= 9; d++) {
    int quadrant = getQuadrant(r, c);
    if (validInRow(r, d) and
        validInCol(c, d) and
        validInQuadrant(getQuadrant(r, c), d)) {
      sudoku[r][c] = d;
      backtrack(nr, nc);
      sudoku[r][c] = 0;
    }
  }
}

void precomputation () {
  found = false;
  N = sudoku.size();
  n = 1;
  while ((n + 1) * (n + 1) <= N) n++;
  // n = sqrt(N)
  quadrant.resize(N);
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      quadrant[getQuadrant(r, c)].push_back({r, c});
    }
  }
}

void print (const vector <vector <int>>& sudoku) {
  for (auto row: sudoku) {
    for (int elem: row) {
      cout << elem << ' ';
    }
    cout << '\n';
  }
}

int main () {
  sudoku = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
            {5, 2, 0, 0, 0, 0, 0, 0, 0},  
            {0, 8, 7, 0, 0, 0, 0, 3, 1},  
            {0, 0, 3, 0, 1, 0, 0, 8, 0},  
            {9, 0, 0, 8, 6, 3, 0, 0, 5},  
            {0, 5, 0, 0, 9, 0, 6, 0, 0},  
            {1, 3, 0, 0, 0, 0, 2, 5, 0},  
            {0, 0, 0, 0, 0, 0, 0, 7, 4},  
            {0, 0, 5, 2, 0, 6, 3, 0, 0}};
  precomputation();
  backtrack(0, 0);
  print(sudoku_solved);
  return (0);
}
