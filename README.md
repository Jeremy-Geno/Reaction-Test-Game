# Reaction-Test-Game
description: A game that test your reaction time using hand eye coordination

Rules
Game will start with a beep then a pause of 1 second
3 inputs left button, right button, and shake
3 different LED colors, Red, Blue, and Green
The right button with the right color within a reference time will grant a +1 to your score
After 4 stages you will then progress to the next level regardless of your score on the previous level.
At the end of the game your score will be totaled and will output a beep for each point you successfully earned.
Max points is 12 consisting of 4 stages per level with a total of 3 levels.

Corresponding commands
Red LED == Shake the arduino with at least total accel of 15
Green LED == press left button also known as pin 5
Blue LED == press right button also known as pin 4
Doing the correct command within the alotted time grants a point.
