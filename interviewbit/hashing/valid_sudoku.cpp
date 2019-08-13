//check if sudoku is valid or not.
 int row[9][9] = {0}, col[9][9] = {0}, cube[9][9] = {0};
            
    for(auto i=0; i<A.size(); i++)
    {
        for(auto j=0; j<A.size(); j++)
        {
            if(A[i][j] != '.')
            {
                int ch = A[i][j] - '0' - 1;
                int k = i/3 * 3 + j/3;
            
                if(row[i][ch]++ || col[j][ch]++ || cube[k][ch]++)
                    return false;
            }
            
        }
    }

return true;


//or

int gridCheck(int row,int col,const vector&A)
{
unordered_set m;
for(int i=row;i<row+3;i++)
{for(int j=col;j<col+3;j++)
{if(isdigit(A[i][j]))
if(m.find(A[i][j])!=m.end())
return 0;
else
m.insert(A[i][j]);
}
}
return 1;
}
int Solution::isValidSudoku(const vector &A) {
unordered_setm;
int i,j;
for(i=0;i<9;i++)
{
m.clear();
for(j=0;j<9;j++)
{
if(isdigit(A[i][j])){
if(m.find(A[i][j])!=m.end())
return 0;
else
m.insert(A[i][j]);
}
}
}
m.clear();
for(i=0;i<9;i++)
{
m.clear();
for(j=0;j<9;j++)
{
if(isdigit(A[j][i])){
if(m.find(A[j][i])!=m.end())
return 0;
else
m.insert(A[j][i]);
}
}
}
for(i=0;i<9;i=i+3)
{
for(j=0;j<9;j=j+3)
{
if(gridCheck(i,j,A)==0)
return 0;
}
}
return 1;
}
