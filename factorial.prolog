predicates
	f(integer, integer)
clauses
	f(1, B):- write("res = ",B).
	f(A, B):-
	A>1,
	C = A*B,
	AA = A - 1,	
	f(AA, C).
goal
	f(5, 1)
