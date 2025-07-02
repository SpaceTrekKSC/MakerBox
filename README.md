# SpaceTrek MakerBox

This entry level kit contains the basics you'll need to get started in the world of Arduino programming & electronics.

## What is Arduino
Arduino refers to an open-source electronics platform or board and the software used to program it. Arduino is designed to make electronics and programming more accessible to students, artists, designers, hobbyists and ayone interested in creating interactive objects or environments.

## What's Included in the MakerBox

| Image          | Part | Description  		|
| ------------- | ------------- |---------------------|
| ![Arduino Uno](images/uno-board.jpg "Arduino Uno") | Arduino Uno | The Arduino Uno is an open source micro controller capable of controlling multiple input and output devices. |
| ![alt text](images/uno-board.jpg "IO Shield") | IO Shield | The IO Shield goes on the Uno and makes connecting devices simple and foolproof. |
| ![alt text](images/uno-board.jpg "Jumper Wires") | Jumper Wires | The jumper wires connect the devices to the IO Shield. |
| ![alt text](images/usb-cable.jpg "USB Cable") | USB Cable | You'll need this to connect your Uno to your computer to power and load code onto the board. |
| ![alt text](images/uno-board.jpg "MicroSD Card") | MicroSD Card | The microSD card is for the MP3 player. |
| ![alt text](images/uno-board.jpg "MicroSD Adapter") | MicroSD Adapter | The MicroSD adapter allows you to connect a microSD card through your USB port. |
| ![alt text](images/uno-board.jpg "MP3 Player") | MP3 Player | An MP3 player for playing music and voice files. |
| ![alt text](images/uno-board.jpg "Touch Pad") | Touch Pad | A capacitive touch pad fro reading user input. |
| ![alt text](images/uno-board.jpg "1602 LCD Display") | 1602 LCD Display | A 16 character by two row LCD display to see output from your Arduino. |
| ![alt text](images/uno-board.jpg "IR Remote Control") | IR Remote Control | An infrared remote control for providing input to your Arduino. |
| ![alt text](images/uno-board.jpg "Ultrasonic Distance Sensor") | Ultrasonic Distance Sensor | An ultrasonic distance sensor meassures distance using sound. |
| ![alt text](images/uno-board.jpg "Temperature Sensor") | Temperature Sensor | Meassure your enviroments temperature with this sensor. |
| ![alt text](images/uno-board.jpg "Water Sensor") | Water Sensor | Detects the presence of water or other conductive materials. |
| ![alt text](images/uno-board.jpg "Light Sensor") | Light Sensor | Detects how much light there is with a photoresistor. |
| ![alt text](images/uno-board.jpg "Active Buzzer") | Active Buzzer | The active buzzer generates a fixed tone when it is turned on. |
| ![alt text](images/uno-board.jpg "Passive Buzzer") | Passive Buzzer | The passive buzzer lets you provide it with different frequencies to change the tone it generates. |
| ![alt text](images/uno-board.jpg "Real Time Clock") | Real Time Clock | The Real Time Clock (RTC) keeps acturate time even when your Arduino is powered off. |
| ![alt text](images/uno-board.jpg "Button") | Button | A simple push button for your projects. |
| ![alt text](images/uno-board.jpg "Rocker Switch") | Rocker Switch | A simple switch for your projects. |
| ![alt text](images/uno-board.jpg "Slider") | Slider | A slider changes resistance as it's position is changed. |
| ![alt text](images/uno-board.jpg "Knob") | Knob | Similar to the slider but rotated instead of slid. |
| ![alt text](images/uno-board.jpg "LED") | LED | A simple LED. |
| ![alt text](images/uno-board.jpg "RGB LED") | RGB LED | The RGB stands for Red, Green, Blue. This LED lets you change its color |
| ![alt text](images/uno-board.jpg "Vibration Motor") | Vibration Motor | A vibration motor is what lets your cell phone vibrate or have heptic feedback. |
| ![alt text](images/uno-board.jpg "4 Digit Display") | 4 Digit Display | The 4 digit display uses 7 segment characters like an old digital clock. |

## Getting Started

### Install Arduino IDE
The Arduino IDE can be found on the official Arduino website at https://www.arduino.cc/en/Main/Software

Download the version suitable for your computer and follow the prompts to install the software package.

### Write or Paste Code 
Opening the Arduino IDE for the first time, you will be presented with the following screen.

![alt text](images/ide-main.png "IDE Main Screen")

This is where you will write or paste in the code for your project.

### Uploading Code
Now that you have prepared your code, it's time to upload it onto the board.

#### Selecting Board type & Port
You'll need to select the entry in the Tools > Board menu that corresponds to your Arduino board. For the duinotech Uno, you will select Arduino/Genuino Uno.

![alt text](images/board-type.png "Board Type")

Select the serial device of the board from the Tools | Serial Port menu. This is likely to be COM3 or higher (COM1 and COM2 are usually reserved for hardware serial ports). To find out, you can disconnect your board and re-open the menu; the entry that disappears should be the duinotech Uno board. Reconnect the board and select that serial port.

![alt text](images/selecting-port.png "Selecting Port")

#### Uploading Code
Now, simply click the "Upload" button in the environment. Wait a few seconds - you should see the RX and TX LEDs on the board flashing. If the upload is successful, the message "Done uploading." will appear in the status bar. 

![alt text](images/uploading.png "Uploading Code")

The example projects in this kit are free of errors, however, if you write your own code you may find an error when uploading your code. The software will show a message indicating the type of error and the location in which it appears in the code.

## Projects
Now that you have the Arduino IDE setup and ready to use you can begin working through our beginner projects.

| Project          | Outcome |
| ------------- |---------------------|
| [Using an LED](https://github.com/) | This basic project will introduce the beginner Arduino user to simple code & circuits by turning on & off an LED. |
| [Using a Potentiometer](https://github.com/) | Use a potentiometer to adjust the brightness of the in-built LED on the Arduino Uno. |
| [Using Buttons](https://github.com/) | Use feedback from an analogue sensor to activate a buzzer via the Arduino board. |
| [Fan Speed Controller](https://github.com/) | Use variable feedback from a potentiometer to adjust the speed of the motor. |
| [Traffic Lights](https://github.com/) | Simulate traffic lights using multiple LEDs & a loop circuit in Arduino. |
