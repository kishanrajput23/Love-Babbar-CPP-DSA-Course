class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    map<char, int> mp;
		    queue<int> q;
		    string ans = "";
		    
		    for (int i=0; i<A.length(); i++) {
		        char ch = A[i];
		        
		      //  increse the count of character
		      mp[ch]++;
		      
		      //push the character into queue;
		      q.push(ch);
		      
		      //check the repetition of character
		      while (!q.empty()) {
		          if (mp[q.front()] > 1) {
		              q.pop();
		          }
		          else {
		              ans.push_back(q.front());
		              break;
		          }
		      }
		      
		      if (q.empty()) {
		          ans.push_back('#');
		      }
		    }
		    return ans;
		}

};