//colorful number example:
//number is 3245: then substring are :
//3,2,4,5,32,24,45,324,245,3245.
//here every individual gives different multiplication result.

char st[20];
    sprintf(st, "%d", n);
    int len = strlen(st); // to find number of digits.

    //or use string num = to_string(n);
    len = num.length();   
    map<long long, bool> Hash;
    //here we check for every multiplication result and
    //store it in hash.
    for(int i = 0; i < len; ++i) {
            
		long long mul = 1;
            
		for(int j = i; j < len; ++j) {
            
			mul *= (long long)(st[j] - '0');
            if(Hash.find(mul) != Hash.end()) return 0;
            Hash[mul] = true;
        }
    }

    return 1;