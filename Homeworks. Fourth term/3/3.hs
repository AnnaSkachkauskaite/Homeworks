maxSum(el1:el2:xs) = sum'(el2:xs) (el1 + el2, 2) 1
maxSum _ = 0
sum' (el1:el2:xs) (maxSum, i) j  | maxSum >= el1 + el2 = sum' (el2:xs) (maxSum, i + 1) j
								 | maxSum < el1 + el2 = sum' (el2:xs) (el1 + el2, i + 1) i
sum' _ _ j = j