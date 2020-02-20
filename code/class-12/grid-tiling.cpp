#include <bits/stdc++.h>

using namespace std;

const int TOP_LEFT = 0;
const int TOP_RIGHT = 1;
const int BOTTON_LEFT = 2;
const int BOTTON_RIGHT = 3;

struct Rectangle {
  int x, y;
  int len;
  pair <int, int> new_black;
  Rectangle () {}
  Rectangle (int x, int y, int len, int position):
    x(x), y(y), len(len) {
    switch (position) {
      case TOP_LEFT:
        new_black = {x, y}; 
        break;
      case TOP_RIGHT:
        new_black = {x, y + len - 1};
        break;
      case BOTTON_LEFT:
        new_black = {x + len - 1, y};
        break;
      case BOTTON_RIGHT:
        new_black = {x + len - 1, y + len - 1};
        break;
      default:
        break;
    }
    
  }
  bool has (pair <int, int> black) {
    return x <= black.first and black.first < x + len and
           y <= black.second and black.second < y + len;
  }
};

char cur_letter = 'a';

void update_cur_letter () {
  if (cur_letter == 'z') cur_letter = 'a';
  else cur_letter++;
}

void solve (Rectangle rect, pair <int, int> black, vector <string>& grid) {
  if (rect.len == 1) return;
  vector <Rectangle> sector;
  int m = rect.len / 2;
  int x = rect.x;
  int y = rect.y;
  sector.emplace_back(x + 0, y + 0, m, BOTTON_RIGHT);
  sector.emplace_back(x + 0, y + m, m, BOTTON_LEFT);
  sector.emplace_back(x + m, y + 0, m, TOP_RIGHT);
  sector.emplace_back(x + m, y + m, m, TOP_LEFT);
  char ch = cur_letter;
  update_cur_letter();
  for (auto s: sector) {
    if (s.has(black)) {
      solve(s, black, grid);
    } else {
      grid[s.new_black.first][s.new_black.second] = ch;
      solve(s, s.new_black, grid);
    }
  }
}

int main () {
  int n, x, y;
  cin >> n >> x >> y;
  assert (1 <= n and n < 8);
  int m = (1 << n);
  assert (0 <= x < m);
  assert (0 <= y < m);
  vector <string> grid(m, string(m, ' '));
  grid[x][y] = '#';
  solve(Rectangle(0, 0, m, -1), pair <int, int>(x, y), grid);
  for (string& row: grid) cout << row << '\n';
  return (0);
}
