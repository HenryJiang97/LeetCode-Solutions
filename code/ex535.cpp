class Solution {
    int i = 0;
    unordered_map<int, string> map;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        map[i++] = longUrl;
        return "http://tinyurl.com/" + to_string(i - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int key = stoi(shortUrl.substr(19));
        return map[key];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));