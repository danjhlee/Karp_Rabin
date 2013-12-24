Karp_Rabin
==========
- Find all substring match(es) from a given string using the Karp-Rabin algorithm
- In the coding implementation, the string is "abracadabra" and the substring is "abr".
- Find a hash value: a prime number p is used as a base to calcuate the hash value. For example,
  the hash value of "abr" is hash("abr") = a*p^2 + b*p^1 + r*p^0;
- Rolling hash: since we already know the hash value of "abr" and the next targeted substring to match is "bra",
  we can calcuate the hash value of "bra" from the previous hash value of "abr". 
  In this case, the hash value of "bra" is hash("bra") = (hash("abr") - a*p^2)*p + a*p^0;
