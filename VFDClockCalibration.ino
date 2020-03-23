/* VFD Clock Calibration tests
Last Updated: 18-05-19
*/
int clk = 43;
int load = 45;
int din = 47;
/*
int g1[20] = {0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1}; // Grid 1
int g2[20] = {0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1}; // Grid 2
int g3[20] = {0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1}; // Grid 3 
int g4[20] = {0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1}; // Grid 4
int g5[20] = {0,0,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,1,1}; // Grid 5
int g6[20] = {0,0,0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,1}; // Grid 6
int g7[20] = {0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1}; // Grid 7
int g8[20] = {0,0,0,0,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1}; // Grid 8
int g9[20] = {0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1}; // Grid 9
int g10[20] = {0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1}; // Grid 10
int g11[20] = {0,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1}; // Grid 11
int g12[20] = {1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1}; // Grid 12
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // Blank

int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}; //Segment dp
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0}; //Segment "d"
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0}; //Segment "c"
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0}; //Segment "e"
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0}; //Segment "g"
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0}; //Segment "b"
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0}; //Segment "f"
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0}; //Segment "a"
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,1,1,0}; // zero
int b[20] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0}; // one
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1,0}; // two
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,0}; // three
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,0}; // four
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,1,1,0}; // five
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,0}; // six
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,1,0,0}; // seven
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0}; // eight
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0}; // nine
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0}; // dash
int a[20] = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}; // dot 
int a[20] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}; // all

int a[20] = {0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,1,1,1,0}; // zero
int b[20] = {0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,0,0}; // one
int c[20] = {0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,1,1,0,1,0}; // two
int d[20] = {0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,1,0,1,1,0}; // three
int e[20] = {0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,1,0,0}; // four
int f[20] = {0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0,1,1,0}; // five
int g[20] = {0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,1,1,1,0}; // six
int h[20] = {0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0,0}; // seven
int j[20] = {0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0}; // eight
           int k[20] = {0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,0,1,0,0}; // nine
*/
int dataRegister[20] = {0,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,0};
char value;
String characterArray[11]; /// Character Array
int index = 0;

int gridArray[13][12]={
{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  },  // Grid 1        
{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  },  // Grid 2       
{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  },  // Grid 3     
{ 0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  },  // Grid 4         
{ 0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  },  // Grid 5    
{ 0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  },  // Grid 6     
{ 0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  },  // Grid 7       
{ 0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  },  // Grid 8         
{ 0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  },  // Grid 9         
{ 0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  },  // Grid 10         
{ 0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  },  // Grid 11         
{ 1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  },  // Grid 12
{ 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  }}; // All grids off

// all need fixing
int segmentArray[29][8]={
{ 1,1,1,0,1,1,1,0,  }, //0          
{ 0,0,1,0,0,1,0,0,  }, //1        
{ 1,0,1,1,1,0,1,0,  }, //2      
{ 1,0,1,1,0,1,1,0,  }, //3         
{ 0,1,1,1,0,1,0,0,  }, //4      
{ 1,1,0,1,0,1,1,0,  }, //5       
{ 1,1,0,1,1,1,1,0,  }, //6        
{ 1,0,1,0,0,1,0,0,  }, //7          
{ 1,1,1,1,1,1,1,0,  }, //8          
{ 1,1,1,1,0,1,0,0,  }, //9          
{ 1,1,1,0,1,1,1,1,  }, //0.          
{ 0,0,1,0,0,1,0,1,  }, //1.       
{ 1,0,1,1,1,0,1,1,  }, //2.      
{ 1,0,1,1,0,1,1,1,  }, //3.        
{ 0,1,1,1,0,1,0,1,  }, //4.     
{ 1,1,0,1,0,1,1,1,  }, //5.      
{ 1,1,0,1,1,1,1,1,  }, //6.       
{ 1,0,1,0,0,1,0,1,  }, //7.         
{ 1,1,1,1,1,1,1,1,  }, //8.          
{ 1,1,1,1,0,1,0,1,  }, //9.  
{ 0,0,0,1,0,0,0,0,  }, //-          
{ 1,1,0,0,1,0,1,0,  }, //C          
{ 1,1,0,1,1,0,0,0,  }, //F           
{ 1,1,1,1,1,0,0,0,  }, //P                            
{ 0,0,0,0,0,0,0,1,  }, //.
{ 1,1,1,1,0,0,0,0,  }, //Upper o             
{ 0,0,1,1,1,0,0,0,  }, // Slash   
{ 0,0,0,1,1,1,1,0,  }, //Lower o  
{ 0,0,0,0,0,0,0,0,  }}; // Blank  

int k = 0;
int offset = 1;
 
void setup() {
  Serial.begin(9600);
  pinMode(din, OUTPUT);
  pinMode(load, OUTPUT);
  pinMode(clk, OUTPUT);
  digitalWrite(clk, LOW);
  digitalWrite(load, LOW);
  digitalWrite(din, LOW); 
  
  characterArray[0] = "1";
  characterArray[1] = "7";
  characterArray[2] = "-";  
  characterArray[3] = "0";  
  characterArray[4] = "5";
  characterArray[5] = "-";
  characterArray[6] = "2";  
  characterArray[7] = "0";  
  characterArray[8] = "1";
  characterArray[9] = "9"; 
    
//  characterArray[0] = "1";
//  characterArray[1] = "9";
//  characterArray[2] = ".";  
//  characterArray[3] = "3";  
//  characterArray[4] = "4";
//  characterArray[5] = ".";
//  characterArray[6] = "2";  
//  characterArray[7] = "0";  
//  characterArray[8] = " ";
//  characterArray[9] = " "; 

//  characterArray[0] = "1";
//  characterArray[1] = "0";
//  characterArray[2] = "3";  
//  characterArray[3] = "4";  
//  characterArray[4] = ".";
//  characterArray[5] = "2";
//  characterArray[6] = "0";  
//  characterArray[7] = " ";  
//  characterArray[8] = "P";
//  characterArray[9] = " "; 

//  characterArray[0] = " ";
//  characterArray[1] = "2";
//  characterArray[2] = "4";  
//  characterArray[3] = ".";  
//  characterArray[4] = "2";
//  characterArray[5] = "0";
//  characterArray[6] = " ";  
//  characterArray[7] = "O";  
//  characterArray[8] = "F";
//  characterArray[9] = " "; 

//  characterArray[0] = " ";
//  characterArray[1] = "7";
//  characterArray[2] = "9";  
//  characterArray[3] = ".";  
//  characterArray[4] = "4";
//  characterArray[5] = "5";
//  characterArray[6] = " ";  
//  characterArray[7] = "O";  
//  characterArray[8] = "C";
//  characterArray[9] = " "; 

//
//  characterArray[0] = "4";
//  characterArray[1] = "5";
//  characterArray[2] = ".";  
//  characterArray[3] = "3";  
//  characterArray[4] = "0";
//  characterArray[5] = " ";
//  characterArray[6] = "o";  
//  characterArray[7] = "/";  
//  characterArray[8] = "O";
//  characterArray[9] = " "; 
}
 
void write_load()
{
    digitalWrite(load, HIGH);
//    delay(10); // slows down display to show individual characters being displayed.
    digitalWrite(load, LOW);  
}
void write_clk()
{
    digitalWrite(clk, HIGH);
    digitalWrite(clk, LOW); 
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
}

void loop() 
{

// Start of test 2

//  Display routine, displays upto 10 characters from array onto IV-27M   
    for (offset = 9; offset >= 0; offset--)
    {
      write_character();
      write_clk();      
      for (int i = 19; i >= 0; i--)
      {
        if (i >= 12)
        {
          dataRegister[i] = segmentArray[index][i-12]; 
        }
        digitalWrite(din, dataRegister[i]);         
        write_clk();
      } 
      write_load();
      dataRegister[offset] = 0;
      if (offset != 0)
      {
          dataRegister[offset-1] = 1; 
      } else
          dataRegister[9] = 1;   
} 
                      
// end of test 2


// Start of Test 1
/*
 for (offset = 9; offset >=0; offset--) // 9 and 2
 {
  digitalWrite(clk, LOW);       
  for (int i = 19; i >= 0; i--)
  {
    digitalWrite(din, a[i]);         
    write_clk();
  } 
  write_load();
  a[offset] = 0;
  if (offset != 0)
  {
      a[offset-1] = 1; 
  }
  for (int i = 19; i >= 0; i--)
  {
    digitalWrite(din, b[i]);         
    write_clk();
  } 
  write_load(); 
  b[offset] = 0;
  if (offset != 0)
  {
    b[offset-1] = 1; 
  }   
  for (int i = 19; i >= 0; i--)
  {
    digitalWrite(din, c[i]);         
    write_clk();
  } 
  write_load();
  c[offset] = 0;
  if (offset != 0)
  {
    c[offset-1] = 1;  
  }
  for (int i = 19; i >= 0; i--)
  {
    digitalWrite(din, d[i]);         
    write_clk();
  } 
  write_load(); 
  d[offset] = 0;
  if (offset != 0)
  {  
    d[offset-1] = 1;
  }     
  for (int i = 19; i >= 0; i--)
  {
    digitalWrite(din, e[i]);         
    write_clk();
  } 
  write_load();  
  e[offset] = 0;
  if (offset != 0)
  {  
    e[offset-1] = 1;  
  }  
  for (int i = 19; i >= 0; i--)
  {
    digitalWrite(din, f[i]);         
    write_clk();
  } 
  write_load();
  f[offset] = 0;
  if (offset != 0)
  {  
    f[offset-1] = 1;    
  }
  for (int i = 19; i >= 0; i--)
  {
    digitalWrite(din, g[i]);         
    write_clk();
  } 
  write_load(); 
  g[offset] = 0; 
  if (offset != 0)
  {  
    g[offset-1] = 1;   
  }
  for (int i = 19; i >= 0; i--)
  {
    digitalWrite(din, h[i]);         
    write_clk();
  } 
  write_load(); 
  h[offset] = 0;
  if (offset != 0)
  {  
    h[offset-1] = 1;  
  }
  for (int i = 19; i >= 0; i--)
  {
    digitalWrite(din, j[i]);         
    write_clk();
  } 
  write_load();  
  j[offset] = 0;
  if (offset != 0)
  {  
    j[offset-1] = 1;  
  }
  for (int i = 19; i >= 0; i--)
  {
    digitalWrite(din, k[i]);         
    write_clk();
  } 
  write_load();
  
  k[offset] = 0;
  if (offset != 0)
  {  
    k[offset-1] = 1;  
  }
 }
 a[0] = 0;
 b[0] = 0;
 c[0] = 0;
 d[0] = 0;
 e[0] = 0;
 f[0] = 0;
 g[0] = 0;
 h[0] = 0;
 j[0] = 0;        
 k[0] = 0; //1
   
 a[9] = 1; 
 b[9] = 1;
 c[9] = 1;
 d[9] = 1;
 e[9] = 1;
 f[9] = 1;
 g[9] = 1;
 h[9] = 1;
 j[9] = 1;        
 k[9] = 1; //9
*/
// end of test 1

//  delay(200);
//  k = k + 1;
//  if (k > 19) k = 0;
}
