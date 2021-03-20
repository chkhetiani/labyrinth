# labyrinth

labyrinth game for uglimes class

---

1. print game info
2. print level info (locked/unlocked)
3. load map from file
4. game
   1. draw map
   2. get input and reduce move count
   3. make move or return error
      1. if error GOTO 4.2
      2. if no error make move
   4. check win
5. print game info
6. if won update unlocked level count
   GOTO: 1

---

### Player

1. current move count `int`
2. curretn position `position`
3. icon `char` `cin || file[avatar.txt]`

---

### Menu

1. level count `int` `file[level_count.txt]`
2. max level unlocked `int`

---

### Level

1. map `char[][]` `file[x.txt]`
2. height `int` `file[x.txt]`
3. width `int` `file[x.txt]`
4. start `position` `file[x.txt]`
5. end `position` `file[x.txt]`
6. move count `int` `file[x.txt]`

### Game

1. Level
2. Player

### position

1. x `int`
2. y `int`

---

## examples:

Output example:

```
1.
2. [locked]
3. [locked]
4. [locked]
   choose level to play: 2
```

Level files example:

```
5 \\ height
4 \\ width
2 \\ start position y
1 \\ start position x
3 \\ goal position y
3 \\ goal position x
5 \\ move count
+--+
|  |
|x |
|  $
+--+
```
