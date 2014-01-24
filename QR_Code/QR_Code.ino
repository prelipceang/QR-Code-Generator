/*
This program takes the current time & displays it as an QR code
 So far this program is capable of converting numbers 0-9, & 
 characters : and (space) into QR code format. Then displays 
 that information as a QR code on the screen.
 */
#include <stdint.h>
#include <UTFT.h>
#include <UTouch.h>

#define YP 38   // must be an analog pin, use "An" notation!
#define XM 39   // must be an analog pin, use "An" notation!
#define YM 40   // can be a digital pin, this is A0
#define XP 41   // can be a digital pin, this is A3 

// Declare which fonts we will be using
extern uint8_t SmallFont[];
extern uint8_t BigFont[];
extern uint8_t Dingbats1_XL[];

//Set to true to enable serial debug information
boolean debug = true;

/*
Log/Anti-Log table used to switch between integer notation
 and alpha notation when performing arithmetic to calculate
 ecc bits. Arduino supports log functions but does not work
 in the same way as this table does.
 */

unsigned int LogTable[255][4] = {
  {
    1,2,1,0  }
  ,
  {
    2,4,2,1  }
  ,
  {
    3,8,3,25  }
  ,
  {
    4,16,4,2  }
  ,
  {
    5,32,5,50  }
  ,
  {
    6,64,6,26  }
  ,
  {
    7,128,7,198  }
  ,
  {
    8,29,8,3  }
  ,
  {
    9,58,9,223  }
  ,
  {
    10,116,10,51  }
  ,
  {
    11,232,11,238  }
  ,
  {
    12,205,12,27  }
  ,
  {
    13,135,13,104  }
  ,
  {
    14,19,14,199  }
  ,
  {
    15,38,15,75  }
  ,
  {
    16,76,16,4  }
  ,
  {
    17,152,17,100  }
  ,
  {
    18,45,18,224  }
  ,
  {
    19,90,19,14  }
  ,
  {
    20,180,20,52  }
  ,
  {
    21,117,21,141  }
  ,
  {
    22,234,22,239  }
  ,
  {
    23,201,23,129  }
  ,
  {
    24,143,24,28  }
  ,
  {
    25,3,25,193  }
  ,
  {
    26,6,26,105  }
  ,
  {
    27,12,27,248  }
  ,
  {
    28,24,28,200  }
  ,
  {
    29,48,29,8  }
  ,
  {
    30,96,30,76  }
  ,
  {
    31,192,31,113  }
  ,
  {
    32,157,32,5  }
  ,
  {
    33,39,33,138  }
  ,
  {
    34,78,34,101  }
  ,  
  {
    35,156,35,47  }
  ,
  {
    36,37,36,225  }
  ,
  {
    37,74,37,36  }
  ,
  {
    38,148,38,15  }
  ,
  {
    39,53,39,33  }
  ,
  {
    40,106,40,53  }
  ,
  {
    41,212,41,147  }
  ,
  {
    42,181,42,142  }
  ,
  {
    43,119,43,218  }
  ,
  {
    44,238,44,240  }
  ,
  {
    45,193,45,18  }
  ,
  {
    46,159,46,130  }
  ,
  {
    47,35,47,69  }
  ,
  {
    48,70,48,29  }
  ,
  {
    49,140,49,181  }
  ,
  {
    50,5,50,194  }
  ,
  {
    51,10,51,125  }
  ,
  {
    52,20,52,106  }
  ,
  {
    53,40,53,39  }
  ,
  {
    54,80,54,249  }
  ,
  {
    55,160,55,185  }
  ,
  {
    56,93,56,201  }
  ,
  {
    57,186,57,154  }
  ,
  {
    58,105,58,9  }
  ,
  {
    59,210,59,120  }
  ,
  {
    60,185,60,77  }
  ,
  {
    61,111,61,228  }
  ,
  {
    62,222,62,114  }
  ,
  {
    63,161,63,166  }
  ,
  {
    64,95,64,6  }
  ,
  {
    65,190,65,191  }
  ,
  {
    66,97,66,139  }
  ,
  {
    67,194,67,98  }
  ,
  {
    68,153,68,102  }
  ,
  {
    69,47,69,221  }
  ,
  {
    70,94,70,48  }
  ,
  {
    71,188,71,253  }
  ,
  {
    72,101,72,226  }
  ,
  {
    73,202,73,152  }
  ,
  {
    74,137,74,37  }
  ,
  {
    75,15,75,179  }
  ,
  {
    76,30,76,16  }
  ,
  {
    77,60,77,145  }
  ,
  {
    78,120,78,34  }
  ,
  {
    79,240,79,136  }
  ,
  {
    80,253,80,54  }
  ,
  {
    81,231,81,208  }
  ,
  {
    82,211,82,148  }
  ,
  {
    83,187,83,206  }
  ,
  {
    84,107,84,143  }
  ,
  {
    85,214,85,150  }
  ,
  {
    86,177,86,219  }
  ,
  {
    87,127,87,189  }
  ,
  {
    88,254,88,241  }
  ,
  {
    89,225,89,210  }
  ,
  {
    90,223,90,19  }
  ,
  {
    91,163,91,92  }
  ,
  {
    92,91,92,131  }
  ,
  {
    93,182,93,56  }
  ,
  {
    94,113,94,70  }
  ,
  {
    95,226,95,64  }
  ,
  {
    96,217,96,30  }
  ,
  {
    97,175,97,66  }
  ,
  {
    98,67,98,182  }
  ,
  {
    99,134,99,163  }
  ,
  {
    100,17,100,195  }
  ,
  {
    101,34,101,72  }
  ,
  {
    102,68,102,126  }
  ,
  {
    103,136,103,110  }
  ,
  {
    104,13,104,107  }
  ,
  {
    105,26,105,58  }
  ,
  {
    106,52,106,40  }
  ,
  {
    107,104,107,84  }
  ,
  {
    108,208,108,250  }
  ,
  {
    109,189,109,133  }
  ,
  {
    110,103,110,186  }
  ,
  {
    111,206,111,61  }
  ,
  {
    112,129,112,202  }
  ,
  {
    113,31,113,94  }
  ,
  {
    114,62,114,155  }
  ,
  {
    115,124,115,159  }
  ,
  {
    116,248,116,10  }
  ,
  {
    117,237,117,21  }
  ,
  {
    118,199,118,121  }
  ,
  {
    119,147,119,43  }
  ,
  {
    120,59,120,78  }
  ,  
  {
    121,118,121,212  }
  ,
  {
    122,236,122,229  }
  ,
  {
    123,197,123,172  }
  ,
  {
    124,151,124,115  }
  ,
  {
    125,51,125,243  }
  ,
  {
    126,102,126,167  }
  ,
  {
    127,204,127,87  }
  ,
  {
    128,133,128,7  }
  ,
  {
    129,23,129,112  }
  ,  
  {
    130,46,130,192  }
  ,
  {
    131,92,131,247  }
  ,
  {
    132,184,132,140  }
  ,
  {
    133,109,133,128  }
  ,
  {
    134,218,134,99  }
  ,  
  {
    135,169,135,13  }
  ,  
  {
    136,79,136,103  }
  ,
  {
    137,158,137,74  }
  ,
  {
    138,33,138,222  }
  ,
  {
    139,66,139,237  }
  ,
  {
    140,132,140,49  }
  ,
  {
    141,21,141,197  }
  ,
  {
    142,42,142,254  }
  ,
  {
    143,84,143,24  }
  ,
  {
    144,168,144,227  }
  ,
  {
    145,77,145,165  }
  ,
  {
    146,154,146,153  }
  ,
  {
    147,41,147,119  }
  ,
  {
    148,82,148,38  }
  ,
  {
    149,164,149,184  }
  ,
  {
    150,85,150,180  }
  ,
  {
    151,170,151,124  }
  ,
  {
    152,73,152,17  }
  ,
  {
    153,146,153,68  }
  ,
  {
    154,57,154,146  }
  ,
  {
    155,114,155,217  }
  ,
  {
    156,228,156,35  }
  ,
  {
    157,213,157,32  }
  ,
  {
    158,183,158,137  }
  ,
  {
    159,115,159,46  }
  ,
  {
    160,230,160,55  }
  ,
  {
    161,209,161,63  }
  ,
  {
    162,191,162,209  }
  ,
  {
    163,99,163,91  }
  ,
  {
    164,198,164,149  }
  ,
  {
    165,145,165,188  }
  ,
  {
    166,63,166,207  }
  ,
  {
    167,126,167,205  }
  ,
  {
    168,252,168,144  }
  ,
  {
    169,229,169,135  }
  ,
  {
    170,215,170,151  }
  ,
  {
    171,179,171,178  }
  ,
  {
    172,123,172,220  }
  ,
  {
    173,246,173,252  }
  ,
  {
    174,241,174,190  }
  ,
  {
    175,255,175,97  }
  ,
  {
    176,227,176,242  }
  ,
  {
    177,219,177,86  }
  ,
  {
    178,171,178,211  }
  ,
  {
    179,75,179,171  }
  ,
  {
    180,150,180,20  }
  ,
  {
    181,49,181,42  }
  ,
  {
    182,98,182,93  }
  ,
  {
    183,196,183,158  }
  ,
  {
    184,149,184,132  }
  ,
  {
    185,55,185,60  }
  ,
  {
    186,110,186,57  }
  ,
  {
    187,220,187,83  }
  ,
  {
    188,165,188,71  }
  ,
  {
    189,87,189,109  }
  ,
  {
    190,174,190,65  }
  ,
  {
    191,65,191,162  }
  ,
  {
    192,130,192,31  }
  ,
  {
    193,25,193,45  }
  ,
  {
    194,50,194,67  }
  ,
  {
    195,100,195,216  }
  ,
  {
    196,200,196,183  }
  ,
  {
    197,141,197,123  }
  ,
  {
    198,7,198,164  }
  ,
  {
    199,14,199,118  }
  ,
  {
    200,28,200,196  }
  ,
  {
    201,56,201,23  }
  ,
  {
    202,112,202,73  }
  ,
  {
    203,224,203,236  }
  ,
  {
    204,221,204,127  }
  ,
  {
    205,167,205,12  }
  ,
  {
    206,83,206,111  }
  ,
  {
    207,166,207,246  }
  ,
  {
    208,81,208,108  }
  ,
  {
    209,162,209,161  }
  ,
  {
    210,89,210,59  }
  ,
  {
    211,178,211,82  }
  ,
  {
    212,121,212,41  }
  ,
  {
    213,242,213,157  }
  ,
  {
    214,249,214,85  }
  ,
  {
    215,239,215,170  }
  ,
  {
    216,195,216,251  }
  ,
  {
    217,155,217,96  }
  ,
  {
    218,43,218,134  }
  ,
  {
    219,86,219,177  }
  ,
  {
    220,172,220,187  }
  ,
  {
    221,69,221,204  }
  ,
  {
    222,138,222,62  }
  ,
  {
    223,9,223,90  }
  ,
  {
    224,18,224,203  }
  ,
  {
    225,36,225,89  }
  ,
  {
    226,72,226,95  }
  ,
  {
    227,144,227,176  }
  ,
  {
    228,61,228,156  }
  ,
  {
    229,122,229,169  }
  ,
  {
    230,244,230,160  }
  ,
  {
    231,245,231,81  }
  ,
  {
    232,247,232,11  }
  ,
  {
    233,243,233,245  }
  ,
  {
    234,251,234,22  }
  ,
  {
    235,235,235,235  }
  ,
  {
    236,203,236,122  }
  ,
  {
    237,139,237,117  }
  ,
  {
    238,11,238,44  }
  ,
  {
    239,22,239,215  }
  ,
  {
    240,44,240,79  }
  , 
  {
    241,88,241,174  }
  ,
  {
    242,176,242,213  }
  ,
  {
    243,125,243,233  }
  ,
  {
    244,250,244,230  }
  ,
  {
    245,233,245,231  }
  ,
  {
    246,207,246,173  }
  ,
  {
    247,131,247,232  }
  ,
  {
    248,27,248,116  }
  ,
  {
    249,54,249,214  }
  ,
  {
    250,108,250,244  }
  ,
  {
    251,216,251,234  }
  ,
  {
    252,173,252,168  }
  ,
  {
    253,71,253,80  }
  ,
  {
    254,142,254,88  }
  ,
  {
    255,1,255,175  }
};

//Type infomation bits encode the mask used, ecc level, ect.
unsigned int TypeInfomationBits[15] = {
  0,1,1,0,1,0,1,0,1,0,1,1,1,1,1};
//Message in binary to be displayed 
unsigned int BinaryMessage[104] = {
};
//Binary ECC data to be displayed
unsigned int BinaryECCWords[104] = {
};
//Array to hold Message in Integer format (used in arithmetic)
unsigned int MessageI[13] = {
};
//Array to hold Message in Alpha Notation (used in arithmetic)
unsigned int MessageA[13] = {
};
//Generator Polynomial data to perform calculations
unsigned int GeneratorA[14] = {
  0,74,152,176,100,86,100,106,104,130,218,206,140,78};
//Result from XOR operation (used in arithmetic)
unsigned int xorResult[15] = {
};
//Result from arithmitic
unsigned int Result[15] = {
};

//ECC words in binary
String eccBinary = "";
//All the binary data is appended into dataString
String dataString = "";
//Then transfered to byteMessage
String byteMessage = "";
//Message that we hope to convert
String messageToEncode = "";
//dataString length
int length = 0;
//byte counter
int byteCounter = 0;
//Coefficients of binary data
int coefficients[13];
//First Term Exponent
int exponent = 25;
//Used to remove zeros from XOR results
boolean zeroFound = false;
//x & y position for binary data used for masking
int x = 1;
int y = 1;
//Start position for binary data
int xPos = 0;
int yPos = 0;
//Keeps track of data displayed
int counter = 0;

#define TS_MINX 140 
#define TS_MAXX 900
#define TS_MINY 120
#define TS_MAXY 940

//TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300); //init TouchScreen port pins

UTFT          myGLCD(ITDB32S,38,39,40,41);
UTouch        myTouch(6,5,4,3,2);

void setup()
{
  myGLCD.InitLCD(PORTRAIT);
  myGLCD.clrScr();

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_HI);
  myGLCD.fillScr(255, 255, 255);
  //Paint background white
  //Generate data used for QR
  calculateQRCode();
  //Draw base QR code
  drawTemplate(myGLCD);
  //Fill in data bits
  informationBits(myGLCD);
  

}

void loop()
{

}


