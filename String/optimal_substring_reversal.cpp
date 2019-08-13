//reverse any substring so that lexicographic smallest
//string produced.
//here we find first b and from that calculate substring
//with counting its lenght.

 int i = 0;
        while(i < str.length()){
            if(str[i] == 'b'){
                break;
            }
            i++;
        }
        if(i == str.length())  {
            cout << "[0,0]";
            return;
        }
        int pre_count = 0;
        int pre_end = 0;
        int start = i;
        int end = i;
        int count = 0;
        for(; i < str.length(); i ++){
            if(str[i] == 'a'){
                end = i;
                count ++;
            }else{
                if(count > pre_count){
                    pre_count = count;
                    pre_end = end;
                }
                count = 0;
            }
        }
        if(count > pre_count){
            pre_end = end;
        }
        cout <<"["<<start <<"," << pre_end << "]" << endl;
    }