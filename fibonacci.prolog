predicates
	f(integer, integer, integer, integer)
clauses
	f(A, B, C, N):-
	N<C, 
	write(B), 
	nl, 
	D = A + B,
	N1 = N + 1,
	f(B, D, C, N1).
goal
	f(0, 1, 5, 0)
