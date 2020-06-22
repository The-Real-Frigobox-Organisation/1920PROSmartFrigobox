/*
* This code is used to receive bluetooth command from the App
* Built by Elian Van Cutsem @The smart frigobox team
*/

#include <Arduino.h>
#include <SoftwareSerial.h>

int bluetoothTx = 2;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 3;  // RX-I pin of bluetooth mate, Arduino D3

bool constructingString = false;
String stringToBuild;

SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);

void setup()
{
  Serial.begin(9600);  // Begin the serial monitor at 9600bps
  Serial.println("Arduino Ready");
  bluetooth.begin(115200);  // The Bluetooth Mate defaults to 115200bps
  bluetooth.print("$");  // Print three times individually
  bluetooth.print("$");
  bluetooth.print("$");  // Enter command mode
  delay(100);  // Short delay, wait for the Mate to send back CMD
  bluetooth.println("U,9600,N");
  // Temporarily Change the baudrate to 9600, no parity
  // 115200 can be too fast at times for NewSoftSerial to relay the data reliably
  bluetooth.begin(9600);  // Start bluetooth serial at 9600
  bluetooth.println("bluetooth Ready");
  Serial.println("output ready");
  pinMode(13, OUTPUT);
}

void loop(){
  if(bluetooth.available() > 0)  // If the bluetooth sent any characters
  {
    // Send any characters the bluetooth prints to the serial monitor
    char charToSend = (char) bluetooth.read();
    Serial.println("got a char: " + charToSend);
    if(constructingString){
      stringToBuild += charToSend;
    }

    if (charToSend == '#'){
      bluetooth.println("got a #!");
      if (constructingString == false){
        bluetooth.println("constructing command now");
        constructingString = true;
      }
      else {
        bluetooth.println("ending command now");
        String command = stringToBuild.substring(0, (stringToBuild.length() - 1));
        bluetooth.println(command);
        checkIfCommand(command);
        stringToBuild = "";
        constructingString = false;
      }
    }
  }
}

void checkIfCommand(String cmd){
    bluetooth.println("checking if " + cmd + " is a command");
    String prefix = cmd.substring(0,3);
    bluetooth.println(prefix);

    if(prefix.equals("LED")){
        bluetooth.println("got LED as prefix");

        int outputNr = cmd.substring(cmd.indexOf('O') + 1, cmd.indexOf('W')).toInt();
        //bluetooth.println(outputNr);

        String state = cmd.substring(cmd.indexOf('W') + 1, cmd.indexOf('W' + 2));
        //bluetooth.println(state);

        if(state.equals("1")){
            Serial.println("turning on LED" + outputNr);
            bluetooth.println("turning on led" + outputNr);
            digitalWrite(outputNr, HIGH);
        }
        else if(state.equals("0")){
            Serial.println("turning off LED" + outputNr);
            bluetooth.println("turning off led" + outputNr);
            digitalWrite(outputNr, LOW);
        }
    }
    else {
      bluetooth.println(cmd + " is not a command");
    }
    
}
