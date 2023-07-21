#include <Adafruit_BNO08x.h>

#include <ros.h>
#include <std_msgs/Float32MultiArray.h>

#define BNO08x_RESET -1 // Not needed for I2C

Adafruit_BNO08x bno08x(BNO08x_RESET);
sh2_SensorValue_t sensorValue;

ros::NodeHandle node_handle;
std_msgs::Float32MultiArray accelerometer_msg;
ros::Publisher accelerometer_publisher("accelerometer", &accelerometer_msg);

void setup() {
  
  Serial.begin(115200);
  while(!Serial) delay(10);

  if(!bno08x.begin_I2C()){
    Serial.println("Failed to find BNO08x chip");
    for(;;);
  }

  Serial.println("I2C channel opened");

  enable_sensors();

  node_handle.initNode();
  node_handle.advertise(accelerometer_publisher);
}

void enable_sensors(){
  if(!bno08x.enableReport(SH2_ACCELEROMETER)) Serial.println("Failed to enable accelerometer");
  //if(!bno08x.enableReport(SH2_GYROSCOPE_CALIBRATED)) Serial.println("Failed to enable gyroscope");
}

void loop() {
  delay(100);

  if (bno08x.wasReset()) {
    Serial.print("sensor was reset ");
    enable_sensors();
  }

  if (! bno08x.getSensorEvent(&sensorValue)) {
    return;
  }
  
  switch (sensorValue.sensorId) {
    case SH2_ACCELEROMETER:
      handle_accelerometer();
      break;
    case SH2_GYROSCOPE_CALIBRATED:
      Serial.print("Gyroscope - (x, y, z) rad/s: (");
      Serial.print(sensorValue.un.gyroscope.x);
      Serial.print(", ");
      Serial.print(sensorValue.un.gyroscope.y);
      Serial.print(", ");
      Serial.print(sensorValue.un.gyroscope.z);
      Serial.println(") rad/s");
      break;
  }
}

void handle_accelerometer(){
  Serial.print("Accelerometer - (x, y, z) m/s^2: (");
  Serial.print(sensorValue.un.accelerometer.x);
  Serial.print(", ");
  Serial.print(sensorValue.un.accelerometer.y);
  Serial.print(", ");
  Serial.print(sensorValue.un.accelerometer.z);
  Serial.println(") m/s^2");

  float data[3] = {sensorValue.un.accelerometer.x, sensorValue.un.accelerometer.y, sensorValue.un.accelerometer.z};

  accelerometer_msg.data = data;
  accelerometer_publisher.publish(&accelerometer_msg);

  node_handle.spinOnce();
}
