import Test.HUnit

diffElements :: (Eq a) => [a] -> Bool

diffElements [] = True
diffElements (el:l) = if (elem el l) then False else diffElements l

test1 = TestCase $ assertEqual "test1" True $ diffElements [0..10]
test2 = TestCase $ assertEqual "test2" True $ diffElements [1, 12, 6, 7, 3]
test3 = TestCase $ assertEqual "test3" False $ diffElements [1, 2, 1, 3, 4]

tests = TestList [TestLabel "test1" test1, TestLabel "test2" test2, TestLabel "test3" test3]

main = do
	runTestTT tests