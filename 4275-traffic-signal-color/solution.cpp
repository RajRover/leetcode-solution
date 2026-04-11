class Solution {
public:
    string trafficSignal(int timer){
        string s="";
        if(30<timer && timer<=90){
            s= "Red";
        }
        else if(timer==30){
            s= "Orange";
        }
        else if(timer==0){
            s= "Green";
        }
        else{
            s= "Invalid";
        }
        return s;
    }
};
