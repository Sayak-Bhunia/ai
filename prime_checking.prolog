predicates
	prime(integer, integer)
	check(integer, integer, integer)
clauses
	prime(A, A):- write("prime").
	prime(A, B):-
	C = A mod B,
	check(A, B, C).
	check(_, _, 0):- write("non prime").
	check(A, B, _):-
	BB = B + 1,
	prime(A, BB).
		
goal
	prime(5, 2)
