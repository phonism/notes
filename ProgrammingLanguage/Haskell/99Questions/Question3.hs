-- Method 1
elementAt :: [a] -> Int -> a
elementAt l i = l !! (i - 1)

-- Method 2
elementAt' :: [a] -> Int -> a
elementAt' (x:_) 1 = x
elementAt' [] _ = error "Index out of bounds!"
elementAt' (_:xs) k
    | k < 1 = error "Index out of bounds!"
    | otherwise = elementAt' xs (k - 1)

-- Method 3
elementAt'' :: [a] -> Int -> a
elementAt'' (x:_) 1 = x
elementAt'' (_:xs) i = elementAt'' xs (i - 1)
elementAt'' _ _ = error "Index out of bounds!"

-- Method 4
elementAt''' xs n 
    | length xs < n = error "Index out of bounds!"
    | otherwise = fst . last $ zip xs [1..n]

-- Method 5
-- Not Perfect!
-- TODO: fix it
elementAt'''' = flip $ (last .) . take . (+ 1)
