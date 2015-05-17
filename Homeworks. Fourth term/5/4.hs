pairsMult :: Int -> [Int]
pairsMult n = [1..n] >>= (\x -> map (x*) [1..n])