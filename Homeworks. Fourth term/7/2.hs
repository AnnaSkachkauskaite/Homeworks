import System.Random
import Data.Time.Clock.POSIX
import Control.Monad.State

data Tree a = Leaf a | Branch (Tree a) a (Tree a) deriving (Show)



randTree :: Tree a -> Int -> Tree Int
randTree tree v = evalState (helper tree) (mkStdGen v)
				where 
					helper (Leaf a) = do
						generator <- get
						let (randval, newgen) = random generator
						put newgen
						return (Leaf randval)
					helper (Branch left x right) = do 
						generator <- get
						let (randval, newgen) = random generator
						put newgen
						randleft <- helper left
						randright <- helper right
						return (Branch randleft randval randright)
					
tree = Branch (Leaf 1) (-2) (Branch (Leaf (-3)) 2 (Leaf 4))

main = do
	print $ show tree
	seed <- round `fmap` getPOSIXTime
	putStrLn . show $ randTree tree seed