
// @Title: 皇位继承顺序 (Throne Inheritance)
// @Author: Singularity0909
// @Date: 2020-09-27 12:11:57
// @Runtime: 1088 ms
// @Memory: 166.1 MB

class ThroneInheritance {
public:
    string king;
    unordered_set<string> dead;
    unordered_map<string, vector<string>> son;
    vector<string> res;
    
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        son[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    void dfs(const string& u) {
        if (dead.find(u) == dead.end()) {
            res.push_back(u);
        }
        for (const string& v : son[u]) {
            dfs(v);
        }
    }
    
    vector<string> getInheritanceOrder() {
        res.clear();
        dfs(king);
        return res;
    }
};
