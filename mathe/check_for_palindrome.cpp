 /*1) We can compare the first digit and the last digit, then we repeat the process.
2) For the first digit, we need the order of the number. Say, 12321. Dividing this by 10000 would get us the leading 1. The trailing 1 can be retrieved by taking the mod with 10.
3 ) Now, to reduce this to 232.

(12321 % 10000)/10 = (2321)/10 = 232 

4 ) And now, the 10000 would need to be reduced by a factor of 100.
*/
 int divisor = 1;
    while(n/divisor >= 10)
      divisor *= 10;

      while(n!=0){
          int leading = n/divisor;
          int trailing = n%10;

          if(leading!=trailing)
             return 0;

         n = (n%divisor)/10;
         divisor /= 100;
      }
      return 1;