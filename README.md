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
    - Relay Board:
    ![Relay board](/images/relay-board-sch.png)
    
    - Level Shifter:
    ![Level Shifter](/images/level-shifter-sch.jpg)

    - Regulator module:
    ![Regulator module](/images/regulator-sch.jpg)

3. **TV modification:**
    - Remove the internal power supply transformer. The set will be powered by a 12V DC external power supply only.
    - Remove the battery contacts for more room for the hardware in the battery compartment.
    - Cut the tracks of the tuning potentiometer, isolated it and connect it to the Arduino board:
    ![Potentiometer tracks](/images/potentiometer.jpg)
    - Isolate the video/TV switch and connect the wires to the relay board:
    ![Relay Board](/images/Relay-board.jpg)
    - Get the 12V from the DC barrel connector.
    
All the wires are send to the battery compartment.

4. **Software:**
    - TVSim.ino = Scketch for Arduino Mini Pro.
    - TVSim.py = Script for Raspberry Pi.

For enable the Raspberry Pi composite video output use the command:
```
$ sudo raspi-config
```

Put the Python script in auto start for the Raspberry Pi boot.

5. **Hardware inside the battery compartment:**
![Hardware inside the battery compartment](/images/final.jpg)

6. **Known problems and items for future improvements:**
    - Sometimes the TV show the mouse cursor or the Linux terminal. (problem)
    - Movies always starts from the beginning. (improvement)
    - Different channels (scifi, horror, cartoons, etc...)(improvement)

7. **Contact:**

Feel free to reach out to me on social media: @pakequis in any of them...

You can also send me an email at pakequis (Gmail).



