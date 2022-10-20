a. BigDecimalInt (string decStr); // Initializes from string & rejects bad input 
b. BigDecimalInt (int decInt); // Initialize from integer 
c. BigDecimalInt operator+ (BigDecimalInt anotherDec); // member fn
d. BigDecimalInt operator- (BigDecimalInt anotherDec); // member fn
e. bool operator< (BigDecimalInt anotherDec); // member fn
f. bool operator> (BigDecimalInt anotherDec); // member fn
g. bool operator==(BigDecimalInt anotherDec); // member fn
h. BigDecimalInt operator= (BigDecimalInt anotherDec); // member fn
i. int size(); // member fn
j. int sign(); // member fn
k. friend ostream& operator << (ostream& out, BigDecimalInt b) 
