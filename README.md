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

2 output example:

1. qwerty
2. werty [locked]
3. erty [locked]
4. rty [locked]
   choose level to play: 2
