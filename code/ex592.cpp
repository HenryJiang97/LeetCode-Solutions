class Solution {
public:
    string fractionAddition(string expression) {
        expression += '+';
        
        vector<int> denominator;
        vector<int> numerator;
        getFractions(expression, denominator, numerator);
        
        // Get common denominator
        int commonDenominator = 1;
        for (int d : denominator)
            commonDenominator = LCM(commonDenominator, d);
        
        // Get numerator sum
        int numeratorSum = 0;
        for (int i = 0; i < numerator.size(); i++)
            numeratorSum += numerator[i] * (commonDenominator / denominator[i]);
        
        // Get the irreducible fraction
        int sign = numeratorSum >= 0 ? 1 : -1;
        int gcp = GCP(abs(numeratorSum), commonDenominator);
        numeratorSum = sign * (abs(numeratorSum) / gcp);
        commonDenominator /= gcp;
        
        // Get result
        string res = "";
        res += to_string(numeratorSum) + "/" + to_string(commonDenominator);
        
        return res;
    }
    
private:
    int GCP(int a, int b) {
        if (b == 0)    return a;
        else    return GCP(b, a % b);
    }
    
    int LCM(int a, int b) {
        return a * b / GCP(a, b);
    }
    
    void getFractions(string expression, vector<int>& denominator, vector<int>& numerator) {
        // Get the list of numerator and denominator
        int sign = 1, i = 0, num = 0;
        if (expression[i] == '-')    {sign = -1;    i++;}
        
        while (i < expression.length()) {
            char c = expression[i++];
            if (c == '/') {
                numerator.push_back(num * sign);
                sign = 1;
                num = 0;
            } else if (c == '+' || c == '-') {
                if (c == '-')    sign = -1;
                denominator.push_back(num);
                num = 0;
            } else {
                num = num * 10 + (c - '0');
            }
        }
    }
};