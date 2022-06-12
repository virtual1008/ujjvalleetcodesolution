class Solution{
public:
	bool isMatch(string s, string p){
		s = "$" + s; 
		p = "$" + p;

		int s_length = s.length();
		int p_length = p.length();

		vector<vector<bool>> DP(s_length, vector<bool>(p_length, false));
		DP[0][0] = true;
		for(int i = 1; i < p_length; i++){
			DP[0][i] = (p[i] == '*') ? DP[0][i - 1] : false;
		}

		for(int i = 1; i < s_length; i++){
			for(int j = 1; j < p_length; j++){
				switch(p[j]){
				case '*':
					DP[i][j] = DP[i - 1][j] or DP[i][j - 1];
					break;

				case '?':
					DP[i][j] = DP[i - 1][j - 1];
					break;

				default:
					DP[i][j] = (s[i] == p[j]) ? DP[i - 1][j - 1] : false;
				}
			}
		}

		return DP[s_length - 1][p_length - 1];
	}
};