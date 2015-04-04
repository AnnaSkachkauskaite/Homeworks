data Tree = Leaf | Branch (Tree)(Tree)

height :: Tree -> Int
height (Leaf ) = 0
height (Branch left right) = max (height left) (height right) + 1

minWay :: Tree -> Int
minWay (Leaf)= 0
minWay (Branch left right)= min (minWay left ) (minWay right) + 1
