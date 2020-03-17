let Cell = function Cell(x, y, d) {
  this.x = x
  this.y = y
  this.d = d
  this.color = [255, 255, 255]
  
  this.render = function () {
    fill(this.color)
    stroke(0, 0, 0)
    strokeWeight(1)
    rect(this.x, this.y, this.d, this.d)
  }

  this.setColor = function (color) {
    this.color = color
  }

}
