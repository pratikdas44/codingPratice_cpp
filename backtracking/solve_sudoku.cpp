//to solve sudoku 
#include<bits/stdc++.h>
using namespace std;
http://video-88.rexporn.com/lvid/1572530508/Moh8d45A45j4JX5AaH425w/13000/13275/13275_240p.mp4/RexPorn.Com_Busty_Aleksa_Nicole_And_Booty_Kayla_Carrera_Prefer_Threesome_Anal_240p.mp4
/*
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
*/
//very good solution
//here all element in each row and each 3*3 box are checked
//and seen if it is present,if present marked as 1/
struct ArrayIn{
    int a[9][9];
};

bool solve(struct ArrayIn s){
    int flag=0;

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(s.a[i][j] == 0){
                flag=1;
                int psbl[] = {0,1,1,1,1,1,1,1,1,1};

                for(int k=0; k<9; k++){
                    psbl[s.a[i][k]]=0;
                    psbl[s.a[k][j]]=0;
                }
                int x_3 = i-i%3, y_3 = j-j%3;
                for(int x= x_3; x< x_3 +3; x++){
                    for(int y=y_3; y<y_3 +3; y++)
                        psbl[s.a[x][y]]=0;
                }

                for(int z=1; z<=9; z++){
                    if(psbl[z] == 1){
                        // cout<<"writting "<<z<<" at a["<<i<<","<<j<<"]"<<endl;
                        s.a[i][j] = z;
                        if(solve(s)){
                            // cout<<"*writting "<<z<<" at a["<<i<<","<<j<<"]"<<endl;
                            return true;
                        }
                    }
                }
                return false;
            }
        }
    }

    if(flag==0){
        // cout<<"\n###Solution is :- "<<endl;
        for(int i=0; i<9; i++){
	        for(int j=0; j<9; j++)
	            cout<<s.a[i][j]<<" ";
	    }
	    cout<<endl;
	    return true;
    }

}

int main() {
	struct ArrayIn s;
	int t;
	cin>>t;

	while(t--){
	    for(int i=0; i<9; i++){
	        for(int j=0; j<9; j++){
	            cin>>s.a[i][j];
	        }
	    }
	    solve(s);
	}

	return 0;
}
