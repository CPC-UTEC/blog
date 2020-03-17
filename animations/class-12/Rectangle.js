const TOP_LEFT = 0
const TOP_RIGHT = 1
const BOTTON_LEFT = 2
const BOTTON_RIGHT = 3

let Rectangle = function (x, y, len, position) {
  this.x = x
  this.y = y
  this.len = len
  this.position = position
  this.new_black = [-1, -1]

  switch (position) {
    case TOP_LEFT:
      this.new_black = [x, y];
      break;
    case TOP_RIGHT:
      this.new_black = [x, y + len - 1];
      break;
    case BOTTON_LEFT:
      this.new_black = [x + len - 1, y];
      break;
    case BOTTON_RIGHT:
      this.new_black = [x + len - 1, y + len - 1];
      break;
    default:
      break;
  }

  this.has = function (black) {
    return this.x <= black[0] && black[0] < this.x + this.len &&
           this.y <= black[1] && black[1] < this.y + this.len;
  }
  
}
