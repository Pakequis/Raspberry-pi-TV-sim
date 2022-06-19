/*
    Raspberry Pi TV simulator - Arduino code
    by Rodrigo Feliciano - https://www.youtube.com/pakequis

    This code read the tune potentiometer of the TV and
    set a relay for 3 different "channels".
*/

#define CH1_MIN_VALUE 50
#define CH1_MAX_VALUE 150
#define CH2_MIN_VALUE 250
#define CH2_MAX_VALUE 350
#define CH3_MIN_VALUE 450
#define CH3_MAX_VALUE 550
#define CH4_MIN_VALUE 650
#define CH4_MAX_VALUE 750
#define CH5_MIN_VALUE 850
#define CH5_MAX_VALUE 950
#define VIDEO_RELAY_PIN 12

#define IN_PIN 7
#define OUT_PIN 8

typedef enum
{
    no_video,
    video_on
}loop_state;

int mode = no_video;
char channel = '0';

/* Channel select with TV tune potentiometer */
char channel_select()
{
    int val = analogRead(A0);

    if(val > CH1_MIN_VALUE && val < CH1_MAX_VALUE) return '1';
    //else if(val > CH2_MIN_VALUE && val < CH2_MAX_VALUE) return '2';   /* for future use with 5 channels */
    else if(val > CH3_MIN_VALUE && val < CH3_MAX_VALUE) return '3';
    //else if(val > CH4_MIN_VALUE && val < CH4_MAX_VALUE) return '4';   /* for future use with 5 channels */
    else if(val > CH5_MIN_VALUE && val < CH5_MAX_VALUE) return '5';
    else return '0';
}

//arduino setup
void setup() 
{
    pinMode(LED_BUILTIN,OUTPUT);
    digitalWrite(LED_BUILTIN,LOW);
    pinMode(VIDEO_RELAY_PIN, OUTPUT);
    digitalWrite(VIDEO_RELAY_PIN, HIGH);

    pinMode(IN_PIN, INPUT);
    pinMode(OUT_PIN, OUTPUT);
    digitalWrite(OUT_PIN, LOW);
}

//arduino loop
void loop() 
{
    channel = channel_select();
    
    switch (mode)
    {
        case no_video:
            if(digitalRead(IN_PIN) == HIGH) mode = video_on;
            digitalWrite(VIDEO_RELAY_PIN, HIGH);
            digitalWrite(OUT_PIN, LOW);
        break;

        case video_on:            
            if(channel != '0')
            {
                digitalWrite(VIDEO_RELAY_PIN, LOW);
                digitalWrite(OUT_PIN, HIGH);
            }
            else 
            {
                digitalWrite(VIDEO_RELAY_PIN, HIGH);
                digitalWrite(OUT_PIN, LOW);
            }
            if(digitalRead(IN_PIN) == LOW) mode = no_video;
        break;
        
        case 2:
            mode = no_video;    /* for future use... */
        break;

        default:
            mode = no_video;
        break;
    }
    
    delay(100);
}
