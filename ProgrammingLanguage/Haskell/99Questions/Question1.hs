-- Method 1
myLast :: [a] -> a
myLast [] = error "No end for empty lists!"
myLast [x] = x
myLast (_:xs) = myLast xs

-- Method 2 using foldr1
myLast' = foldr1 (const id)

-- Method 3
myLast'' = foldr1 (flip const)

-- Method 4
myLast''' = head . reverse

-- Method 5
myLast'''' = foldl1 (curry snd)

-- Method 6
myLast''''' [] = error "No end for empty lists!"
myLast''''' x = x !! (length x - 1)
