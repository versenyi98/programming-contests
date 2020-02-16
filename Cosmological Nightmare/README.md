Alex likes astronomy: every night he looks at the sky and tries to see how the position of the stars differs. He is certain that every night all the stars move with a vector (u,v) compared to the previous position (the same vector for every star). To prove this he drew the position of the stars in two different nights. However, he accidentally spilled water over the two sheets he had drawn and the two drawings merged in a weird way.

Now, a point is present in the final drawing if and only if it belonged to exactly one of the two initial drawings.

He gives you the list of the N points from the final drawing along with a set of M translation vectors and asks you which of these vectors can represent the vector with which the stars were translated.

In other words, you should output "YES" if there is an initial set of points which, after translation with the vector given in query and merging the two sets, it results the points from input.

## Standard input

The first line contains a single integer N. Each of the next N lines describe one point (x,y). The line contains two integers x and y.

The next line contains a single integer M. Each of the next M lines contains two integers u and v which represents the translation vector (u,v).

## Standard output

You have to print M lines, the i-th line contains either "YES" (without quotes) if the answer for the i-th query is yes, or "NO" (without quotes) otherwise.