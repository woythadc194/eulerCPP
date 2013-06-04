#include<iostream>
#include<math.h>
using namespace std;
class Number{

private:
    int array [0];
    Number (int * a);
    Number pow(int power, Number b, bool first);
    Number sqrt(Number high, Number med, Number low);
    string flip(string s);
    int * addLeadingZero(Number b, int numZeros);

public:
    bool isGreaterThan(Number b);
    bool isLessThan(Number b);
    bool equals(Number b);
    bool even();
    bool pandigital();
    Number (string s);
    Number add(Number b);
    Number subtract(Number b);
    Number multiply(Number b);
    Number divide(Number divisor);
    Number mod(Number b);
    Number pow(int power);
    Number sqrt();
    Number add1();
    Number sub1();
    string toString();
};

Number(int * a){
    int * p = &array;
    *p = a;
}

Number(string s){
    this.array = new int[s.length()];
    for(int i=0; i<s.length(); i++)
        this.array[0-i+s.length()-1]=Integer.parseInt(""+s.at(i));
    s = this.toString();
    this.array = new int[s.length()];
    for(int i=0; i<s.length(); i++)
        this.array[0-i+s.length()-1]=Integer.parseInt(""+s.at(i));
    
}

Number add(Number b){
    int maxLength = max(this.array.length, b.array.length);
    int minLength = min(this.array.length, b.array.length);
    int newNum [] = new int[maxLength+1];
    int carryover = 0;
    for(int i=0; i<minLength; i++){
        int n = this.array[i] + b.array[i]+carryover;
        carryover = n/10;
        newNum[i] = n%10;
    }
    if(!this.isLessThan(b)){
        for(int i=minLength; i<maxLength; i++){
            int n = this.array[i] + carryover;
            carryover = n/10;
            newNum[i] = n%10;
        }
    } else {
        for(int i=minLength; i<maxLength; i++){
            int n = b.array[i] + carryover;
            carryover = n/10;
            newNum[i] = n%10;
        }
    }
    newNum[newNum.length-1]=carryover;
    return new Number(new Number(newNum).toString());
}
    
Number subtract(Number b){
    int thisSize = this.array.length;
    int bSize = b.array.length;
    int thisCopy [] = new int [thisSize];
    for(int i=0; i<thisSize; i++)
        thisCopy[i]=this.array[i];
    if(this.isLessThan(b)){
        cout << "Error: Answer Negative" << endl;
        System.exit(0);
    }
    int newNum [] = new int[thisSize];
    for(int i=0; i<bSize; i++){
        if(thisCopy[i]<0){
            thisCopy[i]=9;
            thisCopy[i+1]--;
        }
        if(thisCopy[i]<b.array[i]){
            thisCopy[i] += 10;
            thisCopy[i+1]--;
        }
        newNum[i] = thisCopy[i]-b.array[i];
    }
    for(int i=bSize; i<thisSize; i++)
        newNum[i]=thisCopy[i];
    return new Number(new Number(newNum).toString());
}

Number multiply(Number b){
    int maxLength = max(this.array.length, b.array.length);
    int minLength = min(this.array.length, b.array.length);
    int newNum [] = new int[maxLength*2];
    int temp [] = new int[maxLength*2];

    if(maxLength == b.array.length){
        for(int x=0; x<minLength; x++){         //This.array
            int carryover = 0;
            int placeholder = 0;
            for(int i=0; i<x; i++)
                placeholder++;
            for(int y=0; y<maxLength; y++){     //b.array
                int n = (this.array[x]*b.array[y]) + carryover;
                carryover = n/10;
                temp[x+y] = n%10;
            }
            temp[maxLength+placeholder]=carryover;
            Number c = new Number(newNum);
            Number d = new Number(temp);
            newNum = c.add(d).array;
            temp = new int[maxLength*2];
        }            
    } else{            
        for(int x=0; x<minLength; x++){         //b.array
            int carryover = 0;
            int placeholder = 0;
            for(int i=0; i<x; i++)
                placeholder++;
            for(int y=0; y<maxLength; y++){     //this.array
                int n = (b.array[x]*this.array[y]) + carryover;
                carryover = n/10;
                temp[x+y] = n%10;
            }
            temp[maxLength+placeholder]=carryover;
            Number c = new Number(newNum);
            Number d = new Number(temp);
            newNum = c.add(d).array;
            temp = new int[maxLength*2];
        }            
    }
    return new Number(new Number(newNum).toString());
}

Number divide(Number divisor){
    int thisSize = this.array.length;
    Number reverse = new Number(this.flip(this.toString()));
    int * reverseP = &reverse.array;
    int reverseSize = reverse.array.length;
    bool leadingZero = (thisSize != reverseSize);
    if(leadingZero){
        *reverseP = addLeadingZero(reverse, thisSize-reverseSize);
    }
    string newNum = "";
    if(divisor.toString() == "0"){
        cout << "Error: Divide by Zero" << endl;
        System.exit(0);
    }
    if(this.isLessThan(divisor))
        return new Number("0");
    Number focus = new Number("0");
    for(int i=0; i<thisSize; i++){
        focus = new Number(focus.toString() + reverse.array[i]);
        if(divisor.isGreaterThan(focus)){
            newNum += "0";
        } else if(divisor.equals(focus)){
            newNum += "1";
            focus = new Number("0");
        } else { //divisor < focus
            int counter = 0;
            Number sum = new Number("0");
            while(sum.isLessThan(focus) || sum.equals(focus)){
                sum = sum.add(divisor);
                counter++;
            }
            counter--;                 //Reduced so now less than focus by 1
            sum = sum.subtract(divisor);  //  ""  ""  ""  ""  ""  ""  ""
            focus = focus.subtract(sum);
            newNum += counter;
        }
    }
    return new Number(newNum);
}

Number mod(Number b){
    if(b.toString() == "0"){
        cout << "Error: Modulus by 0" << endl;
        System.exit(0);
    }
    return (this.subtract(this.divide(b).multiply(b)));
}

Number pow(int power){
    if(power == 1)
        return this;
    if(power == 0)
        return new Number("0");
    if(power < 0){
        cout << "Error: Can't accomidate negative powers yet" << endl;
        System.exit(0);
    }
    return pow(power, this, true);
}

//Paramaters: int power - int to raise Number by
//            Number b - number being altered * this
//            bool first - the first time going through the helper or not
//                to decide whether or not to take 2 or 1 away from power
//Returns:  Number ^ power
Number pow(int power, Number b, bool first){
    if(first){                                                              //First time through the method
        first=false;                                                        //makes sure we wont come back to this block if method called again
        if(power == 2)                                                      //if power was only 2 (squared)
            return b.multiply(this);                                        //return value*value 
        return pow(power-2, b.multiply(this), first);                       //else take 2 away from power then call method again
    }
    if(power == 0)                                                          //if power has been reduced to 0, return b
        return b;
    return pow(power-1, b.multiply(this), first);                           //else power is greater than 0, take 1 away and call method again
}

Number sqrt(){
    return sqrt(this, this.divide(new Number("2")), new Number("0"));       //helper method using a high and low limit with an average
}

Number sqrt(Number high, Number med, Number low){
    if(high.multiply(high).equals(this))                                    //perfect square found
        return high;
    if(low.multiply(low).equals(this))                                      //perfect square found
        return low;
    if(med.multiply(med).equals(this))                                      //perfect square found        
        return med;
    if(high.sub1().equals(low))                                             //Not a perfect square, rounding up to next whole number (high)
        return high;
    if(med.multiply(med).isGreaterThan(this))                               //med too great
        return sqrt(med, med.add(low).divide(new Number("2")), low);        //high gets med, low stays same, med is average of high and low
                                                                            //med too little
    return sqrt(high, med.add(high).divide(new Number("2")), med);          //high stays same, low get med, med is average of high and low
}

bool isGreaterThan(Number b){
    int thisSize = this.array.length;
    int bSize = b.array.length;
    if(bSize<thisSize)
        return true;
    if(thisSize<bSize)
        return false;
    for(int i=(thisSize-1); i>=0; i--){
        if(b.array[i]>this.array[i])
            return false;
        else if(b.array[i]<this.array[i])
            return true;
        //if equal, continue
    }
    return false; //if numbers are equal
}

bool isLessThan(Number b){
    int thisSize = this.array.length;
    int bSize = b.array.length;
    if(bSize>thisSize)
        return true;
    if(thisSize>bSize)
        return false;
    for(int i=(thisSize-1); i>=0; i--){
        if(b.array[i]>this.array[i])
            return true;
        else if(b.array[i]<this.array[i])
            return false;
        //if equal, continue
    }
    return false; //if numbers are equal
}

bool equals(Number b){
    int thisSize = this.array.length;
    int bSize = b.array.length;
    if(bSize != thisSize)
        return false;
    for(int i=(thisSize-1); i>=0; i--)
        if(b.array[i] != this.array[i])
            return false;
    return true; //if numbers are equal
}

bool even(){
    return (this.mod(new Number("2")).toString() == "0");
}

bool pandigital(){
    string original = this.toString();
    string flipped = flip(original);
    return flipped.equals(original);
}

Number add1(){
    return this.add(new Number("1"));
}

Number sub1(){
    return this.subtract(new Number("1"));
}

string flip(string s){
    string t = "";
    for(int i=s.length()-1; i>=0; i--)
        t += s.at(i);
    return t;
}

int * addLeadingZero(Number b, int numZeros){
    int x [] = new int [b.array.length + numZeros];
    int * p = &x;
    for(int i=0; i<b.array.length; i++)
        x[i] = b.array[i];
    return p;
}

string toString(){
    string s = "";
    for(int i=this.array.length-1; i>=0; i--)
        s += this.array[i];
    while(s.at(0) == '0'){
        if(s.length() == 1)
            return "0";
        s=s.substring(1);
    }
    return s;
}
