//The library used are listed below

#include <Wire.h> 
#include <LiquidCrystal.h>
#include <Keypad.h>

//the datatype of variables

const int ROW_NUM = 4;
const int COLUMN_NUM = 3;
int count = 0;
char password[2][5]= {"5222"};
int ask=0;
char key;
int choice;
int amount;
char PIN [4]; 
int balance = 10000;



//character keys is a multidimensional array 0f 3*4
char keys[ROW_NUM][COLUMN_NUM] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
    
};

//Declaring the keypad keys as an input 

byte pin_rows[ROW_NUM] = {7, 6, 5, 4};
byte pin_column[COLUMN_NUM] = {3, 2, A4};


Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

// for the lcd pins 
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);  


void setup(){
                Serial.begin(9600);
                // set up the LCD's number of columns and rows:
                lcd.begin(16, 2);
                // Print a message to the LCD.
                lcd.setCursor(0, 0); 
                lcd.print( " Welcome to the Bank ");
                
                lcd.setCursor(0,0);

                // for the scrolling effect of text on the lcd
                for (int scrollCounter = 0; scrollCounter <12 ; scrollCounter++)
                {
                  lcd.scrollDisplayLeft();
                  delay(500);   
                }
                lcd.clear();
                
}

// main loop 
void loop (){
    
     // ask is the number of times for transaction to be make
     while  (ask=1){
     lcd.setCursor(0,0);
     lcd.print("Enter your pin");
     delay(100);
       
     char key = keypad.getKey();
     if (key) {
               lcd.setCursor ( count ,1);
               delay (100);
                 
               PIN [count]=key;
               lcd.print(PIN [count]);
               count++ ;
                       if (count ==4){
                       delay (1000);
                       lcd.clear();
                       delay (1000);

     if ( (PIN[0] == password[0][0] && PIN[1] == password[0][1] && PIN[2] == password[0][1] && PIN[3] == password[0][1] ))
          {         
         lcd.print("Welcome Alyssa");
         delay (5000);
         lcd.clear();      
         lcd.setCursor (0,0);
         if (password[5][2]) //pin = 1222
         {
          lcd.setCursor(10,0);
          lcd.print("");
          delay(3000);
         }
         else {
          lcd.setCursor(10,0);
          lcd.print(""); //pin = 1222
          delay(3000);
         }
        // lcd.print(password[0][4]);
         //delay(1000);
        // lcd.clear(); 
         lcd.setCursor(0,0);
         lcd.print( "1- Withdrawal"); 
         lcd.setCursor(0,1);
         lcd.print ("2- Deposit");
         delay (3000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print( "3- Balance"); 
         lcd.setCursor(0,1);
         lcd.print("4- Transfer");
         delay (3000);
         lcd.clear();
         lcd.setCursor(0,0);
         lcd.print("5- Exit");
         delay(3000);
     
         lcd.setCursor(0,0);
         delay (1000);
         int take= 0;
         while (take<=1 ){ 
                char key = keypad.getKey();
                if (key){

                      if(key !=NO_KEY ){
                           if (key=='1'){
              
                int amount;
                 int others;
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print( "Transaction in Process ") ;
                 lcd.clear();
                 delay(3000);
                 lcd.setCursor(0,0);
                 lcd.print("1- #1000"); 
                 lcd.setCursor(0,1);
                 lcd.print ("2- #2000");
                 delay (2000);
                 lcd.setCursor(0,0);
                 lcd.print( "3- #5000"); 
                 lcd.setCursor(0,1);
                 lcd.print ("4- #10000");
                 delay (2000);
                 lcd.setCursor(0,0);
                 lcd.print( "5- #20000"); 
                 lcd.setCursor(0,1);
                 lcd.print ("6- other");
                 delay (5000);
                 lcd.clear();
                 int i=0;
   if(key =='4'){
    lcd.setCursor(0,0);
    lcd.print("New balance=0");
   }
   else if(key == '2'){
    lcd.setCursor(0,0);
    lcd.print("New balance=8000");
   }
    else if(key == '3'){
    lcd.setCursor(0,0);
    lcd.print("New balance=5000");
   }
    else if(key == '1'){
    lcd.setCursor(0,0);
    lcd.print("New balance=9000");
   }
    else{
    lcd.setCursor(0,0);
    lcd.print("New balance=-10000");
   }
   
                     while (i<=1){ 
                            char key = keypad.getKey();
                            if (key){
                               if( key !=NO_KEY ){
                                  if ( 0 < amount && amount <= 5 ){
                                  lcd.clear();
                                  lcd.setCursor(0,0);
                                  lcd.print( "Please wait");
                                  }
                 
                            else{
                            lcd.clear();
                            lcd.setCursor(0,0);
                            lcd.print( "Enter the amount ");
                            int j =0;
                            int k =0;
                            while (j<=1){
                            char key = keypad.getKey();
                                   if (key) {
                                      lcd.setCursor ( k ,1);
                                      lcd.print(key);
                                      k ++ ;
                                      
                                      if (k==6){
                                         lcd.clear();
                                         lcd.setCursor(0,0);
                                         }
                                      }
                 
                                }
                            break;
                           }
                 
                     break;
                 }
              }
            }
          }

              if (key!=NO_KEY){
                  if (key=='2'){
             int amount;
                 int others;
                 lcd.clear();
                 lcd.setCursor(0,0);
                 lcd.print( "Transaction in Process ") ;
                 lcd.clear();
                 delay(3000);
                 lcd.setCursor(0,0);
                 lcd.print("1- #20"); 
                 lcd.setCursor(0,1);
                 lcd.print ("2- #50");
                 delay (2000);
                 lcd.setCursor(0,0);
                 lcd.print( "3- #100"); 
                 lcd.setCursor(0,1);
                 lcd.print ("4- #200");
                 delay (2000);
                 lcd.setCursor(0,0);
                 lcd.print( "5- #500"); 
                 lcd.setCursor(0,1);
                 lcd.print ("6- #1000");
                 delay (5000);
                 lcd.clear();
                 int i=0;
   if(key =='1'){
    lcd.setCursor(0,0);
    lcd.print("New balance=10020");
   }
   else if(key == '2'){
    lcd.setCursor(0,0);
    lcd.print("New balance=");
    lcd.setCursor(0,1);
    lcd.print("10050");
   }
    else if(key == '3'){
    lcd.setCursor(0,0);
    lcd.print("New balance=10100");
   }
    else if(key == '1'){
    lcd.setCursor(0,0);
    lcd.print("New balance=10200");
   }
    else{
    lcd.setCursor(0,0);
    lcd.print("New balance=10500");
   }
                  }


                  if (key!=NO_KEY){
                      if (key=='3'){
                          lcd.clear();
                          lcd.setCursor(0,0);
                          lcd.print ("Please wait") ;
                          delay (2000);
                          lcd.clear();
                          lcd.setCursor(0,0);
                          lcd.print ("   Your Account");
                          lcd.setCursor(0,1);
                          lcd.print("Balance is 10000");
                          delay (3000);
                          lcd.setCursor(0,1);
                          lcd.print(balance);
                          delay(3000);
                          lcd.clear();
                          delay(2000);
                          break;
                    }
                 }


               if (key!=NO_KEY){
                   if (key=='4'){
                      lcd.clear();
                      lcd.setCursor(0,0);
                      lcd.print ("Please wait") ;
                      delay ("1000");
                      lcd.clear();
                      lcd.setCursor(0,0);
                      lcd.print ("   Initiating");
                      lcd.setCursor(0,1);
                      lcd.print("    Transfer");
                      delay (3000);
                      break;
                    }
           }

           if (key != NO_KEY){
               if (key=='5'){
                  lcd.clear();
                  lcd.setCursor(0,0);
                  delay (1000);
                  lcd.print("Take your card"); 
                  lcd.setCursor(0,1);
                  lcd.print("Goodbye!");
                  delay (3000);
                  break;
                  }
              }
                      }
             }
        }
    }
                      
                     
  }
     
     else{
     lcd.print(" Incorrect pin"); 
     delay(1000);
     lcd.clear();
     lcd.setCursor(0,0);
     count=0;
     }
    }
   }
  }
 }
