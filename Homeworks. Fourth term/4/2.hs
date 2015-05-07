import Test.HUnit

data Tree a = Leaf a | Branch (Tree a) a (Tree a)

foldTree :: (a -> a -> a) -> a -> Tree a -> a

foldTree f s (Leaf el) = f s el
foldTree f s (Branch left el right) = foldTree f (foldTree f (f s el) left) right



testTree = Branch ( Branch (Leaf 1) 4 (Leaf (-1)) ) 1 ( Branch (Leaf 2) 3 (Leaf (-2)) )

test1 = TestCase $ assertEqual "x + y" 8 $ foldTree (\x y -> x + y) 0 testTree
test2 = TestCase $ assertEqual "x * y" 48 $ foldTree (\x y -> x * y) 1 testTree

tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2]

main = do
	   runTestTT tests