class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st;
        for(int i=0;i<wordList.size();i++){
            st.insert(wordList[i]);
        }

        queue<pair<string,int>> q;
        q.push({beginWord,0});
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int pathDist = q.front().second;
            q.pop();
            if(word==endWord){
                return pathDist+1;
            }
            for(int i=0;i<word.size();i++){
                for(char ch='a';ch<='z';ch++){
                    string temp = word;
                    temp[i]=ch;
                    if(st.find(temp)!=st.end()){
                        st.erase(temp);
                        q.push({temp,pathDist+1});
                    }
                }
            }
        }
        return 0;


    }
};