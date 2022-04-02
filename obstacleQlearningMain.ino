
//initialise motor ,sensor variables



int in1 = 8;
int in2 = 7;
int in3 = 5;
int in4 = 4;

int trig = 10;
int echo = 12;
int duration;
float distance;

bool Obstacle = false;
int FLAG;
//END//

//adding Q learnig values//
float ALPHA = 0.1;    //
float GAMMA = 0.5;    //
float EPSILON = 0.90;  //
int REWARD;           //
int EPISODES  = 100;

int STATE;                        // 
int ACTION = 0;                   //
float PROB;                       //
bool ACTION_TAKEN = false;        //
int NEXT_STATE;                   // 
const int STATES = 10;            //
int ACTIONS[4] = {1,2,3,4};
const int NUMBER_OF_ACTIONS = 4; //



float Q[STATES][NUMBER_OF_ACTIONS] = {{0.0,0.0,0.0,0.0},  
                                      {0.0,0.0,0.0,0.0},  
                                      {0.0,0.0,0.0,0.0},  
                                      {0.0,0.0,0.0,0.0},  
                                      {0.0,0.0,0.0,0.0},  
                                      {0.0,0.0,0.0,0.0},
                                      {0.0,0.0,0.0,0.0},
                                      {0.0,0.0,0.0,0.0},
                                      {0.0,0.0,0.0,0.0},
                                      {0.0,0.0,0.0,0.0}};



int REWARDS[STATES][NUMBER_OF_ACTIONS] = {{-10,-2,-1,10}, 
                                          {-10,-2,-1,10}, 
                                          {-10,-2,-1,10}, 
                                          {-10,-2,-1,10},  
                                          {-10,-2,-1,10},
                                          {-10,-2,-1,10},
                                          {-10,-2,-1,10},
                                          {-10,-2,-1,10},
                                          {-10,-2,-1,10},
                                          {-10,-2,-1,10}};            

float Q_OLD;
float Q_NEW;
float Q_MAX;


void setup() 
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);  
  randomSeed(analogRead(A0));
  STATE = 0;
  Serial.println("TRAINING WILL START IN 5 SECONDS:  ");
  delay(5000);
} 


void Forward()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH); 
}
