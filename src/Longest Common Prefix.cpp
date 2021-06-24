class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) {                                      
            return strs[0];                                          
        }                                                            
        string result;                                               
        int pos = 0;                                                 
        char target;                                                 
        while (1) {                                                  
            if (strs[0].size() <= pos) {                             
                return result;                                       
            }                                                        
            target = strs[0][pos];                                   
            for (int i = 1; i < strs.size(); ++i) {                  
                if (strs[i].size() <= pos|| strs[i][pos] != target) {
                    return result;                                   
                }                                                    
            }                                                        
            result.push_back(target);                                
            pos++;                                                   
        }                                                            
    }
};