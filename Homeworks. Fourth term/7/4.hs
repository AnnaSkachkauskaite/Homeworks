import Control.Monad.Cont

mapCps :: (a -> b) -> [a] -> Cont r [b]
mapCps _ [] = return []
mapCps f (x : xs) = do
						rest <- mapCps f xs
						return ((f x) : rest)


filterCps :: (a -> Bool) -> [a] -> Cont r [a]
filterCps _ [] = return []
filterCps f (x : xs) = do
						rest <- filterCps  f xs
						case (f x) of
							False -> return rest
							True -> return (x : rest)
							

