# Raspberry Pi TV Simulator
Code and hardware for simulate a channel change in a old tube TV.

The Raspberry Pi change a random movie file in the folder 'movies' when the TV is showing a static noise. The static noise is provide by the TV circuit. A Arduino Mini Pro get the voltage on the tunning potentiometer and turn a relay on or off, selecting the TV composite video input or the noise from the TV circuit.

**WARNING: Dangerous voltage inside TV set! Be Careful!**

1. **Demo Video**

[![demo video](https://img.youtube.com/vi/1pNfiL1X1ZA/0.jpg)](https://www.youtube.com/watch?v=1pNfiL1X1ZA)

1. **TV set:**

The TV set is a 5 inch tube TV with AM/FM radio. The set is powered by a 12V DC external power supply and has composite video and audio input. This input is selected by a switch on the back of the TV set. The TV has a battery compartment in the bottom where I mounted the Raspberry Pi.

The tuning circuit use a potentiometer to variable the voltage to the TV tunner. The radio board use a variable capacitor. The variable capacitor and the potentiometer are mechanically connected to the tunning knob.

2. **Hardware Schematics:**
    2.1 - Relay Board:
    ![Relay board](/images/relay-board-sch.png)
    
    2.2 - Level Shifter:
    ![Level Shifter](/images/level-shifter-sch.jpg)

    2.3 - Regulator module:
    ![Regulator module](/images/regulator-sch.jpg)

3. **TV modification:**
    3.1 - Remove the internal power supply transformer. The set will be powered by a 12V DC external power supply only.
    3.2 - Remove the battery contacts for more room for the hardware in the battery compartment.
    3.3 - Cut the tracks of the tuning potentiometer, isolated it and connect it to the Arduino board:
    ![Potentiometer tracks](/images/potentiometer.jpg)
    3.4 - Isolate the video/TV switch and connect the wires to the relay board:
    ![Relay Board](/images/relay-board.jpg)
    3.5 - Get the 12V from the DC barrel connector.
    
All the wires are send to the battery compartment.

4. **Software:**
    4.1 - TVSim.ino = Scketch for Arduino Mini Pro.
    4.4 - TVSim.py = Script for Raspberry Pi.

For enable the Raspberry Pi composite video output use the command:
```
$ sudo raspi-config
```

Put the Python script in auto start for the Raspberry Pi boot.

5. **Hardware inside the battery compartment:**
![Hardware inside the battery compartment](/images/final.jpg)

6. **Know problems and items for future improvements:**
    6.1 - Sometimes the TV show the mouse cursor or the Linux terminal. (problem)
    6.2 - Movies always starts from the beginning. (improvement)
    6.3 - Different channels (scifi, horror, cartoons, etc...)(improvement)





