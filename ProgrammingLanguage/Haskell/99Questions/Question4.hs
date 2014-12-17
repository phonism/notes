-- Method 1
myLength = length

-- Method 2: recursive solution
myLength' :: [a] -> Int
myLength' [] = 0
myLength' (_:xs) = 1 + myLength' xs

-- Method 3: using an "accumulator"
myLength'' :: [a] -> Int
myLength'' list = myLength_acc list 0
    where myLength_acc [] n = n
          myLength_acc (_:xs) n = myLength_acc xs (n + 1)

-- Method 4: using foldl/foldr
myLength1 = foldl (\n _ -> n + 1) 0
myLength2 = foldr (\_ n -> n + 1) 0
myLength3 = foldr (\_ -> (+1)) 0
myLength4 = foldr ((+) . (const 1)) 0
myLength5 = foldr (const (+1)) 0
myLength6 = foldl (const . (+1)) 0

-- Method 5: zipping with an infinite list
myLength7 xs = snd $ last $ zip xs [1..]
myLength8 = snd . last . (flip zip [1..])
myLength9 = fst . last . zip [1..]

-- Method 6: mapping all elements to "1"
myLength10 = sum . map (\_ -> 1)
