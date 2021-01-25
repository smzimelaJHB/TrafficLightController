//initialising 
int green1=3;
int green2=6;
int green3=9;

int yellow1=4;
int yellow2=7;
int yellow3=10;

int red1 =5;
int red2= 8;
int red3=11;

int button = 1;
 //store the read value into state variable (it either LOw/High)
int state= digitalRead(button);   

void setup()
 {
  // initialize digital outputS.
    pinMode(red1, OUTPUT);
    pinMode(red2, OUTPUT);
    pinMode(red3, OUTPUT);
    pinMode(yellow1, OUTPUT);
    pinMode(yellow2, OUTPUT);
    pinMode(yellow3, OUTPUT);
    pinMode(green1, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(green3, OUTPUT);
    pinMode(button, INPUT);
  } 


void loop()
  {
  // All functions are called from here                                                 
  if(state==HIGH) 
      {
          // If the swittch is pressed run the mos code forever untill the switch is pressed again  
          callSOS(); 
      } 

      digitalWrite(red2,HIGH);//Stop East_West traffic
      digitalWrite(red3,HIGH);//Stop North_West traffic 
      digitalWrite(red1,HIGH);//Stop North_West traffic 
      North_South_traffic();          // The first traffic to move is NS 
      East_West_traffic();           //Followed by East_West
      North_West_traffic();          //Then North_West
    }


void  North_South_traffic()
  {
    //for North South traffic
    digitalWrite(red1,LOW); // FINALLY GO TO RED TO STOP THE TRAFFIC   
    digitalWrite(green1,HIGH); // sets the LED on
    delay(12000);               //Stay for 5s in the green light
    digitalWrite(green1,LOW); // sets the LED off after 5s

    blinkEastWest();  // Allert East_West TRAFFIC THAT GREEN IS ABOUT TO TURN SAME DELAY AS yELLOW (3S)              
    delay(6000); // Stay 3s in yellow
    digitalWrite(yellow1,LOW); // sets the LED off                          
  }


void  East_West_traffic()
  {
      digitalWrite(red1,HIGH); // TURN RED OFF              
      digitalWrite(red2,LOW); // TURM RED OFF  
      digitalWrite(green2,HIGH); // sets the LED on
      delay(12000);               //Stay for 5s in the green light
      digitalWrite(green2,LOW); // sets the LED off after 5s

      blinkNorthWest(); // Allert East_West TRAFFIC THAT GREEN IS ABOUT TO TURN SAME DELAY AS yELLOW (3S)              
      delay(6000);                // Stay 3s in yellow
      digitalWrite(yellow2,LOW); // sets the LED off                
  }


void  North_West_traffic()
  {            
      digitalWrite(red2,HIGH); // TURM RED OFF  
      digitalWrite(red3,LOW); // TURM RED OFF  
        
      digitalWrite(green3,HIGH); // sets the LED on
      delay(12000);               //Stay for 5s in the green light
      digitalWrite(green3,LOW); // sets the LED off after 5s

      blinkNorthSouth();  // Allert East_West TRAFFIC THAT GREEN IS ABOUT TO TURN SAME DELAY AS yELLOW (3S)              
      delay(6000);                // Stay 3s in yellow
      digitalWrite(yellow3,LOW); // sets the LED off               
  }

          
void blinkEastWest()  //By the time you get ou of here 3s will be gone East_West be green 
  {
    for (int x=0; x<12; x++)         //RUNS 3 TIMES 0 - 2
    {
    digitalWrite(yellow1,HIGH); // GO TO AMBER FOR 3S 
    digitalWrite(red2, LOW);        // sets the LED off
    delay(500);                     // slack with 3ms                        
    digitalWrite(red2, HIGH);        // sets the LED on      
    delay(500);                    // waits for 500ms
    }
  }
  

void blinkNorthWest()                       //By the time you get ou of here 3s will be gone North_West be green 
  {
    for (int x=0; x<12; x++) 
    {
    digitalWrite(yellow2,HIGH); // GO TO AMBER FOR 3S 
    digitalWrite(red3, LOW);        // sets the LED off
    delay(500);                     // slack with 3ms                        
    digitalWrite(red3, HIGH);        // sets the LED on      
    delay(500);                    // waits for 500ms
    }
  }


void blinkNorthSouth()  //By the time you get ou of here 3s will be gone NS be green 
  {
    for (int x=0; x<12; x++) 
    {
    digitalWrite(yellow3,HIGH); // GO TO AMBER FOR 3S 
    digitalWrite(red1, LOW);        // sets the LED off
    delay(500);                     // slack with 3ms                        
    digitalWrite(red1, HIGH);        // sets the LED on      
    delay(500);                    // waits for 500ms
    
    }
  }


void callSOS()
  {
  digitalWrite(red1, LOW); // sets the LED off
  digitalWrite(red2, LOW); // sets the LED off
  digitalWrite(red3, LOW); // sets the LED off
  digitalWrite(green1,LOW); // sets the LED off
  digitalWrite(green2,LOW); // sets the LED off
  digitalWrite(green3,LOW); // sets the LED off
  digitalWrite(yellow1,LOW); // sets the LED off
  digitalWrite(yellow2,LOW); // sets the LED off
  digitalWrite(yellow3,LOW); // sets the LED onff
                                    
  // 3 dits
  for (int x=0; x<3; x++) 
  {
  digitalWrite(red1, HIGH); // sets the LED on
  digitalWrite(red2, HIGH); // sets the LED on
  digitalWrite(red3, HIGH); // sets the LED on
  delay(150);
  // waits for 150ms
  digitalWrite(red1, LOW); // sets the LED off
  digitalWrite(red2, LOW); // sets the LED off
  digitalWrite(red3, LOW); // sets the LED off
  // sets the LED off
  delay(100);
  // waits for 100ms
  }
    
  // 100ms delay to cause slight gap between letters
  delay(100);
  // 3 dahs
  for (int x=0; x<3; x++)
  {
    digitalWrite(red1, HIGH); // sets the LED on
    digitalWrite(red2, HIGH); // sets the LED on
    digitalWrite(red3, HIGH); // sets the LED on
    delay(400);
    // waits for 400ms
    digitalWrite(red1, LOW); // sets the LED off
    digitalWrite(red2, LOW); // sets the LED off
    digitalWrite(red3, LOW); // sets the LED off
    // sets the LED off
    delay(100);
    // waits for 100ms
    // 100ms delay to cause slight gap between letters
    delay(100);
   }
    // 3 dits again
    for (int x=0; x<3; x++) 
    {
    digitalWrite(red1, HIGH); // sets the LED on
    digitalWrite(red2, HIGH); // sets the LED on
    digitalWrite(red3, HIGH); // sets the LED on
    // sets the LED on
    delay(150);
    // waits for 150ms
    digitalWrite(red1, LOW); // sets the LED off
    digitalWrite(red2, LOW); // sets the LED off
    digitalWrite(red3, LOW); // sets the LED off
    // sets the LED off
    delay(100);
    // waits for 100ms
    }          
    // wait 0.5 seconds before repeating the SOS signal
    delay(500);     
    }
