predicates
	gcd(integer, integer).
clauses
	gcd(M,0):- write(M).
	gcd(M,N):-N>M,gcd(N,M).
	gcd(M,N):-S=M mod N,gcd(N,S).
goal
  go(2,3)
