

inline float anglecalcy(float x1,float x2,float y1,float y2)  //everything is inline because fuck you thats why
{
  if(atan2((y2-y1),(x2-x1))<0)
  {
    return 360 + ( 57.3*atan2((y2-y1),(x2-x1)) );
  }
  return 57.3*atan2((y2-y1),(x2-x1));    //angle that the line makes with EW axis 
}

inline float distancecalcy(float y1,float y2,float x1,float x2,int i)
{
  if(i==1)
  {
    return  111692.84*sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));   //distance between 2 points
  }
  else
  {
    return sqrt(((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)));    //distance directly in meters when input is in meters
  }
}

inline float mod(float a)  //taking mod of a number
{
  return sqrt(a*a);
}


inline float gpsOpFlowKalman(float gpscord,float gpsError,float estimate,uint8_t trustInEstimate)   //used in localization tab
{
  estimateError=float(30.0/trustInEstimate);     //biasing was changed to 30 on 1/4/17
  estimateError*=estimateError; //squaring the estimate error because i want the trust to rise very quickly if surface quality is good and fall very quickly if it is lower than 20)
  KG=(estimateError/(estimateError+gpsError));
  return (KG*gpscord+(1-KG)*estimate);  
}

inline float depress(float a,float k)               //used to depress accelgyro values
{
  return (a*a*a*a)/(k+a*a*a*a);
}
