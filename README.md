# Next Smallest Palindrome
A solution to the next smallest palindrome problem using C++.

Given an integer input, the function returns the next smallest palindrome. E.g. 180->181, 1478 -> 1551.

This solution is for C++, uses string and integer manipulation to solve and should be easy to understand relative to other methods in my opinion.

While other methods I've found use arrays and pointers and use these pointers to manually carry over after increments, or use the modulo operator to split the integer into individual digits to compare, I find that it is easier to code this problem similar to how we as humans would see it. Specifically, it transforms the number into a string, splits the string into halves and compares them to decide whether to create the next palindrome by mirroring the left side or incrementing the left half first and then mirroring.

This avoids the manual carry over from the first type of solution mentioned earlier and instead allows simple arithmetic to do the carry for us when needed. It also avoids the modulo method which, from the example solution that I saw, was much too confusing. The method I've written should be easy enough to understand and code for coding interviews and is heavily commented in order to make it clear every step of the way.
