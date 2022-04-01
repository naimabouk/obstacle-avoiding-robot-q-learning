
//



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
/////////////////////////END/////////////////////////////

/////////////////////////////////////Q LEARNING PARAMETERS///////////////////////////////////////////

float ALPHA = 0.1;    //LEARNING RATE
float GAMMA = 0.5;    //DISCOUNT FACTOR
float EPSILON = 0.90;  //EXPLORATION PARAMETER
int REWARD;           //REWARD FOR PERFORMING AN ACTION
int EPISODES  = 100;

int STATE;                        // CURRENT STATE OF THE ROBOT
int ACTION = 0;                   //ACTION PERFORMED BY THE ROBOT(0:FORWARD,1:BACKWARD ,2;STOP,3:LEFT)
float PROB;                       //USED FOR EPSILON DECAY 
bool ACTION_TAKEN = false;        //THIS VARIABLES TELLS US WHETHER AN ACTION IS TAKEN OR NOT
int NEXT_STATE;                   // NEXT STATE OF THE ROBOT
const int STATES = 10;            //NUMBER OF STATES IN ENVIRONMENT 
int ACTIONS[4] = {1,2,3,4};
const int NUMBER_OF_ACTIONS = 4; //TOTAL WE HAVE 4 ACTION FORWARD,BACKWARD,LEFT AND STOP


/*THIS IS THE Q MATRIX OR Q TABLE. THIS IS BASICALLY THE DIARY THAT ROBOT WILL LOOK INTO 
BEFORE PERFORMING AN ACTION.BASED ON THE ACTION THE ROBOT WILL EARN REWARD AND THE Q VALUE 
WILL BE UPDATED IN THIS Q TABLE. HERE I HAVE CONISDERED 10 STATES. I HAVE ASSUMED ALL STATES 
ARE DIFFERENT EVEN THOUGH THEY ARE SAME.BASICALLY OBSTACLE AVOIDING ROBOT CONTAINS ONLY TWO STATES
i.e: 
1:WHEN ITS AWAY FROM OBSTACLE 
2:WHEN ITS NEAR TO THE OBSTACLE
BUT HERE TO ILLUSTRATE MORE COMPLEX ENVIRONMENT I HAVE ASSUMED THERE ARE 10 DIFFERENT STATES HERE
EXPECTING SAME/DIFFERENT ACTION.*/

float Q[STATES][NUMBER_OF_ACTIONS] = {{0.0,0.0,0.0,0.0},  //MOST IMPORTANT OF ALL IS THE Q TABLE.
                                      {0.0,0.0,0.0,0.0},  //IT IS FORMED BY STATES AS ITS  ROWS 
                                      {0.0,0.0,0.0,0.0},  //AND COLLUMNS AS ITS NUMBER OF ACTIONS
                                      {0.0,0.0,0.0,0.0},  //INITIALISED TO ZERO IN THE START
                                      {0.0,0.0,0.0,0.0},  // THIS WILL UPDATED IN THE FUTURE.
                                      {0.0,0.0,0.0,0.0},
                                      {0.0,0.0,0.0,0.0},
                                      {0.0,0.0,0.0,0.0},
                                      {0.0,0.0,0.0,0.0},
                                      {0.0,0.0,0.0,0.0}};

/*THIS IS A REWARD MATRIX OR REWARD TABLE. THIS IS RESPONSIBLE FOR GIVING
REWARD TO ROBOT FOR PERFORMING PARTICULAR ACTION. IT STORES THE REWARD FOR 
EACH ACTION TAKEN AT STATE. THE REWARD WILL BE POSITIVE IF THE ACTION 
PERFORMED IS GOOD AND NEGATIVE IF ACTION YIELDS BAD RESULTS.*/

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
////////////////////////////////////////////END///////////////////////////////////////////////////

////////////////Q LEARNING UPDATE PARAMETERS////////////
float Q_OLD;
float Q_NEW;
float Q_MAX;
//////////////////////////END//////////////////////////

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

////////////////////////////ROBOT'S FUNCTIONS/////////////////////////////////
void Forward()
{
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH); 
}
