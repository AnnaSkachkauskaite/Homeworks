check :: (a -> Bool) -> [a] -> Bool

check f [] = True
check f (x:xs) = if (f x) then check f xs else False