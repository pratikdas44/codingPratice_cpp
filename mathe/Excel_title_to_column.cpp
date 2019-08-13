  int result = 0;
    for (const auto& c : A)
    {
        result *= 26;
        result += c - 'A' + 1;
    }

    return result;


 // column to title

    int i=0;char str[100];
    while(A>0){
        int rem = A%26;
        if(rem == 0){
            str[i++] = 'Z';
            A = (A/26)-1;
        }
        else{
            str[i++] = rem-1 + 'A';
            A /=26;

        }
    }
     str[i] = '\0';
     reverse(str,str+strlen(str));
     return str;