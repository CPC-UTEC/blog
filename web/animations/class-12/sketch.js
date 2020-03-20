let canvas
let height
let width
let n = 4
let d
let grid = []
let moves = []
let cur
let cnt
let limit
let current_square
let slider

function setup () {
  canvas = createCanvas(300, 300)
  canvas.parent('sketch-holder')
  width = document.getElementById('sketch-holder').offsetWidth
  height = document.getElementById('sketch-holder').offsetHeight
  limit = 141 - 20 * 4
  resizeCanvas(width, height + 50)
  createEvents()
  buildGrid()
}

function createEvents () {
  document.getElementById('speed').addEventListener('change', () => {
    let factor = document.getElementById('speed').value
    limit = 1 * (141 - 20 * factor)
  })
  document.getElementById('parameter_n').addEventListener('change', () => {
    n = document.getElementById('parameter_n').value
    buildGrid()
  })

}

function windowResized () {
  let new_width = document.getElementById('sketch-holder').offsetWidth
  let new_height = document.getElementById('sketch-holder').offsetHeight
  if (new_width == width && new_height == height) {
    return
  }
  width = new_width
  height = new_height
  resizeCanvas(width, height)
  background('#fafafa')
  buildGrid()
}

function buildGrid () {
  cur = 0
  cnt = 0
  grid.splice(0, grid.length)
  moves.splice(0, moves.length)
  current_square = null
  let m = 1 << n
  d = Math.floor(height / m)
  for (let x = 0; x < m; x += 1) {
    let row = []
    for (let y = 0; y < m; y += 1) {
      row.push(new Cell(d * x, d * y, d))
    }
    grid.push(row)
  }
  let black = [Math.floor(random(0, m - 1)),
               Math.floor(random(0, m - 1))]
  grid[black[0]][black[1]].setColor([0, 0, 0])
  dc(new Rectangle(0, 0, m, -1), black)
}

function getNextColor () {
  let rand = Math.floor(random(0, 6))
  if (rand == 0) {
    return [255 - random(0, 100),
            random(0, 30),
            random(0, 30)]
  }
  if (rand == 1) {
    return [random(0, 30),
            255 - random(0, 100),
            random(0, 30)]
  }
  if (rand == 2) {
    return [random(0, 30),
            random(0, 30),
            255 - random(0, 100)]
  }
  if (rand == 3) {
    return [random(0, 30),
            255 - random(0, 100),
            255 - random(0, 100)]
  }
  if (rand == 4) {
    return [255 - random(0, 100),
            random(0, 30),
            255 - random(0, 100)]
  }
  if (rand == 5) {
    return [255 - random(0, 100),
            255 - random(0, 100),
            random(0, 30)]
  }
  return [random(0, 255), random(0, 255), random(0, 255)]
}

function dc (rect, black) {
  if (rect.len == 1) {
    return
  }
  moves.push({
    'type': 1,
    'square': rect
  })
  sector = []
  let m = rect.len >> 1
  let x = rect.x
  let y = rect.y
  sector.push(new Rectangle(x + 0, y + 0, m, BOTTON_RIGHT));
  sector.push(new Rectangle(x + 0, y + m, m, BOTTON_LEFT));
  sector.push(new Rectangle(x + m, y + 0, m, TOP_RIGHT));
  sector.push(new Rectangle(x + m, y + m, m, TOP_LEFT));
  let color = getNextColor()
  let shape = []
  for (let s of sector) {
    if (!s.has(black)) {
      shape.push(s.new_black)
    }
  }
  moves.push({
    'type': 2,
    'color': color,
    'shape': shape
  })
  for (let s of sector) {
    if (s.has(black)) {
      dc(s, black)
    } else {
      dc(s, s.new_black)
    }
  }
}

function update () {
  if (cur >= moves.length) {
    return
  }
  if (moves[cur].type == 1) {
    let square = moves[cur].square
    current_square = [d * square.x, d * square.y,
                      square.len * d, square.len * d]
  } else {
    current_square = null
    for (let s of moves[cur].shape) {
      grid[s[0]][s[1]].setColor(moves[cur].color)
    }
  }
  cur += 1
  cnt = 0
}

function draw () {
  translate(2, 2)
  background('#fafafa')
  for (let row of grid) {
    for (let cell of row) {
      cell.render()
    }
  }
  if (current_square) {
    noFill()
    stroke(255, 255, 0)
    strokeWeight(4)
    rect(current_square[0], current_square[1],
         current_square[2], current_square[3])
  }
  cnt += 1
  if (cnt >= limit) {
    update()
  }
}
