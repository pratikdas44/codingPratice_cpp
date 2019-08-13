//question is to find permutation given string with I and D
//where I means increment and D is decrement.
//so if string = ID, array should return : 1,3,2

//approach is to select a number randomly and increment
//if I comes else decrement.
//B is number and length of string is B-1.

  int n =1,m=B;vector<int> a;
  for(int i=0;i<A.length();i++){
      if(A[i] == 'I'){
          a.push_back(n);
          n++;
      }
      else{
          a.push_back(m);
          m--;
      }
        
  }
  a.push_back(n);
  return a;