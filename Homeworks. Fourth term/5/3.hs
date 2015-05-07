listOfSec:: Int -> [[Int]] 

listOfSec 1 = [[1], [2], [3]]
listOfSec n = concatMap (\x -> [1:x, 2:x, 3:x]) (listOfSec (n - 1))
