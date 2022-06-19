# Raspberry Pi TV simulator - Python code
# by Rodrigo Feliciano - https://www.youtube.com/pakequis
#
# This code play a random video from a directory and wait for
# "channel" change.
#
import vlc      # Python-VLC library
import time
import os
import random
import RPi.GPIO as GPIO

# start execution
print ("start")

GPIO.setmode(GPIO.BOARD)

GPIO.setup(12, GPIO.IN, pull_up_down=GPIO.PUD_UP)
GPIO.setup(3, GPIO.OUT)
GPIO.output(3, GPIO.LOW)

random.seed()

#list all files in a directory and subdirectories
def list_files(dir):
    r = []
    for root, dirs, files in os.walk(dir):
        for name in files:
            r.append(os.path.join(root, name))
    return r

#movies path
path = "/home/test/RaspTV/movies"

file = random.choice(list_files(path))
print(file)

time.sleep(1)

Instance = vlc.Instance()
player = Instance.media_player_new()
player.toggle_fullscreen()
media = Instance.media_new(file)
player.set_media(media)
player.play()

time.sleep(2)
while not player.is_playing():
    time.sleep(0.001)

GPIO.output(3, GPIO.HIGH)    # Change Arduino to video_on state

flag = 0

#loop
while True:    
    if(GPIO.input(12) == GPIO.LOW):
        flag = 1
    else:
        if (flag == 1):
            print("change")
            flag = 0
            player.stop
            time.sleep(0.1)
            file = random.choice(list_files(path))
            media = Instance.media_new(file)
            player.set_media(media)
            player.play()
            time.sleep(2)

    # Next video if video is finished
    if not (player.is_playing()):
        print('next')
        player.stop
        time.sleep(0.1)
        file = random.choice(list_files(path))
        media = Instance.media_new(file)
        player.set_media(media)
        player.play()
        time.sleep(2)

# end of execution
print ("stop")