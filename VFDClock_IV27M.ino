
// VFD Clock V2 using IV-27M VFD tube
// Last Updated: 29-05-19
// Displays Time, Date, Temperature, Humidity, Pressure, Alarm
// function added.
/*
               _a
            f| g_| b 
            e| _ | c  o h
               d     
               
Let 'day_number' be the day of the month.
Let "month_number' be the month, counting March as 1 and February as 12. 
Let 'year2_number' be the last two digits of the year.
Let 'year1_number' be the first two digits of the year.
jan = 1, feb = 2, mar = 3, apl = 4, may = 5, jun = 6,
jul = 7, aug = 8, sept = 9, oct = 10, nov = 11, dec = 12
Sun = 0, Mon = 1, Tue = 2, Wed = 3, Thur = 4, Fri = 5, Sat = 6  
*/ 

#include <Wire.h>
#include <DS1307.h>

DS1307 rtc(SDA, SCL);

/* two dimentional array for holdinPing MAX6921 chip dataPinbyte values
   младший разряд начинается справа.
   Grid 1  Grid 2  Grid 3  Grid 4  Grid 5  Grid 6  Grid 7  Grid 8  Grid 9  Grid 10 Grid 11 Grid 12 
   OUT11    OUT10    OUT9    OUT8    OUT7    OUT6    OUT5    OUT4    OUT3    OUT2    OUT1   OUT0 
PIN  11       12       17     18      19      20      21      22      23      24      25      26
      
   seg. A  seg. B  seg. C  seg. D  seg. E  seg. F  seg. G  seg. DP
   OUT12   OUT13   OUT14   OUT15   OUT16   OUT17   OUT18   OUT19
PIN  10       9       8       7       6       5       4       3

*/
int rows = 0;
int columns = 0;
int clockPin = 5;
int loadPin = 6;
int dinPin = 4;
int dataPinRegister[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int offset;

//A B C D E F G,dp
int segmentArray[29][8]={
{ 1,1,1,1,1,1,0,0,  }, //0          
{ 0,1,1,0,0,0,0,0,  }, //1        
{ 1,1,0,1,1,0,1,0,  }, //2      
{ 1,1,1,1,0,0,1,0,  }, //3         
{ 0,1,1,0,0,1,1,0,  }, //4      
{ 1,0,1,1,0,1,1,0,  }, //5       
{ 1,0,1,1,1,1,1,0,  }, //6        
{ 1,1,1,0,0,0,0,0,  }, //7          
{ 1,1,1,1,1,1,1,0,  }, //8          
{ 1,1,1,1,0,1,1,0,  }, //9          
{ 1,1,1,1,1,1,0,1,  }, //0.          
{ 0,1,1,0,0,0,0,1,  }, //1.       
{ 1,1,0,1,1,0,1,1,  }, //2.      
{ 1,1,1,1,0,0,1,1,  }, //3.        
{ 0,1,1,0,0,1,1,1,  }, //4.     
{ 1,0,1,1,0,1,1,1,  }, //5.      
{ 1,0,1,1,1,1,1,1,  }, //6.       
{ 1,1,1,0,0,0,0,1,  }, //7.         
{ 1,1,1,1,1,1,1,1,  }, //8.          
{ 1,1,1,1,0,1,1,1,  }, //9.  
{ 0,0,0,0,0,0,1,0,  }, //-          
{ 1,0,0,1,1,1,0,0,  }, //C          
{ 1,0,0,0,1,1,1,0,  }, //F           
{ 1,1,0,0,1,1,1,0,  }, //P                            
{ 0,0,0,0,0,0,0,1,  }, //.
{ 1,1,0,0,0,1,1,0,  }, //Upper o             
{ 0,1,1,0,1,1,0,0,  }, // Slash   
{ 0,0,1,1,1,0,1,0,  }, //Lower o  
{ 0,0,0,0,0,0,0,0,  }}; // Blank  

char dayArray[7][10]={   
{ 'S','U','N','D','A','Y',' ',' ',' ',' '  }, //Sunday          
{ 'M','X','Z','N','D','A','Y',' ',' ',' '  }, //Monday M character into two parts using special X character    
{ 'T','U','E','S','D','A','Y',' ',' ',' '  }, //Tuesday       
{ 'W','V','E','D','N','E','S','D','A','Y'  }, //Wednesday W character into two parts using special V character   
{ 'T','H','U','R','S','D','A','Y',' ',' '  }, //Thursday   
{ 'F','R','I','D','A','Y',' ',' ',' ',' '  }, //Friday   
{ 'S','A','T','U','R','D','A','Y',' ',' '  }}; //Saturday    

 
/*
char key_matrix[4][4] = {
  {'1','4','7','*'},
  {'2','5','8','0'},
  {'3','6','9','#'},
  {'A','B','C','D'}
};
*/
// Set up the pins used for scanning.
// Don't use 0 or 1 (serial port)
uint8_t row_pins[4] = {5, 4, 3, 2};
uint8_t col_pins[4] = {9, 8, 7, 6};
//char key_pressed;
//int field_value;

// Instantiate a Keypad object.


//Specify digital pin on the Arduino that the positive lead of piezo buzzer is attached.
int piezoPin = 10;
int days = 11;
int months = 3;
int years = 19;
int new_days = 11;
int new_months = 3;
int new_years = 19;
int hours = 16;
int minutes = 11;
int seconds = 20;
int new_hours = 16;
int new_minutes = 11;
int new_seconds = 20;
int found, maxIndex;
int digits_entered = 0;
int alarm_hours = 0;
int alarm_minutes = 0;
int alarm_hours_check;
int alarm_minutes_check,alarmRequired;
int j,x,y,k,m,n,i,t,index,a,b;
int day_number, month_number, year1_number, year2_number,day_of_the_week, working_day;
char testChar;

String new_value_1, new_value_2;
String dayString;
String monthString;
String yearString;
String day1,day2;
String month1,month2;
String year1,year2,year3, year4;
String hourString;
String minuteString;
String secondString;
String hour1;
String minute1;
String second1;
String hour2;
String minute2;
String second2;
String year_string,date_string;
String timeString, dateString;
String characterArray[11]; // Character Array
//String humidityString;
//String humidityString1;
//String humidityString2;
//String pressureString;
//String pressureString1;
//String pressureString2;
//String temperatureCString;
//String temperatureCString1;
//String temperatureCString2;
//String temperatureFString;
//String temperatureFString1;
//String temperatureFString2;
//float pressure,temperatureC, temperatureF, humidity;

void setup()
{
  // initialize outputs for MAX6921 chip
  pinMode(dinPin, OUTPUT);
  pinMode(loadPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  digitalWrite(clockPin, LOW);
  digitalWrite(loadPin, LOW);
  digitalWrite(dinPin, LOW);
  
  Serial.begin(9600);
  rtc.begin();
    rtc.halt(false);

     // The following lines can be uncommented to set the time
 //  rtc.setDOW(MONDAY);        // Set Day-of-Week to SUNDAY
 //  rtc.setTime(22, 12, 0);     // Set the time to 12:00:00 (24hr format)
 //  rtc.setDate(2, 3, 2020);   // Set the date to October 3th, 2010
  
  working_day = 0;
  alarmRequired = 0;
  alarm_hours = 0;
  alarm_minutes = 0;  
   
  
}

void loop()
{
    // Display time for 30 seconds
    display_time();
   
    alarm_hours_check = hourString.toInt();
    alarm_minutes_check = minuteString.toInt();
    // check for alarm time and if alarm has been set 0 = No, 1 = Yes
    if (alarmRequired == 1)
       {
          if (alarm_hours_check == alarm_hours and alarm_minutes_check == alarm_minutes)
             {
                alarm();
             }
       }  

    for (t = 1; t <= 1400; t++) // equates to a display time of 30 seconds 1400
    {    
         
          display_time();  // Display time on VFD screen
    }
       
    // Display date    
    dayString = getValue(rtc.getDateStr(), '.', 0);
    display_date();  // Display date on VFD screen
    
    for (t = 1; t <= 400; t++) // equates to a display time of 5 seconds
    {         
       
          display_date();  // Display date on VFD screen
    }       
}

void alarm()
{

  for (b = 0; b <= 5; b++)
  {  
        /*Tone needs 2 arguments, but can take three
          1) Pin#
          2) Frequency - this is in hertz (cycles per second) which determines the pitch of the noise made
          3) Duration - how long teh tone plays
        */
        tone(piezoPin, 1000, 500);
        delay(500);
        tone(piezoPin, 750, 500);
        delay(500);   
      // display message
        for (t = 1; t <= 400; t++) 
        {              
          characterArray[9] = "W";
          characterArray[8] = "V"; 
          characterArray[7] = "A";
          characterArray[6] = "H"; 
          characterArray[5] = "E"; 
          characterArray[4] = " ";   
          characterArray[3] = "U"; 
          characterArray[2] = "P";   
          characterArray[1] = "!";
          characterArray[0] = " ";  
          process_display();
        }  
             
  }
}

 


void display_time()
{
  hourString = getValue(rtc.getTimeStr(), ':', 0);
  hour1 = hourString.substring(0,1);
  hour2 = hourString.substring(1,2);  
  minuteString = getValue(rtc.getTimeStr(), ':', 1);
  minute1 = minuteString.substring(0,1);
  minute2 = minuteString.substring(1,2);  
  secondString = getValue(rtc.getTimeStr(), ':', 2);
  second1 = secondString.substring(0,1);
  second2 = secondString.substring(1,2); 

  characterArray[9] = " ";
  characterArray[8] = " ";
  characterArray[7] = hour1;
  characterArray[6] = hour2; 
  characterArray[5] = ".";
  characterArray[4] = minute1; 
  characterArray[3] = minute2; 
  characterArray[2] = ".";   
  characterArray[1] = second1; 
  characterArray[0] = second2;   
   
  process_display();       
}

void display_date()
{
  day1 = dayString.substring(0,1);
  day2 = dayString.substring(1,2);  
  monthString = getValue(rtc.getDateStr(), '.', 1);
  month1 = monthString.substring(0,1);
  month2 = monthString.substring(1,2);  
  yearString = getValue(rtc.getDateStr(), '.', 2);
  year1 = yearString.substring(0,1);
  year2 = yearString.substring(1,2); 
  year3 = yearString.substring(2,3);
  year4 = yearString.substring(3,4); 
  
  characterArray[7] = day1;  
  characterArray[6] = day2;
  characterArray[5] = "-";
  characterArray[4] = month1; 
  characterArray[3] = month2;
  characterArray[2] = "-"; 
  characterArray[1] = year3;
  characterArray[0] = year4;
  characterArray[8] = " ";  
  characterArray[9] = " ";  
  process_display();
}


String getValue(String dataPin, char separator, int index)
{
    found = 0;
    int strIndex[] = { 0, -1 };
    maxIndex = dataPin.length() - 1;
    for (i = 0; i <= maxIndex && found <= index; i++) 
    {
        if (dataPin.charAt(i) == separator || i == maxIndex) 
        {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? dataPin.substring(strIndex[0], strIndex[1]) : "";
}

void write_loadPin()
{
    digitalWrite(loadPin, HIGH);
    digitalWrite(loadPin, LOW);  
}

void write_clockPin()
{
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW); 
}

void write_character()
{
  if(characterArray[9-offset] == "0")
    index = 0;
  if(characterArray[9-offset] == "1")
    index = 1;
  if(characterArray[9-offset] == "2")
    index = 2;
  if(characterArray[9-offset] == "3")
    index = 3;
  if(characterArray[9-offset] == "4")
    index = 4;
  if(characterArray[9-offset] == "5")
    index = 5;
  if(characterArray[9-offset] == "6")
    index = 6;                        
  if(characterArray[9-offset] == "7")
    index = 7;
  if(characterArray[9-offset] == "8")
    index = 8;
  if(characterArray[9-offset] == "9")
    index = 9; 
  if(characterArray[9-offset] == "0.")
    index = 10;
  if(characterArray[9-offset] == "1.")
    index = 11;
  if(characterArray[9-offset] == "2.")
    index = 12;
  if(characterArray[9-offset] == "3.")
    index = 13;
  if(characterArray[9-offset] == "4.")
    index = 14;
  if(characterArray[9-offset] == "5.")
    index = 15;
  if(characterArray[9-offset] == "6.")
    index = 16;                        
  if(characterArray[9-offset] == "7.")
    index = 17;
  if(characterArray[9-offset] == "8.")
    index = 18;
  if(characterArray[9-offset] == "9.")
    index = 19;     
  if(characterArray[9-offset] == "-")
    index = 20;
  if(characterArray[9-offset] == "C")
    index = 21;
  if(characterArray[9-offset] == "F")
    index = 22;
  if(characterArray[9-offset] == "P")
    index = 23;
  if(characterArray[9-offset] == ".")
    index = 24;
  if(characterArray[9-offset] == "O")
    index = 25;                        
  if(characterArray[9-offset] == "/")
    index = 26;
  if(characterArray[9-offset] == "o")
    index = 27;
  if(characterArray[9-offset] == " ")
    index = 28;
  if(characterArray[9-offset] == "D")
    index = 29;
  if(characterArray[9-offset] == "A")
    index = 30;
  if(characterArray[9-offset] == "Y")
    index = 31;
  if(characterArray[9-offset] == "M") // first part of M character
    index = 32;
  if(characterArray[9-offset] == "X") // second part of M character
    index = 33;
  if(characterArray[9-offset] == "N")
    index = 34;                        
  if(characterArray[9-offset] == "T")
    index = 35;
  if(characterArray[9-offset] == "U")
    index = 36;
  if(characterArray[9-offset] == "E")
    index = 37; 
  if(characterArray[9-offset] == "S")
    index = 38;
  if(characterArray[9-offset] == "W") // first part of W character
    index = 39;
  if(characterArray[9-offset] == "V") // second part of W character
    index = 40;
  if(characterArray[9-offset] == "H")
    index = 41;
  if(characterArray[9-offset] == "R")
    index = 42;
  if(characterArray[9-offset] == "Z")
    index = 43;
  if(characterArray[9-offset] == "I")
    index = 44;                    
  if(characterArray[9-offset] == "!")
    index = 45; 
}

void process_display()
{
    for (offset = 9; offset >= 0; offset--)
    {
      write_character();
      write_clockPin();      
      for (i = 19; i >= 0; i--)
      {
        if (i >= 12)
        {
          dataPinRegister[i] = segmentArray[index][i-12]; 
        }
        digitalWrite(dinPin, dataPinRegister[i]);         
        write_clockPin();
      } 
      write_loadPin();
      dataPinRegister[offset] = 0;
      if (offset != 0)
          dataPinRegister[offset-1] = 1; 
      else
          dataPinRegister[9] = 1;
      delay(1);   
    }
}
