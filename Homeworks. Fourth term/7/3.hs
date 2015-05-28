import Data.Char
import Data.List
import Control.Monad.State

data HashTable key value = HashTable { hash :: (key -> Int), table :: [(Int, value)]}


findElement :: key -> HashTable key value -> Maybe value
findElement key (HashTable func table) =  find' table
                                        where find' t@((x,y):xs) = if ((func key) == x) then Just y
                                                                        else if ((func key) < x) then Nothing
                                                                            else find' xs


addElement :: key -> value -> HashTable key value -> HashTable key value
addElement key value (HashTable func table) = let addEl t@((x,y):xs)
                                                        | (func key) == x = ((func key), value) : xs
                                                        | (func key) > x = (x, y) : (addEl xs)
                                                        | otherwise = ((func key), value) : t
                                                  addEl [] = [((func key), value)]
                                              in HashTable func (addEl table)


removeElement :: key -> value -> HashTable key value -> HashTable key value
removeElement key value (HashTable func table) = let removeEl t@((x,y):xs)
                                                        | (func key) == x = xs
                                                        | (func key) > x = (x, y) : (removeEl xs)
                                                        | otherwise = t
                                                     removeEl [] = []
                                              in HashTable func (removeEl table)



addhelper:: key -> value -> State (HashTable key value) (HashTable key value)
addhelper key value = do
        table <- get
        put (addElement key value table)
        return table


add :: key -> value -> HashTable key value -> HashTable key value
add key value (HashTable func table) = snd (runState (addhelper key value) $ (HashTable func table))



removehelper:: key -> value -> State (HashTable key value) (HashTable key value)
removehelper key value = do
        table <- get
        put (removeElement key value table)
        return table


remove :: key -> value -> HashTable key value -> HashTable key value
remove key value (HashTable func table) = snd (runState (removehelper key value) $ (HashTable func table))




										
 