# Isometric stuff

Some isometric math experiments, mostly rotating a 2d grid into an isometric view.


## Drawing a 2-d map, diagonally (from the game source code)

    (0, 0)            |              /\ (0,0)                   |  Per-iteration start tile:
      _ _ _ _ _ _     |             /\/\                     <- |  1: (0, 0) - width = 1
     |_|_|_|_|_|_|    |            /\/\/\                       |  2: (0, 1)
     |_|_|_|_|_|_|    |           /\/\/\/\                      |  3: (0, 2)
     |_|_|_|_|_|_|    |   (0, 5) /\/\/\/\/\                     |  4: (0, 3) _
     |_|_|_|_|_|_|    |          \/\/\/\/\/\ (5, 0)          <- |  5: (0, 4)  |- same width
     |_|_|_|_|_|_|    |           \/\/\/\/\/                 <- |  6: (1, 4) _|
             (4, 5)   |       ---- \/\/\/\/ <- a row to draw    |  7: (2, 4)
     fig. 1           |             \/\/\/                      |  8: (3, 4)
     2-D Array        |   fig. 2     \/\/                       |  9: (4, 4)
                      |  Rotated 45°  \/ (4, 5)              <- | 10: (5, 4) - width = 1


diamond.c - Prints the full rectangle rotated 45 degrees
view.c - Prints a coordinate map for a view size and a center point (and a map size)
view_dots.c - mostly the same as view.c, but prints dots for points and an asterisk for the center coordinate (in progress)

Drawing the view is a little different, you just need a start point then add to x and subtract from y as you're going from one element to the next in the row.

