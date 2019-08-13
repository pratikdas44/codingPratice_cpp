//v[] = {a.cat,dog,god,tca};
//return [[1],[2,5],[3,4]];
//very nice solution.
 vector<vector<int> > sol;
    unordered_map<string, vector<int> > myMap;
    string temp;
    for(int i = 0; i < A.size(); i++){
        temp = A[i];
        sort(temp.begin(),temp.end());
        myMap[temp].push_back(i+1);
    }
    
    auto it = myMap.begin();
    
    while(it != myMap.end()){
        sol.push_back(it->second);
        it++;
    }

return sol;